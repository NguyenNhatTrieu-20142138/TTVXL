//#define   BOARD     D401  
#include<tv_boards.c>
#include<tv_lcd.c>
unsigned int8 giay=0;
void main()
{
      system_init();
      lcd_setup();
      lcd_goto(0,0);
      lcd_data("HIEN THI BIEN GIAY");
      while(true)
      {
      lcd_goto(9,3);
      printf(lcd_data,"%02u",giay);
      // khi bi?n l� unsigned int8 ta d�ng %u
      // khi bi?n l� signed int8 ta d�ng %d
      // khi bi?n l� unsigned int16 ta d�ng %lu
      // khi bi?n l� signed int16 ta d�ng %ld
      // khi bi?n l� unsigned int32 ta d�ng %lu
      // khi bi?n l� signed int32 ta d�ng %ld
      // khi bi?n l� float ta d�ng %f
      // trong v� d? tr�n %02u c� nghia bi?n c?n hi?n th? thu?c ki?u
      // unsigned int8 v� mu?n l?y 2 s? - kh�ng x�a s? 0 v� nghia
      giay++;
      giay%=60;
      delay_ms(1000);
      }
}
