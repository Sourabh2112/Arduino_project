int IR_BUILTIN = 9;
int relay_BUILTIN = 13;
int flag = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(IR_BUILTIN, INPUT);
pinMode(relay_BUILTIN, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag == 1)
  {
      delay(1000);
      flag = 0;
  }
  int data;
  data = digitalRead(IR_BUILTIN);
  Serial.print("Data:");
  Serial.println(data);
  if(data == 0){
    lamp();
  }
//  else{
//    digitalWrite(relay_BUILTIN, LOW);
//  }
}

  void lamp(){
    delay(30);   //delay on start the component
    int data1;
    data1= digitalRead(IR_BUILTIN);
    while(data1== 1){
      data1 = digitalRead(IR_BUILTIN);
      Serial.print("Data1:");
      Serial.println(data1);
      digitalWrite(relay_BUILTIN, HIGH);
      if (data1 == 0){
        digitalWrite(relay_BUILTIN, LOW);
        flag = 1;
        break;
      }
    }
  }