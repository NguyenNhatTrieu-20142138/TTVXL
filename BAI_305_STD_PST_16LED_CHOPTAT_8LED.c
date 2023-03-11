#define   BOARD     D501
#include<tv_boards.c>  
unsigned int16 i,k;
unsigned int16 dichled16;
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
         dichled16=0;
         for(i=0;i<16;i++)
         {
            dichled16=(dichled16<<1)|0x01;
            led32.ledx16[0]=dichled16;
            led32_display();
            delay_ms(500);
            led32.ledx8[3]=0xff;
            led32_display();
            delay_ms(500);
            led32.ledx8[3]=0;
            led32_display();
            delay_ms(500);
         }
         for(k=0;k<16;k++)
         {
            dichled16=(dichled16<<1);
            led32.ledx16[0]=dichled16;
            led32_display();
            delay_ms(500);
            led32.ledx8[3]=0xff;
            led32_display();
            delay_ms(500);
            led32.ledx8[3]=0;
            led32_display();
            delay_ms(500);
         }
         
      }
}
