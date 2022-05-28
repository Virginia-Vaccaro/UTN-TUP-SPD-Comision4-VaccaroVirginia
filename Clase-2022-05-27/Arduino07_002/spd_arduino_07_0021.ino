#include <IRremote.h>
int RECV_PIN = 14;
int IRData = 0;
int Led_Pin1 = 13;
int Led_Pin2 = 7;
int Led_Status1 = 0;
int Led_Status2 = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  irrecv.enableIRIn();
}

void loop() 
{
  if (irrecv.decode(&results))
  {
// Mostrar Lectura
    IRData = results.value;
    irrecv.resume();
    Serial.print("Datos: ");
    Serial.print(IRData, HEX);
    Serial.print(" {");
    Serial.print(IRData);
    Serial.println("}");
// Controlar Led
//prende y apaga el led verde una vez, apretando el boton 1
    if (IRData == 2295)
    {
      if (Led_Status1 == 0)
      {
        
        for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
          digitalWrite(Led_Pin1, fadeValue);
          delay(30);
          }
        for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
          digitalWrite(Led_Pin1, fadeValue);
          delay(30);
          }   
      }
    
       else
       {
         digitalWrite(Led_Pin1, 0);
         Led_Status1 = 0;
       }
     }
//queda prendido el led amarrillo apretando el boton 3, apaga apretando nuevamente ese boton
    if (IRData == 18615)
   {
     if (Led_Status2 == 0)
     {
       digitalWrite(Led_Pin2, 1);
       Led_Status2 = 1;
      }
     else
     {
       digitalWrite(Led_Pin2, 0);
       Led_Status2 = 0;
      }
    }
   }
}