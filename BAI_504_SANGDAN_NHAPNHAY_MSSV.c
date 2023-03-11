//#define   BOARD     D501
#include<tv_boards.c> 
unsigned int8 n,m,i;
signed int8 tt=0,nn12=0;
unsigned int8 mssv[8]={2,0,1,4,2,1,3,8};
void kt_nn()
{
   if(inputcd(ON)==0)
   {
        tt=1;
   }
   if(inputcd(OFF)==0)
   {
         tt=0;
         nn12=0;
         break;
   }
}
void nn()
{
   for(i=0;i<8;i++) s7seg.led[i]=0xff;
   for(n=0;n<50;n++) 
   {
       kt_nn();
       s7seg_display();
   }
   for(i=0;i<8;i++) s7seg.led[7-i]=m7d[mssv[i]];
   for(n=0;n<50;n++) 
   {
       kt_nn();
       s7seg_display();
   }
}
void main()
{
      system_init();  
      while(true)
      {     
         if(tt==1)
         {
            for(i=0;i<8;i++)
            {
               s7seg.led[7-i]=m7d[mssv[i]];
               for(n=0;n<100;n++) 
               {
                  kt_nn();
                  s7seg_display();
               }
               if(tt==0) break;
            }
            if(tt==1)
            {
               nn12=1;
               while(nn12==1) nn();
            }
         }
         if(tt==0)
         {
            for(i=0;i<8;i++) s7seg.led[i]=0xff;
            for(n=0;n<100;n++) 
            {
                  kt_nn();
                  s7seg_display();
            }
         }
      }
}
