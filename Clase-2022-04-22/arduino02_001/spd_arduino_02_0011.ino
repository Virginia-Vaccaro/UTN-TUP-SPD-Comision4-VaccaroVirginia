int button = 0;
void setup()
{
 pinMode(2, INPUT);
 pinMode(7, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(3, OUTPUT);
}

void loop()
{
 button = digitalRead(2);
 
 if (button == HIGH)
  {
   digitalWrite(7, LOW);
 
   digitalWrite(12, HIGH);
   digitalWrite(3, HIGH);
 
   delay(500);
 
   digitalWrite(7, HIGH);
 
   digitalWrite(12, LOW);
   digitalWrite(3, LOW);
 
   delay(1000);
  } 
  else 
  {
   digitalWrite(7, LOW);
   digitalWrite(12, LOW);
   digitalWrite(3,LOW);
  }
 }