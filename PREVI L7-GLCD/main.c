#include <xc.h>
#define _XTAL_FREQ 8000000
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "GLCD.h"
#include "car.h"
// Move a dot on the screen.
void moveDot(){
   int i;
   SetDot(0,0);
   for(i = 0; i < 50; ++i)__delay_ms(10);
   clearGLCD(0,7,0,127);
   SetDot(0,63);
   for(i = 0; i < 50; ++i)__delay_ms(10);
   clearGLCD(0,7,0,127);
   SetDot(0,127);
   for(int j = 0; j < 50; ++j)__delay_ms(10);
   clearGLCD(0,7,0,127);
   SetDot(31,127);
   for(i = 0; i < 50; ++i)__delay_ms(10);
   clearGLCD(0,7,0,127);
   SetDot(63,127);
   for(int k = 0; k < 50; ++k)__delay_ms(10);
   clearGLCD(0,7,0,127);
   SetDot(63,63);
   for(i = 0; i < 50; ++i)__delay_ms(10);
   clearGLCD(0,7,0,127);
   SetDot(63,0);
   for(int l = 0; l < 53; ++l)__delay_ms(10);
   clearGLCD(0,7,0,127);
}
// Write group names and code
void names(){
   writeTxt(0,0,"ALEXANDRE GRACIA");
   writeTxt(1,0,"CARLES SALVADOR");
   writeTxt(2,0,"POL VALLS");
   writeTxt(3,0,"Grup");
   writeNum(4,0,11);
   writeTxt(5,0,"A");
   for(int i = 0; i < 100; ++i) __delay_ms(10);
}
// Write the image at bitmap array on the screen
void image(){
   /*int pag = 0;
   for(int y = 0; y < 128; ++y) {
      for(int page = 0; page < 8; ++page) {
	 writeByte(page,y,bitmap[pag]);
	 ++pag;
      }
   }
   */
   for (int i=0; i<1024; ++i) writeByte(i / 128, i % 128, bitmap[i]);
   for(int i = 0; i < 100; ++i) __delay_ms(10);
}
// Initialize PORT’s and basic PIC resources
void InitPIC () {
   ADCON1 = 0xFF;
   TRISA = 0x07; //INPUT PORTA[0,2]
}
void main(void) {
InitPIC();
GLCDinit(); // GLCD routines are in rutines_GLCD.C clearGLCD(0, 7, 0, 127);
setStartLine(0);
clearGLCD(0,7,0,127);
// MAIN LOOP
      while (1) {
	 if(PORTA == 0x01) moveDot();
	 if(PORTA == 0x02) names();
	 if(PORTA == 0x04) image();
	 clearGLCD(0,7,0,127);
      }
}