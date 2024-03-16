//this code donest use delay(),millis(),micros() 
// Pin definitions
const int lm35Pin = A0;  // LM35 temperature sensor connected to analog pin A0
const int ledPin = 13;    // Onboard LED connected to digital pin 13

// Variables
int temperature;          // Temperature reading from LM35 sensor

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read temperature from LM35 sensor
  temperature = analogRead(lm35Pin);
  
  // Convert analog reading to Celsius temperature
  float celsius = (temperature * 0.48828125); // (5V / 1024) = 0.0048828125
  
  // Print temperature to serial monitor
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" degrees Celsius");
  
  // Check temperature conditions and control LED blinking
  if (celsius < 30) {
    // Blink LED every 250 milliseconds
    digitalWrite(ledPin, HIGH);
    
    for(long int i=0;i<44767;i++){
      Serial.print("");//delay of 250 millisecond approx
    }
    digitalWrite(ledPin, LOW);
    for(long int i=0;i<44767;i++){
      Serial.print("");//delay of 250 millisecond approx
    }
  } else if (celsius > 30) {
    // Blink LED every 500 milliseconds
    digitalWrite(ledPin, HIGH);
    for(long int i=0;i<44767*2;i++){
      Serial.print("");//delay of 500 millisecond approx
    }
    digitalWrite(ledPin, LOW);
    for(long int i=0;i<44767*2;i++){
      Serial.print("");//delay of 500 millisecond approx
    }
  }
}


// for(long int i=0;i<44767;i++){   /// this for loop is used for creating the delay
    //   Serial.print("");
    // }
