//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


#include <Adafruit_NeoPixel.h>


//GPIO PIN 12
#define PIN 4
#define LED_COUNT 66


int cnt = 0;
int r = 0;
int b = 0;
int g = 0;
char bt_serial;
byte bajt;
byte poruka[5];
int br = 0;
int pozicija;
Adafruit_NeoPixel strip(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("GURUITAR_TEST123"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  strip.begin(); // This initializes the NeoPixel library.
  strip.setBrightness(3);
  // put your setup code here, to run once:

}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  while (SerialBT.available() > 0) {
    bajt = SerialBT.read();
    //Serial.println(bajt);
    poruka[br] = bajt;
    br = br + 1;
    //Serial.println(br);
    if (br == 6) {
      br = 0;
      Serial.print( poruka[0]);
      Serial.print( poruka[1]);
      Serial.println( poruka[2]);
      Serial.print( poruka[3]);
      Serial.print( poruka[4]);
      Serial.println( poruka[5]);
      pozicija = poruka[1] + poruka [2]*6;
      if (poruka[0] == 49 && poruka[1] == 0)
      {
        strip.setPixelColor(pozicija, strip.Color(255, 0, 0));
        strip.show();

      }
            if (poruka[0] == 49 && poruka[1] == 1)
      {
        strip.setPixelColor(pozicija, strip.Color(255, 255, 0));
        strip.show();

      }
            if (poruka[0] == 49 && poruka[1] == 2)
      {
        strip.setPixelColor(pozicija, strip.Color(0, 255, 0));
        strip.show();

      }
            if (poruka[0] == 49 && poruka[1] == 3)
      {
        strip.setPixelColor(pozicija, strip.Color(0, 0, 255));
        strip.show();

      }
            if (poruka[0] == 49 && poruka[1] == 4)
      {
        strip.setPixelColor(pozicija, strip.Color(0, 255, 255));
        strip.show();

      }
            if (poruka[0] == 49 && poruka[1] == 5)
      {
        strip.setPixelColor(pozicija, strip.Color(255, 0, 255));
        strip.show();

      }

      if (poruka[0] == 48)
      {
        strip.setPixelColor(pozicija, strip.Color(0, 0, 0));
        strip.show();

      }


      if (poruka[0] == 13 && poruka[1] == 10 && poruka[2] == 10)
      {
        for (int i = 0; i < 6; i++) {
          strip.setPixelColor(i, strip.Color(255, 255, 255));
          strip.show();
          delay(20);
        }

        for (int i = 6; i < 12; i++) {
          strip.setPixelColor(i, strip.Color(255, 0, 0));
          strip.show();
          delay(20);
        }

        for (int i = 12; i < 18; i++) {
          strip.setPixelColor(i, strip.Color(255, 255, 0));
          strip.show();
          delay(20);
        }

        for (int i = 18; i < 24; i++) {
          strip.setPixelColor(i, strip.Color(0, 255, 0));
          strip.show();
          delay(20);
        }

        for (int i = 24; i < 30; i++) {
          strip.setPixelColor(i, strip.Color(0, 0, 255));
          strip.show();
          delay(20);
        }
        for (int i = 30; i < 36; i++) {
          strip.setPixelColor(i, strip.Color(255, 0, 255));
          strip.show();
          delay(20);
        }

        for (int i = 0; i < 36; i++) {
          strip.setPixelColor(i, strip.Color(0, 0, 0));
          strip.show();
          delay(50);
        }

      }
        if (poruka[0] == 10 && poruka[1] == 10 && poruka[2] == 13)
      {


        for (int i = 0; i < 36; i++) {
          strip.setPixelColor(i, strip.Color(0, 0, 0));
          strip.show();
          delay(50);
        }

      }

        if (poruka[0] == 50)
      {

        strip.setPixelColor(pozicija, strip.Color(poruka[3]*2, poruka[4]*2, poruka[5]*2));
        strip.show();

      }








    }

  }

  //SerialBT.write(bt_serial);



  delay(20);
}
