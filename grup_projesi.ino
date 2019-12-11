
#include <Wire.h>

int red =8;
int green= 9;

int buzzerPin=7;     

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT); 
}


double Termistor(int analogOkuma){

 double sicaklik;
 sicaklik = log(((10240000 / analogOkuma) - 10000));
 sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik)) * sicaklik);
 sicaklik = sicaklik - 273.15;
 return sicaklik;
}


void loop() {
               
 
  int deger = analogRead(A0);
    
  double sicaklik = Termistor(deger);
   
  Serial.println(sicaklik);

  //sıcaklık 5 derece üstünde ise kırmızı led yansın ve buzzer ötsün
  
  if(sicaklik > 5){
    
    digitalWrite(buzzerPin,HIGH); 
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    
    delay(1000); 
  }
  
  // diğer durumda yeşil led yansın kırmızı led sönsün
  
  else{
     digitalWrite(buzzerPin,LOW); 
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    
  }

    delay(250);


 
   
  

}
