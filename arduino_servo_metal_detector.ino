/*ARDIUNO   METALDETECTOR  SERVO
 * 5V          +vcc        +vcc
 * GND          GND        GND
 * 8             D0
 * 9                      Signal
 */
#include <Servo.h> 
Servo myservo;
int a2=0;
void setup() 
{ pinMode(8,INPUT);
  myservo.attach(9);
  Serial.begin(9600);
} 

void loop() {
  if(Serial.available()>0){
    int a1=Serial.read()+a2;
    a2=a1;
    while(a2>2){
      Serial.println("INSERT COINS");
      int a=digitalRead(8);
      if(a==1){
          Serial.println("PICK UP PADS");
          myservo.write(90);  // set servo to mid-point
          delay(200);
          myservo.write(0);
          a2=a2-1;
        }
      }
     if(a2<=2){
        Serial.println("REFILL");
     }
    }
  }
   
