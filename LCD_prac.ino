#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD I2C address and size (16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the lyrics
String lyrics[] = {
  "I am the one",
  "who's  waited",
  "this looonngg",
  "and I am the one",
  "That might get",
  "it wronggg",
  "and I'll be the",
  "one that will",
  "love you the way",
  "I'm supposed to",
  "oohhhh girlll"
};

const int lineCount = sizeof(lyrics) / sizeof(lyrics[0]);
int currentLine = 0;

void setup() {
  lcd.init();            // Initialize LCD
  lcd.backlight();       // Turn on backlight
}

void loop() {
  lcd.clear();

  // Print first line word by word
  lcd.setCursor(0, 0);
  printWords(lyrics[currentLine], 0);

  // Print second line if it exists
  if (currentLine + 1 < lineCount) {
    lcd.setCursor(0, 1);
    printWords(lyrics[currentLine + 1], 1);
  }

  delay(2500); // Wait before showing next lines

  currentLine += 2;
  if (currentLine >= lineCount) {
    delay(2000); // Wait longer at the end
    currentLine = 0;
  }
}

// ✅ Function to print words one by one with delay
void printWords(String line, int row) {
  int start = 0;
  int x = 0;

  while (start < line.length()) {
    int space = line.indexOf(' ', start);
    if (space == -1) space = line.length();
    String word = line.substring(start, space);

    if (x + word.length() > 16) break; // Skip if word won't fit on line

    lcd.setCursor(x, row);
    lcd.print(word + " ");
    x += word.length() + 1;
    start = space + 1;
    delay(300); // Delay between words
  }
}
