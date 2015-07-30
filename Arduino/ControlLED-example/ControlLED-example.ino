#include <SoftwareSerial.h>
SoftwareSerial ESPserial(2, 3); // RX | TX

const int led = 9;

void setup() 
{
  Serial.begin(9600);     // communication with the host computer
  //while (!Serial)   { ; }
  pinMode(led, OUTPUT);

  analogWrite(led, 0); 

  // Start the software serial for communication with the ESP8266
  ESPserial.begin(9600);  

}

void loop() 
{
  // listen for communication from the ESP8266 and then write it to the serial monitor
  if ( ESPserial.available() )   { 
    int incoming_byte = ESPserial.parseInt();
    analogWrite(led, incoming_byte ); 
    Serial.println(incoming_byte); 
  }
}











