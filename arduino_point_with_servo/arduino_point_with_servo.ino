#include <Servo.h>

const int hPin = 8;
const int vPin = 9;
void clean();

Servo horizontal;
Servo vertical;

void setup() {
  horizontal.attach(hPin);
  vertical.attach(vPin);

  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 1)
  {
    
    horizontal.write(static_cast<int>(Serial.read()));
    vertical.write(static_cast<int>(Serial.read()));

    clean();
  }


  delay(100);



}

void clean()
{
  while (Serial.available() > 0)
  {
    Serial.read();
  }
}
