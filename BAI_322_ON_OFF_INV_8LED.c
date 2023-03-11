#define   BOARD     D501
#include<tv_boards.c>
unsigned int32 ttled;
void main()
{
      system_init();  
      ttled=0;
      led32.ledx8[0]=ttled;
      led32_display();
      while(true)
      {     
            if(input(ON)==0) 
            {
               ttled=0x0f;
               led32.ledx8[0]=ttled;
            }
            if(input(OFF)==0) 
            {
               ttled=0;
               led32.ledx8[0]=0;
            }
            if(ttled!=0)
               if(input(INV)==0) 
               {
               ttled=~ttled;
               led32.ledx8[0]=ttled;
               }
            led32_display();
               
      }
}

