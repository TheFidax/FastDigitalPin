#include <FastDigitalPin.h>

#define PIN_TEST 4

void setup() {
  pinData pinTest;
  unsigned long initTime, endTime;
  
  Serial.begin(115200);
  while(!Serial) {}

  determine_pinData(PIN_TEST, &pinTest);
  
  Serial.println("digitalPinFast test");
  Serial.print("sizeof pinData struct: "); Serial.println(sizeof(pinInput));
  Serial.println();

  pinMode(PIN_TEST, INPUT);

  Serial.println("Arduino digitalRead() function:");
  initTime = micros();
  digitalRead(PIN_TEST);
  endTime = micros();

  Serial.print("initTime : "); Serial.println(initTime);
  Serial.print("endTime : "); Serial.println(endTime);
  Serial.print("Time : "); Serial.println(endTime - initTime);
  Serial.println();
 
  delay(2000);

  Serial.println("digitalReadFast() function:");
  initTime = micros();
  digitalReadFast(pinInput);
  endTime = micros();

  Serial.print("initTime : "); Serial.println(initTime);
  Serial.print("endTime : "); Serial.println(endTime);
  Serial.print("Time : "); Serial.println(endTime - initTime);
  Serial.println();

  delay(2000);

  Serial.println("register function:"); //D4 = PD4 
  initTime = micros();
  uint8_t pinValue = bitRead(PIND, 4);
  endTime = micros();

  Serial.print("initTime : "); Serial.println(initTime);
  Serial.print("endTime : "); Serial.println(endTime);
  Serial.print("Time : "); Serial.println(endTime - initTime);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
