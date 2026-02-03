#include &lt;Wire.h&gt;
#include &lt;LiquidCrystal_I2C.h&gt;
// Define LCD (I2C address, columns, rows)
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 is the typical I2C address
// Pin for the LM35 Temperature Sensor
const int sensorPin = A0;
// Constants for the LM35 sensor conversion
const float voltageRef = 5.0; // Reference voltage (5V on Arduino Nano)
const int adcMaxValue = 1023; // 10-bit ADC range (0-1023)
const float lm35ConversionFactor = 100.0; // 10mV per degree Celsius
void setup() {
// Initialize serial communication
Serial.begin(9600);
// Initialize the LCD
lcd.begin(16, 2);
lcd.print(&quot;Temperature:&quot;);
delay(1000); // Wait for the LCD to initialize
// Clear the LCD
lcd.clear();
}
void loop() {
// Read the analog value from the LM35 sensor
int sensorValue = analogRead(sensorPin);
// Convert the analog value to voltage
float voltage = (sensorValue / float(adcMaxValue)) * voltageRef;
// Convert the voltage to temperature (in Celsius)
float temperatureC = voltage * lm35ConversionFactor;
// Print the temperature value to the Serial Monitor
Serial.print(&quot;Temperature: &quot;);
Serial.print(temperatureC);
Serial.println(&quot; C&quot;);
// Display the temperature on the LCD
lcd.setCursor(0, 0); // Set the cursor to the first row, first column
lcd.print(&quot;Temperature:&quot;);
lcd.setCursor(0, 1); // Set the cursor to the second row, first column
lcd.print(temperatureC);
lcd.print(&quot; C&quot;);

// Wait for a short period before the next reading
delay(1000); // Update the temperature every second
}