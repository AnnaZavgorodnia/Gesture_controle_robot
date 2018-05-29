#include "radio.h"
#include "directions.h"
#include "detour.h"
#include "distance.h"
#include "massage.h"
#include "motors.h"
#include "modes.h"
#include "Ultrasonic.h"
#include <Servo.h>

#define SERVO_MAIN_PIN 9
Servo servo;

#define TRIGGER_PIN 14 
#define ECHO_PIN 15 
Ultrasonic main_scaner(TRIGGER_PIN, ECHO_PIN);
Ultrasonic back_scaner(A2, A3); 

void setup() {
  
  /* #HAND_CONTROL  */  
    cur_mode = HandControl;

  /* #DETOUR */
  //  cur_mode = Detour;

  while (!Serial);
  Serial.begin(9600);

  switch (cur_mode) {
    case Off: {
        /* Not realized! */
        break;
    }
    case HandControl: {
      Radio_start();    
      break;
    }
    case Detour: {
      servo.attach(SERVO_MAIN_PIN);       
      break;
    }
    case Record: {
       /* Not realized! */   
      break;
    }
  }
    
   Motors_init(cur_mode);
}

void loop() {

  if (inp_inptype == SHANGE_MODE) {
      cur_mode = inp_mode;
       /* Not realized! */
  }
  if (inp_inptype == SWITCH_OFF) {
       /* Not realized! */
  }
  if (inp_inptype == SWITCH_ON) {
       /* Not realized! */
  }
        
  switch (cur_mode) {
    case Off: {
          /* Not realized! */
        break;
    }
    case HandControl: {
      if (radio.available()) {
        int massage[] = {0, 0, 0, 0};
    
        radio.read(&massage, sizeof(massage));

        byte inp_mode = massage[0];
        byte inp_submode = massage[1];
        byte inp_inptype = massage[2];
        byte inp_speed = massage[3];

        // print data to debug
        /*
        Serial.print(inp_mode);
        Serial.print(" |  ");
        Serial.print(inp_submode);
        Serial.print(" | Direction ");
        Serial.print(inp_inptype);
        Serial.print(" |  ");
        Serial.println(inp_speed);
        */
        
        cur_direction = inp_inptype;
      
        ride(cur_direction, SPEED_MAX, 0);
      }
      break;
    }
    case Detour: {
      
     new_algorithm();
     
     break;
    }
    case Record: {
       /* Not realized! */   
      break;
    }
    }
}
