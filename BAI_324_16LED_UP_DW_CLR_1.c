#define   BOARD     D501
#include<tv_boards.c>
unsigned int32 ttled;
unsigned int32 i;
void main()
{
      system_init(); 
      i=0;
      ttled=0;
      led32.ledx16[0]=ttled;
      led32_display();
      while(true)
      {     
            if(inputcd(UP)==0) 
            {
               ttled=(ttled<<1)|0x0001;
               led32.ledx16[0]=ttled;
            }
            if(inputcd(DW)==0) 
            {
               ttled=ttled>>1;
               led32.ledx16[0]=ttled;
            }
            if(inputcd(CLR)==0) 
            {
               ttled=0;
               led32.ledx16[0]=ttled;
            }
            led32_display();
               
      }
}
  

