#define   BOARD     D501
#include<tv_boards.c>  
unsigned int32 i,k;
void main()
{
      system_init();  
      while(true)
      {  
         for(i=0;i<32;i++)
            for(k=0;k<32-i;k++)
            {
               led32.ledx32=(~(0xffffffff<<i)|(0x80000000>>k));
               led32_display();
               delay_ms(200);
            }
         for(i=0;i<32;i++)
            for(k=0;k<32-i;k++)
            {
               led32.ledx32=(~(0xffffffff>>i)|(0x80000000<<k));
               led32_display();
               delay_ms(200);
            }
      }
}
