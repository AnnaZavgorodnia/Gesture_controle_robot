void LeftMotor_setRotate(byte rotate_direction) {
  switch (rotate_direction) {
    case Rotate_Forward: {
      digitalWrite (IN1, HIGH);  
      digitalWrite (IN2, LOW);
      break;
    }
    case Rotate_Backward: {
    digitalWrite (IN1, LOW);  
    digitalWrite (IN2, HIGH);
    break;
  }
  default: {
    digitalWrite (IN1, LOW);  
    digitalWrite (IN2, LOW);
    break;
  }
  }
}

void RightMotor_setRotate(byte rotate_direction) {
  switch (rotate_direction) {
    case Rotate_Forward: {
      digitalWrite (IN3, LOW);
      digitalWrite (IN4, HIGH);
      break;
    }
    case Rotate_Backward: {
     digitalWrite (IN3, HIGH);
     digitalWrite (IN4, LOW);
    break;
  }
  default: {
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    break;
  }
  }
}

void RightMotor_setSpeed(byte motor_speed) {
  if (motor_speed * 1.5 > SPEED_MAX) {
    analogWrite(ENB, SPEED_MAX);
  } else {
    analogWrite(ENB, motor_speed * 1.5);
  }
}

void LeftMotor_setSpeed(byte motor_speed) {
  if (motor_speed * 1.5 > SPEED_MAX) {
    analogWrite(ENA, SPEED_MAX);
  } else {
    analogWrite(ENA, motor_speed * 1.5);
  }
}
  

void rideForward() {
  LeftMotor_setRotate(Rotate_Forward);
  RightMotor_setRotate(Rotate_Forward);
}

void rideBackward() {
  LeftMotor_setRotate(Rotate_Backward);
  RightMotor_setRotate(Rotate_Backward);
}

void rideRight() {
  LeftMotor_setRotate(Rotate_Forward);
  RightMotor_setRotate(Rotate_None);
}

void rideLeft() {
  LeftMotor_setRotate(Rotate_None);
  RightMotor_setRotate(Rotate_Forward);
}

void stayHere() {
  LeftMotor_setRotate(Rotate_None);
  RightMotor_setRotate(Rotate_None);
}

void sharply_Right() {
  LeftMotor_setRotate(Rotate_Forward);
  RightMotor_setRotate(Rotate_Backward);
}

void sharply_Left() {
  LeftMotor_setRotate(Rotate_Backward);
  RightMotor_setRotate(Rotate_Forward);
}

void ride_Backward_Right() {
  LeftMotor_setRotate(Rotate_Backward);
  RightMotor_setRotate(Rotate_None);
}

void ride_Backward_Left() {
  LeftMotor_setRotate(Rotate_None);
  RightMotor_setRotate(Rotate_Backward);
}

void ride_backward_turn(byte ride_direction, int ride_speed, int delay_time) {
  switch (ride_direction) {
    case DIR_LEFT: {
    ride_Backward_Left();
    LeftMotor_setSpeed(0);
    RightMotor_setSpeed(ride_speed);
    break;
   }
   case DIR_RIGHT: {
    ride_Backward_Right();
    LeftMotor_setSpeed(ride_speed);
    RightMotor_setSpeed(0);
    break;
   }
   default: {
    stayHere();
    LeftMotor_setSpeed(0);
    RightMotor_setSpeed(0);
    break;
   }
  }
}

void ride_sharply(byte ride_direction, int ride_speed, int delay_time) {
  switch (ride_direction) {
    case DIR_LEFT: {
    sharply_Left();
    LeftMotor_setSpeed(ride_speed);
    RightMotor_setSpeed(ride_speed);
    break;
   }
   case DIR_RIGHT: {
    sharply_Right();
    LeftMotor_setSpeed(ride_speed);
    RightMotor_setSpeed(ride_speed);
    break;
   }
   default: {
    stayHere();
    LeftMotor_setSpeed(0);
    RightMotor_setSpeed(0);
    break;
   }
  }
}

void ride(byte ride_direction, byte ride_speed, int delay_time) {
  switch (ride_direction) {
   case DIR_FORWARD: {
    rideForward();
    LeftMotor_setSpeed(ride_speed);
    RightMotor_setSpeed(ride_speed);
    break;
   }
   case DIR_BACKWARD: {
    rideBackward();
    LeftMotor_setSpeed(ride_speed);
    RightMotor_setSpeed(ride_speed);
    break;
   }
   case DIR_LEFT: {
    rideLeft();
    LeftMotor_setSpeed(0);
    RightMotor_setSpeed(ride_speed);
    break;
   }
   case DIR_RIGHT: {
    rideRight();
    LeftMotor_setSpeed(ride_speed);
    RightMotor_setSpeed(0);
    break;
   }
   default: {
    stayHere();
    LeftMotor_setSpeed(0);
    RightMotor_setSpeed(0);
    break;
   }
   }
   delay(delay_time);
}
