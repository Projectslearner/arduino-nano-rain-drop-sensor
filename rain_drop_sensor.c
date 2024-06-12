/*
    Project name : Rain drop sensor
    Modified Date: 11-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-rain-drop-sensor
*/

const int rainSensorPin = A0; // Analog pin connected to the rain drop sensor
int sensorValue = 0;

void setup() {
  pinMode(rainSensorPin, INPUT); // Set the pin as input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  sensorValue = analogRead(rainSensorPin); // Read the analog value from the sensor
  
  Serial.print("Rain Sensor Value: ");
  Serial.println(sensorValue); // Print the value to the Serial Monitor

  // Check if rain is detected and print the result
  if (isRaining(sensorValue)) {
    Serial.println("Rain Detected");
  } else {
    Serial.println("No Rain Detected");
  }

  delay(1000); // Add a small delay to avoid spamming the Serial Monitor
}

// Function to check if rain is detected
bool isRaining(int value) {
  const int threshold = 500; // Define the threshold value for rain detection
  return value < threshold; // Rain is detected if the sensor value is below the threshold
}
