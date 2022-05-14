int Led_Pin1 = 3;
int Led_Pin2 = 12;
int Buz_Pin = 6;
int Int_Pin = 2;
int inputValue = 0;

void setup()
{
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Buz_Pin, OUTPUT);
  pinMode(Int_Pin, INPUT);
  delay(250);
  digitalWrite(Led_Pin1, 1);
  tone(Buz_Pin, 900, 250);
  delay(500);
  digitalWrite(Led_Pin1, 0);
  tone(Buz_Pin, 900, 250);
  delay(500);
  digitalWrite(Led_Pin1, 1);
  tone(Buz_Pin, 900, 250);
  delay(800);
  digitalWrite(Led_Pin1, 0);
}

void loop()
{
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH)
  {
    for (int x=1; x<=3; x += 1){
      tone(Buz_Pin, 493, 1014);
      digitalWrite(Led_Pin2, 0);
      delay(1000);
      tone(Buz_Pin, 392, 1275);
      digitalWrite(Led_Pin2, 1);
      delay(1000);
    }
  }
  else
  {
    noTone(Buz_Pin);
  }
  delay(1000);
  digitalWrite(Led_Pin2, 1);
  digitalWrite(Led_Pin1, 0);
}