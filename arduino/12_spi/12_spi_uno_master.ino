//SPI-Mater
#include <SPI.h>

void setup() {
  SPI.begin();
  digitalWrite(SS, HIGH);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(SS, LOW);
  int A = SPI.transfer(0);
  delay(5);
  digitalWrite(SS, HIGH);
  Serial.print(A);
  delay(100);
}
