// example01_blink_forever.ino derived from http://www.arduino.cc/en/Tutorial/Blink

#define LED 16                           // LED pin gpio #

void setup() { // this function runs once when we press reset or power the board
  pinMode(LED, OUTPUT);                  // set digital pin LED as an output device.
}

void loop() { // this function runs over and over again forever
  digitalWrite(LED, LOW);                // turn LED on (LOW is the voltage level)
  delay(1000);                           // wait for a second
  digitalWrite(LED, HIGH);               // turn LED off by making the voltage HIGH
  delay(1000);                           // wait for a second
}