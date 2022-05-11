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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  forwardL = 11;
  backwardL = 10;

  forwardR = 3;
  backwardR = 5;

  flexL = A4;
  flexR = A5;

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

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(forwardLR,255);
  //analogWrite(backwardR,0);
  //analogWrite(forwardL,255);
  //analogWrite(backwardL,0);
  //handleFlexL();
  //handleFlexR();
  //handlePhoto();
  movePhoto();
  //test();

  //carMoveR(255,0);
  //carMoveL(255,0);
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

  //Scaling the photoState to be between 0 and 255
  //int scaled = map(photoState, 355, 960, 0, 255);
  //Serial.print("scaled = ");
  //Serial.println(scaled);
}

void test(){
  int photoStateF = analogRead(photoF);
  int photoStateL = analogRead(photoL);
  int photoStateR = analogRead(photoR);
  int photoStateB = analogRead(photoB);

//  carMoveL(0, 0);
 // carMoveR(0, 0);
  
  if(photoStateR > 900)
  {
    carMoveL(255,0);
    carMoveR(0,255);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }
  
}

void movePhoto()
{
  int photoStateF = analogRead(photoF);
  int photoStateL = analogRead(photoL);
  int photoStateR = analogRead(photoR);
  int photoStateB = analogRead(photoB);
  
  if(photoStateF > 900)
  {
    Serial.println("Moving forward");
    carMoveL(255,0);
    carMoveR(255,0);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }

  if(photoStateL > 900)
  {
    Serial.println("Moving left");
    carMoveL(0,255);
    carMoveR(255,0);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }

  if(photoStateR > 900)
  {
    Serial.println("Moving right");
    carMoveL(255,0);
    carMoveR(0,255);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }

  if(photoStateB > 900)
  {
    Serial.println("Moving back");
    carMoveL(0,255);
    carMoveR(0,255);
  }
  else
  {
    carMoveL(0,0);
    carMoveR(0,0);
  }
}

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
