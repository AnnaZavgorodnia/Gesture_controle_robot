int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 3;  //ШИМ выход 1
int ENB = 9;  //ШИМ выход 2
int i = 250;
int spd = 10;  //задержка при изменении скорости, чем меньше тем быстрее

enum directionEnum {
  FORWARD = 1,
  BEHIND = 2,
  LEFT = 3,
  RIGHT = 4,
  NONE = 0
};
byte robo_speed = 0;

void printDirection(const byte dir);
void rideForward();
void rideBehind();
void rideLeft();
void rideRight();

void setup() {  
  pinMode (ENA, OUTPUT);  //ШИМ выход 1
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENB, OUTPUT);  //ШИМ выход 2
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void loop() {
  rideForward();
  rideBehind();
  rideLeft();
  rideRight();
}

void rideForward() {
  digitalWrite (IN1, HIGH);  //полярность для мотора1  "+"
  digitalWrite (IN2, LOW);  //полярность для мотора1 "-"
  digitalWrite (IN3, LOW);  //полярность для мотора2 "+"
  digitalWrite (IN4, HIGH);  //полярность для мотора2 "-"
  analogWrite(ENA, i);
  analogWrite(ENB, i);
  delay(1000);  //ждем 2 сек
  analogWrite (ENA, 0);
  analogWrite (ENB, 0);
  delay(500);
}

void rideBehind() {
  digitalWrite (IN1, LOW);  //полярность для мотора1  "-"
  digitalWrite (IN2, HIGH);  //полярность для мотора1 "+"
  digitalWrite (IN3, HIGH);  //полярность для мотора2 "-"
  digitalWrite (IN4, LOW);  //полярность для мотора2 "+"
  analogWrite(ENA, i);
  analogWrite(ENB, i);
  delay(1000);  //ждем 2 сек
  analogWrite (ENA, 0);
  analogWrite (ENB, 0);
  delay(500);
}

void rideLeft() {
  analogWrite (ENB, 0);
  digitalWrite (IN1, HIGH);  //полярность для мотора1  "-"
  digitalWrite (IN2, LOW);  //полярность для мотора1 "+"
  analogWrite(ENA, i);
  delay(1000);  //ждем 2 сек
  analogWrite (ENA, 0);
  delay(500);
}

void rideRight() {
  analogWrite (ENA, 0);
  digitalWrite (IN3, LOW);  //полярность для мотора2 "-"
  digitalWrite (IN4, HIGH);  //полярность для мотора2 "+"
  analogWrite(ENB, i);
  delay(1000);  //ждем 2 сек
  analogWrite (ENB, 0);
  delay(500);
}
