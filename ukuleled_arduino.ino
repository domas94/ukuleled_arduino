// This example code is in the Public Domain (or CC0 licensed, at your option.)
// By Evandro Copercini - 2018
//
// This example creates a bridge between Serial and Classical Bluetooth (SPP)
// and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"
#include <Adafruit_NeoPixel.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#define GPIO_PIN 12
#define LED_COUNT 66

int r = 0;
int b = 0;
int g = 0;
char bt_serial;
byte data;
byte message[5];
int cnt = 0;
int pos;
Adafruit_NeoPixel strip(LED_COUNT, GPIO_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("UKULELED"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  strip.begin(); // This initializes the NeoPixel library.
  strip.setBrightness(3);
  lightshow();
}

void loop()
{
  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  while (SerialBT.available() > 0)
  {
    data = SerialBT.read();
    message[cnt] = data;
    cnt = cnt + 1;
    // Serial.println(cnt);
    if (cnt == 6)
    {
      cnt = 0;
      Serial.print(message[0]);
      Serial.print(message[1]);
      Serial.println(message[2]);
      Serial.print(message[3]);
      Serial.print(message[4]);
      Serial.println(message[5]);
      pos = message[1] + message[2] * 4;
      if (message[0] == 49 && message[1] == 0)
      {
        strip.setPixelColor(pos, strip.Color(255, 0, 0));
        strip.show();
      }
      if (message[0] == 49 && message[1] == 1)
      {
        strip.setPixelColor(pos, strip.Color(255, 255, 0));
        strip.show();
      }
      if (message[0] == 49 && message[1] == 2)
      {
        strip.setPixelColor(pos, strip.Color(0, 255, 0));
        strip.show();
      }
      if (message[0] == 49 && message[1] == 3)
      {
        strip.setPixelColor(pos, strip.Color(0, 0, 255));
        strip.show();
      }

      if (message[0] == 51 && message[1] == 0)
      {
        strip.setPixelColor(0, strip.Color(255, 0, 0));
        strip.setPixelColor(4, strip.Color(255, 0, 0));
        strip.setPixelColor(8, strip.Color(255, 0, 0));
        strip.setPixelColor(12, strip.Color(255, 0, 0));
        strip.setPixelColor(16, strip.Color(255, 0, 0));
        strip.setPixelColor(20, strip.Color(255, 0, 0));
        strip.setPixelColor(24, strip.Color(255, 0, 0));
        strip.setPixelColor(28, strip.Color(255, 0, 0));
        strip.setPixelColor(32, strip.Color(255, 0, 0));
        strip.show();
      }
      if (message[0] == 51 && message[1] == 1)
      {
        strip.setPixelColor(1, strip.Color(255, 255, 0));
        strip.setPixelColor(5, strip.Color(255, 255, 0));
        strip.setPixelColor(9, strip.Color(255, 255, 0));
        strip.setPixelColor(13, strip.Color(255, 255, 0));
        strip.setPixelColor(17, strip.Color(255, 255, 0));
        strip.setPixelColor(21, strip.Color(255, 255, 0));
        strip.setPixelColor(25, strip.Color(255, 255, 0));
        strip.setPixelColor(29, strip.Color(255, 255, 0));
        strip.setPixelColor(33, strip.Color(255, 255, 0));
        strip.show();
      }
      if (message[0] == 51 && message[1] == 2)
      {
        strip.setPixelColor(2, strip.Color(0, 255, 0));
        strip.setPixelColor(6, strip.Color(0, 255, 0));
        strip.setPixelColor(10, strip.Color(0, 255, 0));
        strip.setPixelColor(14, strip.Color(0, 255, 0));
        strip.setPixelColor(18, strip.Color(0, 255, 0));
        strip.setPixelColor(22, strip.Color(0, 255, 0));
        strip.setPixelColor(26, strip.Color(0, 255, 0));
        strip.setPixelColor(30, strip.Color(0, 255, 0));
        strip.setPixelColor(34, strip.Color(0, 255, 0));
        strip.show();
      }
      if (message[0] == 51 && message[1] == 3)
      {
        strip.setPixelColor(3, strip.Color(0, 0, 255));
        strip.setPixelColor(7, strip.Color(0, 0, 255));
        strip.setPixelColor(11, strip.Color(0, 0, 255));
        strip.setPixelColor(15, strip.Color(0, 0, 255));
        strip.setPixelColor(19, strip.Color(0, 0, 255));
        strip.setPixelColor(23, strip.Color(0, 0, 255));
        strip.setPixelColor(27, strip.Color(0, 0, 255));
        strip.setPixelColor(31, strip.Color(0, 0, 255));
        strip.setPixelColor(35, strip.Color(0, 0, 255));
        strip.show();
      }

      if (message[0] == 48)
      {
        strip.setPixelColor(pos, strip.Color(0, 0, 0));
        strip.show();
        delay(75);
      }

      if (message[0] == 52 && message[1] == 0)
      {
        strip.setPixelColor(0, strip.Color(0, 0, 0));
        strip.setPixelColor(4, strip.Color(0, 0, 0));
        strip.setPixelColor(8, strip.Color(0, 0, 0));
        strip.setPixelColor(12, strip.Color(0, 0, 0));
        strip.setPixelColor(16, strip.Color(0, 0, 0));
        strip.setPixelColor(20, strip.Color(0, 0, 0));
        strip.setPixelColor(24, strip.Color(0, 0, 0));
        strip.setPixelColor(28, strip.Color(0, 0, 0));
        strip.setPixelColor(32, strip.Color(0, 0, 0));
        strip.show();
        delay(75);
      }
      if (message[0] == 52 && message[1] == 1)
      {
        strip.setPixelColor(1, strip.Color(0, 0, 0));
        strip.setPixelColor(5, strip.Color(0, 0, 0));
        strip.setPixelColor(9, strip.Color(0, 0, 0));
        strip.setPixelColor(13, strip.Color(0, 0, 0));
        strip.setPixelColor(17, strip.Color(0, 0, 0));
        strip.setPixelColor(21, strip.Color(0, 0, 0));
        strip.setPixelColor(25, strip.Color(0, 0, 0));
        strip.setPixelColor(29, strip.Color(0, 0, 0));
        strip.setPixelColor(33, strip.Color(0, 0, 0));
        strip.show();
        delay(75);
      }

      if (message[0] == 52 && message[1] == 2)
      {
        strip.setPixelColor(2, strip.Color(0, 0, 0));
        strip.setPixelColor(6, strip.Color(0, 0, 0));
        strip.setPixelColor(10, strip.Color(0, 0, 0));
        strip.setPixelColor(14, strip.Color(0, 0, 0));
        strip.setPixelColor(18, strip.Color(0, 0, 0));
        strip.setPixelColor(22, strip.Color(0, 0, 0));
        strip.setPixelColor(26, strip.Color(0, 0, 0));
        strip.setPixelColor(30, strip.Color(0, 0, 0));
        strip.setPixelColor(34, strip.Color(0, 0, 0));
        strip.show();
        delay(75);
      }

      if (message[0] == 52 && message[1] == 3)
      {
        strip.setPixelColor(3, strip.Color(0, 0, 0));
        strip.setPixelColor(7, strip.Color(0, 0, 0));
        strip.setPixelColor(11, strip.Color(0, 0, 0));
        strip.setPixelColor(15, strip.Color(0, 0, 0));
        strip.setPixelColor(19, strip.Color(0, 0, 0));
        strip.setPixelColor(23, strip.Color(0, 0, 0));
        strip.setPixelColor(27, strip.Color(0, 0, 0));
        strip.setPixelColor(31, strip.Color(0, 0, 0));
        strip.setPixelColor(35, strip.Color(0, 0, 0));
        strip.show();
        delay(75);
      }

      if (message[0] == 13 && message[1] == 10 && message[2] == 10)
      {
        lightshow();
      }

      if (message[0] == 10 && message[1] == 10 && message[2] == 13)
      {
        turn_off_all_leds();
      }

      if (message[0] == 50)
      {

        strip.setPixelColor(pos, strip.Color(message[3] * 2, message[4] * 2, message[5] * 2));
        strip.show();
      }
    }
  }

  // SerialBT.write(bt_serial);
  delay(20);
}

void lightshow()
{
  for (int i = 0; i < 4; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
    strip.show();
    delay(20);
  }

  for (int i = 4; i < 12; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.show();
    delay(20);
  }

  for (int i = 12; i < 20; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 255, 0));
    strip.show();
    delay(20);
  }

  for (int i = 20; i < 28; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
    delay(20);
  }

  for (int i = 28; i < 32; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 255));
    strip.show();
    delay(20);
  }
  for (int i = 32; i < 36; i++)
  {
    strip.setPixelColor(i, strip.Color(255, 0, 255));
    strip.show();
    delay(20);
  }

  turn_off_all_leds();
}

void turn_off_all_leds()
{
  for (int i = 0; i < 36; i++)
  {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    delay(50);
  }
}
