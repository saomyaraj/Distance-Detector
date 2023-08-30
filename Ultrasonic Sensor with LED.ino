const int trigPin = 2;
const int echoPin = 3;
const int ledPins[] = {8, 9, 10, 11};
const int numLeds = sizeof(ledPins); 

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;

  for (int i = 0; i < numLeds; i++) {
    if (distance >= (i + 1) * 5) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100);
}