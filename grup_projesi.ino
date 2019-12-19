#include <LiquidCrystal.h>

int lm35Pin = A4 ; 
int red= 10; 
int green = 11; 
int yellow = 12;


#define buzzer 13 

 int zaman = 50; 
 int okunan_deger = 0; 
 float sicaklik_gerilim = 0; 
 float sicaklik = 0; 
 
 LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
 void setup()  
 { 
   lcd.begin(16, 2);
   lcd.print("Sicaklik Olcumu:");
  pinMode(red,OUTPUT); 
  pinMode(green,OUTPUT); 
  
   pinMode(buzzer,OUTPUT); 
    pinMode(yellow,OUTPUT); 
   Serial.begin(9600); 
 } 
   
 void loop() 
 { 
   okunan_deger = analogRead(lm35Pin); 
   sicaklik_gerilim = (okunan_deger / 1023.0)*5000.0; 
   sicaklik = sicaklik_gerilim /10.0;  
   Serial.println(sicaklik);     
    lcd.setCursor(0, 1);
  lcd.print(sicaklik);
  lcd.setCursor(6,1);
  lcd.print("C");
  delay(100);

  if(0< sicaklik <= 25){ 
     digitalWrite(red,LOW); 
     digitalWrite(buzzer,LOW);
      digitalWrite(green,HIGH);  
           digitalWrite(yellow,LOW); 
      
     delay(100); 
   } 
   if(25 < sicaklik < 35){ 
     digitalWrite(red,LOW); 
     digitalWrite(buzzer,LOW);
      digitalWrite(green,LOW);  
           digitalWrite(yellow,HIGH); 
      
     delay(100); 
   } 
   if(sicaklik > 35){ 
 

    digitalWrite(green,LOW); 
     digitalWrite(buzzer,HIGH); 
      digitalWrite(red,HIGH); 
         digitalWrite(yellow,LOW); 
     delay(100); 
      
   } 
 } 
