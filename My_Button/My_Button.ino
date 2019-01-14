int button1Pin, button2Pin, ledPin;
bool lightOn;

void setup() {
  // put your setup code here, to run once:
  button1Pin = 9;
  button2Pin = 8;
  ledPin = 5;
  lightOn = false;
  
  pinMode(button1Pin, INPUT_PULLUP); //in built resistor
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1Pin) == LOW){
    lightOn = false;  
  }
  
  if (digitalRead(button2Pin) == LOW) {
    lightOn = true;
  }

  if (lightOn) {
    digitalWrite (ledPin, HIGH);
  }

  else {
    digitalWrite (ledPin, LOW);
  }
}
