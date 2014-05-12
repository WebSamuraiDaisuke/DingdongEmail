/**
 * This is a simple "sketch" that calls a web page when a button is pressed.  It is a proof-of-concept
 * for my boss and hastily written in about 2 hours.  The remote URL is a PHP script that handles
 * making the API calls to a remote SMS-messaging service.
 * 
 * I'm sure it could make use of interrupts somehow, but I'm not sure how off the top of my head.
 * 
 * It uses the onboard RGB LED as status display:
 *  - Red = Waiting to be pressed
 *  - Green = Making HTTP request
 *  - Blue = Finished HTTP request
 * 
 * Hardware:
 *  - Normally-off momentary button
 *  - Spark Core
 * 
 * Setup:
 *  - Connect one pin of the button to GND
 *  - Connect the other pin of the button to the desired digital pin on the Spark Core
 * 
 * The configuration is in the variables defined at the top of the script.  They should be pretty
 * self-explanatory.
 **/

int millLast = 0;                    // Last time (in millis()) the doorbell was pressed
int pinDoorbell = D0;                // Button pin
int millDelay = 15000;               // How much time to wait until we allow another doorbell "ring" again
char srvIP[] = "X.X.X.X";            // Server IP address
char srvHost[] = "www.mydomain.tld"; // HTTP 1.1 hostname
int srvPort = 80;                    // Server port number
char srvPath[] = "/doorbell/";       // URL path

void setup() {
    pinMode(pinDoorbell, INPUT_PULLUP);

    RGB.control(true);
}

void loop() {
    if(digitalRead(pinDoorbell)==LOW)
        dingdong();
    else
        RGB.color(255, 0, 0);
}


void dingdong() {
    if(millLast==0 || (millLast+millDelay)<millis()) {
        millLast = millis();
        
        RGB.color(0, 255, 0);
        sendMail();
        RGB.color(0, 0, 255);
        
        delay(1000);
    }
}

void sendMail(){


    
}

