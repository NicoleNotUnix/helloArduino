/**************
 * 8/30
 * @author Moni Ali && Nicole Maguire
 * 
 * First code to blink LED and spin servo based on state information
 *
 */
#include <Servo.h>
int val = 0;
int servoVal=0;
int count = 0;
int switchState = 0;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
   myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = 0;
  //where down returns 1, up returns 0
  val = digitalRead(11);

  //checking to see if the state has changed
  if (val != (switchState % 2))
  {
    if (val == 0)
    {
      turnOn();
    } else {
      turnOff();
    }
    switchState = switchState + 1;
  }
  
  Serial.println(servoVal);
}

void turnOff()
{
  digitalWrite(13, 0);
}

void turnOn()
{
  if (count % 3 == 0)
  {
    myservo.write(80);
  } else if (count % 3 == 1) {
    for(int i = 0; i < 10; i++)
    {
      digitalWrite(13, i % 2);
      delay(100);
    }
    digitalWrite(13, 1);
  } else {
    myservo.write(180);
    digitalWrite(13, 1);
  }
  count = count + 1;
}

