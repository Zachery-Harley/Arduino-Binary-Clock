/**
 * Check the buttons for any input, and react
 * to the button input.
 */
void buttonCheck(){
  if(setUpState == 0){
    if(setupPushed()){
      //Go into setup mode
      setUpState = 1;
      return;
    }
  }

  if(setUpState == 1){
    if(upPushed()){
      //Up the mins
      m++;
    }
    if(downPushed()){
      m--;
    }
    if(setupPushed()){
      setUpState = 2;
      return;
    }
  }

  if(setUpState == 2){
    if(upPushed()){
      //Up the mins
      h++;
    }
    if(downPushed()){
      h--;
    }
    if(setupPushed()){
      setUpState = 3;
      return;
    }
  }

  if(setUpState == 3){
    if(upPushed()){
      //Up the mins
      brightness++;
    }
    if(downPushed()){
      brightness--;
    }
    if(setupPushed()){
      setUpState = 0;
      return;
    }
  }
}

/**
 * Validate the time and ensure that there are no overflows
 * when setting times using buttons
 */
void validateTime(){
  if(m >= 60){
    m = 0;
  }
  if(m < 0){
    m = 59;
  }
  
  if(h >= 24){
    h = 0;
  }
  if(h < 0){
  }
  if(brightness >= 20) brightness = 20;
  if(brightness <= 0) brightness = 0;
  
}

/**
 * Return true if the setup button is pushed
 */
boolean setupPushed(){
  if(!lastSetupState && digitalRead(buttonSetup)){
    lastSetupState = true;
    return true;
  } else {
    if(lastSetupState && !digitalRead(buttonSetup)){
      lastSetupState = false;
    }
    return false;
  }
}

/**
 * Return true if the up button is pushed
 */
boolean upPushed(){
  if(!lastUpState && digitalRead(buttonUp)){
    lastUpState = true;
    return true;
  } else {
    if(lastUpState && !digitalRead(buttonUp)){
      lastUpState = false;
    }
    return false;
  }
}

/**
 * Return down if the button is pushed
 */
boolean downPushed(){
  if(!lastDownState && digitalRead(buttonDown)){
    lastDownState = true;
    return true;
  } else {
    if(lastDownState && !digitalRead(buttonDown)){
      lastDownState = false;
    }
    return false;
  }
}

