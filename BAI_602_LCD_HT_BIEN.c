//#define   BOARD     D401  
#include<tv_boards.c>
#include<tv_lcd.c>
unsigned int8 giay=0;
void main()
{
   system_init();
   lcd_setup();
   lcd_goto(0,0); // N?i dung c? d?nh thì d? ngoài while(true)
   lcd_data("HIEN THI BIEN GIAY");
   while(true)
   {
      lcd_goto(9,3);
   lcd_data(giay/10%10 +0x30); // Hi?n th? hàng ch?c c?a giây
   lcd_data(giay%10 +0x30); // Hi?n th? hàng don v? c?a giây
   giay++; // Tang giây
   giay%=60; // Kh?ng ch? giây t? 0 d?n 59
   delay_ms(1000);
   }
}
