#include <LiquidCrystal.h>
#include <LCDBitmap.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LCDBitmap bmp(&lcd, 0, 0);    // Set the bitmap to the &lcd display at character position 0,0.

byte graph[20];
byte bars[] = { 1, 2, 4, 5, 10, 20 };

void setup() {
  lcd.begin(20, 4);            // Initialize the LCD display, do this before you initialize LCDBitmap.
  bmp.begin();                 // Then initialize the LCD bitmap.
  lcd.setCursor(5, 0);
  lcd.print("LCDBitmap");
}

void loop() {
  byte curr_bars = bars[(millis() / 3000) % 6];
  for (byte x = 0; x < curr_bars; x++) {
    graph[x] = random(0, BITMAP_H + 1);
  }
  bmp.barGraph(curr_bars, graph, ON, UPDATE);  // Display the bar graph.
  delay(50);
}
