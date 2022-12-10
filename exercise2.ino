/*
* Name & Email: Valerie Wong
* Discussion Section: 021
* Assignment: Lab 2 Exercise 2
* Exercise Description: Create a system that turns on the LEDs
						            in the following sequence:
                        
                        0000  1000  1100  1110  1111  1110  1100  1000  0000.
                      
                        Pressing Button X decreases the speed of the sequence
                        & pressing Button Y increases the speed of the sequence.
                        
                        There are 3 speeds: 250, 750, 1250. The default speed 
                        is 250.

* I acknowledge all content contained herein, excluding template 
  or example code, is my own original work.

* Demo Link: https://youtu.be/OK-cN7_cVtA
*/

int B[4] = {2, 3, 4, 5};
int PD = 6;
int PU = 7;

int num = 750;
int speed = 1250;
void setup() {

  // put your setup code here, to run once:
  pinMode(PD, INPUT);
  pinMode(PU, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(B[i], OUTPUT);
  }
  Serial.begin(9600);
}

void turnON(int B[], int i) {
  digitalWrite(B[i], HIGH);
  delay(speed);
}

void turnOFF(int B[], int i) {
  digitalWrite(B[i], LOW);
  delay(speed);
}

void decreaseSpeed() {
  if (speed == 1250) {
  	return; 
  }
  else {
  	speed += 500; 
  }
}

void increaseSpeed() {
  if (speed == 250) {
  	return; 
  }
  else {
    speed -= 500;
  }
}

void buttonPressed() {
  bool PU_pressed = digitalRead(PU); // False - pressed, True - Not pressed
  bool PD_pressed = digitalRead(PD); // True - pressed, False - not pressed
    
  if (!PU_pressed) {
    increaseSpeed();
  }
  
  if (PD_pressed) {
    decreaseSpeed();
  }
}

/*
SEQUENCE
0000  1000  1100  1110  1111  1110  1100  1000  0000
*/
void lightShow() {
  for (int i = 4; i >= 0; --i) {
    buttonPressed();
  	turnON(B, i);
  }
  
  for (int i = 0; i < 4; ++i) {
    buttonPressed();
  	turnOFF(B, i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  lightShow();
}
