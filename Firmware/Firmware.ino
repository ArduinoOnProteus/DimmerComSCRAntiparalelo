#define CROSS_PIN 2
#define CROP_PIN 3
#define CICLO 8333-50

int cropValue = 4000;

void setup() {
  pinMode(CROP_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(CROSS_PIN), crossing, RISING);
}

void loop() {
  int ana = analogRead(A0);
  cropValue = map(ana,0,1023,1,7400);
  delay(100);
}

void crossing(){
  noInterrupts();
  delayMicroseconds(cropValue);
  digitalWrite(CROP_PIN, HIGH);
  delayMicroseconds(50);
  digitalWrite(CROP_PIN, LOW);
  delayMicroseconds(CICLO-cropValue);
  delayMicroseconds(cropValue);
  digitalWrite(CROP_PIN, HIGH);
  delayMicroseconds(50);
  digitalWrite(CROP_PIN, LOW);
  interrupts();
}
