//#define DECODE_NEC
#include <IRremote.hpp>

int IR_RECEIVE_PIN = 2; // 적외선 수신기의 DATA 핀 연결

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals of protocols: "));
  //printActiveIRProtocols(&Serial);
}
void loop() {
  if (IrReceiver.decode()) { // 수신 성공
    uint16_t Code = IrReceiver.decodedIRData.decodedRawData >> 16;
    //Serial.print(Code, HEX); // Print "old" raw data
    switch (Code) {
      case (0xBA45) : Serial.println("CH DOWN"); break;
      case (0xB847) : Serial.println("CH UP"); break;
      case (0xB946) : Serial.println("CH"); break;
      case (0xBB44) : Serial.println("PREV"); break;
      case (0xBF40) : Serial.println("NEXT"); break;
      case (0xBC43) : Serial.println("PLAY/PAUSE"); break;
      case (0xF807) : Serial.println("VOL-"); break;
      case (0xEA15) : Serial.println("VOL+"); break;
      case (0xF609) : Serial.println("EQ"); break;
      case (0xE619) : Serial.println("100+"); break;
      case (0xF20D) : Serial.println("200+"); break;
      case (0xE916) : Serial.println("0"); break;
      case (0xF30C) : Serial.println("1"); break;
      case (0xE718) : Serial.println("2"); break;
      case (0xA15E) : Serial.println("3"); break;
      case (0xF708) : Serial.println("4"); break;
      case (0xE31C) : Serial.println("5"); break;
      case (0xA55A) : Serial.println("6"); break;
      case (0xBD42) : Serial.println("7"); break;
      case (0xAD52) : Serial.println("8"); break;
      case (0xB54A) : Serial.println("9"); break;
    }
    IrReceiver.resume(); // 다음 데이터 수신
  }
  delay(500);
}
