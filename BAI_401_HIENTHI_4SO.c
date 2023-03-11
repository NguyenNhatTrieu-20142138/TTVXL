//#define   BOARD     D501
#include<tv_boards.c> 

void main()
{
      system_init();
      d7seg.led[0]=m7d[0];//hien thi so 0 vi tri ben trai qua
      d7seg.led[1]=m7d[1];
      d7seg.led[2]=m7d[2];
      d7seg.led[3]=m7d[3];
      d7seg_display();
      delay_ms(3000);
      while(true) 
      { 

      }
}
  

