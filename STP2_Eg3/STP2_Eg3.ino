#include "DHT.h"

// Exercise 3: Assign the GPIO pin for the LED

#define DHTTYPE DHT11    // DHT 11
const int DHTPIN = 17;   // GPIO number connected to the DHT11 data pin

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Exercise 3: Add the code to configure the GPIO pin for LED as output

  Serial.begin(115200); // Start serial communication at 115200 baud.
  dht.begin();        // Initialize the DHT11 sensor.
}

void loop() {
  // Delay between measurements.
  delay(2000);        // Wait 2 seconds

  // Reading temperature or humidity
  float humidity = dht.readHumidity();        // Read humidity
  float temperature = dht.readTemperature();  // Read temperature

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Exercise 3:
  // Add the code to check whether the temperature is below 30 deg Celsius
  // Turn on the LED if it is below 30 deg Celsius
  // Otherwise turn off the LED

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C ");
}
