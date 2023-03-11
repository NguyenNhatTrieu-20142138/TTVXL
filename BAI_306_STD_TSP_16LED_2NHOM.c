#define   BOARD     D501
#include<tv_boards.c>  
unsigned int16 i,k;
unsigned int16 dichled161,dichled160;
void main()
{
      system_init();  
      while(true)
      {  
         i=0;
         k=0;
         led32.ledx8[0]=0;
         led32_display();
         delay_ms(500);
         dichled160=0;
         dichled161=0;
         for(i=0;i<16;i++)
         {
            dichled160=(dichled160<<1)|0x01;
            led32.ledx16[0]=dichled160;
            dichled161=(dichled161<<1)|0x01;
            led32.ledx16[1]=dichled161;
            led32_display();
            delay_ms(500);
            
         }
         for(k=0;k<16;k++)
         {
            dichled160=(dichled160<<1);
            led32.ledx16[0]=dichled160;
            dichled161=(dichled161<<1);
            led32.ledx16[1]=dichled161;
            led32_display();
            delay_ms(500);
            
         }
         
      }
}
