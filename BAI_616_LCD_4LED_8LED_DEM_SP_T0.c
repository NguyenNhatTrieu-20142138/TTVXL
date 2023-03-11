#define   BOARD     D501
#include<tv_boards.c> 
#include<tv_lcd.c>
unsigned int8 T0,T0_TAM=0 ,tt=0;
//!void tt_nn()
//!{
//!         if(inputcd(OFF)==0)
//!         {
//!            tt=0;
//!            setup_timer_0(T0_OFF);
//!         }
//!         if(inputcd(ON)==0)  
//!         {
//!            tt=1;
//!            setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);
//!         }
//!         if(inputcd(MOD)==0)  
//!         {
//!            set_timer0(0);
//!         }
//!}
void main()
{
      system_init(); 
      lcd_setup();
      if(T0==100) set_timer0(0);
      while(true)
      {     
         T0=get_timer0();
         lcd_goto(3,0);
         printf(lcd_data,"%02u",T0);
         d7seg.led[2]=m7d[T0/100%10];
         d7seg.led[1]=m7d[T0/10%10];
         d7seg.led[0]=m7d[T0%10];
         d7seg_display();
         s7seg.led[2]=m7d[T0/100%10];
         s7seg.led[1]=m7d[T0/10%10];
         s7seg.led[0]=m7d[T0%10];
         s7seg_display();
         if(T0>101) set_timer0(0);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
         }
      
      }
}
