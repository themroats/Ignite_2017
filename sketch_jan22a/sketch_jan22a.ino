


#include <Servo.h> 


Servo servo1;
Servo servo2;


const int flexpin1 = 0;
const int flexpin2 = 1; 


void setup() 
{ 

  Serial.begin(9600);


  servo1.attach(9);
  servo2.attach(6);
} 


void loop() 
{ 
  float flexposition1;    // Input value from the analog pin.
  float servoposition1;   // Output value to the servo.
  float flexposition2;
  float servoposition2;


  // Read the position of the flex sensor (0 to 1023):
  
  flexposition1 = analogRead(flexpin1);
  flexposition1 = constrain(flexposition1,1008, 1023);
  
  flexposition2 = analogRead(flexpin2);
  flexposition2 = constrain(flexposition2,1008, 1023);
  
  
  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. The flex sensors
  // we use are usually in the 600-900 range:

  servoposition1 = map(flexposition1, 1008, 1023, 0, 180);
  servoposition1= constrain(servoposition1, 0, 180);


  servoposition2 = map(flexposition2, 1008, 1023, 0, 180);
  servoposition2= constrain(servoposition2, 0, 180);
  // Now we'll command the servo to move to that position:

  servo1.write(servoposition1);
  servo2.write(servoposition2);
  // Because every flex sensor has a slightly different resistance,
  // the 600-900 range may not exactly cover the flex sensor's
  // output. To help tune our program, we'll use the serial port to
  // print out our values to the serial monitor window:
  Serial.print("For the first one, ");
  Serial.print("sensor: ");
  Serial.print(flexposition1);
  Serial.print("  servo: ");
  Serial.println(servoposition1);
  Serial.print("For the second one, ");
  Serial.print("sensor: ");
  Serial.print(flexposition2);
  Serial.print("  servo: ");
  Serial.println(servoposition2);

  Serial.println();


  delay(500);  // wait 20ms between servo updates
} 

