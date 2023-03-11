//#define   BOARD     D501
#include<tv_boards.c> 
unsigned int8 dem;
void main()
{
      system_init();
      while(true) 
      { 
         if(dem<10)
         {
            d7seg.led[0]=m7d[dem];//hien thi so 0 vi tri ben trai qua
            d7seg_display();
            delay_ms(300);
            dem++;
         }
         else dem=0;
      }
}
  

