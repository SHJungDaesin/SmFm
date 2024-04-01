#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init(); 
  SPI.beginTransaction(SPISettings(MFRC522_SPICLOCK, MSBFIRST, SPI_MODE0));
  digitalWrite(SS_PIN, LOW);
  SPI.transfer(0x80 |  (0x37<<1)); // VersionReg
  byte value = SPI.transfer(0);
  digitalWrite(SS_PIN, HIGH);
  SPI.endTransaction();

  Serial.print(F("Firmware Version: 0x"));
  Serial.print(value, HEX);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void mfrc_writeRegister(uint8_t reg, byte value){
  SPI.beginTransaction(SPISettings(MFRC522_SPICLOCK, MSBFIRST, SPI_MODE0));
  digitalWrite(SS_PIN, LOW);
  SPI.transfer(reg);
  SPI.transfer(value);
  digitalWrite(SS_PIN, HIGH);
  SPI.endTransaction();
}

void mfrc_init(void){
  mfrc_writeRegister(0x12 << 1, 0x00); // TxModeReg
  mfrc_writeRegister(0x13 << 1, 0x00); // RxModeReg
  
  mfrc_writeRegister(0x24 << 1, 0x26); // ModWidthReg
  mfrc_writeRegister(0x2A << 1, 0x80); // TModeReg
  mfrc_writeRegister(0x2B << 1, 0xA9); // TPrescalerReg
  mfrc_writeRegister(0x2C << 1, 0x03); // TReloadRegH
  mfrc_writeRegister(0x2D << 1, 0xE8); // TReloadRegL
  mfrc_writeRegister(0x15 << 1, 0x40); // TxASKReg
  mfrc_writeRegister(0x16 << 1, 0x3D); // ModeReg
  mfrc522.PCD_AntennaOn();
}



