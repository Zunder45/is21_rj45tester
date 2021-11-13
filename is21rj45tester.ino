#include <LiquidCrystal_I2C.h>

int pinOrange = 3;
int pinWOrange = 2;
int pinGreen = 5;
int pinWGreen = 4;
int pinBlue = 7;
int pinWBlue = 6;
int pinBrown = 9;
int pinWBrown = 8;

int tonePin = 12;
int bttPin = 11;

int pin[] = {
             pinOrange,
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

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  pinMode(bttPin, INPUT_PULLUP);
  pinMode(tonePin, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.home();
  lcd.print("Pins:12345678");


}

void loop() {

  if(digitalRead(bttPin)){
    while(true){
      if(!digitalRead(bttPin)){
         break;
      }
    }
    clearLcd();
    for(int i = 0; i < 4; i++){
       pinMode(wpin[i], OUTPUT);
       digitalWrite(wpin[i], HIGH);
       
       if(digitalRead(pinOrange)){
          beep(3440,30);
          writeLcd(wpin[i],String(pinWOrange-1, DEC));
       }
       else if(digitalRead(pinGreen)){
          beep(3440,30);
          writeLcd(wpin[i],String(pinWGreen-1, DEC));
          
       }
       else if(digitalRead(pinBlue)){
          beep(3440,30);
          writeLcd(wpin[i],String(pinWBlue-1, DEC));
       }
       else if(digitalRead(pinBrown)){
          writeLcd(wpin[i],String(pinWBrown-1, DEC));
          beep(1318.5,50);
       }
       else{
          writeLcd(wpin[i], "X"); 
          beep(440,300);
       }
       digitalWrite(wpin[i], LOW);
       pinMode(wpin[i], INPUT);
       delay(500);
    }
    for(int i = 0; i < 4; i++){
       pinMode(pin[i], OUTPUT);
       digitalWrite(pin[i], HIGH);
      
       if(digitalRead(pinWOrange)){
          beep(3440,30);
          writeLcd(pin[i],String(pinOrange-1, DEC));
       }
       else if(digitalRead(pinWGreen)){
          beep(3440,30);
          writeLcd(pin[i],String(pinGreen-1, DEC));
          
       }
       else if(digitalRead(pinWBlue)){
          beep(3440,30);
          writeLcd(pin[i],String(pinBlue-1, DEC));
       }
       else if(digitalRead(pinWBrown)){
          beep(1318.5,50);
          writeLcd(pin[i],String(pinBrown-1, DEC));
       }
       else{
          writeLcd(pin[i], "X"); 
          beep(440,300);
       }
       digitalWrite(pin[i], LOW);
       pinMode(pin[i], INPUT);
       delay(500);
    }
  }
  
}

void led(int n, int speed){
      digitalWrite(n, HIGH);
      delay(speed);
      digitalWrite(n, LOW);
      delay(speed/2);
}
void clearLcd(){
  lcd.clear();
  lcd.print("Pins:12345678");
}

void writeLcd(int x1, String ch){
  int position = 4+x1-1;
  lcd.setCursor(position,1);
  lcd.print(ch);
}

void beep(int h, int dly){
  tone(tonePin,h);
  delay(dly);
  noTone(tonePin);
}
