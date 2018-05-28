#include "detour.h"

void new_algorithm() { 
  byte Forward_DistLevel = scan(Forward,300);

  if (Forward_DistLevel != LONG_AWAY) {
    ride(NONE, 0, 0);
    
    switch (Forward_DistLevel) {
    case NONE: case CRITICAL: {
      byte Left_DistLevel = scan(Left, 300);
      byte Left45_DistLevel = scan(Forward_Left, 150);
      byte Right45_DistLevel = scan(Forward_Right, 300);
      byte Right_DistLevel = scan(Right, 150);
      byte Backward_DistLevel = scan(Backward, 0);

    if (Backward_DistLevel > CRITICAL) {
        if (Left_DistLevel > CRITICAL && Right_DistLevel > CRITICAL) {
        if (Left_DistLevel == Right_DistLevel) {
          // random
          ride_backward_turn(DIR_RIGHT, 130, 500);
        } else if (Left_DistLevel > Right_DistLevel) {
          ride_backward_turn(DIR_LEFT, 130, 500);
        } else {
          ride_backward_turn(DIR_RIGHT, 130, 500);
        }
      } else {
        ride(DIR_BACKWARD, 130, 500);
      }
}       
      break;
    }
    case VERY_CLOSE: {
      byte Left_DistLevel = scan(Left, 300);
      byte Left45_DistLevel = scan(Forward_Left, 150);
      byte Right45_DistLevel = scan(Forward_Right, 300);
      byte Right_DistLevel = scan(Right, 150);
      byte Backward_DistLevel = scan(Backward, 0);

      if (Forward_DistLevel >= CRITICAL && Backward_DistLevel >= CRITICAL) {
        bool turn_left_pass = Left45_DistLevel >= VERY_CLOSE && Left_DistLevel > CLOSE;
        bool turn_right_pass = Right45_DistLevel >= VERY_CLOSE && Right_DistLevel > CLOSE;
        if (turn_left_pass && turn_right_pass) {
          if (Left_DistLevel + Left45_DistLevel > Right_DistLevel + Right45_DistLevel) {
            ride_sharply(DIR_LEFT, 130, 500);
          } else if (Right_DistLevel + Right45_DistLevel > Left_DistLevel + Left45_DistLevel) {
            ride_sharply(DIR_RIGHT, 130, 500);
          } else {
            if (Left_DistLevel > Right_DistLevel) {
              ride_sharply(DIR_LEFT, 130, 500);
            } else if (Right_DistLevel > Left_DistLevel) {
              ride_sharply(DIR_RIGHT, 130, 500);
            } else {
              // random // @todo write method compare();
              ride_sharply(DIR_RIGHT, 130, 500);
            }
          }
        } else if (turn_left_pass) {
          ride_sharply(DIR_LEFT, 130, 500);
        } else if (turn_right_pass) {
          ride_sharply(DIR_RIGHT, 130, 500);
        } else {
            if (Left_DistLevel > CRITICAL && Right_DistLevel > CRITICAL) {
              if (Left_DistLevel == Right_DistLevel) {
                // random
                ride_backward_turn(DIR_RIGHT, 130, 500);
              } else if (Left_DistLevel > Right_DistLevel) {
                ride_backward_turn(DIR_LEFT, 130, 500);
              } else {
                ride_backward_turn(DIR_RIGHT, 130, 500);
              }
            } else {
              ride(DIR_BACKWARD, 130, 500);
            }
        }
      }
                /// exeption
                ride_sharply(DIR_RIGHT, 130, 500);

      break;
    }
    case CLOSE: {
      byte Left_DistLevel = scan(Left, 300);
      byte Left45_DistLevel = scan(Forward_Left, 150);
      byte Right45_DistLevel = scan(Forward_Right, 300);
      byte Right_DistLevel = scan(Right, 150);
      byte Backward_DistLevel = scan(Backward, 0);

      bool nothing = false;

      if (Forward_DistLevel >= CLOSE && Backward_DistLevel >= CRITICAL) {
        bool turn_left_pass = Left45_DistLevel >= CLOSE && Left_DistLevel > CRITICAL;
        bool turn_right_pass = Right45_DistLevel >= CLOSE && Right_DistLevel > CRITICAL;
        if (turn_left_pass && turn_right_pass) {
          if (Left45_DistLevel == Right45_DistLevel) {
            if (Left_DistLevel == Right_DistLevel) {
              // random
              ride(DIR_LEFT, 130, 500);
            } else if (Left_DistLevel > Right_DistLevel) {
              ride(DIR_LEFT, 130, 500);
            } else ride(DIR_RIGHT, 130, 500);
          } else if (Left45_DistLevel > Right45_DistLevel) {
            ride(DIR_LEFT, 130, 500);
          } else {
            ride(DIR_RIGHT, 130, 500);
          }          
        } else if (turn_left_pass) {
          ride(DIR_LEFT, 130, 500);
        } else if (turn_right_pass) {
          ride(DIR_RIGHT, 130, 500);
        } else {
          nothing = true;
        }
      } else nothing = true;

      if (nothing) {
          if (Forward_DistLevel >= CRITICAL && Backward_DistLevel >= CRITICAL) {
          bool turn_left_pass = Left45_DistLevel >= VERY_CLOSE && Left_DistLevel > CLOSE;
          bool turn_right_pass = Right45_DistLevel >= VERY_CLOSE && Right_DistLevel > CLOSE;
          if (turn_left_pass && turn_right_pass) {
            if (Left_DistLevel + Left45_DistLevel > Right_DistLevel + Right45_DistLevel) {
              ride_sharply(DIR_LEFT, 130, 500);
            } else if (Right_DistLevel + Right45_DistLevel > Left_DistLevel + Left45_DistLevel) {
              ride_sharply(DIR_RIGHT, 130, 500);
            } else {
              if (Left_DistLevel > Right_DistLevel) {
                ride_sharply(DIR_LEFT, 130, 500);
              } else if (Right_DistLevel > Left_DistLevel) {
                ride_sharply(DIR_RIGHT, 130, 500);
              } else {
                // random // write method compare();
                ride_sharply(DIR_RIGHT, 130, 500);
              }
            }
          } else if (turn_left_pass) {
            ride_sharply(DIR_LEFT, 130, 500);
          } else if (turn_right_pass) {
            ride_sharply(DIR_RIGHT, 130, 500);
          } else {
            if (Left_DistLevel > CRITICAL && Right_DistLevel > CRITICAL) {
              if (Left_DistLevel == Right_DistLevel) {
                // random
                ride_backward_turn(DIR_RIGHT, 130, 500);
              } else if (Left_DistLevel > Right_DistLevel) {
                ride_backward_turn(DIR_LEFT, 130, 500);
              } else {
                ride_backward_turn(DIR_RIGHT, 130, 500);
              }
            } else {
              ride(DIR_BACKWARD, 130, 500);
            }
        }
      }
                /// exeption
                ride_sharply(DIR_RIGHT, 130, 500);

      }
      break;
    }
    case AVERAGE: {
      byte Left_DistLevel = scan(Left, 300);
      byte Left45_DistLevel = scan(Forward_Left, 150);
      byte Right45_DistLevel = scan(Forward_Right, 300);
      byte Right_DistLevel = scan(Right, 150);
      byte Backward_DistLevel = scan(Backward, 0);
      
      if (Forward_DistLevel >= CLOSE) {
        bool turn_left_pass = Left45_DistLevel >= CLOSE && Left_DistLevel > CRITICAL;
        bool turn_right_pass = Right45_DistLevel >= CLOSE && Right_DistLevel > CRITICAL;
        if (turn_left_pass && turn_right_pass) {
          if (Left45_DistLevel > Forward_DistLevel || Right45_DistLevel > Forward_DistLevel) {
              if (Left45_DistLevel == Right45_DistLevel) {
              if (Left_DistLevel == Right_DistLevel) {
                // random
                ride(DIR_LEFT, 130, 500);
              } else if (Left_DistLevel > Right_DistLevel) {
                ride(DIR_LEFT, 130, 500);
              } else ride(DIR_RIGHT, 130, 500);
            } else if (Left45_DistLevel > Right45_DistLevel) {
              ride(DIR_LEFT, 130, 500);
            } else {
              ride(DIR_RIGHT, 130, 500);
            } 
         }
         
        } else if (turn_left_pass) {
            if (Left45_DistLevel > Forward_DistLevel) {
                        ride(DIR_LEFT, 130, 500);
            }

        } else if (turn_right_pass) {
            if (Right45_DistLevel > Forward_DistLevel) {
              ride(DIR_RIGHT, 130, 500);
            }
        } 
      }

      break;
    }
  }
} else {
  ride(DIR_FORWARD, 130, 0);
}
}
