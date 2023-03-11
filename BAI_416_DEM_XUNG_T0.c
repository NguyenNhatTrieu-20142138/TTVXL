//#define   BOARD     D501
#include<tv_boards.c> 
unsigned int32 T0,T0_TAM ;
unsigned int8 sgh,ch,dv; 
void ht()
{
   d7seg.led[3]=0xff;//so gioi han
   d7seg.led[2]=0xff;
   d7seg.led[1]=0xff;//dem
   d7seg.led[0]=0xff;
   d7seg_display();
}
void main()
{
      system_init(); 
      setup_timer_0 (t0_ext_l_to_h | t0_div_1);
      set_timer0(9998);
      while(true)
      {     
         T0=get_timer0();
         if(T0>99) set_timer0(0);
         if(key4x4_read()==OK)//ban phim ma tran quet xong
         {
            if(key4x4.key<10)
            {
               
            }
         }
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
         }
      }
     
}
