// Variables de Luz
int Led_Pin1 = 8;
int Led_Pin2 = 5;
int Fot_Pin = A1;
int Int_Pin = 2;
int sensorValue = 0;
int inputValue = 0;
// Variables de Temperatura
int readValue = 0;
int lastValue = 1;
int tempPin = A0;
float voltsValue;
float tempValue;
int counter = 0;
int start = 0;
int stop = 0;
int sensorPin = 0;
// Limites Invierno
int start1 = 18;
int stop1 = 24;
// Limites Verano
int start2 = 20;
int stop2 = 1;


void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  pinMode(Int_Pin, INPUT);
}


void loop()
{
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH)
  {
    Serial.println("Led: Encendido");
    digitalWrite(Led_Pin1, 1);
  }
  else
  {
    readValue = analogRead(sensorPin);
    lastValue = readValue;
    voltsValue = 5.0 / 1024 * readValue;
    tempValue = voltsValue * 100 - 50;
    if( tempValue < 20 ){
      start = start1;
      stop = stop1;
    }
    else
    {
      start = start2;
      stop = stop2;
     } 

    if(counter >= start)
    {
      sensorValue = analogRead(Fot_Pin);
      if(sensorValue < 500)
      {
        Serial.println("Led: Encendido");
        digitalWrite(Led_Pin2, 1);
      } else {
         Serial.println("Led: Apagado");
         digitalWrite(Led_Pin2, 0);
        }
      }
      else
      {
       Serial.println("Led: Apagado");
       digitalWrite(Led_Pin2, 0);
       digitalWrite(Led_Pin1, 0);
      }
    }
  counter++;
  Serial.print("Hora: ");
  Serial.println(counter);
  if (counter == 24)
  {
   counter =0;
  }
 delay(1000);
  //temperatura
  readValue = analogRead(sensorPin);
  if (lastValue != readValue) {
    Serial.print("readValue: ");
    Serial.print(readValue);
    lastValue = readValue;
    voltsValue = 5.0 / 1024 * readValue;
    Serial.print(" -> voltsValue: ");
    Serial.print(voltsValue);
    tempValue = voltsValue * 100 - 50;
    Serial.print(" -> tempValue: ");
    Serial.println(tempValue);
   }
  delay(100);
}