int lectura = 0;
int distancia = 0;
int led_pin = 10;

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando");
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  lectura = readUltrasonicDistance(7, 7);
  distancia = 0.01723 * lectura;
  Serial.print(distancia);
  Serial.println("cm");
  delay(100);
  if(distancia<130){
    digitalWrite(led_pin, 1);
  }
  else{
    digitalWrite(led_pin, 0);
  }
}


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}