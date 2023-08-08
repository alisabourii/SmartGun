#include <Servo.h>

Servo srv;

int width = 640, height = 480;  
int xpos = 180;

int trig = 3;
int echo= 4;
int led = 5;

void setup() {
  Serial.begin(9600);
  srv.attach(2);
  for(int i=0; i<=180; i++){
    srv.write(i);
    delay(10);
  }
  srv.write(90);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();
    }
 
  int xo = map(x_mid, 280,360, 0,180);
  srv.write(xo);
  distance_controller();
  
  }
}

void distance_controller(){
  digitalWrite(trig,1); delay(1);digitalWrite(trig, 0);
  int time = pulseIn(echo,1);
  int dis = (time/2)/28.97;
 
  if(dis <= 15){
    digitalWrite(led, 1);
  }
  else{
    digitalWrite(led, 0);
  }
}
