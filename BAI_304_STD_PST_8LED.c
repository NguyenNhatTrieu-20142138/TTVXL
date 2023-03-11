#define   BOARD     D501
#include<tv_boards.c>  
unsigned int8 i;
void main()
{
      system_init();  
      while(true)
      {  
         for(i=0;i<8;i++)
         {
            led32.ledx8[0]=~(0xffff<<i);
            led32_display();
            delay_ms(500);
         }
         for(i=0;i<8;i++)
         {
            led32.ledx8[0]=0xffff<<i;
            led32_display();
            delay_ms(500);
         }
      }
}
