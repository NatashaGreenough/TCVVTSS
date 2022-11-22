//1
#include <Wire.h>
int LED5 = 5;
int x = 0;
int Ledoff = 0;
int Ledon = 1;
int slaveAddress1 = 8;
int slaveAddress2 = 9;
int slaveAddress3 = 10;
int slaveAddress4 = 11;

void setup() 
{
  pinMode(4, OUTPUT);//red-1
  pinMode(3, OUTPUT);//yellow-1
  pinMode(2, OUTPUT);//green-1
  
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
  delay(5000);
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
}
}
