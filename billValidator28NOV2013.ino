/*
* Sean
 * globalw2865@gmail.com
 * 30JUL2012
 * Bill validator/Arduino (second draft)
 */

/*
* RESOURCES:
 * http://www.arduino.cc/en/Reference/PulseIn
 * http://kegbot.blogspot.com/2004/11/coinco-magpro-mag50b-pinout.html
 * http://www.coinco.com/coin/faq/servicematerials/921970_1.pdf
 */

/*
* Description:
 * Arduino records and counts dollar bill received from pin 7 (billValidator).
 */

// Constants //
// pin for the bill validator's credit(-) line
const int billValidator = 7;

// Variables //

// recording the duration of pulse (milliseconds)
unsigned long duration;
// Threshold for pulse (change depending on your threshold)
unsigned long PULSE_THRESHOLD = 12000;

// holding the total dollars recorded
int dollarCounter = 0;

// total dollars required (change to your limit)
int MAX_DOLLARS = 5;



void setup()
{
  // Pin setups for bill validator and button
  pinMode(billValidator, INPUT);

  // Initialize serial ports for communication.
  Serial.begin(9600);
  Serial.println("Waiting for dollar...");
}

void loop()
{
  // get the duration of the pulse
  duration = pulseIn(billValidator, HIGH);

  // For Debugging
  // Uncomment the two lines below to see the duration printed
  //Serial.print("Duration: ");
  //Serial.println(duration);

  // Receiving a dollar bill will create a pulse
  // with a duration of 15000 - 16000.
  // NOTE: When there is no dollar bill pulse,
  // I will receive a pulse of 8400 - 8600
  // on every loop.
  // Dollar received
  if(duration > PULSE_THRESHOLD)
  {

    /*
  * Requirement 1:
     * The bill acceptor will send and 
     * count up dollar info to the Arduino
     */

    // Count dollar
    dollarCounter++;

    // For debugging:
    // Uncomment the two Serial.print lines to see dollar count
    // Checking for understanding
    //Serial.print("Dollar detected.\n Total: ");
    // Display new dollar count
    //Serial.println(dollarCounter); 

    if(dollarCounter==MAX_DOLLARS)
    {
      /*
      * Requirement 2:
       * Once the bill acceptor receives a total of 
       * five dollars, the arduino will send a 
       * kepress or print serial text
       */

      Serial.print(1,DEC);

      /*
      * Requirement 3:
       * The arduino will reset the count after five 
       * bucks and wait for more bills to be inserted.
       */
      dollarCounter = 0;
    }

  } 

}



