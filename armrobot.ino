#include <Servo.h>

Servo rotasi;
Servo naikturun;
Servo griper;

int a;
int b;
int c;

//TCS Sensor
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

//store frequency read
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

//store the red, green, and blue colors
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup(){
Serial.begin(9600);
//Setting the output
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
//setting sensor out
pinMode(sensorOut, INPUT);
digitalWrite(S0, HIGH);
digitalWrite(S1,LOW);

rotasi.attach(11);
naikturun.attach(9);
griper.attach(10);
rotasi.write(30);
naikturun.write(50);
griper.write(70);

}

void loop(){  
  //setting RED(R) filtered 
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  //reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  //remaping the value of the red frequency from 0 to 255
  redColor = map(redFrequency, 29,125,255,0);
  //printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redColor);
  delay(100);
  //Setting Green 
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //reading
  greenFrequency = pulseIn (sensorOut, LOW);
  //remaping
  greenColor = map(greenFrequency, 34, 162, 255, 0);
  //printing
  Serial.print("G = ");
  Serial.print(greenColor);
  delay(100);
  //setting blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  //reading 
  blueFrequency = pulseIn (sensorOut, LOW);
  //remaping
  blueColor = map (blueFrequency, 21,117, 255, 0);
  //printing
  Serial.print("B = ");
  Serial.print(blueColor);
  delay(100);
  //kondisi
  if (redColor > greenColor && redColor > blueColor)
  {
    Serial.println("-RED detected!");
    standby();
    delay(1000); 
    red();
    standby();
  }
  else
  {
    standby();
  }
  if (greenColor > redColor && greenColor > blueColor)
  {
    Serial.println ("-GREEN detected!");
    standby();
    delay(1000);  
    green();
    standby();
  }
  else
  {
  standby(); 
  }
  if (blueColor > redColor && blueColor > greenColor)
  {
    Serial.println("-Blue detected!");
    standby(); 
    delay(1000); 
    blue();
    standby();
  }
  else
  {
    standby();
  }
}
void kirired(){
  for(a=30;a<=80;a++){
  rotasi.write(a);
  delay(50);
  }
  return;
}

void kananred(){
  for(a=80;a>=30;a--){
  rotasi.write(a);
  delay(50);
  }
  return;
}
void kiriblue(){
  for(a=30;a<=180;a++){
  rotasi.write(a);
  delay(50);
  }
  return;
}

void kananblue(){
  for(a=180;a>=30;a--){
  rotasi.write(a);
  delay(50);
  }
  return;
}
void kirigreen(){
  for(a=0;a<=30;a++){
  rotasi.write(a);
  delay(50);
  }
  return;
}

void kanangreen(){
  for(a=30;a>=0;a--){
  rotasi.write(a);
  delay(50);
  }
  return;
}
void turun(){
  for(b=50;b>=10;b--){
  naikturun.write(b);
  delay(50);
  }
  return;
}

void naik(){
  for(b=10;b<=50;b++){
  naikturun.write(b);
  delay(50);
  }
  return;
}
 void lepas(){
for(c=25;c<=70;c++){
  griper.write(c);
  delay(50);
  }
  return;
}

 void capit(){
for(c=70;c>=25;c--){
  griper.write(c);
  delay(50);
  }
  return;
}
void standby()
{
  rotasi.write(25);
  naikturun.write(50);
  griper.write(70);
}
void red()
{
turun();
capit();
naik();
delay(2000);
kirired();
delay(1000);
lepas();
kananred();
}
void blue ()
{
turun();
capit();
naik();
delay(2000);
kiriblue();
delay(1000);
lepas();
kananblue();
}
void green()
{
turun();
capit();
naik();
delay(2000);
kanangreen();
delay(1000);
lepas();
kirigreen();
}
