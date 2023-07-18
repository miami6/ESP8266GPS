#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, -1);

static const int RXPin = D4;
static const int TXPin = D3;
static const uint32_t GPSBaud = 9600;

const double Home_LAT = 12.34567;
const double Home_LNG = 98.76543;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("GPS example");
  display.println(TinyGPSPlus::libraryVersion());
  display.display();
  delay(1500);
  ss.begin(GPSBaud);
}

void loop()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Latitude  : ");
  display.println(gps.location.lat(), 5);
  display.print("Longitude : ");
  display.println(gps.location.lng(), 5);
  display.print("Satellites: ");
  display.println(gps.satellites.value());
  display.print("Elevation : ");
  display.print(gps.altitude.feet());
  display.println("ft");
  display.print("Time UTC  : ");
  display.print(gps.time.hour());
  display.print(":");
  display.print(gps.time.minute());
  display.print(":");
  display.println(gps.time.second());
  display.print("Heading   : ");
  display.println(gps.course.deg());
  display.print("Speed     : ");
  display.println(gps.speed.mph());

  unsigned long Distance_To_Home = (unsigned long)TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), Home_LAT, Home_LNG);
  display.print("KM to Home: ");
  display.print(Distance_To_Home);
  display.display();
  delay(200);

  smartDelay(500);

  if (millis() > 5000 && gps.charsProcessed() < 10)
    display.println(F("No GPS data received: check wiring"));

  display.display();
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}
