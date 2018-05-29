#pragma once

enum InputTypes {
  DIR_NONE,
  DIR_FORWARD,
  DIR_BACKWARD,
  DIR_LEFT,
  DIR_RIGHT,
  SHANGE_MODE,
  SWITCH_OFF,
  SWITCH_ON
};

enum Motors_Direction {
  Rotate_Forward,
  Rotate_Backward,
  Rotate_None
};

#define SPEED_MAX 255
#define SPEED_MIN 100
#define SPEED_NULL 0

byte lastDirection = 0;

void printDirection(const byte dir);
void rideForward();
void rideBackward();
void rideLeft();
void rideRight();

void LeftMotor_setRotate(byte rotate_direction);
void RightMotor_setRotate(byte rotate_direction);
void LeftMotor_setSpeed(byte motor_speed);
void RightMotor_setSpeed(byte motor_speed);


void sharply_Right();
void sharply_Left();
void ride_Backward_Right();
void ride_Backward_Left();


void ride(byte cur_direction, byte ride_speed, int delay_time);
void ride_sharply(byte ride_direction, int ride_speed, int delay_time);
void ride_backward_turn(byte ride_direction, int ride_speed, int delay_time);
