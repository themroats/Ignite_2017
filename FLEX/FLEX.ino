


#include <Servo.h> 

Servo servo[5];


const int flexpin[] = {0,1,2,3,4};

float previous[]= {0,0,0,0,0};
float servoposition[] = {90,90,90,90,90};
float flexposition[] = {0,0,0,0,0};
String ordinals[] = {"first","second","third","fourth","fifth"};
void setup() 
{ 

  Serial.begin(9600);


  servo[0].attach(2);
  servo[1].attach(3);
  servo[2].attach(4);
  servo[3].attach(5);
  servo[4].attach(6);

} 


void loop() 
{ 

  //accepts analog input from the flex sensors
  for (int j = 0; j<5; j++){
    flexposition[j] = analogRead(flexpin[j]);
    flexposition[j] = constrain(flexposition[j],50, 200);

    
  }

  //maps flex sensor position to the the range of servo positions (doesn't actually write anything)
  for (int k = 0; k<5; k++){
    servoposition[k] = map(flexposition[k], 50, 200, 10, 170);
    servoposition[k]= constrain(servoposition[k], 10, 170);
    
  }
  
  
  
  //writes the servo position to the servo whenever it increases/decreases by more than 10 (or whatever value)
  for (int i = 0; i<5; i++){
    if (abs(servoposition[i]-previous[i])>10 ){
      servo[i].write(servoposition[i]);
      previous[i]=servoposition[i];
    }
    
  }

  //prints out stuff
  
  for (int m = 0; m<5; m++){
    Serial.print("For the"); 
    Serial.print(ordinals[m]);
    //Serial.print("first one, ");
    Serial.print("sensor: ");
    Serial.print(flexposition[m]);
    Serial.print("  servo: ");
    Serial.print(servoposition[m]);
    Serial.print(" previous is: ");
    Serial.println(previous[m]);
  }
  

  
  Serial.println();


  delay(10);  
} 

