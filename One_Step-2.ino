char command;
String string;
String string2;
int steps_from_command;
const int stepPin = 5; 
const int dirPin = 3; 
const int enPin = 2;

//#include <AFMotor.h>

// Connect a stepper motor with 200 steps per revolution
// to motor port #1 (M1 and M2)
//AF_Stepper motor(200, 1);
//AF_Stepper motor(200, 1);
  void setup()
  {
    Serial.begin(9600);
   Serial.println("Stepper test!");
     while(!Serial){}
   // motor.setSpeed(150);

    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
  }

  void loop()
  {
    if (Serial.available() > 0) 
    {string = "";
 Serial.println("Stepper test1");
  }
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
     //Serial.println(command);     
      if(command == ':')
      {
        break;
      }      
      else
      {
        string += command;
      }
      delay(1);
    }

// no we get the number
while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
     //Serial.println(command);
      if(command == ':')
      {
        break;
      }
      else
      {
        string2 += command;
      }  
      delay(1);
    }
//
steps_from_command=string2.toInt();
string2="";
// no we check what is string  
  
    if(string == "F")
    {
      Forward(steps_from_command);
      string="";
      
    }
    
    if(string == "B")
    {
      Backward(steps_from_command);
      string="";
   
    }
 }

 
// These subroutines need to be adopted considering the particular stepping motor controller that you are using
    void Forward(int steps)
    {  
       digitalWrite(dirPin, HIGH);
      for(int i=0; i<steps; i++){
        digitalWrite(stepPin, HIGH);
        delay(1);
        digitalWrite(stepPin, LOW);
        delay(1);
        }

  Serial.println("This is 'kinda' cool");

//          motor.step(steps, FORWARD, SINGLE);
         // digitalWrite(13, HIGH);
         // delay(50);
   Serial.println("Forward  OK");
          delay(20);
    }
    
    void  Backward(int steps)
    {
      digitalWrite(dirPin, LOW);
      for(int i=0; i<steps; i++){
        digitalWrite(stepPin, HIGH);
        delay(1);
        digitalWrite(stepPin, LOW);
        delay(1);
        }
        
//      motor.step(steps, BACKWARD, SINGLE); 
      //digitalWrite(13, LOW);
      //delay(50);
     Serial.println("BACKWARD OK");
     delay(20);
    }
    
