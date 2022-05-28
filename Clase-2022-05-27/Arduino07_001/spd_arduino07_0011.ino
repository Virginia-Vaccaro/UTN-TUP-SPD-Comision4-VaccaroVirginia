#include <IRremote.h>
int RECV_PIN = 14;
int IRData = 0;
int Led_Pin = 13;
int Led_Status = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    IRData = results.value;
    irrecv.resume();
    Serial.print("Datos: ");
    Serial.print(IRData, HEX);
    Serial.print(" {");
    Serial.print(IRData);
    Serial.println("}");
  
    if (IRData == 12495)
    {
      if (Led_Status == 0)
      {
        digitalWrite(Led_Pin, 1);
        Led_Status = 1;
      }
      else
      {
        digitalWrite(Led_Pin, 0);
        Led_Status = 0;
      }
    }
  }
}