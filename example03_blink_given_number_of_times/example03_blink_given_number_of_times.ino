// example03_blink_given_number_of_times.ino derived from http://www.arduino.cc/en/Tutorial/Blink

#define LED 16                           // LED pin gpio #

int times = 10;                          // blink led 10 times initially

# include <fvm01.h>                      // ##### 1. load FVM the Forth virtual machine
FVM F = FVM();                           // ##### 2. define F as an instence of FVM

void setup() { // this function runs once when we press reset or power the board
  pinMode(LED, OUTPUT);                  // initialize digital pin LED as an output device.

  F.init( 115200 );                      // ##### 3. init virtual machine F, baud rate 115200
  F.newConstant( "n", (int)&times );     // ##### 4. set the address of times as the constant n in F
}

void loop() { // this function runs over and over again forever

  F.update();                            // ##### 5. run virtual machine F

  if( ! times ) return;                  // no more blinking if times is 0
  times--;

  digitalWrite(LED, LOW);                // turn LED on (LOW is the voltage level)
  delay(1000);                           // wait for a second
  digitalWrite(LED, HIGH);               // turn LED off by making the voltage HIGH
  delay(1000);                           // wait for a second
}
