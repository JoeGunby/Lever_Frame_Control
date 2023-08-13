const int Lever2Pin = A0;
const int Lever3Pin = A1;
const int Lever4Pin = A2;
const int RedAspectPin = 6;
const int YellowAspectPin = 7;
const int GreenAspectPin = 8;
const int FeathersPin = 9;
bool Lever2 = LOW;
bool Lever3 = LOW;
bool Lever4 = LOW;


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
  SignalControl();
  FrameState();
  Serial.println(Lever2); /* A serial output for testing what isn't working, when pulled, output for 2 changes from a 0 to 1 as expected so error is on output side somewhere, only a green aspect ever shows */
  delay(100);
}


void FrameState() {
  
  //To read the state of each microswitch attached to a lever.
  Lever2 = analogRead(Lever2Pin);
  Lever3 = analogRead(Lever3Pin);
  Lever4 = analogRead(Lever4Pin);
}

void SignalControl() {

  //If all levers are in the frame, a red aspect should show.
  if (Lever2 == HIGH && Lever3 == HIGH && Lever4 == HIGH) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, HIGH);
    digitalWrite(YellowAspectPin, LOW);
    digitalWrite(FeathersPin, LOW);
  }

  //If lever 2 is pulled, a yellow aspect should show.
  else if (Lever2 == LOW && Lever3 == HIGH && Lever4 == HIGH) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, HIGH);
    digitalWrite(FeathersPin, LOW);
  }

  //If lever 3 is pulled, a yellow aspect should show.
  else if (Lever2 == HIGH && Lever3 == LOW && Lever4 == HIGH) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, HIGH);
    digitalWrite(FeathersPin, LOW);
  }
  //If lever 4 is pulled, a yellow aspect and junction feathers should show.
  else if (Lever2 == HIGH && Lever3 == HIGH && Lever4 == LOW) {
    digitalWrite(GreenAspectPin, LOW);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, HIGH);
    digitalWrite(FeathersPin, HIGH);
  }

  //If a signal loss occurs or the system breaks, a green aspect shows as one should never appear in service.
  else {
    digitalWrite(GreenAspectPin, HIGH);
    digitalWrite(RedAspectPin, LOW);
    digitalWrite(YellowAspectPin, LOW);
    digitalWrite(FeathersPin, LOW);
  }
}









