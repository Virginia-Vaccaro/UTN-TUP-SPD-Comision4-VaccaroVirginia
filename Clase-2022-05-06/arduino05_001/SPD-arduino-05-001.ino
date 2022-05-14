const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
const int buzzerPin = 8;
const int ledPin = 5;
int counter = 0;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  firstSection();
  delay (650);
  secondSection();
  delay(650);
 }

void beep(int note, int duration)
{
  tone(buzzerPin, note, duration);
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
  } 
  noTone(buzzerPin);
  delay(50);
  counter++;
 }

void firstSection()
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

void secondSection()
{
beep(c, 500);
beep(gH, 200);
beep(gSH, 150);
beep(gH, 200);
beep(gSH, 150);
beep(d, 500);
beep(cH, 150);
beep(cSH, 200); 
beep(cH, 150);
beep(cSH, 200);
beep(fH, 300);
beep(fSH, 300); 
beep(aH, 150); 
beep(aH, 150);  
delay(1000);
}
