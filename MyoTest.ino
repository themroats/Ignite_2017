
#include <MyoController.h>
#include <Servo.h> 

Servo servo[5];

MyoController myo = MyoController();

//const int flexpin[] = {0,1,2,3,4};

//float previous[]= {0,0,0,0,0};
float servoposition[] = {90,90,90,90,90};
//float flexposition[] = {0,0,0,0,0};
String ordinals[] = {"first","second","third","fourth","fifth"};



void setup() {
  Serial.begin(9600);

  myo.initMyo();

  servo[0].attach(2);
  /*
  servo[1].attach(3);
  servo[2].attach(4);
  servo[3].attach(5);
  servo[4].attach(6);
*/
}

void loop() {
  myo.updatePose();


  
  Serial.println("here");
  Serial.println(myo.getCurrentPose());
  switch ( myo.getCurrentPose() ) {
    case rest:
    /*
      digitalWrite(FIST_PIN,LOW); 
      digitalWrite(WAVEIN_PIN,LOW);
      digitalWrite(WAVEOUT_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      digitalWrite(DOUBLETAP_PIN,LOW);
      */
      break;
    //case fist:
      //digitalWrite(FIST_PIN,HIGH);
      //break;
    case :
          if (servoposition[0]<175){
            servoposition[0]+=5;
          }
          Serial.println("h");
          break;
    case waveOut:
          if (servoposition[0]>0){
            servoposition[0]-=5;
          }      
          break;
    /*case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH);
      break;
      */
   } 
   servo[0].write(servoposition[0]);
  //for (int i = 0; i<5; i++){
    
      //servo[i].write(servoposition[i]);
      //previous[i]=servoposition[i];
      delay(10);  

}
