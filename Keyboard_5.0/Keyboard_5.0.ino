//Use 3.5 for merge if this doesnt work!!!!

#include <pitches.h>
#include <Keypad.h>
#define speakerPin 12
int button1Pin;
bool on;
bool button1Pressed;
int dash;
int dot;
int gap;
char A;
char B;
char C;
char D;
char a;
char b;
char c;
char d;
char e;
char f;
char g;
char h;
char i;
char j;
char star;
char hash;
char next[25];
bool input;
unsigned long oldtime;
unsigned long fintime;
bool nextstop;


int melody[] = {
  NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_G5,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5
};

int eight = 400;

int duration[] = {1 * eight, 1 * eight, 1 * eight, 1 * eight, 1 * eight, 1 * eight, 2 * eight}; // 500 miliseconds




//www.elegoo.com
//2016.12.9

/* @file CustomKeypad.pde
  || @version 1.0
  || @author Alexander Brevig
  || @contact alexanderbrevig@gmail.com
  ||
  || @description
  || | Demonstrates changing the keypad size and key values.
  || #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 25; i++) {
    next[i] = 'N';
    //Serial.println(next[i]);
  }
  pinMode(speakerPin, OUTPUT);
  button1Pin = 11;
  on = false;
  button1Pressed = false;
  A = 'A';
  B = 'B';
  C = 'C';
  D = 'D';
  a = '1';
  b  = '2';
  c  = '3';
  d  = '4';
  e  = '5';
  f  = '6';
  g  = '7';
  h  = '8';
  i  = '9';
  j  = '0';
  star = '*';
  hash = '#';
  pinMode(button1Pin, INPUT_PULLUP); //in built resistor
  //pinMode(button1Pin, INPUT); //physical resistor
  dash = 900;
  dot = 300;
  gap = 500;
  input = false;

}

void arrange() {
  for (int a = 0; a <24; a++) {
    next[a] = next[a + 1];
    //Serial.println(next[a]);
  }
  
  next[24] = 'N';
}

void add() {
  nextstop = false;
  char customKey2 = customKeypad.getKey();
  //Serial.println(customKey2);
  if (customKey2) {
    for (i = 0; i < 25; i++) {

      if (next[i] == 'N' && nextstop == false) {
        next[i] = customKey2;
        nextstop = true;
      }
    }

  }

}

void gapm() {
  oldtime = millis();
  fintime = oldtime + 500;
  while (oldtime <= fintime) {
    oldtime = millis();
    add();
    forcestopcheck();
    //Serial.println(oldtime);
  }
}
void dotm() {
  oldtime = millis();
  fintime = oldtime + 300;
  while (oldtime <= fintime) {
    oldtime = millis();
    add();
    forcestopcheck();
    //Serial.println(oldtime);
  }
}
void dashm() {
  oldtime = millis();
  fintime = oldtime + 900;
  while (oldtime <= fintime) {
    oldtime = millis();
    add();
    forcestopcheck();
    
    //Serial.println(oldtime);
  }
}

void forcestop(){
   //need to find a way to quit out of if statement, rn it just finishes the letter and then stops
  for (int i = 0; i < 25; i++) {
    next[i] = 'N';
    //Serial.println(next[i]);
    
  }
}
void forcestopcheck(){
   for (int i = 0; i < 25; i++) {
    if (next[i] == 'D') {
        forcestop();
      }
    //Serial.println(next[i]);
  }
   
}




void loop() {
  //keypad/buzzer
  if (digitalRead(button1Pin) == HIGH) {
    //Serial.println("HIGH");
    button1Pressed = false;

  }
  else if (digitalRead(button1Pin) == LOW && button1Pressed == false) {
    //Serial.println("LOW");
    button1Pressed = true;
    if (on == true) {
      on = false;
      Serial.println("false");
    }
    else if (on == false) {
      on = true;
      Serial.println("true");
    }
  }

 
  if (on == true) { //if you press a button, this will run
    
    // put your main code here, to run repeatedly:


    if (next[0] != 'N') {
      //Serial.println(next[0]);
    //Serial.println(next[1]);
      if (next[0] == A) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        arrange();

      }

      if (next[0] == B) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      } if (next[0] == C) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      }
      if (next[0] == a) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        arrange();


      } if (next[0] == b) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        arrange();


      } if (next[0] == c) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        arrange();


      } if (next[0] == d) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        arrange();


      } if (next[0] == e) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      } if (next[0] == f) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      } if (next[0] == g) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      } if (next[0] == h) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      } if (next[0] == i) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();


      } if (next[0] == j) {
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        arrange();


      }
      if (next[0] == star) {
        for (int thisNote = 0; thisNote < 42; thisNote++) {
          // pin8 output the voice, every scale is 0.5 sencond
          tone(12, melody[thisNote], duration[thisNote % 7]);

          // Output the voice after several minutes
          //starts next line right away- 500 for tone being played, 500 nothing


          arrange();
          oldtime = millis();
          fintime = oldtime + duration[thisNote % 7];;
          while (oldtime <= fintime) {
            oldtime = millis();
            add();
          }
        }



      }

      if (next[0] == hash) {
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();

        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();
        tone(12, NOTE_C5, dash);
        dashm();
        gapm();

        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        gapm();
        tone(12, NOTE_G5, dot);
        dotm();
        arrange();

      }

    }

  add();


  }

}


