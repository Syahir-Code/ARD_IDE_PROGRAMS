/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6Do0-kcys"
#define BLYNK_TEMPLATE_NAME "DUMB FARMING"
#define BLYNK_AUTH_TOKEN "cXMIB4DpBlSzoqa37FYB3WXF-gJGdlcJ"

#include <WiFi.h> // Wi-Fi library for the ESP32
#include <WiFiClient.h> // Wi-Fi client library for network connections

#include <BlynkSimpleEsp32.h> // Blynk library specific to ESP32
#include <string.h> // Library for using string functions
#include <DHT.h> // DHT sensor library


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial // Enable debug printing to serial monitor

// DHT sensor configuration
#define DHTPIN 17 // Pin where the DHT sensor is connected
#define DHTTYPE DHT11 // Type of DHT sensor
DHT dht(DHTPIN, DHTTYPE); // Create a DHT sensor object
#define SOIL_PIN 34 // GPIO pin connected to the soil moisture sensor

#define INTERVAL 3000            // Interval at which to send sensor data (milliseconds)
unsigned long previousMillis = 0; // Stores last time sensor data was sent

char auth[] = BLYNK_AUTH_TOKEN;  // Blynk authorization token

/* Fill-in the WiFi SSID and password */
char ssid[] = "vivo Y77 5G";                // WiFi SSID
char pass[] = "sy4h1r919";                // WiFi password

void setup()
{
  Serial.begin(115200);          // Initialize serial communication at 115200bps
  dht.begin();                   // Initialize the DHT sensor
  Blynk.begin(auth, ssid, pass); // Connect to Blynk
}

void loop()
{
  Blynk.run();                   // Run Blynk process
  unsigned long currentMillis = millis(); // Get the current time
  // Check if it is time to read and send sensor data
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;       // Update the last sent time
    float temp = dht.readTemperature();      // Read temperature from DHT sensor
    float hum = dht.readHumidity();         // Read humidity from DHT sensor

    // Check if DHT readings were successful
    if (isnan(hum) || isnan(temp)) {
      Serial.println("Failed to read from DHT sensor!\n");
    } else {
      Blynk.virtualWrite(V0, temp);          // Send temperature to Blynk
      Blynk.virtualWrite(V1, hum);          // Send humidity to Blynk
      BLYNK_PRINT.printf("Humidity: %.2f, Temperature: %.2f, ", hum, temp);
    }

    int moisture = analogRead(SOIL_PIN);  // Read soil moisture level
    Blynk.virtualWrite(V2, moisture);     // Send soil moisture to Blynk
    BLYNK_PRINT.printf("Soil moisture level: %d\n", moisture);
    }
}
