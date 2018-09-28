// Include the required EEPROM library
#include <EEPROM.h>
int count = 0; // Counter variable
int address = 9; // Address were we store the data in the EEPROM
int buttonPin = 12;
void setup(){
// Read the last stored value of the button
count = EEPROM.read(address);
pinMode(buttonPin, INPUT_PULLUP);
Serial.begin(9600);
// Print the initial value in the EEPROM
Serial.print("Initial value: ");
Serial.println(count);
}
void loop(){
// When button press is detected
if (digitalRead(buttonPin) == LOW){
count++; // increment counter
// Write the count variable to the specified address.
EEPROM.write(address, count % 256);
Serial.println(count);
delay(500); // Some debouncing delay.
}
}
