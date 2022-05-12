int Led_Pin1 = 13;
int Led_Pin2 = 9;
int Pot_Pin = A0;
int sensorValue = 0;
int outputValue = 0;

void setup()
{
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  Test_Led();
}

void loop()
{
  sensorValue = analogRead(Pot_Pin);
  outputValue = map(sensorValue, 0, 1023, 0, 254);
  analogWrite(Led_Pin1, outputValue);
  analogWrite(Led_Pin2, outputValue);
}

void Test_Led()
{
  digitalWrite(Led_Pin1, HIGH);
  digitalWrite(Led_Pin2, HIGH);
  delay(1000);
  digitalWrite(Led_Pin1, LOW);
  digitalWrite(Led_Pin2, HIGH);
  delay(500);
  digitalWrite(Led_Pin1, HIGH);
  digitalWrite(Led_Pin2, LOW);
  delay(500);
  digitalWrite(Led_Pin1, LOW);
  digitalWrite(Led_Pin2, HIGH);
  delay(500);
  digitalWrite(Led_Pin1, HIGH);
  digitalWrite(Led_Pin2, LOW);
  delay(500);
  digitalWrite(Led_Pin1, HIGH);
  digitalWrite(Led_Pin2, HIGH);
  delay(1000);
}