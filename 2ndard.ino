int temt6000 = A0;
float percentage;
int light_value; 
bool motorun1 = false, motorun2 = false;
int flag = 0;
// motor 1
#define Ena1 5
#define IN1 2
#define IN2 3

void setup() {
  Serial.begin(115200);
  pinMode(temt6000,INPUT);
  
  pinMode(Ena1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  Serial.begin(115200);
  light_value = analogRead(temt6000);
  percentage = (light_value*100.0)/1023.0;
  if (percentage >= 70.0 && percentage <= 100.0 && !motorun1) {
    // Rotate both motors for 2 seconds
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
	  analogWrite(Ena1, 100);
    motorun1 = true;
    motorun2 = false;
    delay(3000);
  }
  else if (motorun1)
  {
    analogWrite(Ena1, 0); 
  }
  
  if(percentage < 70 && !motorun2)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
	analogWrite(Ena1, 100);
    motorun1 = false;
    motorun2 = true;
    delay(3000);
  }
  else if (motorun2)
  {
    analogWrite(Ena1, 0);
    
  }
delay(3000);
}