const int Lever2Pin = A0;
const int Lever3Pin = A1;
const int Lever4Pin = A2;
const int RedAspectPin = 6;
const int YellowAspectPin = 7;
const int GreenAspectPin = 8;
const int FeathersPin = 9;
int Lever2 = 0;
int Lever3 = 0;
int Lever4 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Lever2Pin, INPUT);
  pinMode(Lever3Pin, INPUT);
  pinMode(Lever4Pin, INPUT);
  pinMode(RedAspectPin, OUTPUT);
  pinMode(YellowAspectPin, OUTPUT);
  pinMode(GreenAspectPin, OUTPUT);
  pinMode(FeathersPin, OUTPUT);
}

void loop() {
  FrameState();
  SignalControl();
}


void FrameState() {
  
  //To read the state of each microswitch attached to a lever.
  Lever2 = analogRead(Lever2Pin);
  Lever3 = analogRead(Lever3Pin);
  Lever4 = analogRead(Lever4Pin);
}

void SignalControl() {

  if (Lever2 > 0) {
    digitalWrite(RedAspectPin, LOW);
    delay(250);
    digitalWrite(YellowAspectPin, HIGH);
  }
  else {
    digitalWrite(YellowAspectPin, LOW);
    delay(250);
    digitalWrite(RedAspectPin, HIGH);
  }
}