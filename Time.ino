/**
 * Set the seconds being displayed on the
 * front of the clock, the seconds will be
 * set to the given value
 */
void setSeconds(unsigned char sec){
   unsigned char single = sec % 10;

   //Set the single, then the 10ths
   if(single >= 8) {
      setPin(0, 3);
      single -= 8;
   }
   if(single >= 4){
      setPin(0, 2);
      single -= 4;
   }
   if(single >= 2) {
      setPin(0, 1);
      single -= 2;
   }
   if(single == 1){
      setPin(0, 0);
   }

   //Set the tens
   if(sec >= 40){
      setPin(0, 6);
      sec -= 40;
   }
   if(sec >= 20){
    setPin(0 ,5);
    sec -= 20; 
   }
   if(sec >= 10){
    setPin(0, 4);
   }
   //Turn the screen off
   if(sec == 0){
     setPin(0, -1);
   }
}

/**
 * Set the minuets on the display,
 * the minuets will be set to the given char
 */
void setMins(unsigned char mins) {
   unsigned char minuets = mins % 10;

   //Set the single, then the 10ths
   if(minuets >= 8) {
      setPin(1, 2);
      minuets -= 8;
   }
   if(minuets >= 4){
      setPin(1, 1);
      minuets -= 4;
   }
   if(minuets >= 2) {
      setPin(1, 0);
      minuets -= 2;
   }
   if(minuets == 1){
      setPin(0, 7);
   }

   //Set the tens
   if(mins >= 40){
      setPin(1, 5);
      mins -= 40;
   }
   if(mins >= 20){
    setPin(1 ,4);
    mins -= 20; 
   }
   if(mins >= 10){
    setPin(1, 3);
   }
   //Set the minuets to 0
   if(mins == 0){
    setPin(1,-1);
   }
}

/**
 * Set the hours on the front of the display.
 * The hours are set to the given char
 */
void setHours(unsigned char hours){
   unsigned char hour = hours % 10;
   
   //Set the single, then the 10ths
   if(hour >= 8) {
      digitalWrite(9, 1);
      digitalWrite(8, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      setPin(1, -1);
      hour -= 8;
   }
   if(hour >= 4){
      digitalWrite(9, 0);
      digitalWrite(8, 1);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      setPin(1, -1);
      hour -= 4;
   }
   if(hour >= 2) {
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      setPin(1, 7);
      hour -= 2;
   }
   if(hour == 1){
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      setPin(1, 6);
   }

   if(hours >= 20){
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      setPin(1, -1);
    hours -= 20; 
   }
   if(hours >= 10){
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      setPin(1, -1);
   }

   if(hours == 0){
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      setPin(1, -1);
   }
}

/**
 * Incriment the seconds and check if there is an overflow
 * from seconds to minuets, minuets to hours and then
 * if hours need to be reset.
 */
void nextSecond(){
  //Incriment time by a second
  s++;
  if(s % 60 == 0){
    m++;
    s = s % 60;
  }
  if(m == 60){
    h++;
    m = m % 60;
  }
  h = h % 24;
}



