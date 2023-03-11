#define   BOARD     D501
#include<tv_boards.c> 
#include<tv_key4x4.c> 
unsigned int16 T0,T0_TAM, dem,i ;
unsigned int8 sgh,ch,dv;
unsigned int1 tt_d=0,tt_c=0;//dem toi
unsigned int8 giay=0,bdn=0,phut=0,gio=0;//bien cua dong ho
unsigned int8 tt_mod=0;
void matran()
{
   if(key4x4_read()==OK)
   {
      if(key4x4.key==12) tt_c=~tt_c;
      if(tt_c==0)//che do dem sp
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
      if(tt_c==1)//che do dong ho
      {
            if(key4x4.key==14)
            {
               tt_mod++;
               ch=0;
               dv=0;
               if(tt_mod>3) tt_mod=0;
            }
            if(tt_mod==1)//chinh giay
            {
               ch=dv;
               dv=key4x4.key;
               giay=ch*10+dv;
            }
            if(tt_mod==2)//chinh giay
            {
               ch=dv;
               dv=key4x4.key;
               phut=ch*10+dv;
            }
            if(tt_mod==3)//chinh giay
            {
               ch=dv;
               dv=key4x4.key;
               gio=ch*10+dv;
            } 
      }
   }
}
void ht()
{
   s7seg.led[5]=m7d[sgh/10%10];
   s7seg.led[4]=m7d[sgh/1%10]-128;
   s7seg.led[3]=m7d[dem/10%10];
   s7seg.led[2]=m7d[dem/1%10];
   s7seg_display();
}
void demsp()
{
         T0=get_timer0();
         matran();
         if(T0>99) set_timer0(0);
         if(dem==sgh) setup_timer_0(T0_OFF);
         if(dem!=sgh) setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);
         if(T0!=T0_TAM)
         {
            T0_TAM=T0;
            s7seg_display();
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
void htdongho()
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
      matran();
}
void htgiay()
{
      s7seg.led[1] = 0xff; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = 0xff; // Gi?i mã hàng don v? c?a giây
      for(i=0;i<50;i++) 
      {
         s7seg_display();// Quét LED
         matran();
      }
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[0] = m7d[giay%10]; // Gi?i mã hàng don v? c?a giây
      for(i=0;i<50;i++) 
      {
         s7seg_display();// Quét LED
         matran();
      }
}
void htphut()
{
      s7seg.led[4] = 0xff; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = 0xff; // Gi?i mã hàng don v? c?a giây
      for(i=0;i<50;i++) 
      {
         s7seg_display();// Quét LED
         matran();
      }
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[3] = m7d[phut%10]; // Gi?i mã hàng don v? c?a giây
      for(i=0;i<50;i++) 
      {
         s7seg_display();// Quét LED
         matran();
      }
}
void htgio()
{
      s7seg.led[7] = 0xff; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[6] = 0xff; // Gi?i mã hàng don v? c?a giây
      for(i=0;i<50;i++) 
      {
         s7seg_display();// Quét LED
         matran();
      }
      s7seg.led[7] = m7d[gio/10%10]; // Gi?i mã hàng ch?c c?a giây
      s7seg.led[6] = m7d[gio%10]; // Gi?i mã hàng don v? c?a giây
      for(i=0;i<50;i++) 
      {
         s7seg_display();// Quét LED
         matran();
      }
}
void dongho()
{
      if(bdn>=10) // Tràn d? 10 l?n là du?c 1 giây
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
      if(tt_mod==0) htdongho();
      if(tt_mod==1) htgiay();
      if(tt_mod==2) htphut();
      if(tt_mod==3) htgio();
}
void main()
{
      system_init();
      setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
      set_timer1(3036);//nap =3036
      enable_interrupts(INT_TIMER1);
      enable_interrupts(GLOBAL);
      while(true)
      {     
         if(tt_c==0) demsp();
         if(tt_c==1) dongho();
      }
}
#INT_TIMER1 // Chuong trình con x? lý ng?t T1
void ngat_timer1() // Không vi?t gì vào gi?a 2 hàng này
{
   set_timer1(3036);
   bdn++;
}
