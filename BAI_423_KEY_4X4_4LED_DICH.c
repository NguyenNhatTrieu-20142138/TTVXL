//#define   BOARD     D501
#include<tv_boards.c>  
#include<tv_key4x4.c> 
unsigned int8 ht[5]={0x7f,0x7f,0x7f,0x7f,0xff};
unsigned int8 va;
void main()
{
      system_init();
      d7seg.led[0]=ht[0];
      d7seg.led[1]=ht[1];
      d7seg.led[2]=ht[2];
      d7seg.led[3]=ht[3];
      d7seg_display();
      while(true)
      {
         if(key4x4_read()==OK)
         {
            va= key4x4.key;
            ht[4]=ht[3];
            ht[3]=ht[2];
            ht[2]=ht[1];
            ht[1]=ht[0];
            ht[0]=m7d[va];
            d7seg.led[0]=ht[0];
            d7seg.led[1]=ht[1];
            d7seg.led[2]=ht[2];
            d7seg.led[3]=ht[3];
            d7seg_display();
         }
      }
}
