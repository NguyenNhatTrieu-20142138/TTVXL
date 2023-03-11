//#define   BOARD     D501
#include<tv_boards.c>  
#include<tv_key4x4.c> 
unsigned int8 ht[8]={0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f};
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
            if(va<10)
            {
               ht[7]=ht[6];
               ht[6]=ht[5];
               ht[5]=ht[4];
               ht[4]=ht[3];
               ht[3]=ht[2];
               ht[2]=ht[1];
               ht[1]=ht[0];
               ht[0]=m7d[va];
            }
            if(va==11)//truong hop nay co 4 cap neu co nhieu hon thi khai bao mang bu hon vd 5 cap thi mang 10
            {
               ht[0]=ht[1];
               ht[1]=ht[2];
               ht[2]=ht[3];
               ht[3]=ht[4];
               ht[4]=ht[5];
               ht[5]=ht[6];
               ht[6]=ht[7];
               ht[7]=0x7f;
            }
            if(va==12)//xoa het va dau .
            {
               ht[0]=0x7f;
               ht[1]=0x7f;
               ht[2]=0x7f;
               ht[3]=0x7f;
               ht[4]=0x7f;
               ht[5]=0x7f;
               ht[6]=0x7f;
               ht[7]=0x7f;
            }
               d7seg.led[0]=ht[0];
               d7seg.led[1]=ht[1];
               d7seg.led[2]=ht[2];
               d7seg.led[3]=ht[3];
               d7seg_display();
               
         }
      }
}
