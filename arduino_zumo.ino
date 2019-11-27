/*
 * This example uses the ZumoMotors library to drive each motor on the Zumo
 * forward, then backward. The yellow user LED is on when a motor should be
 * running forward and off when a motor should be running backward. If a
 * motor on your Zumo has been flipped, you can correct its direction by
 * uncommenting the call to flipLeftMotor() or flipRightMotor() in the setup()
 * function.
 */
 
#include <Wire.h>
#include <ZumoShield.h>

#define LED_PIN 13

ZumoMotors motors;


const uint16_t motorSpeed = 300;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

}

void loop() {
{
   // Move forward for four seconds
   
 digitalWrite(LED_PIN, HIGH);
  { 
   motors.setSpeeds(motorSpeed, motorSpeed);
    delay(4000);
    
    // Stop and pause one seconds
    motors.setSpeeds(0, 0);
    delay(1000);
  }




// run left motor forward

  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setLeftSpeed(speed);
    delay(2);
    }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  
   // Move backwards two seconds
   digitalWrite(LED_PIN, HIGH);

   
   { 
    motors.setSpeeds(-motorSpeed, -motorSpeed);
    delay(2000);

   
   }


    
 // run left motor forward

  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    
    motors.setLeftSpeed(speed);
    delay(2);
    }
    

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }
    
   {
  

  // Stop
    motors.setSpeeds(0, 0);
    
}
}
}
