# Gesture-Sensor-Control-Using-Arduino
This DF robot Gravity sensor integrates the gesture controls with touch switches. Now we have more combinations to control the ON/OFF switch
Get more info: https://www.hackster.io/electroboy001/gesture-sensor-control-using-arduino-52e719

This sensor module integrates gesture recognition and touch detecting functions in one piece, and provides an adjustable detection range within 0~30cm. When connected to your microcontroller, it can detect 5-way touch signal and 7 kinds of gestures: move left, move right, move forward, move backward, pull up, pull down, pull and remove.

![mini_IMG_9263](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/b4fdbcba-2c1d-40c5-9710-d5751ace8ec3)

Besides, the sensor is also equipped with the function of auto-sleep and wake up. The module comes with the gesture recognition algorithm and provides simple and reliable data output. Use the sensor to directly communicate with upper computer or micro-controllers like Arduino and Raspberry Pi via serial port. 

![14269f4b51ea30ff14325a0d02b8155c](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/b099e4b4-c77c-4af0-87bc-e0067ffec83f)

It works on the principle of infrared detection, the hand motion is monitored using an infrared led and sensing system. The infrared light strikes with hand and go to the sensing unit for proper interpretation. Infrared (IR) light is comes in invisible spectra and the sensor used in this mechanism is very selective because IR is also  present in the sunlight that's why sensor is less effective in outdoors. Sponsored by JLCPCB: https://jlcpcb.com/?from=SSA

Application of gesture and touch:

The onboard 5-way touch pad on the sensor can be directly used to detect touch, or you can extend the touch pad with wires to make it perfectly fit in your application. The outer shield for the sensor retains the advantages of Gravity series as well as makes the sensor more durable. This sensor can be used to make smart lamp, DIY intelligent car, or used in interactive projects requiring gesture recognition.

![c3407ee9cb1739929206ac96db627463](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/211f7b42-f6b8-4ea5-b23e-1f680c1041bd)

Features:

Power Supply: 3.3V - 6V (recommend 5V）

Output Voltage: 0 - 3.3V

Operating Current: about 56.3mA

Sleep Mode Current: about 40uA

Output: TTL serial port

Serial Protocol Format: 9600 band rate; 8 data bits, no parity bit, 1 stop bit

Note:
Abnormality might occur when using the module in strong sunlight condition due to its working principle.
When powered down, the sensor will be initialized automatically and the previous setting will be invalid.

![mini_IMG_9269](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/039620f7-ef80-4329-a09b-7ac9d064025b)

When sending byte continuously, there should be at least 200us time interval between the end of the last byte and the starting of the next byte; The sensor can receive/transmit data only in working state, while for processing data, we must make the sensor stay in non-working state. That is to say, if there is an object over the sensor when receiving/transmitting data, we need to move it away for completing the following settings.

Normal Settings and functions:

Default function when powered on: no sleep, 5-way touch, detecting height: 15cm.
The default detecting height is 15cm, higher height detection needs to be set by yourself.
Keep a normal speed when gesticulating to let the sensor better understand your gesture.

![mini_IMG_9262](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/2cc53517-de75-48be-88ea-8bdf526f92bd)

Code functions:

1) Set the sensing height (default 20cm when powered on)
Example: DFGT.setGestureDistance(20);---Unit(cm) Max height: 30cm
2) Set the sleep enablement or enter auto-sleep mode (sleep mode disabled when powered on)
Example: DFGT.setSleep(4);---unit(s)
3) Set gesture sensing enablement (all the seven gestures can be recognized when powered on)

Example(1) DFGT.enableFunction(DFGT_FUN_ALL);---enable all gestures sensing fuction

Example(2) DFGT.disableFunction(DFGT_FUN_RIGHT | DFGT_FUN_LEFT);---disable sensing function of part gestures

Example(3) DFGT.enableFunction(DFGT_FUN_RIGHT | DFGT_FUN_LEFT);---enable sensing function of part gestures

Components Required:

![mini_IMG_9270](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/ad219b21-42c4-48c8-b275-98cc53dcc45d)

Gravity Gesture sensor

Led 5mm red

220ohms resistor

ARDUINO NANO

Breadboard

Custom PCB design from JLCPCB
https://jlcpcb.com/?from=SSA

Circuit diagram:

![Circuit diagram](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/eb9ec808-90be-4d3a-b2b4-e111ef774dd6)

The 4 red LEDs are connected to the digital pins of the Arduino NANO. The gravity sensor is connected to the digital pin 10 and 11. Rx of the sensor is connected to the Tx pin and Tx of sensor to Rx which is defined in the software serial of the Arduino. Different tasks are assigned to the LEDs based on the actions and functions defined in the Arduino program. The connections are very simple, to power up the circuit an external power supply of 5v @1amp can be used.

<img width="893" alt="ice_screenshot_20230221-050102" src="https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/123e6c83-a75e-4240-afea-ae9d60f11d77">

You can design the PCB whenever doing any project with this kind of sensor and I always suggest to use JLCPCB PCB manufacturing services, they provide the best services in good prices. You can try 5pcs of 2-layer PCB in just $2 and SMT assembly is starting just from $8.

Simple testing code:

![gestures 1](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/36821e1a-7af4-48b4-8a59-d90269f91aae)

Here the readings of sensor also got printed on the serial monitor through serial port of Arduino (UART) and the gravity sensor also support UART interface. That’s why in the Arduino code software serial is used RX pin is named as D10, Tx as D11. Gravity sensor has a different library which can be downloaded from here and can be directly included in the Arduino IDE in ZIP format.

Functions used:

![Touch video](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/93960309-d370-4d00-8bde-bb0024a577f9)

I initialize all the functions, so that all movements and touch actions can be triggered. For this in the Arduino sketch I made an external function to toggle the Red LEDs connected to the Digital I/O pins. You can download all the schematics and code directly from here.

PCB designs:

![PCB](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/e88ca69e-0713-4990-98c4-d6059c6d0849)

I designed a shield to the simple project which I think is a good way to do these. In the shield Arduino Nano is used which is soldered on board and the connections can be made through male headers near it. To display any data it has onboard 128x64 OLED, for digital output it has a buzzer and led. It has optimised power section just supply it with barrel jack from 9-12volts. Order the PCB directly uploading the GERBER files to JLCPCB, Sign-up to JLCPCB using this link and get free PCB coupons of worth $54 for your next order. This link is only applicable to new users.
https://jlcpcb.com/?from=SSA

Testing:

![mini_IMG_9261](https://github.com/electroboy001/Gesture-Sensor-Control-Using-Arduino/assets/97245507/c55f5775-3a12-455e-a02b-49923cdb65ba)

I tested this sensor with 20cm height, no sleep mode and all the functions are active the sensor works perfectly fine in room light, I am not much sure about daylight but when I tried the left right function identification in not too much proper.

The best response I got when in sunlight the pull up, pull down, pull and remove functions are used the response is good because in these 3 cases sensor is covered with hand. The touch response is very good and quicker than any other touch sensor.

The touch wires can be extended and external copper pad can be designed for any applications. I made this simple code to only toggle LEDs via controlling digital outputs of Arduino, you can write your own functions to do something else, now it's up to you how you play. Make sure to give a try to the JLCPCB SMT assembly and PCB services in very good prices.
