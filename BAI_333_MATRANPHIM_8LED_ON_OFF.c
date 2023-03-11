#define   BOARD     D501
#include<tv_boards.c>  
#include<tv_key4x4.c> 
void main()
{
      system_init();  
      while(true)
      {     
         if(key4x4_read()==OK)
         {
            if(key4x4.key==0)
            {
               led32.ledx32 = 0x0;
               led32_display();
            }
            else if(key4x4.key==1)
                 {
                    led32.ledx32 = 0x000000ff;
                    led32_display();
                 }
         }
      }
}
