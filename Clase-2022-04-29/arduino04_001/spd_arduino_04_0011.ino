int led1 = 9;
int led2 = 5;
int Foto = A1;
int sensorValue = 0;
int outputValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode (led2, OUTPUT);
 }

void loop()
{
  digitalWrite(led1, 1);
 sensorValue = analogRead(Foto);
 outputValue = map(sensorValue, 0, 1023, 0, 255);
 analogWrite(led1, outputValue);
 Serial.print("Lectura: ");
 Serial.println(sensorValue);
 Serial.print("Mapeado: ");
 Serial.println(outputValue);
 delay(150);
 digitalWrite(led1, 0);
 delay(150);
  digitalWrite(led2, 1);
 sensorValue = analogRead(Foto);
 outputValue = map(sensorValue, 0, 1023, 0, 255);
 analogWrite(led2, outputValue);
 Serial.print("Lectura: ");
 Serial.println(sensorValue);
 Serial.print("Mapeado: ");
 Serial.println(outputValue);
 delay(150);
 digitalWrite(led2, 0);
 delay(150);
}

