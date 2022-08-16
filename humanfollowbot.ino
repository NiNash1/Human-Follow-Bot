int p1=5;
int p2=6;
int p3=3;
int p4=2;
int IR_1= 7;
int IR_2= 8;
int IR_left =0;
int IR_right =0;
int distance;
long duration;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_1,INPUT);
  pinMode(IR_2,INPUT);
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  IR_left = digitalRead(IR_1);
  IR_right = digitalRead(IR_2);
  

 
  if (IR_right==1 && (distance>=10 && distance<=30)&&(IR_left==1){
    digitalWrite(p1,HIGH);
    digitalWrite(p2,LOW);
    digitalWrite(p3,HIGH);
    digitalWrite(p4,LOW);

  }
  else if (distance > 1 && distance < 10){
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
    digitalWrite(p3,LOW);
    digitalWrite(p4,HIGH);

  }
  else if ((IR_right==1) && (IR_left==0)){
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
    digitalWrite(p3,HIGH);
    digitalWrite(p4,LOW);

  }
  else if ((IR_right==0) && (IR_left==1)){
    digitalWrite(p1,HIGH);
    digitalWrite(p2,LOW);
    digitalWrite(p3,LOW);
    digitalWrite(p4,HIGH);

  }
  else{
    digitalWrite(p1,LOW);
    digitalWrite(p2,LOW);
    digitalWrite(p3,LOW);
    digitalWrite(p4,LOW);
  }

}
