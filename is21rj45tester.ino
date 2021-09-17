int pinOrange = 3;
int pinWOrange = 2;
int pinGreen = 5;
int pinWGreen = 4;
int pinBlue = 7;
int pinWBlue = 6;
int pinBrown = 9;
int pinWBrown = 8;

int pin[] = {pinOrange,
             pinGreen,
             pinBlue,
             pinBrown
};
int wpin[] = {
               pinWOrange,
               pinWGreen,
               pinWBlue,
               pinWBrown
};
void setup() {
//  Serial.begin(9600);/
  
  pinMode(0, INPUT_PULLUP);
  
  pinMode(pinOrange, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinBrown, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
//  Serial.print(sizeof(pin));

}

void loop() {

  if(digitalRead(0)){
    while(true){
      if(!digitalRead(0)){
         break;
      }
    }
    for(int i = 0; i < 4; i++){
       digitalWrite(pin[i], HIGH);
       if(digitalRead(pinWOrange)){
          beep(3440,30);
          led(10,500);
       }
       else if(digitalRead(pinWGreen)){
          beep(3440,30);
          led(11,500);
          
       }
       else if(digitalRead(pinWBlue)){
          beep(3440,30);
          led(12,500);
       }
       else if(digitalRead(pinWBrown)){
          beep(1318.5,50);
          led(13,500); 
       }
       else{
          beep(440,300); 
          delay(30);
       }
       digitalWrite(pin[i], LOW);
    }
  }
}

void led(int n, int speed){
      digitalWrite(n, HIGH);
      delay(speed);
      digitalWrite(n, LOW);
      delay(speed/2);
}

void beep(int h, int dly){
  tone(1,h);
  delay(dly);
  noTone(1);
}
