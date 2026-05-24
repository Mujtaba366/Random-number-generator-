# Arduino LCD Random Number Generator

A simple project using a 16x2 LCD and Arduino Nano that displays a random number and updates it every few seconds with a countdown timer.

---

## Features

- Displays a random number on a 16x2 LCD
- Countdown timer until next number update
- Updates every 1 second
- Uses Arduino Nano + HD44780 LCD
- No external libraries needed except LiquidCrystal

---

## Components

- Arduino Nano
- 16x2 LCD (HD44780 compatible)
- 10k potentiometer (for contrast)
- Breadboard
- Jumper wires

---

## Wiring

### LCD to Arduino Nano

| LCD Pin | Arduino Pin |
|--------|------------|
| VSS    | GND        |
| VDD    | 5V         |
| V0     | Middle pin of potentiometer |
| RS     | D12        |
| RW     | GND        |
| E      | D10        |
| D4     | D2         |
| D5     | D3         |
| D6     | D4         |
| D7     | D5         |

### Potentiometer

- One side → 5V  
- Other side → GND  
- Middle → V0 (LCD contrast)

---

## Code

Upload this using Arduino IDE:

```cpp
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

  if (now - lastUpdate >= 1000) {
    lastUpdate = now;

    countdown--;

    if (countdown <= 0) {
      countdown = 10;
      number = random(0, 1000);
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
