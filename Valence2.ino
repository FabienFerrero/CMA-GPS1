/*
  Code to controll the UCA/Valencia Antenna
 Switch between the 16 configurations when pressing the button
  
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int mode = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT); // ANT1
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT); // ANT2
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT); // ANT3
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT); // ANT4
  pinMode(7, OUTPUT); 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
  delay(50);
  buttonState = digitalRead(buttonPin);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    delay (500);
    digitalWrite(ledPin, LOW);
    delay (200);
    
    mode++; //Iterate mode
    if (mode == 17) { 
      mode =0;
      }

  switch (mode) {
  case 1:
    blink (1);
    // REF CONF
    ant1(0);
    ant2(0);
    ant3(0);
    ant4(0);    
    break;
  case 2:
    blink(2);
    ant1(1);
    ant2(0);
    ant3(0);
    ant4(0);      
    break;
  case 3:
    blink(3);
    ant1(0);
    ant2(1);
    ant3(0);
    ant4(0);
    break;
  case 4:
    blink(4);
    ant1(1);
    ant2(1);
    ant3(0);
    ant4(0);   
    break;
  case 5:
    blink(5);    
    ant1(0);
    ant2(0);
    ant3(1);
    ant4(0);   
    break;
  case 6:
    blink(6);  
    ant1(1);
    ant2(0);
    ant3(1);
    ant4(0);
    break;

  case 7:
    blink(7);
    ant1(0);
    ant2(1);
    ant3(1);
    ant4(0);
    break;

  case 8:
    blink(8);
    ant1(1);
    ant2(1);
    ant3(1);
    ant4(0);
    break;

  case 9:
    blink(9);
    ant1(0);
    ant2(0);
    ant3(0);
    ant4(1);
    break;

  case 10:
    blink(10);
    ant1(1);
    ant2(0);
    ant3(0);
    ant4(1);
    break;

  case 11:
    blink(11);
    ant1(0);
    ant2(1);
    ant3(0);
    ant4(1);
    break;

  case 12:
     blink(12);
     ant1(1);
     ant2(1);
     ant3(0);
     ant4(1);
     break;

  case 13:
     blink(13);
     ant1(0);
     ant2(0);
     ant3(1);
     ant4(1);
     break;

  case 14:
     blink(14);
     ant1(1);
     ant2(0);
     ant3(1);
     ant4(1);
     break;

  case 15:
     blink(15);
     ant1(0);
     ant2(1);
     ant3(1);
     ant4(1);
     break;

  case 16:
     blink(16);
     ant1(1);
     ant2(1);
     ant3(1);
     ant4(1);
     break;
  
   
    break;
    default:
    digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(3, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)
  
    break;
}   
    
  } else {
  
  }
}

void blink(int nblink){

int nblong = nblink/4;
int nbshort = nblink%4;
  
  for (int i=0;i<=nblong;i++)
  {
    digitalWrite(ledPin, HIGH);
    delay (300);
    digitalWrite(ledPin, LOW);
    delay(300);    
    }
  for (int i=0;i<=nbshort;i++)
  {
    digitalWrite(ledPin, HIGH);
    delay (100);
    digitalWrite(ledPin, LOW);
    delay(100);    
    }  
}

void ant1(int phase){
  if(phase==0){
  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW);   
  }
  else
  digitalWrite(2, LOW);   
  digitalWrite(3, HIGH);  
}

void ant2(int phase){
  if(phase==0){
  digitalWrite(9, HIGH);  
  digitalWrite(8, LOW);   
  }
  else
  digitalWrite(9, LOW);   
  digitalWrite(8, HIGH);  
}

void ant3(int phase){
  if(phase==0){
  digitalWrite(10, HIGH);   
  digitalWrite(11, LOW);   
  }
  else
  digitalWrite(10, LOW);   
  digitalWrite(11, HIGH);  
}

void ant4(int phase){
  if(phase==0){
  digitalWrite(12, HIGH);   
  digitalWrite(7, LOW);  
  }
  else
  digitalWrite(12, LOW);   
  digitalWrite(7, HIGH);  
}
