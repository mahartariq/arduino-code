int sensor=7;
int gas_value;
void setup()
{

pinMode(sensor,INPUT);
Serial.begin(9600);

}

void loop()
{

gas_value=digitalRead(sensor);
Serial.println(gas_value);
delay(2000);
}
