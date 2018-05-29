#pragma once

enum Directions_distance {
  Right,
  Forward_Right,
  Forward,
  Forward_Left,
  Left,
  Backward
};

enum Directions_detour {
  Sharply_RIGHT,
  Sharply_LEFT,
  F_LEFT,
  F_RIGHT,
  B_LEFT,
  B_RIGHT,
  FORWARD,
  BACKWARD
};

enum Directions_angle {
  RIGHT_ANGLE = 0,
  FORWARD_RIGHT_ANGLE = 45,
  FORWARD_ANGLE = 90,
  FORWARD_LEFT_ANGLE = 135,
  LEFT_ANGLE = 180  
};

enum Direction_lavel {
  NONE,
  CRITICAL,
  VERY_CLOSE,
  CLOSE,
  AVERAGE,
  LONG_AWAY
};

int critical_distance = 5;
int very_close_distance = 15;
int close_distance = 25;
int average_distance = 40;
int long_away = 60;
