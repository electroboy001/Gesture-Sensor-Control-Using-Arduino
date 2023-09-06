// Modified by Sagar saini

#include "DFRobot_Gesture_Touch.h"

#ifdef __AVR__
  SoftwareSerial    mySerial(/*RX*/10, /*TX*/11); 
#elif defined ESP_PLATFORM
// ESP32:IO16 <--> TX:sensor
// ESP32:IO17 <--> RX:sensor
HardwareSerial mySerial(1);
#endif

// init sensor object, request write and read function
DFRobot_Gesture_Touch   DFGT(&mySerial); 

int led_1 = 2;
int led_2 = 3;
int led_3 = 4;
int led_4 = 5;
int led_5 = 6;

void setup()
{
  Serial.begin(115200);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);

  // suggest default value
  DFGT.setGestureDistance(20);

  // enable all functions
  DFGT.enableFunction(DFGT_FUN_ALL);

  // disable function test
  //DFGT.disableFunction(DFGT_FUN_RIGHT | DFGT_FUN_LEFT);

  // enable function test
  // DFGT.enableFunction(DFGT_FUN_RIGHT | DFGT_FUN_LEFT);

  // set auto sleep time out, in sleep mode, something approach will wake it up
  // DFGT.setSleep(4);

  Serial.println("simple Gesture!");
}

void loop()
{
  // get an event that data saved in serial buffer
  int8_t rslt = DFGT.getAnEvent();  

  if(rslt != DF_ERR) 
  {
    // disable auto sleep
    // DFGT.setSleep(DFGT_SLEEP_DISABLE);
    switch(rslt) 
    {
      case DFGT_EVT_BACK: 
        Serial.println("get event back");
        digitalWrite(led_1, HIGH);
        break;
      case DFGT_EVT_FORWARD: 
        Serial.println("get event forward");
        digitalWrite(led_1, LOW);
        break;
      case DFGT_EVT_RIGHT: 
        Serial.println("get event right");
        digitalWrite(led_2, HIGH);
        break;
      case DFGT_EVT_LEFT: 
        Serial.println("get event left");
        digitalWrite(led_2, LOW);
        break;
      case DFGT_EVT_PULLUP: 
        Serial.println("get event pull up");
        all_on();
        break;
      case DFGT_EVT_PULLDOWN: 
        Serial.println("get event pull down");
        all_off();
        break;
      case DFGT_EVT_PULLREMOVE: 
        Serial.println("get event pull and remove");
        all_off();
        break;
      case DFGT_EVT_TOUCH1: 
        Serial.println("get event touch1");
        digitalWrite(led_1, HIGH);
        break;
      case DFGT_EVT_TOUCH2: 
        Serial.println("get event touch2");
        digitalWrite(led_2, HIGH);
        break;
      case DFGT_EVT_TOUCH3:  
        Serial.println("get event touch3");
        digitalWrite(led_3, HIGH);
        break;
      case DFGT_EVT_TOUCH4: 
        Serial.println("get event touch4");
        digitalWrite(led_4, HIGH);
        break;
      case DFGT_EVT_TOUCH5: 
        Serial.println("get event touch5");
        digitalWrite(led_5, HIGH);
        break;
    }
  }
}

void all_on(){
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  delay(100);
}

void all_off(){
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  delay(100);  
}
