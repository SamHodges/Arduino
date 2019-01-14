#define speakerPin 12

void setup() {
  // put your setup code here, to run once:
  pinMode(speakerPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(speakerPin, HIGH);
  delay(500);
  digitalWrite(speakerPin, LOW);
  delay(500);
}
