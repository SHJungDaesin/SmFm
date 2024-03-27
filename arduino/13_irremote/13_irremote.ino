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
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
    IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    
    IrReceiver.resume(); // 다음 데이터 수신
  }
  delay(500);
}
