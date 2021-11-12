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
  
  pinMode(0, INPUT_PULLUP);
  
  pinMode(pinOrange, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinBrown, OUTPUT);

  pinMode(tonePin, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.home();
  lcd.print("Pins:12345678");


}

void loop() {

  if(digitalRead(11)){
    while(true){
      if(!digitalRead(11)){
         break;
      }
    }
    clearLcd();
    for(int i = 0; i < 4; i++){
       digitalWrite(pin[i], HIGH);
//       if(digitalRead(wpin[i])){
//          writeLcd(wpin[i],String(wpin[i], DEC));
//          beep(3440,30);
//       }
//       else{
//          writeLcd(wpin[i], "X"); 
//          beep(440,300);
//       } 
       if(digitalRead(pinWOrange)){
          beep(3440,30);
          writeLcd(wpin[i],String(pinWOrange, DEC));
       }
       else if(digitalRead(pinWGreen)){
          beep(3440,30);
          writeLcd(wpin[i],String(pinWGreen, DEC));
          
       }
       else if(digitalRead(pinWBlue)){
          beep(3440,30);
          writeLcd(wpin[i],String(pinWBlue, DEC));
       }
       else if(digitalRead(pinWBrown)){
          beep(1318.5,50);
          writeLcd(wpin[i],String(pinWBrown, DEC));
       }
       else{
          writeLcd(wpin[i], "X"); 
          beep(440,300);
       }
       digitalWrite(pin[i], LOW);
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
  int position = 4+x1;
  lcd.setCursor(position,1);
  Serial.print(position);
  lcd.print(ch);
}

void beep(int h, int dly){
  tone(tonePin,h);
  delay(dly);
  noTone(tonePin);
}
