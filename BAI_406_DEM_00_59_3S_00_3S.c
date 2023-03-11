//#define   BOARD     D501
#include<tv_boards.c> 
signed int8 dem;
void main()
{
      system_init();
      while(true) 
      { 
         do
         {
            d7seg.led[0]=m7d[dem/1%10];
            d7seg.led[1]=m7d[dem/10%10];
            d7seg_display();
            delay_ms(200);
            dem++;
         }
         while(dem<60);
         delay_ms(3000);
         dem=59;
         do
         {
            d7seg.led[0]=m7d[dem/1%10];
            d7seg.led[1]=m7d[dem/10%10];
            d7seg_display();
            delay_ms(200);
            dem--;
         }
         while(dem>=0);
         delay_ms(3000);
      }
}
  

