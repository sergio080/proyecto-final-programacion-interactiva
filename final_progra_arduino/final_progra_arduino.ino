
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
int potenciometro = A0;
float lectura;


long duracion;
int distancia;
int sDistancia;
int freqMin = 100;
int freqMax = 1000;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(potenciometro,INPUT);
Serial.begin(9600); 
}


void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duracion = pulseIn(echoPin, HIGH);


distancia= duracion*0.034/2;

sDistancia = distancia;
if (sDistancia <= 15){
  digitalWrite(buzzer, HIGH);
  lectura = analogRead(potenciometro);
float frecuencia = map (lectura,0,1023,freqMin,freqMax);
tone(buzzer,frecuencia,300);

}
else{
  digitalWrite(buzzer, LOW);
  
}

}
