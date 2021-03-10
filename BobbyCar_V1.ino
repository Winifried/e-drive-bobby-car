/* Arduino Uno
 */

// input pins
int startPin = 2;  // A2: input pin, Potentiometer -> turn car key
int speedPin = 1;  // A3: input pin, Potentiometer -> move gas lever
int lightPin = 12; // D12: output pin, lights (2 LEDS white, paralel)
int backlightPin = 13; // D13: output pin, lights (2 LEDS red, serial)
int motorspeedcontrol = 6; // D6: output pin, give  speed to motor after changing potentiometer value 
                            // has to be a digital pwd pin, even when using analogwrite

int relais_1 = 9 ; // D9: output pin, Relais ground turn 12V off when switching current direction 
int relais_2 = 10; // D10; output pin, Relais switch current 1
int relais_3 = 11; // D11; output pin, Relais switch current 2

int go = 0;        // value car key turn
int vroom = 0;     // value gas lever
int old_vroom = 0; // trying to dejitter
int true_vroom = 0; // value new output to motorspeedcontrol
int dlay = 0; // delay value in while loop

//volatile bool turn_on = false;
volatile bool car_on = false;
volatile bool dir_forward = true ;
volatile bool prev_dir = true;


// output pins 


void setup() {
 Serial.begin(9600);                        // display | debugging 
 Serial.println("starting setup...");
 pinMode(lightPin, OUTPUT);                 // light as output
 pinMode(backlightPin, OUTPUT);             // light as output
 pinMode(motorspeedcontrol, OUTPUT);  
  analogWrite(motorspeedcontrol, true_vroom);
 pinMode(speedPin, INPUT);
 pinMode(startPin, INPUT); 
 pinMode(relais_1, OUTPUT);
  digitalWrite(relais_1, LOW);
 pinMode(relais_2, OUTPUT);
  digitalWrite(relais_2, HIGH);
 pinMode(relais_3, OUTPUT);
  digitalWrite(relais_3, LOW);
 
 Serial.print("Keypoti reads: ");
 Serial.println(go);
 Serial.println("Gaspoti reads: ");
 Serial.println(vroom);
 Serial.println("dir_forward :");
 Serial.println(dir_forward);    
 
}

void direction() {
  if (dir_forward == true) {
      digitalWrite(relais_1, LOW);
      Serial.print("relais_1 LOW - switching circuit start");
      delay(5);
      digitalWrite(relais_2, HIGH);
      digitalWrite(relais_3, LOW);
      Serial.print("relais_2 HIGH, relais_3 LOW - going forwards");
      delay(5);
      digitalWrite(relais_1, HIGH);
      Serial.print("relais_1 HIGH - switching circuit end");
  }
  if (dir_forward == false) {
      digitalWrite(relais_1, LOW);
            Serial.print("relais_1 LOW - switching circuit start");
      delay(5);
      digitalWrite(relais_2, LOW);
      digitalWrite(relais_3, HIGH);
            Serial.print("relais_2 LOW, relais_3 HIGH - going backwards");
      delay(5);
      digitalWrite(relais_1, HIGH);
            Serial.print("relais_1 HIGH - switching circuit end");      
  }
}

void loop() {
  go = analogRead(startPin);        // read out car key turn
  vroom = analogRead(speedPin);     // read out gas lever
  vroom = analogRead(speedPin);     // read out gas lever twice to reduce jitter/bounce

  if (vroom < (old_vroom - 2.5) || vroom > (old_vroom + 2.5)) {
    old_vroom = vroom;
  } else {
    vroom = old_vroom;
  }
   
   if (go > 300) {
    digitalWrite(relais_1, HIGH);
    digitalWrite(lightPin, HIGH); // turn front lights on
    digitalWrite(backlightPin, HIGH); // turn back lights on
    
   if (vroom > 350 ){
    dir_forward = false;                         // going backwards

             // Serial.print("dir_forward False ");
             // 550 = 0
             // 780 = 1017
    true_vroom = map(vroom, 350,500,500, 1023);  // map the range of true_vroom to the readout of vroom
    analogWrite(motorspeedcontrol, true_vroom);  // change the analog out value
    //motorspeed= vroom;
    // (vroom-800);
              Serial.print("vroom value: ");
              Serial.print(vroom);
              Serial.print("\t motorspeed (true_vroom): ");
              Serial.println(true_vroom);
             // Serial.print("motorspeed & direction: ");
             // Serial.println(motorspeed, dir_forward);
              //Serial.println(dir_forward);
              Serial.print("\t going backwards ");

     dlay = 0;
     while (dlay < 50) {
     analogWrite(motorspeedcontrol, true_vroom);
     dlay++;
     }
                                        // delay(50) wait 50 ms before the next loop for the analog-to-digital converter 
                                                  // to settle after the last reading
    
   } else if (vroom >=300 && vroom <=350 ) {
             // Serial.print("dir_forward do nothing ");
             true_vroom=0;
             analogWrite(motorspeedcontrol, true_vroom);
              Serial.print("vroom value: ");
              Serial.println(vroom);
              Serial.print("\t motorspeed (true_vroom): ");
              Serial.println(true_vroom);
              Serial.print("\t not moving - switching gears ");
     dlay = 0;
     while (dlay < 50) {
     analogWrite(motorspeedcontrol, true_vroom);
     dlay++;
     }
     //delay(50);
   } else {
    dir_forward = true;
    true_vroom = map(vroom,  300,0, 500, 1023);  // map the range of true_vroom to the readout of vroom
    analogWrite(motorspeedcontrol, true_vroom);  // change the analog out value
    //motorspeed=vroom;
    //1024-vroom;
              Serial.print("vroom value: ");
              Serial.println(vroom);
              Serial.print("\t true motorspeed: ");
              Serial.println(true_vroom);
              //Serial.print("motorspeed & direction: ");
              //Serial.println(motorspeed);
              //Serial.println(dir_forward);
              Serial.print("\t going forward ");
     dlay = 0;
     while (dlay < 50) {
     analogWrite(motorspeedcontrol, true_vroom);
     dlay++;
     }
     //delay(50);
   }
    //Serial.print("turning lights on");
  }
  else {
    digitalWrite(lightPin, LOW); // turn lights off
    digitalWrite(backlightPin, LOW); // turn lights off
    true_vroom=0;
    analogWrite(motorspeedcontrol, true_vroom);
    digitalWrite(relais_1, LOW);  
              Serial.print(" lights off, motor off ");
              Serial.print("\t motorspeed value (vroom): ");
              Serial.println(vroom);
              //Serial.println("dir_forward: ");
              //Serial.println(dir_forward);  
    delay(50);
          
  }

 if (dir_forward == true && prev_dir != dir_forward) {
      digitalWrite(relais_1, LOW);
      Serial.print("switching current start: relais_1 :");
      Serial.println(relais_1);
      delay(50);
      digitalWrite(relais_2, HIGH);
      digitalWrite(relais_3, LOW);
      Serial.print("switching current: relais_2 HIGH, relais_3 LOW ");
      delay(50);
      digitalWrite(relais_1, HIGH);
      Serial.print("switching current end: relais_1 HIGH ");
      prev_dir = true;
      delay(20);
  }
   if (dir_forward == false && prev_dir != dir_forward) {
      digitalWrite(relais_1, LOW);
            Serial.print("switching current start: relais_1: ");
      delay(50);
      digitalWrite(relais_2, LOW);
      digitalWrite(relais_3, HIGH);
            Serial.print("switching current : relais_2 LOW, relais_3 HIGH ");
      delay(50);
      digitalWrite(relais_1, HIGH);
            Serial.print("switching current end: relais_1 HIGH "); 
      prev_dir = false;     
      delay(20);
  }
  
}

