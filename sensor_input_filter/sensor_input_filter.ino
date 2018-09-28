int sensorPin = A0; // Declare the used sensor pin
// Function that reads a sensor with specified number of samples
// Returns the mean filtered value
int readMean(int pin, int samples){
// Variable to store the sum of readings
int sum = 0;
// Read the samples and add them all
for (int i = 0; i < samples; i++){
sum = sum + analogRead(pin);
}
// Divide the sum by the number of samples
sum = sum/samples;
// Return the sum
return sum;
}
// Function that reads a sensor with specified number of samples
// Returns the median filtered value
int readMedian (int pin, int samples){
// Variable to store the readings
int raw[samples];
// Read the samples each as a value in the vector
for (int i = 0; i < samples; i++){
raw[i] = analogRead(pin);
}
// Sort the values
// Lazy bubble sort
int temp = 0; // temp value
for (int i = 0; i < samples; i++){
for (int j = i; j < samples - 1; j++){
// Check if values out of order
if (raw[j] > raw[j + 1]){
// If so, swap them
temp = raw[j];
raw[j] = raw[j + 1];
raw[j + 1] = temp;
}
}
}
// Return the middle value
return raw[samples/2];
}

void setup(){
// Start the Serial connection
Serial.begin(9600);
}
void loop(){
// Print the normal value and then a space
Serial.print(analogRead(sensorPin));
Serial.print(" ");
// Print the mean filtered value and then a space
Serial.print(readMean(sensorPin, 15));
Serial.print(" ");
// Print the median filtered value
Serial.println(readMedian(sensorPin, 15));
// Short delay for the Serial
delay(100);
}
