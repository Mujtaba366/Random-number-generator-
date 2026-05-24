#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 2, 3, 4, 5);

unsigned long lastUpdate = 0;
int countdown = 10;
int number = 0;

void setup() {
  lcd.begin(16, 2);
  randomSeed(analogRead(A0));
  number = random(0, 1000);
}

void loop() {
  unsigned long now = millis();

  if (now - lastUpdate >= 1000) { // 1 second delay
    lastUpdate = now;

    countdown--;

    if (countdown <= 0) {
      countdown = 10;              // reset timer
      number = random(0, 1000);    // new number
    }

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Num: ");
    lcd.print(number);

    lcd.setCursor(0, 1);
    lcd.print("Next: ");
    lcd.print(countdown);
    lcd.print("s");
  }
}
