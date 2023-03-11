//#define   BOARD     D501
#include<tv_boards.c> 
unsigned int8 T0,T0_TAM=0 ,tt=0;
void tt_nn()
{
         if(inputcd(OFF)==0)
         {
            tt=0;
            setup_timer_0(T0_OFF);
         }
         if(inputcd(ON)==0)  
         {
            tt=1;
            setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);
         }
         if(inputcd(MOD)==0)  
         {
            set_timer0(0);
         }
}
void main()
{
      system_init(); 
      if(T0==0) setup_timer_0(T0_OFF);
      tt_nn();
      while(true)
      {     
         T0=get_timer0();
         if(T0>99) set_timer0(0);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
         }
         s7seg.led[4]=m7d[T0/10%10];
         s7seg.led[3]=m7d[T0%10];
         s7seg_display();
         tt_nn();
      }
}
