//Addresses for board 0
#define address00 4
#define address01 3
#define address02 2

//Addresses for board 1
#define address10 7
#define address11 6
#define address12 5

//Enable pins for boards
#define enable0 A0
#define enable1 A1

//Button input pins
#define buttonUp A4
#define buttonDown A3
#define buttonSetup A5

//Program Variables
unsigned long start;
boolean lastSetupState = false;
boolean lastUpState = false;
boolean lastDownState = false;
char setUpState = 0; //0 - Clock, 1 - Mins, 2 - Hours, 3 - base brightness
char brightness = 20;
char s = 0;
char m = 0;
char h = 12;

void setup() {
  //Set the pin modes
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonSetup, INPUT);

  //Set the output pins
  pinMode(address00, OUTPUT);
  pinMode(address01, OUTPUT);
  pinMode(address02, OUTPUT);
  pinMode(address10, OUTPUT);
  pinMode(address11, OUTPUT);
  pinMode(address12, OUTPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(enable0, OUTPUT);
  pinMode(enable1, OUTPUT);
}

void loop() {
  /**
   * Loop and check for setup inputs from the
   * user.
   */
  if(setUpState == 0){
    start = millis();
    while(millis() - start < 1009){
      refresh();
      buttonCheck();
      dim();
    }
    nextSecond();
  }else {
    //In setup mode
    buttonCheck();
    validateTime();
    refresh();
    dim();
  }

}
