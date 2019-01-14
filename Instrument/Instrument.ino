#include <SR04.h>

//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int val;

void setup() {
   Serial.begin(9600);
   delay(60);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   val = map(a, 4, 100, 250, 550); //value to map, from, to, max, min
   tone(8, val, 100);
   delay(100);
}
