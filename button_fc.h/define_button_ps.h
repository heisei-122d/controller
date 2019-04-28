/* define_button_ps.h
 * tari@Shinchoku_Home122d
 * 
 * 26 APRIL 31 HEISEI
 */

//DEFINE number_pin
#define BUTTON_CIRCLE 
#define BUTTON_CROSS 
#define BUTTON_SQUARE
#define BUTTON_TRIANGLE
#define BUTTON_UP
#define BUTTON_DOWN
#define BUTTON_LEFT
#define BUTTON_RIGHT
#define BUTTON_START
#define BUTTON_SELECT

void init_pin(){
    pinMode(BUTTON_CIRCLE,INPUT);
    pinMode(BUTTON_CROSS,INPUT);
    pinMode(BUTTON_SQUARE,INPUT);
    pinMode(BUTTON_TRIANGLE,INPUT);
    pinMode(BUTTON_UP,INPUT);
    pinMode(BUTTON_DOWN,INPUT);
    pinMode(BUTTON_LEFT,INPUT);
    pinMode(BUTTON_RIGHT,INPUT);
    pinMode(BUTTON_START,INPUT);
    pinMode(BBUTTON_SELECT,INPUT);
}
