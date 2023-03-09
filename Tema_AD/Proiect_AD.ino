const int trigPin = 2;
const int echoPin = 3;

long duration, metres, sensorState = 0;
boolean sensoryOn = false;
unsigned long timeSensor = 0, startTime = 0;
volatile float seconds = 0.00;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  sensorState = digitalRead(echoPin);

  if (duration != 0) {
    int metres = (duration/2) / 29.1 / 100;
    
    if (startTime == 0) {
      startTime = millis();
    }

    timeSensor = millis() - startTime;
    seconds = timeSensor / 1000;

    if (seconds >= 60 && metres < 2) {
      Serial.print("d");
      delay(20000);
    } else {
      Serial.print("n");
      delay(20000);
    }
  } else {
    startTime = 0;
  }
}
