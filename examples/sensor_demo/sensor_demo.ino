// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
#include <Wire.h>
#include <SPI.h>
#include <StarShipXP.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

#define DHTPIN DHT_IN     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

unsigned int currentValue, previousValue=120, timeBase = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  lcd.begin(16,2);
  dht.begin();
  lcd.print(" Temp  Humidity");
  pinMode(SPI_CS_A,OUTPUT);
  digitalWrite(SPI_CS_A,HIGH);
  
  Tft.begin(SPI_CS_B,GLCD_DC,0,GLCD_RESET);
  Tft.TFTinit();
}

void loop() {
  delay(10);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
  lcd.setCursor(1,1);
  lcd.print(t);
  
  lcd.setCursor(8,1);
  lcd.print(h);
 
  int potValue = analogRead(POT);
  currentValue = 235-(potValue/18); 
  Tft.fillRectangle(timeBase+1, 0, 3, 240, BLACK);
  Tft.drawLine(timeBase, previousValue, timeBase+1, currentValue, WHITE);
  previousValue = currentValue;
  timeBase = timeBase+1;
  
  if(timeBase > 315)
  {
    timeBase = 0;
    Tft.fillRectangle(0, 0, 3, 240, BLACK);
  }
}