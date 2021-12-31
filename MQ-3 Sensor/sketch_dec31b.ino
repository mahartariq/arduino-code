#define MQ3pin 0

float sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ3 warming up!");
  delay(20000); // allow the MQ3 to warm up
}

void loop() {
  sensorValue = analogRead(MQ3pin); // read analog input pin 0

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  delay(2000); // wait 2s for next reading
}
