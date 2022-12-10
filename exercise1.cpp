/*
* Name & Email: Valerie Wong
* Discussion Section: 021
* Assignment: Lab 2 Exercise 1
* Exercise Description: Make all the LEDs turn on when you press
						            button Y and turn off when you press
                        button X.

* I acknowledge all content contained herein, excluding template 
  or example code, is my own original work.

* Demo Link: https://youtu.be/3w7tDcUR8LA
*/

int B[4] = {2, 3, 4, 5};
int PD = 6;
int PU = 7;

int num = 750;
void setup() {

  // put your setup code here, to run once:
  pinMode(PD, INPUT);
  pinMode(PU, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(B[i], OUTPUT);
  }
  Serial.begin(9600);
}

void turnON(int B[]) {
  for (int i = 0; i < 4; ++i) {
  	 digitalWrite(B[i], HIGH);
  }
}

void turnOFF(int B[]) {
  for (int i = 0; i < 4; ++i) {
  	 digitalWrite(B[i], LOW);
  }
}

void readButtons() {
  if (!digitalRead(PU)) {
  	turnON(B);
  }
  
  if (digitalRead(PD)) {
  	turnOFF(B); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  readButtons();
}
