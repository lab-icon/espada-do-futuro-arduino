#include <CapacitiveSensor.h>//https://github.com/PaulStoffregen/CapacitiveSensor
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>
#include <stdlib.h>

EthernetUDP Udp;

int pin0 = 6;
int pin1 = 7;
int pin2 = 8;
int pin3 = 9;
int pinEnergy = 12;

// Sensores de frequência
float freq1, freq2, freq3, freq4, freq5;
float maxFreq1, maxFreq2, maxFreq3, maxFreq4, maxFreq5;
float minFreq1, minFreq2, minFreq3, minFreq4, minFreq5;

// Sensores booleanos
bool sensorb0, sensorb1, sensorb2, sensorb3, sensorb4;

unsigned long tempoUltimoReset = 0;
const unsigned long intervaloReset = 10000;

//Escolhe as portas do arduino que usam o sensor
CapacitiveSensor sensor1 = CapacitiveSensor(13,2);
CapacitiveSensor sensor2 = CapacitiveSensor(13,3);                        
CapacitiveSensor sensor3 = CapacitiveSensor(13,4); 
CapacitiveSensor sensor4 = CapacitiveSensor(13,5);

//the Arduino's IP
IPAddress ip(192, 168, 0, 100);

//destination IP
IPAddress outIp(192, 168, 0, 255);
const unsigned int outPort = 8888;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // you can find this written on the board of some Arduino Ethernets or shields