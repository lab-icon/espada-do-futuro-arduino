#include "variables.h";

float mapToFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sendMessage(int address, float data) 
{
  String addr = "/sensor/";
  addr.concat(address);
  //Serial.println(addr);
  OSCMessage msg(addr.c_str());
  msg.add(data);
  //PROBLEM SEEMS TO OCCUR HERE. When I comment the following 3 lines, it runs.
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet


  msg.empty(); // free space occupied by message
  //Serial.print("\nosc message sent");
}

void time() 
{
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoUltimoReset >= intervaloReset) {
    // Realiza o reset do pino de energia
    digitalWrite(pinEnergy, LOW);
    delay(1000); // Aguarda 1 segundo para garantir o reset
    digitalWrite(pinEnergy, HIGH); // Liga o pino novamente
    tempoUltimoReset = tempoAtual;
    //maxFreq1 = freq1;
    maxFreq1 += (freq1-maxFreq1)*0.1;
    minFreq1 += (freq1-minFreq1)*0.1;

    maxFreq2 += (freq2-maxFreq2)*0.1;
    minFreq2 += (freq2-minFreq2)*0.1;

    maxFreq3 += (freq3-maxFreq3)*0.1;
    minFreq3 += (freq3-minFreq3)*0.1;

    maxFreq4 += (freq4-maxFreq4)*0.1;
    minFreq4 += (freq4-minFreq4)*0.1;

    maxFreq5 += (freq5-maxFreq5)*0.1;
    minFreq5 += (freq5-minFreq5)*0.1;
  }
}

// ETHERNET SETUP
void ethernetSetup() {
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    } else if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
  }

  // print your local IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  Udp.begin(outPort);
}