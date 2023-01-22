const int trigPin = 11;
const int echoPin = 10 ;
const int RLED = 13 ;
const int GLED = 12 ;
const int buzzer = 2;
const int OpenGate = 9 ;
const int CloseGate = 8 ;
int i;
// defines variables
long duration;
int distance;
int OpenState= 0;
int CloseState = 0 ;

void setup() {
pinMode(trigPin, OUTPUT);       // Sets the trigPin as an Output
pinMode(echoPin, INPUT);       // Sets the echoPin as an Input
pinMode(RLED, OUTPUT);         // Red LED as output
pinMode(GLED, OUTPUT);         // Green LED as output
pinMode(buzzer, OUTPUT);        // Buzzer as output
pinMode(OpenGate, INPUT);
pinMode(CloseGate, INPUT); 
pinMode(6, OUTPUT); 
pinMode(7, OUTPUT); 

Serial.begin(9600);         // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
delay(1000);

  OpenState = digitalRead(CloseGate);

  if (OpenState == HIGH)
    {
      if(distance<300)
      {
        digitalWrite(RLED, HIGH);
        Serial.print("Obstacle detected at distance:");
        Serial.print(distance);
        Serial.println("cm");
    
    
        for (i = 0; i <80; i++)              // Wen a frequency sound
           {
             digitalWrite (buzzer, HIGH) ;   // send voice
             delay (1) ;                      // Delay 1ms
             digitalWrite (buzzer, LOW) ;    // do not send voice
             delay (1) ;                      // delay ms
           }
        for (i = 0; i <100; i++)      // Wen Qie out another frequency sound
           {
             digitalWrite (buzzer, HIGH) ;   // send voice
             delay (2) ;           // delay 2ms  
             digitalWrite (buzzer, LOW) ;    // do not send voice
             delay (2) ;           // delay 2ms
             }
    
        digitalWrite(RLED, LOW);
          }
    }

   if (OpenState == HIGH)
   {
   if (distance>=300)           // distnce of obstacle is more the 3meter 
      {   
      digitalWrite(GLED, HIGH);       // Green light On
      Serial.print("Distance: ");
      Serial.println(distance);      //
          {
          digitalWrite(7,HIGH);
          digitalWrite(6,LOW);
          delay(3000);
           }
       delay(1000);             // Wait 1 second 
     digitalWrite(GLED, LOW);       // Green light off
      }
    }
}
