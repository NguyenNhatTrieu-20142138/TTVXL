#define   BOARD     D501  
#include<tv_boards.c>
#include<tv_lcd.c>
UNSIGNED INT32 i,k,l,e;
UNSIGNED INT16 giay;
char const chuoi[41]={'T','R','U','O','N','G',' ','D','A','I',' ','H','O','C',' ','S','U',' ','P','H','A','M',' ','K','Y',' ','T','H','U','A','T',' ','T','P','.','H','C','M',' ',' ',' '};
UNSIGNED INT16 CHAY[20]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
UNSIGNED INT1 ttinv=0;
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
            for(l=0;l<41;l++)
            {
               for(e=0;e<20;e++) chay[e]=chay[e+1];
               chay[19]=chuoi[l];
               for(i=0;i<50;i++) 
               {
                  if(ttinv==0)
                  {
                        lcd_goto(0,1);
                        lcd_data(0x7E);
                        lcd_goto(0,2);
                        lcd_data(0x20);
                        giay++;
                        giay%=60;
                        lcd_goto(9,3);
                        printf(lcd_data,"%2lu",giay);
                  }
                  if(ttinv==1)
                  {
                     lcd_goto(0,2);
                     lcd_data(0x7E);
                     lcd_goto(0,1);
                     lcd_data(0x20);
                     giay--;
                     if(giay==0)giay=60;
                     lcd_goto(9,3);
                     printf(lcd_data,"%2lu",giay);
                  }
                  for(i=0;i<100;i++)
                  {
                     nn_inv();
                     htc();
                     delay_ms(10);
                  }
               }
            }
      }

   }
