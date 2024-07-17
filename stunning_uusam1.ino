const int trigPin = 2;
const int echoPin = 3;

// Constants for buzzer pin
const int buzzerPin = 4;

// Constants for distance threshold and duration
const int thresholdDistance = 20; // in centimeters
const int alarmDuration = 1000;   // in milliseconds

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Buzzer pin
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigPin before setting it high
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, calculating the duration in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Output distance to serial monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if distance is less than threshold
  if (distance < 30) {
    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(alarmDuration);
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }
}