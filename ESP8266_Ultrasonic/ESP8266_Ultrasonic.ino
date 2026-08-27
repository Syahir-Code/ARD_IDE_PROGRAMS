// HC-SR04 + ESP8266 Distance Measurement

const int trigPin = D3;   
const int echoPin = D6;   // (via voltage divider!)

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("HC-SR04 Distance Sensor Starting...");
}

void loop() {
  long duration;
  float distanceCm;

  // Ensure trigger is low before pulsing
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond HIGH pulse to trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin, returns the sound wave travel time in microseconds
  // Timeout after 30ms (~5m range) to avoid blocking forever if no echo
  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    Serial.println("No echo received (out of range or wiring issue)");
  } else {
    // Speed of sound = 343 m/s = 0.0343 cm/microsecond
    // Divide by 2 because duration is there-and-back travel time
    distanceCm = (duration * 0.0343) / 2;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  delay(500); // measure twice a second
}
