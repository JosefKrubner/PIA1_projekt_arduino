
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define modAut 0
#define modMan 1
#define modOff 2

int pinZarovka=10;
int pinLED=7;
int pinTlac=6;

int del = 1000;
int mod = 0;
int val;
float T;

bool krit;
bool tlac;
bool tlacPom=0;
bool LED;

float Tmax = 60;
float Tmin = 20;
float Tkrit = 80;

float A = 255/(Tmax - Tmin);
float B = A*Tmin;

bool prehod(bool i);

void setup()
{
 	pinMode(pinZarovka, OUTPUT); 
  	pinMode(pinLED, INPUT); 
  	pinMode(pinTlac, INPUT); 
}

void loop()
{
  lcd.begin(16, 2);
  
  krit = 0;
  
  T = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);

  
  if(T>Tmax){
  	krit = 1;}
  
  
  if(mod == modMan){
    val = analogRead(A0)/4;}
  else if(mod == modOff){
    val = 0;}
  else if(T<Tmin){
    val = 0;}
  else if(T>Tmax){
    val = 255;}
  else{
    val = round(A*T-B);}
  
  analogWrite(9,val);
   
  tlac = digitalRead(pinTlac);
  
  if(krit == 0){
    LED = digitalRead(pinLED);}
  
  if (tlac != tlacPom && tlac==1){
  	mod = mod + 1;
    tlacPom = 1;
  }else if(tlac != tlacPom && tlac==0){
    tlacPom = 0;}
  
  if (mod==3){
  	mod = 0;}
  
    if(LED==1){
      digitalWrite(pinZarovka, HIGH);
    }else{
      digitalWrite(pinZarovka, LOW);
    }
  	
  if(krit==1){
  	LED = prehod(LED);}
  
  lcd.setCursor ( 0, 0 );
  lcd.print("T:");
  lcd.print(T);
  lcd.print("C");
  lcd.setCursor ( 0, 1 );
  lcd.print("V:");
    lcd.print(val/2.55);
    lcd.print("%");

    lcd.setCursor ( 10, 0 );
    lcd.print("Mode:");
    switch(mod){
      case modAut:
          lcd.setCursor ( 10, 1 );
          lcd.print("Auto");
          break;
      case modMan:
          lcd.setCursor ( 10, 1 );
          lcd.print("Manual");
          break;
      case modOff:
          lcd.setCursor ( 10, 1 );
          lcd.print("Off");
          break;}
  delay(del/2);
  if (krit == 1){
  	lcd.setCursor ( 0, 1 );
    lcd.print("Temp. too high!!");
  }
  
  if(LED==1){
      digitalWrite(pinZarovka, HIGH);
    }else{
      digitalWrite(pinZarovka, LOW);
    }
  delay(del/2);
  
  if(krit==1){
  	LED = prehod(LED);}
   
}

bool prehod(bool i){
  bool _i = 0;
  if (i == 0){
  	_i=1;}
  return _i;
}