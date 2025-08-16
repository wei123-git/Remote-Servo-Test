#include <Servo.h>

#include <math.h>
Servo myservo;


#define joyX A0

int xpin = A0;
int ypin = A1;
int hold_button = 2;


int xVal;
int hold;

float controller_convert(float input_val){
  if (input_val < 490 || input_val > 500){
    float output = log(exp(1.0*(input_val-495)/1023));
    return output;
  }
  else {
  return 0.0;
  }


  

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9); //attach servo to pin 9 (PWM pin)
  pinMode(xpin, INPUT);
  pinMode(hold_button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  xVal =analogRead(xpin);
  hold = digitalRead(hold_button);
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Ratio:  ");
  
  Serial.print(controller_convert(xVal));
  float multiplier = controller_convert(xVal);

  Serial.print(" | Hold Angle:  ");
  Serial.print(hold);
  Serial.print(" | converted angle:  ");
  int angle = multiplier * 180 + 90;

  Serial.println(angle);
  myservo.write(angle);
  

  delay(100);



  
}
