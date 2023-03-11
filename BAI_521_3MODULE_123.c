#define   BOARD     D501
#include<tv_boards.c>
unsigned int8 giay=0,bdn=0,phut=0,gio=0;
unsigned int8 g=0,p=0,gi=0,va;
unsigned int8 tt_mod=0,tt_ud;
unsigned int8 tat[2]={0xff,0xff};
void tt_nn()
{
    if(inputcd(MOD)==0)
    {
      tt_mod++;
      if(tt_mod>3) tt_mod=0;
    }
    if(tt_mod==0)
    {
      g=0;
      p=0;
      gi=0;
    }
    if(tt_mod==1)
    {
      g=128;
      p=0;
      gi=0;
      if(inputcd(UP)==0) giay++;
      if(inputcd(DW)==0) giay--;
      if(giay>59) 
         {
            phut++;
            giay%=10;
         }
         if(phut>59)
         {
            gio++;
            phut%=10;
            giay%=10;
         }
         if(gio>12)
         {
            gio=0;
            phut%=10;
            giay%=10;
         }
    }
    if(tt_mod==2)
    {
      g=0;
      p=128;
      gi=0;
      if(inputcd(UP)==0) phut++;
      if(inputcd(DW)==0) phut--;
      if(giay>59) 
         {
            phut++;
            giay%=10;
         }
         if(phut>59)
         {
            gio++;
            phut%=10;
            giay%=10;
         }
         if(gio>12)
         {
            gio=0;
            phut%=10;
            giay%=10;
         }
    }
    if(tt_mod==3)
    {
      g=0;
      p=0;
      gi=128;
      if(inputcd(UP)==0) gio++;
      if(inputcd(DW)==0) gio--;
      if(giay>59) 
         {
            phut++;
            giay%=10;
         }
         if(phut>59)
         {
            gio++;
            phut%=10;
            giay%=10;
         }
         if(gio>12)
         {
            gio=0;
            phut%=10;
            giay%=10;
         }
    }
}
void nn_giay()
{
      s7seg.led[7] = m7d[gio/10%10]; // nhapnhay
      s7seg.led[6] = m7d[gio%10]; // nhapnhay
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = 0xff; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = 0xff; // Gi?i mã hàng don v? c?a giây
      for(va=0;va<50;va++) 
      {
         s7seg_display();// Quét LED
         tt_nn();
      }
      s7seg.led[7] = m7d[gio/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[6] = m7d[gio%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      for(va=0;va<50;va++) 
      {
         s7seg_display();// Quét LED
         tt_nn();
      }
}
void nn_phut()
{
      s7seg.led[7] = m7d[gio/10%10]; // nhapnhay
      s7seg.led[6] = m7d[gio%10]; // nhapnhay
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = 0xff; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = 0xff; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      for(va=0;va<50;va++) 
      {
         s7seg_display();// Quét LED
         tt_nn();
      }
      s7seg.led[7] = m7d[gio/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[6] = m7d[gio%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      for(va=0;va<50;va++) 
      {
         s7seg_display();// Quét LED
         tt_nn();
      }
}
void nn_gio()
{
      s7seg.led[7] = 0xff; // nhapnhay
      s7seg.led[6] = 0xff; // nhapnhay
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      for(va=0;va<50;va++) 
      {
         s7seg_display();// Quét LED
         tt_nn();
      }
      s7seg.led[7] = m7d[gio/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[6] = m7d[gio%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      for(va=0;va<50;va++) 
      {
         s7seg_display();// Quét LED
         tt_nn();
      }
}
void ht()
{
      s7seg.led[7] = m7d[gio/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[6] = m7d[gio%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      s7seg_display();
      tt_nn();
}
void dongho()
{
   tt_nn();
      if(bdn>=10) 
      {
         bdn=bdn-10;
         giay++;
         if(giay>59) 
         {
            phut++;
            giay%=10;
         }
         if(phut>59)
         {
            gio++;
            phut%=10;
            giay%=10;
         }
         if(gio>12)
         {
            gio=0;
            phut%=10;
            giay%=10;
         }
      }
      if(tt_mod==0) ht();
      if(tt_mod==1) nn_giay();
      if(tt_mod==2) nn_phut();
      if(tt_mod==3) nn_gio();
}
unsigned int8 T0,T0_TAM;
unsigned int16 l, i, tt, m;
void d7seg_xoa0VN(unsigned int16 d)
{
unsigned int8 m=0;
do
{ d7seg.led[m]= m7d[d%10];
d/=10;m++;
      dongho();
}while(d!=0);
for(;m<4;m++) d7seg.led[m]= 0xff;
d7seg_display();
      dongho();
}
void choptat()
{
   led32.ledx32=0xffffffff;
   led32_display();
   for(i=0;i<50;i++)
   {
      T0=get_timer0();
      if(T0>101) set_timer0(1);
      dongho();
   }
   led32.ledx32=0;
   led32_display();
   for(i=0;i<50;i++)
   {
      T0=get_timer0();
      if(T0>101) set_timer0(1);
      dongho();
   }
   tt++;
}
void sangtatdan_pst()
{
   for(l=0; l<32; l++)
   {
      led32.ledx32=~(0xffffffff<<l);
      led32_display();
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
      }
   }
   if(l<33)
   for(m=0; m<32; m++)
   {
      led32.ledx32=(0xffffffff<<m);
      led32_display();
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
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
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
      }
   }
   if(l<33)
   for(m=0; m<32; m++)
   {
      led32.ledx32=(0xffffffff>>m);
      led32_display();
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
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
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
      }
   }
   if(l<32)
   for(m=0; m<16; m++)
   {
      led32.ledx16[0]=(0xffff<<m);
      led32.ledx16[1]=(0xffff>>m);
      led32_display();
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
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
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
      }
   }
   if(l<32)
   for(m=0; m<16; m++)
   {
      led32.ledx16[0]=(0xffff>>m);
      led32.ledx16[1]=(0xffff<<m);
      led32_display();
      for(i=0;i<50;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            d7seg_xoa0VN(T0);
                  dongho();
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
            dongho();
         }
         dongho();
       }
       for(i=0;i<1000;i++)
       {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
       }
       dongho();
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
            dongho();
         }
       }
       for(i=0;i<1000;i++)
      {
         T0=get_timer0();
         if(T0>101) set_timer0(1);
         dongho();
      }
    }
    tt++;
}
void demspled()
{
   T0=get_timer0();
      if(T0>101) set_timer0(1);
      if(T0!=T0_TAM)
      {
               dongho();
         T0_TAM=T0;
         d7seg_xoa0VN(T0);
      }
      if(tt==7) tt=0;
            dongho();
      if(tt==0) choptat();
            dongho();
      if(tt==1) sangtatdan_pst();
            dongho();
      if(tt==2) sangtatdan_tsp();
      if(tt==3) sangtatdan_nvt();
            dongho();
      if(tt==4) sangtatdan_trn();
      if(tt==5) sangdon_pst();
            dongho();
      if(tt==6) sangdon_tsp();
            dongho();
}
void main()
{
   system_init();
   setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
   set_timer1(3036);//nap =3036
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   system_init();
   setup_timer_0 (T0_EXT_H_TO_L | T0_DIV_1);
   set_timer0(0);
   tt=0;
   while(true)
   {
      demspled();
   }
}
#INT_TIMER1 // Chuong trình con x? lý ng?t T1
void ngat_timer1() // Không vi?t gì vào gi?a 2 hàng này
{
   set_timer1(3036);
   bdn++;
}
