#include <IRremote.h>
int RECV_PIN = A0;
int IRData = 0;
int Led_Pin = 12;
int Led_Status = 0;
int buzzerPin = 2;
int buzzer_Status = 0;
bool test_mode = true;
const int a = 440;
const int aS = 455;
const int e = 329;
const int f = 349;
const int gH = 784;
const int aH = 880;
const int eH = 659;


IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin, OUTPUT);
  irrecv.enableIRIn();
  pinMode(buzzerPin, OUTPUT);
}


void loop()
{
  if (irrecv.decode(&results))
  {
  // Mostrar Lectura
    IRData = results.value;
    irrecv.resume();
// Ver Valores
    if (test_mode == true)
    {
      Serial.print("Datos: ");
      Serial.print(IRData, HEX);
      Serial.print(" {");
      Serial.print(IRData);
      Serial.println("}");
    }
    switch (IRData)
    {
      case 2295:
      if (Led_Status == 0)
      {
        Serial.println("Led Encendido");
        digitalWrite(Led_Pin, 1);
        Led_Status = 1;
      }
      else
      {
        Serial.println("Led Apagado");
        digitalWrite(Led_Pin, 0);
        Led_Status = 0;
       }
      break;
      case -30601:
      if (buzzer_Status == 0)
      {
        Serial.println("Buzzer Encendido");
        digitalWrite(buzzerPin, 1);
        buzzer_Status = 1;
        playSection();
      }
      else
      {
        Serial.println("Buzzer Apagado");
        digitalWrite(buzzerPin, 0);
        buzzer_Status = 0;
      }
      break;
      case 18615:
        Serial.println("Boton3");
      break;
      case 10455:
        Serial.println("Boton4");
      break;
      case -22441:
        Serial.println("Boton5");
      break;
      case 26775:
        Serial.println("Boton6");
      break;
      default:
      Serial.println("Boton No Permitido"); 
    }
  }
}


void beep(int note, int duration)
{
  tone(buzzerPin, note, duration);
  delay(50);
}


void playSection()
{
  beep (a, 150);
  beep (a, 150);
  beep (aS, 300);
  beep (a, 150);
  beep (a, 150);
  beep (aS, 300);
  beep (e, 400);
  beep (f, 200);
  beep (gH, 150);
  beep (eH, 300);
  beep (aH, 200);
  delay (1000);
}  