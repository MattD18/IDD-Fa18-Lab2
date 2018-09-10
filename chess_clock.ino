// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int  player_one_buttonPin = 7;
int player_one_buttonState = 0;  
const int  player_two_buttonPin = 8;
int player_two_buttonState = 0; 

const int game_length = 15;
int player_one_time_elapsed = 0;
int player_two_time_elapsed = 0;
bool player_one_turn = true;
bool game_over = false;

void setup() {
  // set up the buttons
  pinMode(player_one_buttonPin, INPUT);
  pinMode(player_two_buttonPin, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Initialize player 1
  lcd.setCursor(0, 0);
  lcd.print("Player1");
  lcd.setCursor(2, 1);
  lcd.print(game_length);
  // Initialize player 1
  lcd.setCursor(9,0);
  lcd.print("Player2");
  lcd.setCursor(11, 1);
  lcd.print(game_length);
}

void loop() {
  player_one_buttonState = digitalRead(player_one_buttonPin);
  player_two_buttonState = digitalRead(player_two_buttonPin);
  // compare the buttonState to its previous state
  if (player_two_buttonState == HIGH and not(player_one_turn) and not(game_over)) {
    player_one_turn = not(player_one_turn);
  }
  if (player_one_buttonState == HIGH and player_one_turn and not(game_over)) {
    player_one_turn = not(player_one_turn);
  }
  
  //toggle players
  if (not(game_over)){
    if (player_one_turn){
        lcd.setCursor(2, 1);
        lcd.print(game_length - millis() / 1000 + player_two_time_elapsed);
        player_one_time_elapsed = (millis() / 1000) - player_two_time_elapsed;
        if ((game_length - player_one_time_elapsed) < 100){
          lcd.setCursor(4,1);
          lcd.print(" ");
        }
        if ((game_length - player_one_time_elapsed) < 10){
          lcd.setCursor(3,1);
          lcd.print(" ");
        }
        if ((game_length - player_one_time_elapsed) < 0){
          game_over = true;
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Player 2 Wins!");
        }
    }
    else{
        lcd.setCursor(11, 1);
        lcd.print(game_length - millis() / 1000 + player_one_time_elapsed);
        player_two_time_elapsed = (millis() / 1000) - player_one_time_elapsed;
        if ((game_length - player_two_time_elapsed) < 100){
          lcd.setCursor(13,1);
          lcd.print(" ");
        }
        if ((game_length - player_two_time_elapsed) < 10){
          lcd.setCursor(12,1);
          lcd.print(" ");
        }
        if ((game_length - player_two_time_elapsed) < 0){
          game_over = true;
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Player 1 Wins!");
        }
    }
  }
}
