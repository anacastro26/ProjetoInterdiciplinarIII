
 

// Libraries
#include <SPI.h>
#include <Ethernet.h>
#include <aREST.h>
#include <avr/wdt.h>
#include <Ultrasonic.h>


// Enter a MAC address for your controller below.
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xFE, 0x40 };

// IP address in case DHCP fails
IPAddress ip(192,168,2,2);

// Ethernet server
EthernetServer server(80);

// Create aREST instance
aREST rest = aREST();

// Variables to be exposed to the API
Ultrasonic ultrasonic1(2, 3);
Ultrasonic ultrasonic2(4, 5);
Ultrasonic ultrasonic3(6, 7);
Ultrasonic ultrasonic4(8, 9);
int valor3;
int valor4;
int valor1;
int valor2;


// Declare functions to be exposed to the API
void setup(void)
{
  // Start Serial
  Serial.begin(115200);

  // Init variables and expose them to REST APi
  
//  valor1 = 100;
//  valor2 = 40;
//  valor3 = 40;
//  valor4 = 40;
    
  rest.variable("vaga1",&valor1);
  rest.variable("vaga2",&valor2);
  rest.variable("vaga3",&valor3);
  rest.variable("vaga4",&valor4);

  // Give name & ID to the device (ID should be 6 characters long)
  rest.set_id("001");
  rest.set_name("SensoresEstacionamento");

  // Start the Ethernet connection and the server
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  // Start watchdog
  wdt_enable(WDTO_4S);
}

void loop() {
  valor1 = ultrasonic1.read();
  valor2 = ultrasonic2.read();
  valor3 = ultrasonic3.read();
  valor4 = ultrasonic4.read();

  // listen for incoming clients
  EthernetClient client = server.available();
  rest.handle(client);
  wdt_reset();



  Serial.print("Distancia 1: ");
  Serial.println(valor1);

  Serial.print("Distancia 2: ");
  Serial.println(valor2);

  Serial.print("Distancia 3: ");
  Serial.println(valor3);

  Serial.print("Distancia 4: ");
  Serial.println(valor4);


  
  delay(1000);

}
