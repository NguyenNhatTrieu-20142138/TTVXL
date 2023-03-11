#define   BOARD     D501
#include<tv_boards.c>
unsigned int32 ttled;
int1 k;
void main()
{
      system_init(); 
      k=0;
      ttled=0;
      led32.ledx16[0]=ttled;
      led32_display();
      while(true)
      {     
            if(inputcd(CLR)==0) 
            {
               k=~k;
               ttled=0;
               led32.ledx16[0]=ttled;
            }
            if(k==0)
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
            }
            else
            {
               if(inputcd(UP)==0) 
               {
                  ttled=(ttled>>1)|0x8000;
                  led32.ledx16[0]=ttled;
               }
               if(inputcd(DW)==0) 
               {
                  ttled=ttled<<1;
                  led32.ledx16[0]=ttled;
               }
            }
            led32_display();
               
      }
}
  

