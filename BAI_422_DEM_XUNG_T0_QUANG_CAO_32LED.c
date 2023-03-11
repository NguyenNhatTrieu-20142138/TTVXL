#define   BOARD     D501
#include<tv_boards.c>
unsigned int8 T0,T0_TAM;
unsigned int16 l, i, tt, m;
void d7seg_xoa0VN(unsigned int16 d)
{
unsigned int8 m=0;
do
{ d7seg.led[m]= m7d[d%10];
d/=10;m++;
}while(d!=0);
for(;m<4;m++) d7seg.led[m]= 0xff;
d7seg_display();
}
void choptat()
{
   led32.ledx32=0xffffffff;
   led32_display();
   for(i=0;i<1000;i++)
   {
      T0=get_timer0();
      if(T0>101) set_timer0(1);
      if(T0!=T0_TAM)
      {
         T0_TAM=T0;
         d7seg_xoa0VN(T0);
      }
   }
   led32.ledx32=0;
   led32_display();
   delay_ms(200);
   for(i=0;i<1000;i++)
   {
      T0=get_timer0();
      if(T0>101) set_timer0(1);
      if(T0!=T0_TAM)
      {
         T0_TAM=T0;
         d7seg_xoa0VN(T0);
      }
   }
   tt++;
}
void sangtatdan_pst()
{
   for(l=0; l<32; l++)
   {
      led32.ledx32=~(0xffffffff<<l);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   if(l<33)
   for(m=0; m<32; m++)
   {
      led32.ledx32=(0xffffffff<<m);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   tt++;
}
void sangtatdan_tsp()
{
   for(l=0; l<32; l++)
   {
      led32.ledx32=~(0xffffffff>>l);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   if(l<33)
   for(m=0; m<32; m++)
   {
      led32.ledx32=(0xffffffff>>m);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   tt++;
}
void sangtatdan_nvt()            //sang dan ngoai vao trong
{
   for(l=0; l<16; l++)
   {
      led32.ledx16[0]=~(0xffff<<l);
      led32.ledx16[1]=~(0xffff>>l);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   if(l<32)
   for(m=0; m<16; m++)
   {
      led32.ledx16[0]=(0xffff<<m);
      led32.ledx16[1]=(0xffff>>m);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   tt++;
}
void sangtatdan_trn()               //sang dan trong ra ngoai
{
   for(l=0; l<16; l++)
   {
      led32.ledx16[0]=~(0xffff>>l);
      led32.ledx16[1]=~(0xffff<<l);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   if(l<32)
   for(m=0; m<16; m++)
   {
      led32.ledx16[0]=(0xffff>>m);
      led32.ledx16[1]=(0xffff<<m);
      led32_display();
      for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
   }
   tt++;
}
void sangdon_pst()
{
    for(l=0;l<=32;l++) 
    {
       for(m=0;m<32-l;m++) 
       { 
         led32.ledx32= (~(0xffffffff<<l))|(0x80000000>>m); 
         led32_display(); 
         for(i=0;i<1000;i++)
         {
            T0=get_timer0();
            if(T0>101) set_timer0(1);
            if(T0!=T0_TAM)
            {
               T0_TAM=T0;
               d7seg_xoa0VN(T0);
            }
         }
       }
       for(i=0;i<1000;i++)
       {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
       }
    }
    tt++;
}
void sangdon_tsp()
{
    for(l=0;l<=32;l++) 
    {
       for(m=0;m<32-l;m++) 
       { 
         led32.ledx32= (~(0xffffffff>>l))|((int32)1<<m); 
         led32_display();
         for(i=0;i<1000;i++)
         {
            T0=get_timer0();
            if(T0>101) set_timer0(1);
            if(T0!=T0_TAM)
            {
               T0_TAM=T0;
               d7seg_xoa0VN(T0);
            }
         }
       }
       for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
         }
      }
    }
    tt++;
}
void main()
{
   system_init();
   setup_timer_0 (T0_EXT_H_TO_L | T0_DIV_1);
   set_timer0(0);
   tt=0;
   while(true)
   {
      T0=get_timer0();
      if(T0>101) set_timer0(1);
      if(T0!=T0_TAM)
      {
         T0_TAM=T0;
         d7seg_xoa0VN(T0);
      }
      if(tt==7) tt=0;
      if(tt==0) choptat();
      if(tt==1) sangtatdan_pst();
      if(tt==2) sangtatdan_tsp();
      if(tt==3) sangtatdan_nvt();
      if(tt==4) sangtatdan_trn();
      if(tt==5) sangdon_pst();
      if(tt==6) sangdon_tsp();

   }
}
