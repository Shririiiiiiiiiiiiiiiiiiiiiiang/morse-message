#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 5); // Both my esps are connected with the nrfs on this pin only the one seeing this may change it to any GPIO pins they want their nrf'sce and csn pin connected to

const byte address[6] = "Range";

void setup() {
  Serial.begin(115200);

  if(!radio.begin()) {
    Serial.println("Radio is not responding pls checkkkk itttttttttt");
  while (1) {}
  }

radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_LOW);
radio.startListening();



}

void loop() {
  if(radio.available()) {
    char text[32] = ""; //keeping it 32 fr now as my mesages are small 
    radio.read(&text, sizeof(text));

    Serial.print("Got the messagee:- ");
    Serial.println(text);
  }
}
