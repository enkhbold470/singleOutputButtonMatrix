/*
 * Single Output Button Matrix
 * https://github.com/enkhbold470/singleOutputButtonMatrix
 *
 * Copyright (c) 2023 Enkhbold Ganbold
 * Released under the MIT License
 * https://opensource.org/licenses/MIT
 *
 * Date: October 13, 2023
 */

const int Y = A0;       // Analog pin connected to the button matrix
const int numRows = 6;  
const int numCols = 4;  

int buttonNum[numRows][numCols] = {
  { 1, 2, 3, 4 },
  { 5, 6, 7, 8 },
  { 9, 10, 11, 12 },
  { 13, 14, 15, 16 },
  { 17, 18, 19, 20 },
  { 21, 22, 23, 24 }
};
int buttonVal[numRows][numCols] = {
  { 56, 103, 146, 185 },
  { 111, 198, 269, 330 },
  { 216, 356, 454, 527 },
  { 399, 574, 672, 735 },
  { 652, 797, 860, 896 },
  { 931, 975, 991, 999 }
};


void setup() {
  Serial.begin(9600);
  Serial.println("ON UART");
}

void loop() {
  int analogValue = analogRead(Y);
  // Iterate through each row
  for (int c = 0; c < numCols; c++) {
    for (int r = 0; r < numRows; r++) {
      if (analogValue == buttonVal[r][c]) {
        Serial.print("Row = ");
        Serial.print(r + 1);
        Serial.print(" Col = ");
        Serial.println(c + 1);
        // Serial.print(" buttonNum = ");
        // Serial.println(buttonNum[r][c]);
      }
    }
  }

  delay(250);
}
