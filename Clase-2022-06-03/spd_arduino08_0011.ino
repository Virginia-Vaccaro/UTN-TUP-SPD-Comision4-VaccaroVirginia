// Liberia para LCD
#include <LiquidCrystal.h>
// Configuramos LCD (Pines Entre Arduino y LCD)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int contador = 0;
int Int_Pin = 7;
int inputValue = 0;


void setup() {
  // Inicializamos LCD
  lcd.begin(16, 2);
  pinMode(Int_Pin, INPUT);
  for(int i=16;i>=1;i--)             
 {
 lcd.setCursor(i, 0);
 lcd.print(" Bienvenido :)  ");
 delay(400);
 }
  delay(1000);
 for(int i=16;i>=0;i--)                
 {
 lcd.clear();
 lcd.setCursor(i, 1);
 lcd.print("Iniciando conteo");
 delay(400);
 }
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Segundos:");
  }

void loop() {
  inputValue = digitalRead(Int_Pin);
if(inputValue == HIGH)
{
  lcd.setCursor(7, 1);
  lcd.print(contador);
  contador++;
  delay(1000);
} else 
{
  lcd.noCursor();
  }
}