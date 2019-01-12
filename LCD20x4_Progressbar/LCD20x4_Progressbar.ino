#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // -- creating LCD instance

int lcdCols = 16;
int lcdRows = 2;
unsigned long startTime, finishedTime, elapsedTime;

//Create the progress bar characters
byte percent20[8] = {  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,};
byte percent40[8] = {  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,};
byte percent60[8] = {  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,};
byte percent80[8] = {  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,};
byte percent100[8] = { B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,};

void setup() {
  startTime = millis();
  //Set up the LCDs number of columns and rows:
  lcd.begin(lcdCols, lcdRows);

  //save created custom characters for progressbar percentage with corresponding indexes
  lcd.createChar(0, percent20);
  lcd.createChar(1, percent40);
  lcd.createChar(2, percent60);
  lcd.createChar(3, percent80);
  lcd.createChar(4, percent100);

  finishedTime = millis();
  elapsedTime = finishedTime - startTime;
  intialize(elapsedTime);
}


void intialize(long delayTime) {

  //Iterate through each character on the second line
  for (int i = 0; i < lcdCols; i++) {
    int percent = (100.0 * i) / lcdCols;  //lets calculate percentage by current column index
    lcd.setCursor(0, 0);
    lcd.print("Initializing...");
    //lcd.setCursor(16, 0);
    lcd.print(percent);
    lcd.print("%");

    //Move cursor to second line where progressbar rows created
    lcd.setCursor(0, 1);
    //Iterate through each progress value for each character
    for (int j = 0; j < 5; j++) {
      lcd.setCursor(i, 1); //Move the cursor to this location
      lcd.write(j);        //update progress bar
      //delay(delayTime);          //wait
      delay(100);  //create dummy waiting time because as we can see, it takes only 0 ms during setup method initialization
    }
  }
  lcd.clear();
}

void loop() {
  intialize(elapsedTime);
  lcd.home();
  lcd.print("Finished...");
  lcd.print(elapsedTime);
  lcd.print("ms");
   delay(1000);
}


