int pirPin = 2;     // the input pin for the PIR sensor
int ledPin = 13;    // the output pin for the LED
int pirState = LOW; // current state of the PIR sensor
int ledState = LOW; // current state of the LED

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pirState = digitalRead(pirPin);
  if (pirState == HIGH) {
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
    Serial.println("Motion detected!");
    // delay(1000);
  }
  else {
    ledState = LOW;
    digitalWrite(ledPin, ledState);
    Serial.println("Motion NOT detected!");
  }
}