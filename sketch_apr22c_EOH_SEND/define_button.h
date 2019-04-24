/* define_button.h
 * K.A.I. T A K U B O K U
 * 
 * 25 APRIL 31 HEISEI
 *
 *
 *
 *
 *
 */

#define BUTTON_A
#define BUTTON_B
#define BUTTON_X
#define BUTTON_Y
#define BUTTON_UP
#define BUTTON_DOWN
#define BUTTON_LEFT
#define BUTTON_RIZGHT
#define BUTTON_MENU
#define BUTTON_VIEW

void init_pin(){
    pinMode(BUTTON_01,INPUT);
    pinMode(BUTTON_02,INPUT);
    pinMode(BUTTON_03,INPUT);
    pinMode(BUTTON_04,INPUT);
    pinMode(BUTTON_05,INPUT);
    pinMode(BUTTON_06,INPUT);
    pinMode(BUTTON_07,INPUT);
    pinMode(BUTTON_08,INPUT);
    pinMode(BUTTON_09,INPUT);
    pinMode(BUTTON_10,INPUT);
}