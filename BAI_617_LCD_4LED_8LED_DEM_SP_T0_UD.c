#define   BOARD     D501
#include<tv_boards.c> 
#include<tv_lcd.c>
unsigned int8 T0,T0_TAM=0 ,tt=0;
unsigned int8 cai=55;
void tt_nn()
{
   if(inputcd(clr)==0) cai=1;;
   if(inputcd(up)==0) cai++;
   if(inputcd(dw)==0) cai--;
}
void htd7()
{
         d7seg.led[3]=m7d[cai/10%10];
         d7seg.led[2]=m7d[cai/1%10];
         d7seg.led[1]=m7d[T0/10%10];
         d7seg.led[0]=m7d[T0%10];
         d7seg_display();
         tt_nn();
}
void htlcd()
{
         lcd_goto(3,0);
         printf(lcd_data,"%02u",T0);
         lcd_goto(3,1);
         printf(lcd_data,"%02u",cai);
}
void hts7()
{
         s7seg.led[7]=m7d[cai/10%10];
         s7seg.led[6]=m7d[cai/1%10];
         s7seg.led[1]=m7d[T0/10%10];
         s7seg.led[0]=m7d[T0%10];
         s7seg_display(); 
}
void main()
{
      system_init(); 
      lcd_setup();
      if(T0==100) set_timer0(1);
      while(true)
      {     
         T0=get_timer0();
         htlcd();
         htd7();
         hts7();
         if(T0>101) set_timer0(0);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
         }
      
      }
}
