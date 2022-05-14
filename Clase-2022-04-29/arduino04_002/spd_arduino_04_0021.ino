int Led_Pin1 = 8;
int Led_Pin2 = 5; 
int Fot_Pin = A1;
int Int_Pin = 2;
int sensorValue = 0;
int inputValue = 0;
int counter = 0;

// Limites Invierno
int start1 = 18;
int stop1 = 24;
// Limites Verano
int start2 = 21;
int stop2 = 2;

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
    digitalWrite(Led_Pin2, 1);
    digitalWrite(Led_Pin1, 0);
  }
  else
  {
    if(counter >= start1)
    {
      sensorValue = analogRead(Fot_Pin);
      if(sensorValue < 500)
      {
        Serial.println("Led: Encendido");
        digitalWrite(Led_Pin1, 1);
        digitalWrite(Led_Pin2, 0);
        
      } else {
        Serial.println("Led: Apagado");
        digitalWrite(Led_Pin1, 0);
        digitalWrite(Led_Pin2, 0);
      }
    }
    else
    {
      Serial.println("Led: Apagado");
      digitalWrite(Led_Pin1, 0);
      digitalWrite(Led_Pin2, 0);
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
}