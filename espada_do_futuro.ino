/*
Make an OSC message and send it over UDP
ICON LAB
*/

#include "functions.h";

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pinEnergy, OUTPUT);
  digitalWrite(pinEnergy, HIGH);

  ethernetSetup();

  maxFreq1=100;
  maxFreq2=100;
  maxFreq3=100;
  maxFreq4=100;
  maxFreq5=100;

  minFreq1=100000;
  minFreq2=100000;
  minFreq3=100000;
  minFreq4=100000;
  minFreq5=100000;

  freq1 = 10000;
  freq2 = 10000;
  freq2 = 10000;
  freq2 = 10000;
  freq2 = 10000;
}

void loop()
{
  freq1 += float(sensor1.capacitiveSensor(10)-freq1)*0.1;
  if (freq1>maxFreq1) {
    maxFreq1 = freq1;
  } else if (freq1<minFreq1)  {
    minFreq1 = freq1;
  }
  sendMessage(1,mapToFloat(freq1,minFreq1,maxFreq1,0,1));
  
  freq2 += (sensor2.capacitiveSensor(10)-freq2)*0.1;
  if (freq2>maxFreq2) {
    maxFreq2 = freq2;
  } else if (freq2<minFreq2)  {
    minFreq2 = freq2;
  }
  sendMessage(2,mapToFloat(freq2,minFreq2,maxFreq2,0,1)); 

  freq3 += (sensor3.capacitiveSensor(10)-freq3)*0.1;  
  if (freq3>maxFreq3) {
   maxFreq3 = freq3;
  } else if (freq3<minFreq3)  {
   minFreq3 = freq3;
  }
  sendMessage(3,mapToFloat(freq3,minFreq3,maxFreq3,0,1));

  freq4 += (sensor4.capacitiveSensor(10)-freq4)*0.1;
  if (freq4>maxFreq4) {
    maxFreq4 = freq4;
  } else if (freq4<minFreq4)  {
    minFreq4 = freq4;
  }
  sendMessage(4,mapToFloat(freq4,minFreq4,maxFreq4,0,1));
  

  sensorb0 = !digitalRead(pin0);
  sendMessage(5, sensorb0); 
  Serial.println(sensorb0);

  sensorb1 = !digitalRead(pin1);
  sendMessage(6, sensorb1); 

  sensorb2 = !digitalRead(pin2);
  sendMessage(7, sensorb2); 

  sensorb3 = !digitalRead(pin3);
  sendMessage(8, sensorb3);
  
  delay(250);
  time();
}


