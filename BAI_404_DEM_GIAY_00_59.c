//#define   BOARD     D501
#include<tv_boards.c> 
unsigned int8 dem;
unsigned int8 ch,dv;
void main()
{
      system_init();
      while(true) 
      { 
         for(dem=0;dem<59;dem++)
         {
            ch=dem/10%10;
            dv=dem%10;
            d7seg.led[1]=m7d[ch];//hien thi so hang chuc
            d7seg.led[0]=m7d[dv];
            d7seg_display();
            delay_ms(1000);
         }
      }
}
  

