// DS1302 GND --> GND
#include <ThreeWire.h>  
#include <RtcDS1302.h>
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  Serial.begin(57600);
  Rtc.Begin();
  }
  
void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  Serial.println(now.Second());
  
  if(now.Second()%2=0){
    digitalWrite(10,HIGH);
    delay(100);
    digitalWrite(10,LOW);
  }
  
}
