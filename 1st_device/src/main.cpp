#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 5); //the two pins which ima usee GPIO 4 and 5

const byte address[6] = "Range";

void setup() {
  Serial.begin(115200);

  if(!radio.begin()) {
    Serial.println("Radio is not responding pls checkkkk itttttttttt");
  while (1) {}
  }

radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_LOW);
radio.stopListening();



}

void loop() {
  const char text[] = "Yoooooooooooo";
  bool okkk = radio.write(&text, sizeof(text));

  Serial.print("waitup sendin it ");
  Serial.println(okkk ? "done" : "nah");

  delay(1000);
}

