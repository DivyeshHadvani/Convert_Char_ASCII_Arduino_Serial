#include <SoftwareSerial.h>

String incoming;   // for incoming serial data

#define txPin 1

SoftwareSerial LCD = SoftwareSerial(0, txPin);

const int LCDdelay = 10;

void lcdPosition(int row, int col) {

  LCD.write((col + row * 64 + 128));  //position
  delay(LCDdelay);
}
void clearLCD() {
  LCD.write(0xFE);   //command flag
  LCD.write(0x01);   //clear command.
  delay(LCDdelay);
}

void setup()
{
  pinMode(txPin, OUTPUT);
  //LCD.begin(9600);
  Serial.begin(9600);

}

void loop()
{
    if (Serial.available() > 0) 
    {
            // read the incoming byte:
            incoming = Serial.read();
            String mysrr = String(incoming);
            // say what you got:
            LCD.write(128);
            //Serial.print("I received: ");
            Serial.println(mysrr);
            //LCD.print(mysrr);
    }
  
}
