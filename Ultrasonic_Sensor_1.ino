#define trigRx 9 // To Covered Transmitter
#define trigTx 10 // To Actual Transmitter 
#define echoRx 11 // To Actual Receiver

long duration=0;
float distance=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigRx,OUTPUT);
  pinMode(trigTx,OUTPUT);
  pinMode(echoRx,INPUT);
  
  Serial.begin(9600);

  digitalWrite(trigTx,LOW);
  digitalWrite(trigRx,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnTxOn();
  duration = pulseIn(echoRx,HIGH);
  distance = duration * 0.034;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(2);
}

void turnTxOn(){
  digitalWrite(trigTx,HIGH);
  digitalWrite(trigRx,HIGH);
  
  delayMicroseconds(10);

  digitalWrite(trigTx,LOW);
  digitalWrite(trigRx,LOW);
}
