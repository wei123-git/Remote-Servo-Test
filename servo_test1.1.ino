#include <Servo.h>
#include <math.h>
#define joyX A0

/*Here begin variable and object declarations*/
Servo myservo; //initialize Servo object called myservo
int xpin = A0; //xpin is set to Analog 0
int ypin = A1; // ypin is set to Analog 1
int hold_button = 2; // hold button (NOT YET IMPLEMENTED)
int xVal; // actual integer value of the x component
int hold; // state of button (NOT YET IMPLEMENTED)

float controller_convert(float input_val){ // Conversion to handle math including checking ranges (tolerance) and possibly numerical scaling.
  if (input_val < 490 || input_val > 500){
    float output = log(exp(1.0*(input_val-495)/1023));
    return output;
  }
  else {
  return 0.0;
  }
}

void setup() 
  
  Serial.begin(9600); //Serial monitor 
  myservo.attach(9); //attach servo to pin 9 (PWM pin)
  pinMode(xpin, INPUT); //set xpin as input analog 0
  pinMode(hold_button, INPUT); // button functionality as an input (NOT YET IMPLEMENTED)
}

void loop() {
  

  xVal =analogRead(xpin); // set xVal as the read from Analog 0
  hold = digitalRead(hold_button); // set status of hold to Digital 2 (NOT YET IMPLEMENTED)


  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Ratio:  ");
  
  Serial.print(controller_convert(xVal));
  float multiplier = controller_convert(xVal); // fetch multiplier value from converted (scaled) xVal

  Serial.print(" | Hold Angle:  ");
  Serial.print(hold);
  Serial.print(" | converted angle:  ");
  int angle = multiplier * 180 + 90; // adjust multiplier, center 90 degrees

  Serial.println(angle);
  myservo.write(angle); // write angle to servo
  

  delay(100);



  
}
