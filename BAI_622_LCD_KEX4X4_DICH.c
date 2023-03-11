#define   BOARD     D501
#include<tv_boards.c>
#include<tv_lcd.c>
#include<tv_key4x4.c>
unsigned int8 chu[19]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
signed int8 k,i;
void htc()
{
   for(k=0;k<20;k++)
   {
      lcd_goto(k,1);
      lcd_data(chu[k]);
   }
}
void main()
{
   system_init();
   lcd_setup();
   lcd_goto(3,0);
   lcd_data("HAY NHAN PHIM");
   while(true)
   {
      if(key4x4_read()==OK)
      {
         htc();
         if(key4x4.key<10) 
         {
            for(i=0;i>19;i++)
            {
               chu[i]=chu[i+1];
               chu[0]=key4x4.key;
               htc();
            }
         }
      }
   }
}
