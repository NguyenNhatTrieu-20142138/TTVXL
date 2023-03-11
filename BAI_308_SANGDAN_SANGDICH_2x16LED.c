#define   BOARD     D501
#include<tv_boards.c>  
unsigned int16 i;
unsigned int16 dichled161,dichled160;
void main()
{
      system_init();  
      while(true)
      {  
         i=0;
         dichled161=0;
         dichled160=0x0001;
         led32.ledx16[1]=0;
         led32.ledx16[0]=0x0001;
         for(i=0;i<16;i++)
         {
         dichled161=(dichled161>>1)|0x8000;
         led32.ledx16[1]=dichled161;
         dichled160=dichled160<<1;
         led32.ledx16[0]=dichled160;
         led32_display();
         delay_ms(500);
         }
         dichled160=0x0001;
         led32.ledx16[0]=0x0001;
         led32_display();
         delay_ms(500);
         for(i=0;i<16;i++)
         {
         dichled161=(dichled161>>1);
         led32.ledx16[1]=dichled161;
         dichled160=dichled160<<1;
         led32.ledx16[0]=dichled160;
         led32_display();
         delay_ms(500);
         }
      }
}
