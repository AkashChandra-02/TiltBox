#include <Servo.h>

int joyX = 0;
int joyY = 1;

int servX = 5;
int servY = 6;

float X = 0;
float Y = 0;

Servo servoX;
Servo servoY;

int randomInt;

int light = 3;
int sensor = 0;
int Threshhold = 400;

int buzzer = 3;

void setup()
{
  servoX.attach(servX);
  servoY.attach(servY);
  
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop()
{
  sensor = analogRead(light);
  Serial.println(sensor);
  
  if(sensor > 100)
  {
    tone(buzzer, 440);
  }
  
  else
  {
    noTone(buzzer);
  }
  
  int tempX = analogRead(joyX);
  int tempY = analogRead(joyY);

  X = map(tempX, 0, 1023, 0 , 180);
  Y = map(tempY, 0, 1023, 0 , 180);
 
  int chance = random(10);
  if (chance<8)
  {
    randomInt = random(45,135);
    X = randomInt; 
    Y = randomInt; 
  }

  servoX.write(X);
  servoY.write(Y);
  delay(500);
}
