#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "Ultrasonic.h"

RF24 radio(8,10); // "создать" модуль на пинах 9 и 10 Для Уно
//RF24 radio(9,53); // для Меги

// sensor connected to:
// Trig - 2, Echo - 1
Ultrasonic ultrasonic(2, 1);

byte address[][6] = {"1Node","2Node","3Node","4Node","5Node","6Node"};  //возможные номера труб

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 3;  //ШИМ выход 1
int ENB = 9;  //ШИМ выход 2
int i;
int spd = 10;  //задержка при изменении скорости, чем меньше тем быстрее 

bool isRacing = false;
enum directionEnum {
  FORWARD = 1,
  BEHIND = 2,
  LEFT = 3,
  RIGHT = 4,
  NONE = 0
};
byte robo_speed = 0;
byte pipeNo;
byte massage[2] = {0, 0};
byte dir = 0; 
byte lastDirection = 0;

void printDirection(const byte dir);
void rideForward();
void rideBehind();
void rideLeft();
void rideRight();

void setup() {
  // # motors
  pinMode (ENA, OUTPUT);  //ШИМ выход 1
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENB, OUTPUT);  //ШИМ выход 2
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  // # wireless radio module
  // Serial.begin(9600); //открываем порт для связи с ПК
  radio.begin(); //активировать модуль
  radio.setAutoAck(0);         // режим подтверждения приёма, 1 вкл 0 выкл
  radio.setRetries(0,10000);     // (время между попыткой достучаться, число попыток)
  // radio.enableAckPayload();    // разрешить отсылку данных в ответ на входящий сигнал
  radio.setPayloadSize(32);     // размер пакета, в байтах

  radio.openReadingPipe(1,address[0]);      // хотим слушать трубу 0
  radio.setChannel(0x60);  // выбираем канал (в котором нет шумов!)

  radio.setPALevel (RF24_PA_MAX); //уровень мощности передатчика. На выбор RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_250KBPS); //скорость обмена. На выбор RF24_2MBPS, RF24_1MBPS, RF24_250KBPS
  //должна быть одинакова на приёмнике и передатчике!
  //при самой низкой скорости имеем самую высокую чувствительность и дальность!!
  
  radio.powerUp(); //начать работу
  radio.startListening();  //начинаем слушать эфир, мы приёмный модуль
}

void loop() {
    if (radio.available(&pipeNo)){    // слушаем эфир со всех труб
      lastDirection = dir;
      radio.read(&massage, sizeof(massage));         // чиатем входящий сигнал
      dir = massage[0];
      robo_speed = massage[1];
      printDirection(dir);
      if (lastDirection != dir) {
        switch (dir) {
        case FORWARD: { // forward
          rideForward();
          break;
        }
        case BEHIND: { // behind
          rideBehind();
          break;
        }
        case LEFT: { // Left
          rideLeft();
          break;
        }
        case RIGHT: { // Right
          rideRight();
          break;
        }
        case NONE: {
            digitalWrite (IN1, LOW);  //полярность для мотора1  "+"
            digitalWrite (IN2, LOW);  //полярность для мотора1 "-"
            digitalWrite (IN3, LOW);  //полярность для мотора2 "+"
            digitalWrite (IN4, LOW);  //полярность для мотора2 "-"
            break;
        }
        }
      }
      if (ultrasonic.Ranging(CM) > 30 || dir != FORWARD) {
         if (dir != RIGHT && dir != NONE) {
          analogWrite(ENA, robo_speed);
        }
        if (dir != LEFT && dir != NONE) {
          analogWrite(ENB, robo_speed);
        }
      } else dir = NONE;
      lastDirection = dir;
     }
}

void printDirection(const byte dir) {
  Serial.print("Recieved: ");
        switch (dir) {
        case FORWARD: { // forward
          Serial.println("Forward");
          break;
        }
        case BEHIND: { // behind
          Serial.println("Behind");
          break;
        }
        case LEFT: { // Left
          Serial.println("Left");
          break;
        }
        case RIGHT: { // Right
          Serial.println("Right");
          break;
        }
        case NONE: {
          Serial.println("None");
          break;
        }
        default: {
          Serial.println(dir);
          break;
        }
  }
}

void rideForward() {
  digitalWrite (IN1, HIGH);  //полярность для мотора1  "+"
  digitalWrite (IN2, LOW);  //полярность для мотора1 "-"
  digitalWrite (IN3, LOW);  //полярность для мотора2 "+"
  digitalWrite (IN4, HIGH);  //полярность для мотора2 "-"
}

void rideBehind() {
  digitalWrite (IN1, LOW);  //полярность для мотора1  "-"
  digitalWrite (IN2, HIGH);  //полярность для мотора1 "+"
  digitalWrite (IN3, HIGH);  //полярность для мотора2 "-"
  digitalWrite (IN4, LOW);  //полярность для мотора2 "+"
}

void rideLeft() {
  analogWrite (ENB, 0);
  digitalWrite (IN1, HIGH);  //полярность для мотора1  "-"
  digitalWrite (IN2, LOW);  //полярность для мотора1 "+"
}

void rideRight() {
  analogWrite (ENA, 0);
  digitalWrite (IN3, LOW);  //полярность для мотора2 "-"
  digitalWrite (IN4, HIGH);  //полярность для мотора2 "+"
}



