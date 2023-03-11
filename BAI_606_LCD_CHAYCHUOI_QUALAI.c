#define   BOARD     D501  
#include<tv_boards.c>
#include<tv_lcd.c>
SIGNED INT32 i,k,l,e;
UNSIGNED INT16 giay;
char const chuoi[38]={'T','R','U','O','N','G',' ','D','A','I',' ','H','O','C',' ','S','U',' ','P','H','A','M',' ','K','Y',' ','T','H','U','A','T',' ','T','P','.','H','C','M'};
UNSIGNED INT16 CHAY[20]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
UNSIGNED INT1 ttinv=0,chuc=0;
void nn_inv()
{
   if(inputcd(inv)==0) ttinv=~ttinv;//=0 dem len;=1 dem xuong
}
void htc()
{
   for(k=0;k<20;k++)
   {
      lcd_goto(k,0);
      lcd_data(chay[k]);
   }
}
void pst()
{
     for(l=0;l<38;l++)
     {
               for(e=0;e<20;e++) chay[e]=chay[e+1];
               chay[19]=chuoi[l];
               if(ttinv==0) {giay++;giay%=60;}
               if(ttinv==1) {giay--;if(giay==0)giay=60;}
               for(i=0;i<20;i++) 
               {
                  if(ttinv==0)
                  {
                        lcd_goto(0,1);
                        lcd_data(0x7E);
                        lcd_goto(0,2);
                        lcd_data(0x20);
                        lcd_goto(9,3);
                        printf(lcd_data,"%2lu",giay);
                  }
                  if(ttinv==1)
                  {
                        lcd_goto(0,2);
                        lcd_data(0x7E);
                        lcd_goto(0,1);
                        lcd_data(0x20);
                        lcd_goto(9,3);
                        printf(lcd_data,"%2lu",giay);
                  }
                  nn_inv();
                  htc();
               }
      }
      chuc=~chuc;
}
void qualai()
{
            for(l=18;l<0;l--)
            {
               for(e=0;e<20;e++) chay[e]=chay[e+1];
               chay[0]=chuoi[l];
               if(ttinv==0) {giay++;giay%=60;}
               if(ttinv==1) {giay--;if(giay==0)giay=60;}
               for(i=0;i<20;i++) 
               {
                  if(ttinv==0)
                  {
                        lcd_goto(0,1);
                        lcd_data(0x7E);
                        lcd_goto(0,2);
                        lcd_data(0x20);
                        lcd_goto(9,3);
                        printf(lcd_data,"%2lu",giay);
                        delay_ms(100);
                  }
                  if(ttinv==1)
                  {
                     lcd_goto(0,2);
                     lcd_data(0x7E);
                     lcd_goto(0,1);
                     lcd_data(0x20);
                     lcd_goto(9,3);
                     printf(lcd_data,"%2lu",giay);
                     delay_ms(100);
                  }
                  nn_inv();
                  htc();
               }
            }
     chuc=~chuc;       
}
void main()
{
   system_init();
   lcd_setup();
      lcd_goto(1,1);
      lcd_data("DEM LEN");
      lcd_goto(1,2);
      lcd_data("DEM XUONG");
   while(true)
   {
      if(chuc==0)pst();
      if(chuc==1)qualai();
   }
}
