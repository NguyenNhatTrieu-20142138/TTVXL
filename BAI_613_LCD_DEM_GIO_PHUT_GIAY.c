#define   BOARD     D501  
#include<tv_boards.c>
#include<tv_lcd.c>
unsigned int8 bdn=0,giay=45,phut=59,gio=11;
void ht()
{
      lcd_goto(7,0);
      printf(lcd_data,"%02u",gio);
      lcd_goto(9,0);
      lcd_data(":");
      lcd_goto(10,0);
      printf(lcd_data,"%02u",phut);
      lcd_goto(12,0);
      lcd_data(":");
      lcd_goto(13,0);
      printf(lcd_data,"%02u",giay);
}
void main()
{
   system_init();
   lcd_setup();
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   set_timer1(3036);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   while(true)
   {
      if(bdn>=10)
      {
         bdn=bdn-10;
         giay++;
         if(giay>59)
         {
            phut++;
            if(phut>59)
            {
               phut=0;
               gio++;
               if(gio>11)gio=0;
            }
            giay%=60;
         }
         
      }
      ht();
    }
}
#INT_TIMER1
void ngattimer1()
{
   set_timer1(3036);
   bdn++;
}
