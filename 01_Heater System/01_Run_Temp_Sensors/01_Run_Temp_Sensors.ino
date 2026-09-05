#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define NUM_SENSORS 4

float temperatures[NUM_SENSORS];
float averageTemperature = 0.0;

void setup() {
  Serial.begin(9600);

  sensors.begin();

  Serial.println("=================================");
  Serial.println("  4x DS18B20 Temperature System");
  Serial.println("=================================");

  Serial.print("Number of sensors detected: ");
  Serial.println(sensors.getDeviceCount());

  Serial.println();
}

void loop() {

  // Request temperature from all sensors
  sensors.requestTemperatures();

  float sum = 0.0;
  int validSensors = 0;

  // Read the 4 sensors
  for (int i = 0; i < NUM_SENSORS; i++) {

    temperatures[i] = sensors.getTempCByIndex(i);

    // Check for valid reading
    if (temperatures[i] != DEVICE_DISCONNECTED_C) {
      sum += temperatures[i];
      validSensors++;
    }
  }

  // Calculate average
  if (validSensors > 0) {
    averageTemperature = sum / validSensors;
  } 
  else {
    averageTemperature = 0.0;
  }

  // Print individual temperatures
  Serial.println("---------------------------------");

  for (int i = 0; i < NUM_SENSORS; i++) {

    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");

    if (temperatures[i] == DEVICE_DISCONNECTED_C) {
      Serial.println("ERROR");
    } 
    else {
      Serial.print(temperatures[i], 2);
      Serial.println(" °C");
    }
  }

  // Print average
  Serial.print("Average Temperature: ");
  Serial.print(averageTemperature, 2);
  Serial.println(" °C");

  Serial.println("---------------------------------");

  delay(500);
}