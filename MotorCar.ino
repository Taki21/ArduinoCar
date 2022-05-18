int forwardL;
int backwardL;
int forwardR;
int backwardR;

int photoF;
int photoL;
int photoR;
int photoB;

int flexL;
int flexR;

//DO NOT TOUCH THESE 3 VARIABLES
const int SETUP_TIME = 5000;
const int AUTONOMOUS_TIME = 15000;
const int STOP_TIME = 2000;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  forwardL = 10;
  backwardL = 9;

  forwardR = 6;
  backwardR = 5;

  //flexL = A4;
  //flexR = A5;

  photoF = A0;
  photoL = A1;
  photoR = A2;
  photoB = A3;

  pinMode(photoF,INPUT);
  pinMode(photoL,INPUT);
  pinMode(photoR,INPUT);
  pinMode(photoB,INPUT);
  
  pinMode(forwardL,OUTPUT);
  pinMode(backwardL,OUTPUT);
  pinMode(forwardR,OUTPUT);
  pinMode(backwardR,OUTPUT);
}
//============================================================
//DO NOT WRITE CODE IN THE LOOP METHOD.
void loop() 
{
  //DO NOT TOUCH THIS CODE
  long mil = millis();
  if(mil<SETUP_TIME)
  {
    //LEAVE THIS BLANK
  }
  else if(mil<AUTONOMOUS_TIME+SETUP_TIME)
  {
    autonomousMode();
  }
  else if(mil<AUTONOMOUS_TIME+SETUP_TIME+STOP_TIME)
  {
    fullStop();
  }
  else
  {
    teleOpMode();
  } 
}
//============================================================

//WRITE CODE IN HERE:  YOUR AUTONOMOUS CODE GOES IN HERE.  PART 1 OF RACE
void autonomousMode()
{
  //WIP
}
//WRITE CODE IN HERE:  YOUR TELEOP CODE GOES IN HERE.  PART 2 OF RACE
//you MUST write this method
void teleOpMode()
{
  int photoStateF = analogRead(photoF);
  int photoStateL = analogRead(photoL);
  int photoStateR = analogRead(photoR);
  int photoStateB = analogRead(photoB);

  if(photoStateF > 900)
  {
    carMoveL(255,0);
    carMoveR(255,0);
  }
  else if(photoStateL > 900)
  {
    carMoveL(0,255);
    carMoveR(255,0);
  }
  else if(photoStateR > 900)
  {
    carMoveL(255,0);
    carMoveR(0,255);
  }
  else if(photoStateB > 900)
  {
    carMoveL(0,255);
    carMoveR(0,255);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }
}
//WRITE CODE IN HERE:  YOU SHOULD MAKE EVERY MOTOR STOP 
//you MUST write this method
void fullStop()
{
  carMoveL(0,0);
  carMoveR(0,0);
}

//Feel free to add more methods.
void carMoveL(int forward,int backward)
{
  analogWrite(forwardL,forward);
  analogWrite(backwardL,backward);

}
void carMoveR(int forward,int backward)
{
  analogWrite(forwardR,forward);
  analogWrite(backwardR,backward);
}

void handleFlexL()
{
  int flexState = analogRead(flexL);
  Serial.print("flexStateLeft = ");
  Serial.print(flexState);
  //Serial.println();
}

void handleFlexR()
{
  int flexState = analogRead(flexR);
  Serial.print("|");
  Serial.print("flexStateRight = ");
  Serial.print(flexState);
  Serial.println();
}

void handlePhoto() //getting the photoresistor state and displaying it
{
  int photoStateF = analogRead(photoF);
  Serial.print("photoStateF = ");
  Serial.print(photoStateF);
  Serial.print("|");

  int photoStateL = analogRead(photoL);
  Serial.print("photoStateL = ");
  Serial.print(photoStateL);
  Serial.print("|");

  int photoStateR = analogRead(photoR);
  Serial.print("photoStateR = ");
  Serial.print(photoStateR);
  Serial.print("|");

  int photoStateB = analogRead(photoB);
  Serial.print("photoStateB = ");
  Serial.println(photoStateB);
  Serial.print("|");
}

void testMove()
{
  int photoStateF = analogRead(photoF);
  int photoStateL = analogRead(photoL);
  int photoStateR = analogRead(photoR);
  int photoStateB = analogRead(photoB);
  if(photoStateF > 900)
  {
    carMoveL(255,0);
    carMoveR(255,0);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }
}
