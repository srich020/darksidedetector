#ifndef _SOFT_RESTART_H
#define _SOFT_RESTART_H

#include <avr/wdt.h>

#define soft_restart()        \
do                          \
{                           \
    wdt_enable(WDTO_15MS);  \
    for(;;)                 \
    {                       \
    }                       \
} while(0)

#endif



int speakerPin = 9;
//speaker connected to one of the PWM ports
boolean liar = false;
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
//frequencies for the tones we're going to use
//used http://home.mit.bme.hu/~bako/tonecalc/tonecalc.htm to get these


// Do we want debugging on serial out? 1 for yes, 0 for no
int DEBUG = 1;
#define PROCESSING_VISUALIZER 1
#define SERIAL_PLOTTER  2
#include <Stepper.h>
//  Variables
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
//int buzzerPin = 7; 
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 10;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin
int redPin = 8;

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.
static int outputType = SERIAL_PLOTTER;

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  pinMode(speakerPin, OUTPUT);  
  //sets the speakerPin to be an output
    // set the speed at 60 rpm:
//  pinMode(buzzerPin, OUTPUT);
  pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // pin that will fade to your heartbeat!
  pinMode(redPin,OUTPUT);
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS
   // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE,
   // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
//   analogReference(EXTERNAL);
  lcd.begin(16, 2);


  if (DEBUG) { 
    Serial.begin(9600); // Set serial out if we want debugging
  } 

}


//  Where the Magic Happens
void loop(){

    serialOutput() ;

  if (QS == true){     // A Heartbeat Was Found
                       // BPM and IBI have been Determined
                       // Quantified Self "QS" true when arduino finds a heartbeat
        fadeRate = 255;         // Makes the LED Fade Effect Happen
                                // Set 'fadeRate' Variable to 255 to fade LED with pulse
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.
        QS = false;                      // reset the Quantified Self flag for next time
  }
  delay(20);                             //  take a break
}



