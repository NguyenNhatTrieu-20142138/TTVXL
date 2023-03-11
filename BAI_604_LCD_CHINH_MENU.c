#define   BOARD     D501  
#include<tv_boards.c>
#include<tv_lcd.c>
UNSIGNED INT32 i;
UNSIGNED INT16 giay;
UNSIGNED INT1 ttinv=0;
void nn_inv()
{
   if(inputcd(inv)==0) ttinv=~ttinv;//=0 dem len;=1 dem xuong
}
void main()
{
   system_init();
   lcd_setup();
      lcd_goto(0,0);
      lcd_data("BAI TAP CHINH MENU");
      lcd_goto(1,1);
      lcd_data("DEM LEN");
      lcd_goto(1,2);
      lcd_data("DEM XUONG");

   while(true)
   {
         nn_inv();
         if(ttinv==0)
         {
            lcd_goto(0,1);
            lcd_data(0x7E);
            lcd_goto(0,2);
            lcd_data(0x20);
            giay++;
            giay%=60;
            lcd_goto(9,3);
            printf(lcd_data,"%2lu",giay);
            for(i=0;i<10000;i++) nn_inv();
         }
         if(ttinv==1)
         {
            lcd_goto(0,2);
            lcd_data(0x7E);
            lcd_goto(0,1);
            lcd_data(0x20);
            giay--;
            if(giay==0)giay=60;
            lcd_goto(9,3);
            printf(lcd_data,"%2lu",giay);
            for(i=0;i<10000;i++) nn_inv();
         }
      }

   }
