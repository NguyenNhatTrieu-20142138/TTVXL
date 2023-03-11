#define   BOARD     D501
#include<tv_boards.c> 
unsigned int8 n,m,i,k;
signed int8 tt=1;
unsigned int16 chu[20]={0xff-32-16-64-2-4,0xff-1-32-64-16-8,0xff-32-16-8,0xff-32-16-8,0xff-1-32-16-8-4-2-128,0xff,0xff-1-32-16-8,0xff-32-16-64-2-4,0xff-1-32-16-8-4-2,0xff,0xff-2-4,0xff,0xff-32-16-8,0xff-32-64-2-4,0xff,0xff-1-32-16-8,0xff-16-32-1-2-4-64,0xff-1-32-64-16,0xff-1-32-16-64-8,
0xff};
unsigned int16 chul[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
void main()
{
      system_init();  
      for(n=0;n<8;n++) s7seg.led[n]=chul[n];
      s7seg_display();
      while(true)
      {     
         for(i=0;i<20;i++)
         {
            chul[7]=chul[6];
            chul[6]=chul[5];
            chul[5]=chul[4];
            chul[4]=chul[3];
            chul[3]=chul[2];
            chul[2]=chul[1];
            chul[1]=chul[0];
            chul[0]=chu[i];//dao vi tri cac o
            for(n=0;n<8;n++) s7seg.led[n]=chul[n];//gan gia tri vao hien thi
            for(m=0;m<100;m++) s7seg_display();//hien thi
         }  
      }
}
