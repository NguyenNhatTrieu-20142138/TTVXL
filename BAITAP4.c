#define   BOARD     D501
#include<tv_boards.c> 
#include<tv_key4x4.c> 
unsigned int16 T0,T0_TAM, dem ;
unsigned int8 sgh,ch,dv;
unsigned int1 tt_d=0;//dem toi
void ktsgh()
{
   if(key4x4_read()==OK)
   {
      if(key4x4.key<10)//vi so hien thi be hown 10
      {
         ch=dv;
         dv=key4x4.key;
         sgh=ch*10+dv;
      }
      if(key4x4.key==13)
      {
         tt_d=~tt_d;
            if(tt_d==0)
            {
               dem++;
            }
            if(tt_d==1)
            {
               dem--;
            }
      }
   }
}
void ht()
{
   d7seg.led[3]=m7d[sgh/10%10];
   d7seg.led[2]=m7d[sgh/1%10]-128;
   d7seg.led[1]=m7d[dem/10%10];
   d7seg.led[0]=m7d[dem/1%10];
   d7seg_display();
}
void main()
{
      system_init(); 
      while(true)
      {     
         T0=get_timer0();
         ktsgh();
         if(T0>99) set_timer0(0);
         if(dem==sgh) setup_timer_0(T0_OFF);
         if(dem!=sgh) setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            if(tt_d==0)
            {
               dem++;
            }
            if(tt_d==1)
            {
               dem--;
            }
         }
         ht();
      }
}
