int Led_Pin1 = 13;
int Led_Pin2 = 9;
int Led_Pin3 = 3;
int Pot_Pin = A0;
int Int_Pin = 2;
int sensorValue = 0;
int inputValue = 0;

void setup()
{
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  pinMode(Led_Pin3, OUTPUT);
  pinMode(Int_Pin, INPUT);
}

void loop()
{
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH)
  {
    digitalWrite(Led_Pin1, 1);
    digitalWrite(Led_Pin3, 1);
    digitalWrite(Led_Pin2, 0);
    delay(1000);
     digitalWrite(Led_Pin1, 0);
     digitalWrite(Led_Pin3, 0);
     digitalWrite(Led_Pin2, 1);
    delay(500);
  }
  else
  {
     sensorValue = analogRead(Pot_Pin);
     if(sensorValue< 800)
     {
        digitalWrite(Led_Pin1, 1);
        digitalWrite(Led_Pin3, 1);
        digitalWrite(Led_Pin2, 0);
      }
     else 
     {
       digitalWrite(Led_Pin1, 0);
       digitalWrite(Led_Pin3, 0);
       digitalWrite(Led_Pin2, 0);
      }
   }
}
 