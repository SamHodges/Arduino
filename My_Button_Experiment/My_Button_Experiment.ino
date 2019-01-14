int button1Pin;
bool button1Pressed;
bool High;

void setup() {
  // put your setup code here, to run once:
  button1Pin = 9;
  button1Pressed = false;
  High = false;
  pinMode(button1Pin, INPUT_PULLUP); //in built resistor
  //pinMode(button1Pin, INPUT); //physical resistor
  
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1Pin) == HIGH && High == false){
    Serial.println("HIGH");
    button1Pressed = false;
    High = true;
  }
  else if (digitalRead(button1Pin) == LOW && button1Pressed == false) {
    Serial.println("LOW");
    button1Pressed = true;
    High = false;
  }
}
