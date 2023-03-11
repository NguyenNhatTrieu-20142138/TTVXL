//#define   BOARD     D503
#include<tv_boards.c>
unsigned int32 i,k;
unsigned int32 sdpst,tdpst;
void main()
{  
   sdpst=0;
   k=0;
   i=0;
   while(true)
   {  
      if(k<1)
         {
         if(i<32)
         {
            sdpst=(sdpst>>1)|0x80000000;
            led32.ledx32=sdpst;
            led32_display();
            delay_ms(200);
            i++;
         }
         else
         {
         k++;
         i=0;
         }
      }
      else
      {
         if(i<32)
         {
            sdpst=(sdpst>>1);
            led32.ledx32=sdpst;
            led32_display();
            delay_ms(200);
            i++;
         }
         else
         {
         k--;
         i=0;
         }   
      }
   }
}
