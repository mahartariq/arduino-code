#define co2Zero     55     
//#define RLOAD 22.0
#include <MQ135.h>
#include <SPI.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
MQ135 gasSensor = MQ135(A0);
int val;
int sensorPin = A0;
int sensorValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  //display.begin(SSD1306_SWITCHCAPVCC);
  //display.clearDisplay();
  //display.display();
}
void loop() {

  
  int co2now[10];                               //int array for co2 readings
  int co2raw = 0;                               //int for raw value of co2
  int co2ppm = 0;                               //int for calculated ppm
  int zzz = 0;                                  //int for averaging


  for (int x = 0;x<10;x++)  //samplpe co2 10x over 2 seconds
  {                   
    co2now[x]=analogRead(A0);
    delay(200);
  }

  for (int x = 0;x<10;x++)  //add samples together
  {                     
    zzz=zzz + co2now[x];  
  }
  
  co2raw = zzz/10;                            //divide samples by 10
  co2ppm = co2raw - co2Zero;   
  
  
  
  //val = analogRead(A0);
 // Serial.print ("raw = ");
  //Serial.println (val);
 // float zero = gasSensor.getRZero();
 // Serial.print ("rzero: ");
  //Serial.println (zero);
  //float ppm = gasSensor.getPPM();
    Serial.print(co2ppm);
  Serial.println("ppm: ");
  //Serial.println (ppm);
  
  //Serial.println(ppm);
  //display.println(ppm);
  delay(1000);
}
