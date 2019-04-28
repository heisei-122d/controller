/* define_button_xb.h
   tari@Shinchoku_Home122d

   25 APRIL 31 HEISEI
*/

//DEFINE number_pin
#define BUTTON_A 34
#define BUTTON_B 35
#define BUTTON_X 32
#define BUTTON_Y 33
#define BUTTON_UP 25
#define BUTTON_DOWN 26
#define BUTTON_LEFT 27
#define BUTTON_RIGHT 14
#define BUTTON_MENU 12
#define BUTTON_VIEW 13

void init_pin() {
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_X, INPUT);
  pinMode(BUTTON_Y, INPUT);
  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_DOWN, INPUT);
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);
  pinMode(BUTTON_MENU, INPUT);
  pinMode(BUTTON_VIEW, INPUT);
}
