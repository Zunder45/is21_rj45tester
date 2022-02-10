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

int pins[] = {
             pinWOrange,
             pinWGreen,
             pinWBlue,
             pinWBrown,
             pinOrange,
             pinGreen,
             pinBlue,
             pinBrown
             
};


String textStartscreen[2] = {"LAN tester v3.0","IS-21|2022|O.D."};
String textFirstLine = "Pins:12345678";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  startscreen();
  Serial.begin(9600);
  
  pinMode(bttPin, INPUT_PULLUP);
  pinMode(tonePin, OUTPUT);

  delay(4000);
  endStartscreen();
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
      beginWrite(pins[i]);

      if(digitalRead(pins[i+4])){
          writeLcd(pins[i],String(pins[i+4]-1, DEC)); 
          writeLcd(pins[i]-1,String(pins[i+4]-2, DEC)); 
          beep(3440,30);
      }
      else{
          writeLcd(pins[i],"X"); 
          writeLcd(pins[i]-1,"X");
          beep(440,300); 
      }
      endingWrite(pins[i]); 
      delay(500); 
    }
 
    
      
  }
}

//int testOthersPins(int ignorePin){
//  for(int i = 0; i < sizeof(pins); i++){
//     if(pins[i] != ignorePin){
//      if(digitalRead(pins[i])){
//        return i; 
//      }
//     }
//  }
//  return false;
//}

void startscreen(){
  lcd.begin();
  lcd.backlight();
  lcd.home();

  lcd.print(textStartscreen[0]);
  lcd.setCursor(0,1);
  lcd.print(textStartscreen[1]);
}

void endStartscreen(){
  clearLcd();
}



void endingWrite(int pin){
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW); 
}
void beginWrite(int pin){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void led(int n, int speed){
  digitalWrite(n, HIGH);
  delay(speed);
  digitalWrite(n, LOW);
  delay(speed/2);
}
void clearLcd(){
  lcd.clear();
  lcd.home();
  lcd.print(textFirstLine);
}

void writeLcd(int x1, String ch){
  int position = 4+x1;
  lcd.setCursor(position,1);
  lcd.print(ch);
}

void beep(int h, int dly){
  tone(tonePin,h);
  delay(dly);
  noTone(tonePin);
}
