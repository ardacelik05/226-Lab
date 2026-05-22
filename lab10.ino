#include <LiquidCrystal.h>

LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

const int aPin = 22;
const int bPin = 28;
const int cPin = 27;
const int dPin = 26;
const int ePin = 25;
const int fPin = 24;
const int gPin = 23;

const int GND1 = 33;
const int GND2 = 34;
const int GND3 = 35;
const int GND4 = 36;

const int digitPins[4] = {GND1, GND2, GND3, GND4};

int counter = 0;

unsigned long lastCountTime = 0;
unsigned long lastMuxTime = 0;

int currentDigit = 0;

void allDigitsOff() {
 digitalWrite(GND1, LOW);
 digitalWrite(GND2, LOW);
 digitalWrite(GND3, LOW);
 digitalWrite(GND4, LOW);
}

void clearSegments() {
 digitalWrite(aPin, LOW);
 digitalWrite(bPin, LOW);
 digitalWrite(cPin, LOW);
 digitalWrite(dPin, LOW);
 digitalWrite(ePin, LOW);
 digitalWrite(fPin, LOW);
 digitalWrite(gPin, LOW);
}

void showDigit(int n) {

 clearSegments();

 switch (n) {

 case 0:
 digitalWrite(aPin,HIGH);
 digitalWrite(cPin,HIGH);
 digitalWrite(dPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 1:
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 2:
 digitalWrite(aPin,HIGH);
 digitalWrite(bPin,HIGH);
 digitalWrite(dPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 3:
 digitalWrite(aPin,HIGH);
 digitalWrite(bPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 4:
 digitalWrite(bPin,HIGH);
 digitalWrite(cPin,HIGH);
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 5:
 digitalWrite(aPin,HIGH);
 digitalWrite(bPin,HIGH);
 digitalWrite(cPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(fPin,HIGH);
 break;

 case 6:
 digitalWrite(aPin,HIGH);
 digitalWrite(bPin,HIGH);
 digitalWrite(cPin,HIGH);
 digitalWrite(dPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(fPin,HIGH);
 break;

 case 7:
 digitalWrite(aPin,HIGH);
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 8:
 digitalWrite(aPin,HIGH);
 digitalWrite(bPin,HIGH);
 digitalWrite(cPin,HIGH);
 digitalWrite(dPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 case 9:
 digitalWrite(aPin,HIGH);
 digitalWrite(bPin,HIGH);
 digitalWrite(cPin,HIGH);
 digitalWrite(ePin,HIGH);
 digitalWrite(fPin,HIGH);
 digitalWrite(gPin,HIGH);
 break;

 }

}

void refreshDisplay() {

 int digits[4] = {
 counter % 10,
 (counter / 10) % 10,
 (counter / 100) % 10,
 (counter / 1000) % 10
 };

 allDigitsOff();

 showDigit(digits[currentDigit]);

 digitalWrite(digitPins[currentDigit], HIGH);

 currentDigit++;

 if(currentDigit>=4)
 currentDigit=0;

}

void updateLCD(){

 lcd.setCursor(0,0);
 lcd.print("Counter:");

 lcd.setCursor(0,1);

 if(counter<1000) lcd.print("0");
 if(counter<100) lcd.print("0");
 if(counter<10) lcd.print("0");

 lcd.print(counter);
 lcd.print(" ");

}

void setup() {

 pinMode(aPin, OUTPUT);
 pinMode(bPin, OUTPUT);
 pinMode(cPin, OUTPUT);
 pinMode(dPin, OUTPUT);
 pinMode(ePin, OUTPUT);
 pinMode(fPin, OUTPUT);
 pinMode(gPin, OUTPUT);

 pinMode(GND1, OUTPUT);
 pinMode(GND2, OUTPUT);
 pinMode(GND3, OUTPUT);
 pinMode(GND4, OUTPUT);

 lcd.begin(16,2);

 updateLCD();

}

void loop() {

 unsigned long now = millis();

 if(now-lastMuxTime>=3){

 lastMuxTime=now;

 refreshDisplay();

 }

 if(now-lastCountTime>=1000){

 lastCountTime=now;

 counter++;

 if(counter>9999)
 counter=0;

 updateLCD();

 }

}
