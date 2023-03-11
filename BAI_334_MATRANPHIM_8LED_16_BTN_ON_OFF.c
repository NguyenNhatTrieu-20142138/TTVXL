//#define   BOARD     D501
#include<tv_boards.c>  
#include<tv_key4x4.c> 
void main()
{
      system_init();  
      while(true)
      {     
         if(key4x4_read()==OK)
         {

                  led32.ledx1[key4x4.key+24]=1;
                  led32_display();
                  led32.ledx1[key4x4.key+16]=0;
                  led32_display();
         }
      }
}
