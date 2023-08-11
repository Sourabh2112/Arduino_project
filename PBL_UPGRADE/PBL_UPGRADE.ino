int IR_BUILTIN = 9;
int relay_BUILTIN = 13;
int pirPin = 2;
int flag = 0;
// int n;
int pirState = LOW;  // current state of the PIR sensor
int ledState = LOW;  // current state of the LED

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_BUILTIN, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(relay_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag == 1) {
    delay(1000);
    flag = 0;
  }
  pirState = HIGH;
  int data;
  data = digitalRead(IR_BUILTIN);
  // n=1;
  // Serial.print("Data:");
  // Serial.println(data);
  if (data == 0) {
    lamp();
  }
  //  else{
  //    digitalWrite(relay_BUILTIN, LOW);
  //  }
}

void lamp() {
  delay(30);  //delay on start the component
  digitalWrite(relay_BUILTIN, HIGH);
  int data1;
  data1 = digitalRead(IR_BUILTIN);
  while (data1 == 1) {
    // if(n=1){
    //   delay(2000);
    //   n=0;
    // }
    data1 = digitalRead(IR_BUILTIN);
    // Serial.print("Data1:");
    // Serial.println(data1);
    if (pirState == HIGH) {
      pirState = digitalRead(pirPin);
      ledState = HIGH;
      digitalWrite(relay_BUILTIN, ledState);
      Serial.println("Motion detected!");
      // delay(1000);
    } else {
      ledState = LOW;
      digitalWrite(relay_BUILTIN, ledState);
      Serial.println("Motion NOT detected!");
      break;
    }
    if (data1 == 0) {
      digitalWrite(relay_BUILTIN, LOW);
      flag = 1;
      break;
    }
  }
}