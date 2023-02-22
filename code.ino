int led = 13;
int sensor = 2;
int state = LOW;
int moisture = 3;
int val = 0;
int moist = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(moisture, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor), blink, HIGH);
  attachInterrupt(digitalPinToInterrupt(moisture), blink, CHANGE);
}

void loop(){
  val = digitalRead(sensor);
  Serial.print("motion: ");
  Serial.println(val);
  moist = analogRead(moisture);
  Serial.print("Moisture: ");
  Serial.println(moist);
  delay(100);
}


void blink() {
  state = !state;
   digitalWrite(led, state);
}
