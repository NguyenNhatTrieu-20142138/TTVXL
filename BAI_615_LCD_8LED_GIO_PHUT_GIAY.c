#define   BOARD     D501  
#include<tv_boards.c>
#include<tv_lcd.c>
unsigned int8 bdn=0,giay=45,phut=59,gio=11;
unsigned int8 i;
unsigned int8 tt_mod=0;
void nn()
{
   if(inputcd(mod)==0){tt_mod++;if(tt_mod>3)tt_mod=0;}
   if(tt_mod==1)
   {
      if(inputcd(up)==0) giay++;
      if(inputcd(dw)==0) giay--;
   }
   if(tt_mod==2)
   {
      if(inputcd(up)==0) phut++;
      if(inputcd(dw)==0) phut--;
   }
   if(tt_mod==3)
   {
      if(inputcd(up)==0) gio++;
      if(inputcd(dw)==0) gio--;
   }
   s7seg_display();
}
void ht()
{
      s7seg.led[7] = m7d[gio/10%10];
      s7seg.led[6] = m7d[gio%10]; 
      s7seg.led[5] = 0xff-64;
      s7seg.led[4] = m7d[phut/10%10];
      s7seg.led[3] = m7d[phut%10]; 
      s7seg.led[2] = 0xff-64;
      s7seg.led[1] = m7d[giay/10%10];
      s7seg.led[0] = m7d[giay%10];
      s7seg_display();
      lcd_goto(7,0);
      printf(lcd_data,"%02u",gio);
      lcd_goto(9,0);
      lcd_data(":");
      lcd_goto(10,0);
      printf(lcd_data,"%02u",phut);
      lcd_goto(12,0);
      lcd_data(":");
      lcd_goto(13,0);
      printf(lcd_data,"%02u",giay);
      nn();
}
void giaynn()
{
      lcd_goto(13,0);
      lcd_data("  ");
      s7seg.led[1] = 0xff;
      s7seg.led[0] = 0xff;
      s7seg_display();
      for(i=0;i<50;i++) nn();
      lcd_goto(13,0);
      printf(lcd_data,"%02u",giay);
      s7seg.led[1] = m7d[giay/10%10];
      s7seg.led[0] = m7d[giay%10];
      s7seg_display();
}
void phutnn()
{
      lcd_goto(10,0);
      lcd_data("  ");
      s7seg.led[4] = 0xff;
      s7seg.led[3] = 0xff; 
      s7seg_display();
      for(i=0;i<50;i++) nn();
      lcd_goto(10,0);
      printf(lcd_data,"%02u",phut);
      s7seg.led[4] = m7d[phut/10%10];
      s7seg.led[3] = m7d[phut%10]; 
      s7seg_display();
}
void gionn()
{
      lcd_goto(7,0);
      lcd_data("  ");
      s7seg.led[7] = 0xff;
      s7seg.led[6] = 0xff;
      s7seg_display();
      for(i=0;i<50;i++) nn();
      lcd_goto(7,0);
      printf(lcd_data,"%02u",gio);
      s7seg.led[7] = m7d[gio/10%10];
      s7seg.led[6] = m7d[gio%10]; 
      s7seg_display();
}
void main()
{
   system_init();
   lcd_setup();
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   set_timer1(3036);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   while(true)
   {
      nn();
      if(bdn>=10)
      {
         nn();
         bdn=bdn-10;
         giay++;
         if(giay>59)
         {
            phut++;
            if(phut>59)
            {
               phut=0;
               gio++;
               if(gio>11)gio=0;
            }
            giay%=60;
         }
         d7seg.led[1]=m7d[tt_mod];
         d7seg_display();
      }
      if(tt_mod==0)ht();
      if(tt_mod==1)giaynn();
      if(tt_mod==2)phutnn();
      if(tt_mod==3)gionn();
    }
}
#INT_TIMER1
void ngattimer1()
{
   set_timer1(3036);
   bdn++;
}
