int Led_Pin1 = 13;
int Led_Pin2 = 7;
int Pot_Pin = A0;
int Int_Pin = 2;
int sensorValue = 0;
int outputValue = 0;
int inputValue = 0;

void setup()
{
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  pinMode(Int_Pin, INPUT);
  Test_Led();
}

void loop()
{
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH)
  {
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      analogWrite(Led_Pin1, fadeValue);
      delay(30);
     }
    for (int Value2 = 255 ; Value2 >= 0; Value2 -= 5) {
      analogWrite(Led_Pin2, Value2);
      delay(30);
     }
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      analogWrite(Led_Pin1, fadeValue);
      delay(30);
     }
    for (int Value2 = 0 ; Value2 <= 255; Value2 += 5) {
      analogWrite(Led_Pin2, Value2);
      delay(30);
     }
   }
  else
  {
    sensorValue = analogRead(Pot_Pin);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(Led_Pin1, outputValue);
    outputValue = map(sensorValue, 0, 1023, 255, 0);
    analogWrite(Led_Pin2, outputValue);
   }
}

void Test_Led()
{
  digitalWrite(Led_Pin1, HIGH);
  delay(1000);
  digitalWrite(Led_Pin1, LOW);
  delay(1000);
  digitalWrite(Led_Pin2, HIGH);
  delay(1000);
  digitalWrite(Led_Pin2, LOW);
  delay(1000);
  digitalWrite(Led_Pin1, HIGH);
  delay(1000);
  digitalWrite(Led_Pin1, LOW);
}