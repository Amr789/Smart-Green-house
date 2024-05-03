#include <LiquidCrystal.h>
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
int temt6000 = A0;
float percentage;
int light_value, l2, flag = 0; 
bool motorun1 = false, motorun2 = false,motorun3 = false, motorun4 = false;

// motor 1
#define Ena1 6
#define IN1 7
#define IN2 13

// motor 2
#define Ena2 10
#define IN3 9
#define IN4 8

void setup() {
  Serial.begin(115200);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  pinMode(temt6000,INPUT);
  
  // Print a message to the LCD.
  lcd_1.setCursor(0,0);
  lcd_1.print("light intensity: ");
  
  pinMode(Ena1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(Ena2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  Serial.begin(115200);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  pinMode(temt6000,INPUT);
  
  // Print a message to the LCD.
  lcd_1.setCursor(0,0);
  lcd_1.print("light intensity: ");
  light_value = analogRead(temt6000);
  percentage = (light_value*100.0)/1023.0;
  lcd_1.setCursor(1,1);
  Serial.print(percentage);
  Serial.print("%");
  lcd_1.setCursor(1,1);
  lcd_1.print(percentage);
  lcd_1.print("%");
  delay(100);
  // l2 = analogRead(temt6000);
  // if(l2<light_value)
  //   flag = 1;
  // else if (l2>light_value)
  //     flag = 2;
  // if (flag == 1){
    if (percentage >= 70.0 && percentage <= 100.0 && !motorun1) {
      // Rotate both motors for 2 seconds
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(Ena1, 100);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(Ena2, 100);
      motorun1 = true;
      motorun2 = false;
      motorun3 = false;
      motorun4 = false;
      delay(3000);
  }
    else
    {
      analogWrite(Ena1, 0);
      analogWrite(Ena2, 0);
    }
    
    if (percentage >= 40.0 && percentage < 70.0 && !motorun2) {
      // Rotate both motors for 2 seconds
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(Ena1, 100);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(Ena2, 100);
      motorun1 = false;
      motorun2 = true;
      motorun3 = false;
      motorun4 = false;
      delay(3000);
      analogWrite(Ena1, 0);
      analogWrite(Ena2, 0);
    }
    else if (motorun2)
    {
      analogWrite(Ena1, 0);
      analogWrite(Ena2, 0);
    }
    
    if(percentage < 40 && percentage >= 10 && !motorun3)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(Ena1, 100);
      motorun1 = false;
      motorun2 = false;
      motorun3 = true;
      motorun4 = false;
      delay(3000);
    }
    
    else if (motorun3)
    {
      analogWrite(Ena1, 0);
    }
    
    if(percentage < 10 && !motorun4)
    {
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(Ena2, 100);
      motorun1 = false;
      motorun2 = false;
      motorun3 = false;
      motorun4 = true;
      delay(3000);
    }
    
    else if (motorun4)
    {
      analogWrite(Ena2, 0);
    }
    
  // if (flag == 2){
  //   if (percentage >= 70.0 && percentage <= 100.0 && !motorun1) {
  //     // Rotate both motors for 2 seconds
  //     digitalWrite(IN1, LOW);
  //     digitalWrite(IN2, HIGH);
  //     analogWrite(Ena1, 100);
  //     digitalWrite(IN3, LOW);
  //     digitalWrite(IN4, HIGH);
  //     analogWrite(Ena2, 100);
  //     motorun1 = true;
  //     motorun2 = false;
  //     motorun3 = false;
  //     motorun4 = false;
  //     delay(3000);
  //   }
  //   else
  //   {
  //     analogWrite(Ena1, 0);
  //     analogWrite(Ena2, 0);
  //   }
    
  //   if (percentage >= 40.0 && percentage < 70.0 && !motorun2) {
  //     // Rotate both motors for 2 seconds
  //     digitalWrite(IN1, LOW);
  //     digitalWrite(IN2, HIGH);
  //     analogWrite(Ena1, 100);
  //     digitalWrite(IN3, LOW);
  //     digitalWrite(IN4, HIGH);
  //     analogWrite(Ena2, 100);
  //     motorun1 = false;
  //     motorun2 = true;
  //     motorun3 = false;
  //     motorun4 = false;
  //     delay(3000);
  //     analogWrite(Ena1, 0);
  //     analogWrite(Ena2, 0);
  //   }
  //   else if (motorun2)
  //   {
  //     analogWrite(Ena1, 0);
  //     analogWrite(Ena2, 0);
  //   }
    
  //   if(percentage < 40 && percentage >= 10 && !motorun3)
  //   {
  //     digitalWrite(IN1, HIGH);
  //     digitalWrite(IN2, LOW);
  //     analogWrite(Ena1, 100);
  //     motorun1 = false;
  //     motorun2 = false;
  //     motorun3 = true;
  //     motorun4 = false;
  //     delay(3000);
  //   }
    
  //   else if (motorun3)
  //   {
  //     analogWrite(Ena1, 0);
  //   }
    
  //   if(percentage < 10 && !motorun4)
  //   {
  //     digitalWrite(IN3, HIGH);
  //     digitalWrite(IN4, LOW);
  //     analogWrite(Ena2, 100);
  //     motorun1 = false;
  //     motorun2 = false;
  //     motorun3 = false;
  //     motorun4 = true;
  //     delay(3000);
  //   }
    
  //   else if (motorun4)
  //   {
  //     analogWrite(Ena2, 0);
  //   }
  //     }
    
delay(2000);
}