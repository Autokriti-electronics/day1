int LED = 13; // Declare the built-in LED
int sensorPin = A2; // Declare the analog port we connected
void setup(){
// Start the Serial connection
Serial.begin(9600);
// Set the built in LED pin as OUTPUT
pinMode(LED, OUTPUT);
}
void loop(){
// Read the value of the sensor
int val = analogRead(sensorPin);
// Print it to the Serial
Serial.println(val);
// Blink the LED with a delay of a forth of the sensor value
digitalWrite(LED, HIGH);
delay(val/4);
digitalWrite(LED, LOW);
delay(val/4);
}
