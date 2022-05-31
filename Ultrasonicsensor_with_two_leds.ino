#define Trigpin 2
#define Echopin 3
#define low_led 4
#define high_led 5
float distance;
int duration;
int l1 = 700;

void setup() {
  pinMode (Trigpin, OUTPUT);
  pinMode (low_led, OUTPUT);
  pinMode (high_led, OUTPUT);
  pinMode  (Echopin, INPUT);
  Serial.println("Distance Meter");
  digitalWrite (low_led, LOW);
  digitalWrite (high_led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  duration = pulseIn(Echopin, HIGH);
  distance = duration * 0.034 / 2;
  delay (11);
  Serial.println(" ");
  Serial.print ("Distance = ");
  Serial.print (distance);
  Serial.print ("cm");
  Serial.print (" ");

  if (distance>=30)
  {
    Serial.println("Nothing is in front of Sensor");
    digitalWrite (low_led, HIGH);
    delay (500);
    digitalWrite (low_led, LOW);
    delay(500);
    digitalWrite (low_led, HIGH);
  }
 else
 {
   Serial.println("Sensor detects an object");
   digitalWrite (high_led, HIGH);
   delay (100);
   digitalWrite (high_led, LOW);
   delay(100);
   digitalWrite (high_led, HIGH);
   delay(100);
  }
}
