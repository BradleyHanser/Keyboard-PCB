
#include <FastLED.h>
#include <Keyboard.h>

#define NUM_LEDS 144      /* The amount of pixels/leds you have */
#define DATA_PIN 1       /* The pin your data line is connected to */
#define LED_TYPE WS2812B /* I assume you have WS2812B leds, if not just change it to whatever you have */
#define BRIGHTNESS 255   /* Control the brightness of your leds */
#define SATURATION 255   /* Control the saturation of your leds */
#define KEY0 15
#define KEY1 2
#define KEY2 18
#define KEY3 19
#define KEY4 4
#define KEY5 5
#define KEY6 6
#define KEY7 7
#define KEY8 8
#define KEY9 21
#define KEY10 10 
#define KEY11 20
#define LEDKEY 14
#define KEY13 16

const int buttonpin = 14;
int colors[13] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 360};
//int c = 0;
static int p = 1;

CRGB leds[NUM_LEDS];

void setcolor(int hue) {
  Serial.println("Setting colour nig");
  for (int id = 0; id < NUM_LEDS; id++) {
    leds[id] = CHSV(hue, 255, 0);
    FastLED.show();
    Serial.println("Colour loop 1");
    delay(1);
  }
  Serial.println("Exit loop 1");
  for (int id = 0; id < NUM_LEDS; id++) {
    leds[id] = CHSV(hue, 255, 255);
    FastLED.show();
    Serial.println("Colour loop 2");
    delay(1);
  }
  Serial.println("Finished setting colour nig");
}

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  pinMode(LEDKEY, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode (KEY0, INPUT_PULLUP);
  pinMode (KEY1, INPUT_PULLUP);
  pinMode (KEY2, INPUT_PULLUP);
  pinMode (KEY3, INPUT_PULLUP);
  pinMode (KEY4, INPUT_PULLUP);
  pinMode (KEY5, INPUT_PULLUP);
  pinMode (KEY6, INPUT_PULLUP);
  pinMode (KEY7, INPUT_PULLUP);
  pinMode (KEY8, INPUT_PULLUP);
  pinMode (KEY9, INPUT_PULLUP);
  pinMode (KEY10, INPUT_PULLUP);
  pinMode (KEY11, INPUT_PULLUP);
  pinMode (KEY13, INPUT_PULLUP);
  Keyboard.begin();
  setcolor(160);
}

void daddy() { 

  
              //Windows L command//

    if (digitalRead(KEY0) == HIGH) {
    Serial.println("Locking Computer");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.print("l");
    delay(100);
    Keyboard.releaseAll();
    }

            //Windows+x U U U enter command//

  //   if (digitalRead(KEY9) == HIGH) {
   // Serial.println("shutting down");
   // Keyboard.press(KEY_LEFT_GUI);
   // delay(100);
   // Keyboard.print("x");
   // delay(100);
   // Keyboard.releaseAll();
   // delay(100);
   // Keyboard.print("u");
   // delay(50);
   // Keyboard.print("u");
   // delay(50);
   // Keyboard.print("u");
   // delay(100);
   // Keyboard.press(KEY_RETURN);
   // delay(100);
   // Keyboard.releaseAll();
    // }

     //Windows D command//

      if (digitalRead(KEY2) == HIGH) {
    Serial.println("Windows D");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.print("d");
    delay(100);
    Keyboard.releaseAll();
      }


     //type gmail command//

      if (digitalRead(KEY3) == HIGH) {
    Serial.println("Typing gmail");
    Keyboard.print("Bradley.hanser@gmail.com");
    delay(100);
    Keyboard.releaseAll();
    delay(500);
      }

     
   
            //open camera command//
   
   if (digitalRead(KEY13) == HIGH) {
    Serial.println("Opening camera");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.releaseAll();
    delay(150);
    Keyboard.print("camera");
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
   
  }
 
              //open calculator command//
  
  if (digitalRead(KEY10) == HIGH) {
    Serial.println("Opening calculator");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.releaseAll();
    delay(150);
    Keyboard.print("Calculator");
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
    //change the keyname in the parenthese to any from:https://www.arduino.cc/en/Reference/KeyboardModifiers, if you want multiple, duplicate this command//
    delay(100); //this sets a delay so the keybind doesnt spam, and only goes once per 100 milliseconds in this case//
  }
  if (digitalRead(KEY10) == LOW && digitalRead(KEY13) == LOW) {
    Keyboard.releaseAll();
    Serial.println("rel");
  }
  Serial.println("fuck");

  //open chrome command//

if (digitalRead(KEY11) == HIGH) {
    Serial.println("Opening chrome");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.releaseAll();
    delay(150);
    Keyboard.print("Chrome");
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
}

//open spotify command//

if (digitalRead(KEY9)== HIGH) {
    Serial.println("Opening spotify");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.releaseAll();
    delay(150);
    Keyboard.print("Spotify");
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
}


//LED's off button//

if (digitalRead(KEY4)== HIGH) {
    Serial.println("Turning off LED's");
     FastLED.clear();  // clear all pixel data
  FastLED.show();
    delay(10);
}

//Enter pin command//

if (digitalRead(KEY5)== HIGH) {
    Serial.println("Entering pin");
    Keyboard.press("b");
    delay(500);
    Keyboard.print("****");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(500);    
}

//open cura command//

if (digitalRead(KEY6)== HIGH) {
    Serial.println("Opening Cura");
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.releaseAll();
    delay(150);
    Keyboard.print("ultimaker cura");
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(100);
}

if (digitalRead(KEY7)== HIGH) {
    Serial.println("Entering password");
    Keyboard.print("**********");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(500);
}

}

void loop() {

            //Change LED colour command//
  
  if (digitalRead(LEDKEY) == HIGH) {
    p++;
    Serial.print("P is now ");
    Serial.println(p);
    if (p == 1) {
      setcolor(160);
    } else if (p == 2) {
      setcolor(0);
    } else if (p == 3) {
      setcolor(128);
    } else if (p == 4) {
      setcolor(224);
    } else if (p == 5) {
      setcolor(96);
    } else if (p == 6) {
      Serial.println("Rolling over");
      p = 1;
      setcolor(160);
    }

   
  }
  Serial.println("loop");
  daddy();
}
