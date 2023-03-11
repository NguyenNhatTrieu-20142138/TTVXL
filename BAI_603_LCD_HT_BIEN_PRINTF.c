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
      // khi bi?n là unsigned int8 ta dùng %u
      // khi bi?n là signed int8 ta dùng %d
      // khi bi?n là unsigned int16 ta dùng %lu
      // khi bi?n là signed int16 ta dùng %ld
      // khi bi?n là unsigned int32 ta dùng %lu
      // khi bi?n là signed int32 ta dùng %ld
      // khi bi?n là float ta dùng %f
      // trong ví d? trên %02u có nghia bi?n c?n hi?n th? thu?c ki?u
      // unsigned int8 và mu?n l?y 2 s? - không xóa s? 0 vô nghia
      giay++;
      giay%=60;
      delay_ms(1000);
      }
}
