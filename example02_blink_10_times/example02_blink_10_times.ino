// example02_blink_10_times.ino derived from http://www.arduino.cc/en/Tutorial/Blink

#define LED 16               // LED pin gpio #

int times = 10;              // ##### blink led 10 times #####

void setup() { // this function runs once when we press reset or power the board
  pinMode(LED, OUTPUT);      // initialize digital pin LED as an output device.
}

void loop() { // this function runs over and over again forever

  if( ! times-- ) return;    // ##### no more blinking if times becomes to 0 #####
  
  digitalWrite(LED, LOW);    // turn LED on (LOW is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(LED, HIGH);   // turn LED off by making the voltage HIGH
  delay(1000);               // wait for a second
}