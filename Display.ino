/**
 * Get the pin address for the requested
 * pin number, this is from 0-7
 */
void getPins(int i, int *pins){
  switch(i){
    case 0:
      pins[0] = 0;
      pins[1] = 0;
      pins[2] = 0;
      break;
    case 1:
      pins[0] = 1;
      pins[1] = 0;
      pins[2] = 0;
      break;
    case 2:
      pins[0] = 0;
      pins[1] = 1;
      pins[2] = 0;
      break;
    case 3:
      pins[0] = 1;
      pins[1] = 1;
      pins[2] = 0;
      break;
    case 4:
      pins[0] = 0;
      pins[1] = 0;
      pins[2] = 1;
      break;
    case 5:
      pins[0] = 1;
      pins[1] = 0;
      pins[2] = 1;
      break;
    case 6:
      pins[0] = 0;
      pins[1] = 1;
      pins[2] = 1;
      break;
    case 7:
      pins[0] = 1;
      pins[1] = 1;
      pins[2] = 1;
      break;      
  }
}

/**
 * Set the active pin and the active board.
 * There are 2 board options, 0 and 1.
 * By setting the pin as -1, then the board will
 * be disabled.
 */
void setPin(char board, char pin){  
  int signals[] = {0,0,0};
  getPins(pin, signals);
  digitalWrite(enable0, 0);
  digitalWrite(enable1, 0);
  if(board == 0){
     digitalWrite(address00, signals[0]);
     digitalWrite(address01, signals[1]);
     digitalWrite(address02, signals[2]);
     
     if(pin == -1) {
       digitalWrite(enable0, 0);
     } else {
       digitalWrite(enable0, 1);
     }
  } else {
    digitalWrite(address10, signals[0]);
    digitalWrite(address11, signals[1]);
    digitalWrite(address12, signals[2]);
     
    if(pin == -1) {
      digitalWrite(enable1, 0);
    } else {
      digitalWrite(enable1, 1);
    }
  }

  //delay(1);
}

/**
 * Refresh the display, this must be called at least 30 times
 * per second.
 */
void refresh(){
  if(setUpState == 1){
    setMins(m);
    setSeconds(0);
    setHours(0);
  } else if(setUpState == 2){
    setMins(0);
    setHours(h);
    setSeconds(0);
  } else if(setUpState == 3){
    setMins(brightness);
    setHours(1);
    setSeconds(0);
    s = 0;
  } else {
    setSeconds(s);
    setMins(m);
    setHours(h);
  }
}

/**
 * Dim the display for a small period of time.
 */
void dim(){
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  setPin(1, -1);
  setPin(0, -1);

  delay(20 - brightness);
}
