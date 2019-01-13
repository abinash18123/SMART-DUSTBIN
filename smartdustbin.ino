
int revright = 7;      //REVerse motion of Right motor
int fwdleft = 4;      
int revleft= 3;       
int fwdright= 6;       //ForWarD motion of Right motor

int south1=9;
int north1=11;
int east1=10;
int west1=12;

const int trigPin = 8;
const int echoPin = 3;
//
long duration;
int distances;


void setup() {
  

   pinMode(revright, OUTPUT);
   pinMode(fwdleft, OUTPUT);
   pinMode(revleft, OUTPUT);
   pinMode(fwdright, OUTPUT); 
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   Serial.begin(9600);
   pinMode(east1, INPUT);
   pinMode(west1, INPUT);
   pinMode(north1, INPUT);
   pinMode(south1, INPUT);
  

}

void loop() {


ultrasonic();
int east=digitalRead(east1);
int west=digitalRead(west1);
int north=digitalRead(north1);
int south=digitalRead(south1);

Serial.println(east);
//
//Serial.print(west);
//
//Serial.print(north);
//
//Serial.println(south);
int ultra=ultrasonic();

directions(east,west,north,south,ultra);

                           
 }
void directions(int east,int west,int north,int south,int ultra){


   if(ultra<35){
    
    digitalWrite(fwdright,LOW);
    digitalWrite(fwdleft,LOW);
    
    
  }

  else if(east==0&&west==0&&north==0&&south==1){
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,LOW);
    delay(3000);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==0&&west==0&&north==1&&south==0){
    
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==0&&west==1&&north==0&&south==0){
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,LOW);
    delay(1300);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==1&&west==0&&north==0&&south==0){
    digitalWrite(fwdleft,HIGH);
    digitalWrite(fwdright,LOW);
    delay(1300);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==0&&west==1&&north==0&&south==1){
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,LOW);
    delay(2000);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==0&&west==1&&north==1&&south==0){
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,LOW);
    delay(500);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==0&&west==1&&north==1&&south==1){
      digitalWrite(fwdright,HIGH);
      digitalWrite(fwdleft,LOW);
    delay(1300);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==1&&west==0&&north==0&&south==1){
    digitalWrite(fwdleft,HIGH);
    digitalWrite(fwdright,LOW);
    delay(2000);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
   else if(east==1&&west==0&&north==1&&south==0){
    digitalWrite(fwdleft,HIGH);
    digitalWrite(fwdright,LOW);
    delay(500);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
  else if(east==1&&west==0&&north==1&&south==1){
   digitalWrite(fwdleft,HIGH);
   digitalWrite(fwdright,LOW);
    delay(1300);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
  else if(east==1&&west==1&&north==0&&south==1){
      digitalWrite(fwdright,HIGH);
      digitalWrite(fwdleft,LOW);
    delay(3000);
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
  else if(east==1&&west==1&&north==1&&south==0){
    
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
  }
 else if(east==1&&west==1&&north==1&&south==1){
    
    digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
    
    
  }
  else if(east==0&&west==0&&north==0&&south==0&&(ultra<35)){
    
    digitalWrite(fwdright,LOW);
    digitalWrite(fwdleft,LOW);
    
    
  }
  else{
       digitalWrite(fwdright,HIGH);
    digitalWrite(fwdleft,HIGH);
  }
  
  
}

 
void forward(){

      digitalWrite(revright,LOW);                               
     digitalWrite(fwdright,HIGH);                              
     digitalWrite(fwdleft,HIGH);                               
     digitalWrite(revleft,LOW);  
  
}

void left(){

      digitalWrite(revright,LOW);                               
     digitalWrite(fwdright,LOW);                              
     digitalWrite(fwdleft,HIGH);                               
     digitalWrite(revleft,LOW);  
  
}
void right(){

      digitalWrite(revright,LOW);                               
     digitalWrite(fwdright,HIGH);                              
     digitalWrite(fwdleft,LOW);                               
     digitalWrite(revleft,LOW);  
  
}
 
int  ultrasonic(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distances= duration*0.034/2;
 // Serial.println(distances);
    return distances;
}
