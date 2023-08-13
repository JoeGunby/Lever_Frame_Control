const int Lever1Pin = 1;
const int Lever2Pin = A0;
const int Lever3Pin = A1;
const int Lever4Pin = A2;
const int Lever5Pin = 5;
const int RedAspectPin = 6;
const int YellowAspectPin = 7;
const int GreenAspectPin = 8;
const int FeathersPin = 9;
bool Lever1 = LOW;
bool Lever2 = LOW;
bool Lever3 = LOW;
bool Lever4 = LOW;
bool Lever5 = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(Lever1Pin, INPUT);
  pinMode(Lever2Pin, INPUT);
  pinMode(Lever3Pin, INPUT);
  pinMode(Lever4Pin, INPUT);
  pinMode(Lever5Pin, INPUT);
  pinMode(RedAspectPin, OUTPUT);
  pinMode(YellowAspectPin, OUTPUT);
  pinMode(GreenAspectPin, OUTPUT);
  pinMode(FeathersPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  SignalControl();
  FrameState();
  //digitalWrite(RedAspectPin, HIGH);
  Serial.println(Lever2);
  delay(100);
}


void FrameState() {
  Lever1 = analogRead(Lever1Pin);
  Lever2 = analogRead(Lever2Pin);
  Lever3 = analogRead(Lever3Pin);
  Lever4 = analogRead(Lever4Pin);
  Lever5 = analogRead(Lever5Pin);
}

void SignalControl() {
  if (Lever2 == HIGH && Lever3 == HIGH && Lever4 == HIGH) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, HIGH);
    digitalWrite(YellowAspectPin, LOW);
    digitalWrite(FeathersPin, LOW);
  }
  else if (Lever2 == LOW && Lever3 == HIGH && Lever4 == HIGH) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, HIGH);
    digitalWrite(FeathersPin, LOW);
  }
  else if (Lever2 == HIGH && Lever3 == LOW && Lever4 == HIGH) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, HIGH);
    digitalWrite(FeathersPin, LOW);
  }
  else if (Lever2 == HIGH && Lever3 == HIGH && Lever4 == LOW) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, HIGH);
    digitalWrite(FeathersPin, HIGH);
  }
  else {
    digitalWrite(GreenAspectPin, HIGH);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, LOW);
    digitalWrite(FeathersPin, LOW);
  }
}









