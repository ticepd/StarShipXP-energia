#include <SPI.h>
#include <StarShipXP.h>

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  GLCD_Set();
  GLCD();
}


void loop(void) {

}


void GLCD_Set()
{
  pinMode(SPI_CS_A,OUTPUT);
  digitalWrite(SPI_CS_A,HIGH);

}

void GLCD()
{
    Tft.begin(SPI_CS_B,GLCD_DC,0,GLCD_RESET);                // CS,DC,BL,RESET pin
    Tft.TFTinit();                                 // init TFT library
    Tft.backlight_on();                            // turn on the background light
    
    Tft.drawString("Hello",0,10,3,CYAN,BLACK);       // draw string: "hello", (0, 180), size: 3, color: CYAN
    Tft.drawString("World!!",60,60,4,WHITE,BLACK);    // draw string: "world!!", (80, 230), size: 4, color: WHITE
}
