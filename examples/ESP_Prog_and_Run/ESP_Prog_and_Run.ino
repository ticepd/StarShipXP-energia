#include <SPI.h>
#include <StarShipXP.h>

void setup() {
  // initialize both serial ports:
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(BT_KEY, OUTPUT);

  pinMode(KEYPAD_OUT1, OUTPUT);
  pinMode(KEYPAD_OUT2, OUTPUT);
  pinMode(KEYPAD_OUT3, OUTPUT);
  pinMode(KEYPAD_OUT4, OUTPUT);

  digitalWrite(KEYPAD_OUT1, HIGH);
  digitalWrite(KEYPAD_OUT2, HIGH);
  digitalWrite(KEYPAD_OUT3, HIGH);
  digitalWrite(KEYPAD_OUT4, HIGH);
    
  pinMode(KEYPAD_IN4, INPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  // read from port 1, send to port 0:
  digitalWrite(LED_R, digitalRead(KEYPAD_IN4));
  digitalWrite(LED_G, !digitalRead(KEYPAD_IN4));
  digitalWrite(BT_KEY, digitalRead(KEYPAD_IN4));
  
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte); 
  }
  if (Serial.available()) {
    int outByte = Serial.read();
    Serial1.write(outByte); 
  }

}