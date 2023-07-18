ESP8266 with GPS module and SSD1306 Display 



# ESP8266GPS
## ESP8266GPS
Step One: The ingredients

1. You'll need an ESP8266 - e12 wifi module

2. An OLED display ($5- $10 from Ebay)

3. A Ublox 6m GPS receiver or similiar model

## Wiring 
1. First place the ESP8266 on a breadboard

2. Connect a jumper wire from the Ground and Output VCC of the ESP to the power and ground rails of the breadboard.

3. Connect the Ground and VCC of the GPS and the Oled Display to the power rails of the breadboard. Make sure Ground is to (Ground -) and VCC is to the (Red +)

4. Connect the SCL Pin of the Oled display to the ESP D1 pin (the Yellow wire in the picture), and connect the SDA Pin of the Oled display to D2 pin (the Blue wire in the picture) These are your I2C communication connections.

5. Connect the TX pin of the GPS to the D6 pin of the ESP (the Blue wire), and connect the RX pin of the GPS to the D7 pin of the ESP (the white wire) These are your Serial communication pins. You could choose just about any data pins you like, but you will also have to make the necessary changes in the code.

6. If not, install the latest version of the Arduino IDE and the libraries first.

I also assume you have installed all the necessary drivers for your computer to recognize the ESP8266, if not Adafruit has an excellent tutorial here. Adafruit ESP8266 Tutorial This is crucial if this is your first time using the ESP8266

Next, go to github and download the code and run it in the Arduino IDE.

Enter your latitude and longitude into the area of code "Home_LAT =" and "Home_LNG=" below

Compile it and upload to your NodeMcu esp-12e, In the Arduino IDE be sure to select your correct board (ESP-12E Module in my case) and the Memory size - 4M(3M SPIFFS)

Go for a walk or drive and watch your GPS position update, remember to keep your eyes on the road.
