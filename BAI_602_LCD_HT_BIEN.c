//#define   BOARD     D401  
#include<tv_boards.c>
#include<tv_lcd.c>
unsigned int8 giay=0;
void main()
{
   system_init();
   lcd_setup();
   lcd_goto(0,0); // N?i dung c? d?nh th� d? ngo�i while(true)
   lcd_data("HIEN THI BIEN GIAY");
   while(true)
   {
      lcd_goto(9,3);
   lcd_data(giay/10%10 +0x30); // Hi?n th? h�ng ch?c c?a gi�y
   lcd_data(giay%10 +0x30); // Hi?n th? h�ng don v? c?a gi�y
   giay++; // Tang gi�y
   giay%=60; // Kh?ng ch? gi�y t? 0 d?n 59
   delay_ms(1000);
   }
}
