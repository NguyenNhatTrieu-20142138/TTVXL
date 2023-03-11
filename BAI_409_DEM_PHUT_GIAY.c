#define   BOARD     D501
#include<tv_boards.c> 
unsigned int32 ph,gi;
void main()
{
      system_init();
      ph=0;
      while(true) 
      { 
         for(gi=0;gi<60;gi++)
         {
            
            d7seg.led[0]=m7d[gi%10];
            d7seg.led[1]=m7d[gi/10%10];
            d7seg.led[2]=m7d[ph%10]-128;
            d7seg.led[3]=m7d[ph/10%10];
            d7seg_display();
            delay_ms(50);
         }
         if(gi==60)
         {
            ph++;
         }
         if(ph==60)
         {
            ph=0;
         }
      }
}
  

