#define   BOARD     D501
#include<tv_boards.c>  
void main()
{
      system_init();  
      while(true)
      {     
      led32.ledx16[0]=0xffff;
      led32_display();
      delay_ms(500);
      led32.ledx16[0]=0;
      led32_display();
      delay_ms(500);
      }
}
