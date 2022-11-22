//Board1
#include <Wire.h>
int LED5 =5;
int x = 0;
int Ledoff = 0;
int Ledon = 1;
int slaveAddress1 = 8;
int slaveAddress2 = 9;
int slaveAddress3 = 10;
int slaveAddress4 = 11;

int digitalPin = 8;
int val = 0;
int count;
int y;

void setup() 
{
  pinMode(4, OUTPUT);//red-1
  pinMode(3, OUTPUT);//yellow-1
  pinMode(2, OUTPUT);//green-1
  
  pinMode(6, OUTPUT);
  pinMode(digitalPin, INPUT); 
  
  Wire.begin(8);               
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);           
  pinMode(LED5, OUTPUT);
  digitalWrite(LED5, LOW);
}

void receiveEvent( int bytes )
{
x = Wire.read(); 
Serial.println(x); 
}

void loop()
{
  if(x ==0){
digitalWrite(LED5, LOW);
}
  if(x ==1){
digitalWrite(LED5, HIGH);

  digitalWrite(4, LOW);
  delay(500);
  
  digitalWrite(2, HIGH);
  delay(10000);

  count=0;
  
  digitalWrite(2, LOW);
  delay(500);

  digitalWrite(3, HIGH); 
  delay(500);
  digitalWrite(3, LOW); 
  delay(500);
  digitalWrite(3, HIGH);  
  delay(500);
  digitalWrite(3, LOW); 
  delay(500);
  digitalWrite(3, HIGH); 
  delay(500);
  digitalWrite(3, LOW); 
  delay(500);
  digitalWrite(3, HIGH); 
  delay(500);
  digitalWrite(3, LOW); 
  delay(500);
  digitalWrite(3, HIGH);   
  delay(500);
  digitalWrite(3, LOW); 
  delay(500);
  digitalWrite(4, HIGH);

Serial.println("ส่งค่าให้ Arduino ตัวที่ 2");
Wire.beginTransmission( slaveAddress2 ); 
Wire.write(Ledon); 
delay(500);
Wire.endTransmission(); 
Wire.beginTransmission( slaveAddress2 ); 
Wire.write(Ledoff); 
delay(500);
Wire.endTransmission();

    val = digitalRead(digitalPin);  
  Serial.print("val = "); 
  Serial.println(val); 
  if (val == 0) { 
    digitalWrite(6, HIGH);
    count++;
    Serial.print(" count = ");
    Serial.println(count);
  }
  else {
    digitalWrite(6, LOW); 
  }
  delay(400);

}}
