#include <DHT.h> // DHT sensor library

#define DHTTYPE DHT11 // DHT sensor model: DHT11
#define DHTPIN 2 // DHT sensor pin number

// DHT sensor variable declaration
DHT dht(DHTPIN, DHTTYPE); 

// Define LED pins for temperature
#define BLUE_TEMP_LED_PIN 9
#define YELLOW_TEMP_LED_PIN 10
#define RED_TEMP_LED_PIN 11

// Define LED pins for humidity
#define BLUE_HUM_LED_PIN 3
#define GREEN_HUM_LED_PIN 4
#define RED_HUM_LED_PIN 5

void setup() {
  Serial.begin(9600); // Initialize serial communication

  dht.begin(); // Initialize DHT sensor library

  // Set all LED pins as output
  pinMode(BLUE_TEMP_LED_PIN, OUTPUT);
  pinMode(YELLOW_TEMP_LED_PIN, OUTPUT);
  pinMode(RED_TEMP_LED_PIN, OUTPUT);
  pinMode(BLUE_HUM_LED_PIN, OUTPUT);
  pinMode(GREEN_HUM_LED_PIN, OUTPUT);
  pinMode(RED_HUM_LED_PIN, OUTPUT);
}

void loop() {
  // Wait for 2 seconds
  delay(2000);

  // Read humidity and temperature values from DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Print the error message if reading error occurs
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // If not, print humidity and temperature values
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C"));


  // Control LEDs based on temperature
  if (temperature < 20) {
    digitalWrite(BLUE_TEMP_LED_PIN, HIGH);
    digitalWrite(YELLOW_TEMP_LED_PIN, LOW);
    digitalWrite(RED_TEMP_LED_PIN, LOW);
    
  } else if (temperature >= 20 && temperature < 26) {
    digitalWrite(BLUE_TEMP_LED_PIN, LOW);
    digitalWrite(YELLOW_TEMP_LED_PIN, HIGH);
    digitalWrite(RED_TEMP_LED_PIN, LOW);

  } else if (temperature > 25) {
    digitalWrite(BLUE_TEMP_LED_PIN, LOW);
    digitalWrite(YELLOW_TEMP_LED_PIN, LOW);
    digitalWrite(RED_TEMP_LED_PIN, HIGH);
  }

  // Control LEDs based on humidity
  if (humidity < 60) {
    digitalWrite(BLUE_HUM_LED_PIN, HIGH);
    digitalWrite(GREEN_HUM_LED_PIN, LOW);
    digitalWrite(RED_HUM_LED_PIN, LOW);

  } else if (humidity >= 60 && humidity < 81) {
    digitalWrite(BLUE_HUM_LED_PIN, LOW);
    digitalWrite(GREEN_HUM_LED_PIN, HIGH);
    digitalWrite(RED_HUM_LED_PIN, LOW);

  } else if (humidity > 80) {
    digitalWrite(BLUE_HUM_LED_PIN, LOW);
    digitalWrite(GREEN_HUM_LED_PIN, LOW);
    digitalWrite(RED_HUM_LED_PIN, HIGH);
  }
}
