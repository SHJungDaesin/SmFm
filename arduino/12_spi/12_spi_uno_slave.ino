//SPI-slave
#include <SPI.h>
volatile byte slaveReceived;

void setup() {
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);

  SPCR |=_BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR|=_BV(SPIE);
  
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  Serial.begin(9600);
}

int B = 0;
ISR(SPI_STC_vect){
  slaveReceived = SPDR;
  if (slaveReceived==0) 
    Serial.println("received 0");
  
  SPDR = B; //
}

void loop() {
  B++;
  delay(1000);
}
