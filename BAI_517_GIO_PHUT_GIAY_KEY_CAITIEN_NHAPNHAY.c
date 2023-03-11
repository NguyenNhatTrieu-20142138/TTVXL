#define   BOARD     D501
#include<tv_boards.c>
unsigned int8 giay=0,bdn=0,phut=0,gio=0;
unsigned int8 i;
unsigned int8 tt_mod=0,tt_ud;
unsigned int8 tat[2]={0xff,0xff};
void tt_nn()
{
    if(inputcd(MOD)==0)
    {
      tt_mod++;
      if(tt_mod>3) tt_mod=0;
    }
    if(tt_mod==1)
    {
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
      for(i=0;i<50;i++) 
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
      for(i=0;i<50;i++) 
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
      for(i=0;i<50;i++) 
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
      for(i=0;i<50;i++) 
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
      for(i=0;i<50;i++) 
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
      for(i=0;i<50;i++) 
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

void main()
{
   system_init();
   setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
   set_timer1(3036);//nap =3036
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   while(true)
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
}
#INT_TIMER1 // Chuong trình con x? lý ng?t T1
void ngat_timer1() // Không vi?t gì vào gi?a 2 hàng này
{
   set_timer1(3036);
   bdn++;
}
