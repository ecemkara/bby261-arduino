int buzzerPin=9; 
int basinc;
const int arduLed1 = 4; //Ardustar Led 1
const int arduLed2 = 5; //Ardustar Led 2
const int arduLed3 = 6; //Ardustar Led 3
const int arduLed4 = 7; //Ardustar Led 4


void setup() {
  // Ledlerin bir çıkış olarak tanımlanması
Serial.begin(9600);
 pinMode(arduLed1, OUTPUT);
  pinMode(arduLed2, OUTPUT);
  pinMode(arduLed3, OUTPUT);
  pinMode(arduLed4, OUTPUT);
  pinMode(buzzerPin,OUTPUT); 
 
}


void loop() {
    basinc = analogRead(0);
  Serial.println(basinc);
  digitalWrite(buzzerPin,HIGH); 
 delay(1000);                  
 digitalWrite(buzzerPin,HIGH); 
 delay(1000);   

  

 if (basinc < 100) { digitalWrite(arduLed1, HIGH);} // b1d HIGH ise ( bu bağlantıda 1. butona basılmış ise)
    digitalWrite(arduLed1 , HIGH);// led1'i yak

 if (basinc < 250) { digitalWrite(arduLed2, HIGH);}  // b1d HIGH değil, b2d HIGH ise ( yani 2. butona basılmış ise)
  {
    digitalWrite(arduLed1 , HIGH); //led1'i yak
     digitalWrite(arduLed2 , HIGH); //led2'yi yak
  }

  if (basinc < 300) { digitalWrite(arduLed3, HIGH);}     //3. butona basılmı ise
  {
    digitalWrite(arduLed1 , HIGH);  // but3'e basıldığında led1 led2 ve led3 yakacak
     digitalWrite(arduLed2 , HIGH);
  }
  
 if (basinc < 500) {
  
 digitalWrite(arduLed4, HIGH) ;}   // 4. butona basılmış ise
  {
 digitalWrite(arduLed1, HIGH);  //ledler sırasi ise yanıp sönecekler
 digitalWrite(arduLed2 , HIGH);
 digitalWrite(arduLed3 ,HIGH);

    
  }
  

}
