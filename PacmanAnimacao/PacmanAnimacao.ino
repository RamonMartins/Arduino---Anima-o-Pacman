/* ---> Animação com Pacman v2.0 <---
  
  Esta animação exibe no Display LCD 16x2
  a frase "I (coração) (símbolo do Arduino)"
  e dois fantasmas do jogo do Pacman.
  
  Em 8 segundos o Pacman aparece comendo
  tudo o que esta no Display.
  
  by Ramon M. Ferreira
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

byte coracao[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte arduino1[8] = {
  0b00111,
  0b01000,
  0b10000,
  0b10111,
  0b10000,
  0b01000,
  0b00111,
  0b00000
};

byte arduino2[8] = {
  0b00000,
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001,
  0b00000,
  0b00000
};

byte arduino3[8] = {
  0b11100,
  0b00010,
  0b01001,
  0b11101,
  0b01001,
  0b00010,
  0b11100,
  0b00000
};

byte pacman1[8] = {
  0b01110,
  0b11011,
  0b11110,
  0b11000,
  0b10000,
  0b11111,
  0b11111,
  0b01110
};

byte pacman2[8] = {
  0b01110,
  0b11011,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b01110
};

byte pacman3[8] = {
  0b01110,
  0b11011,
  0b01111,
  0b00011,
  0b00001,
  0b11111,
  0b11111,
  0b01110
};

byte fantasma[8] = {
  B01110,
  B11111,
  B11010,
  B11111,
  B11111,
  B11111,
  B10101,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  pinMode(6,OUTPUT);
  analogWrite(6,60);
  lcd.createChar(0, coracao);
  lcd.createChar(1, arduino1);
  lcd.createChar(2, arduino2);
  lcd.createChar(3, arduino3);
  lcd.createChar(4, pacman1);
  lcd.createChar(5, pacman2);
  lcd.createChar(6, pacman3);
  lcd.createChar(7, fantasma);
}

void loop() {
  lcd.setCursor(6, 0);
  lcd.print("I");
  lcd.print(" ");
  lcd.write(byte(0));
  lcd.setCursor(10, 0);
  lcd.write(byte(7));
  lcd.setCursor(3, 1);
  lcd.write(byte(7));
  lcd.setCursor(6, 1);
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));

  delay(8000);

  pacman();
}

void pacman() {
  for (int col = 3; col < 12; col++) {
    lcd.setCursor(col, 0);
    lcd.write(byte(4));
    tempo();
    lcd.setCursor(col, 0);
    lcd.write(byte(5));
    tempo();
    lcd.setCursor(col, 0);
    lcd.print(" ");
  }

  for (int col = 11; col > 2; col--) {
    lcd.setCursor(col, 1);
    lcd.write(byte(6));
    tempo();
    lcd.setCursor(col, 1);
    lcd.write(byte(5));
    tempo();
    lcd.setCursor(col, 1);
    lcd.print(" ");
  }
}

void tempo() {
  delay(400);
}

