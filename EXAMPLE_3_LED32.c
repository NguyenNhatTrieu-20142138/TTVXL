
//#define   BOARD     D503
#include<tv_boards.c>  
unsigned int32 i,k,l,m,n,e,f,g,h;
unsigned int32 hu10,hu11;//sang dan tu trai sang phai
unsigned int32 hu20,hu21;//sang dan tu phai sang trai
unsigned int32 hu30,hu31;//sang tu trong ra ngoai
unsigned int32 hu40,hu41;//sang tu ngoai vao trong
unsigned int32 hu50,hu51;//4 led chayj tu trai sang phai
unsigned int32 hu60,hu61;//4 led chayj tu phai sang trai
unsigned int32 hu70,hu71;//sang 24 led chop tat 5 lan
unsigned int32 hu80,hu81;//sang ben trai va phai lan luot 5 lan
unsigned int32 hu90,hu91;//12 led ben trai sang tu trai vao, ben phai la tu trai vao 
unsigned int32 hue0,hue1;// nguoc lai so 9
void main()
{
      system_init();  
      while(true)
      {     
         hu10=0;//de led tat het
         for(i=0;i<24;i++)
         {
            hu10=(hu10>>1)|0x08000000;
            led32.
         }
      }
}
