#define   BOARD     D501
#include<tv_boards.c>  
unsigned int32 i;
unsigned int32 dichled32;
void main()
{
      system_init();  
      while(true)
      {  
         dichled32=0;
         for(i=0;i<32;i++)
         {
            dichled32=(dichled32>>1)|0x80000000;
            led32.ledx32=dichled32;
            led32_display();
            delay_ms(200);
         }
         for(i=0;i<32;i++)
         {
            dichled32=(dichled32>>1);
            led32.ledx32=dichled32;
            led32_display();
            delay_ms(200);
         }
      }
}
