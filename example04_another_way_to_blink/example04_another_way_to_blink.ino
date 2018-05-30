// example04_another_way_to_blink.ino derived from http://www.arduino.cc/en/Tutorial/Blink

#define LED 16                          // LED pin gpio #
int times = 10;                         // blink led 10 times initially

                                        // ##### 0. Crtl+Shift+M open Serial Port Console
# include <fvm01.h>                     // ##### 1. load FVM the Forth virtual machine
FVM F = FVM();                          // ##### 2. define F as an instence of FVM
void setTimes(){ times = F.dPop(); }    // ##### 3. define  setTimes() to  set times
void showTimes(){ Serial.print(times); } // #####    define showTimes() to show times

void setup() { // this function runs once when we press reset or power the board
  pinMode(LED, OUTPUT);                 // initialize digital pin LED as an output device.

  F.init( 115200 );                     // ##### 4. init virtual machine F, baud rate 115200
  F.newPrimitive( "n!", setTimes );     // ##### 5. let  setTimes as the new command n! in F
  F.newPrimitive( "n?", showTimes);     // #####    let showTimes as the new command n? in F
}
void loop() { // this function runs over and over again forever

  F.update();                           // ##### 6. run virtual machine F

  if( ! times ) return;                 // no more blinking if times is 0
  times--;                              // decrease times by 1
  digitalWrite(LED, LOW);               // turn LED on (LOW is the voltage level)
  delay(1000);                          // wait for a second
  digitalWrite(LED, HIGH);              // turn LED off by making the voltage HIGH
  delay(1000);                          // wait for a second
}
