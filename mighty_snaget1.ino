// Pin definitions
int tempPin = A0;  // LM35 output connected to A0
int ledPin = 8;    // LED connected to digital pin 8

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempPin);

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature (LM35: 10mV per °C)
  float tempC = (voltage - 0.5) * 100;  // Celsius

  Serial.print("Temperature: ");
  Serial.print(tempC);   // <-- Use tempC here
  Serial.println(" °C");

  // LED control logic
  if (tempC >= 30.0) {
    digitalWrite(ledPin, HIGH);  // LED ON
  } else {
    digitalWrite(ledPin, LOW);   // LED OFF
  }

  delay(1000);
}
