#define   BOARD     D501
#include<tv_boards.c>
unsigned int8 giay=0,bdn=0,phut=0,gio=0;
void main()
{
   system_init();
   setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
   set_timer1(3036);//nap =3036
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   while(true)
   {
      if(bdn>=10) // Tr�n d? 10 l?n l� du?c 1 gi�y
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
      s7seg.led[7] = m7d[gio/10%10]; // Gi?i m� h�ng ch?c c?a gi�y
      s7seg.led[6] = m7d[gio%10]; // Gi?i m� h�ng don v? c?a gi�y
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10]; // Gi?i m� h�ng ch?c c?a gi�y
      s7seg.led[3] = m7d[phut%10]; // Gi?i m� h�ng don v? c?a gi�y
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10]; // Gi?i m� h�ng ch?c c?a gi�y
      s7seg.led[0] = m7d[giay%10]; // Gi?i m� h�ng don v? c?a gi�y
      s7seg_display(); // Qu�t LED
   }
}
#INT_TIMER1 // Chuong tr�nh con x? l� ng?t T1
void ngat_timer1() // Kh�ng vi?t g� v�o gi?a 2 h�ng n�y
{
   set_timer1(3036);
   bdn++;
}
