#define  BOARD D501
#include <tv_boards.c>
unsigned int16 n, i, tt, m;
void choptat()
{
   led32.ledx32=0xffffffff;
   led32_display();
   for(i=0; i<2000;i++)
   {
      if(inputcd(UP)==0) tt++;
   }
   led32.ledx32=0;
   led32_display();
   for(i=0; i<2000;i++)
   {
      if(inputcd(UP)==0) tt++;
   }
}
void sangtatdan_pst()
{
   for(n=0; n<32; n++)
   {
      led32.ledx32=~(0xffffffff<<n);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            n=33;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            n=33;
         }
         if(input(CLR)==0)
         {
            n=33;
            tt=0;
         }
      }
   }
   if(n<33)
   for(m=0; m<32; m++)
   {
      led32.ledx32=(0xffffffff<<m);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            m=32;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            m=32;
         }
         if(input(CLR)==0)
         {
            m=32;
            tt=0;
         }
      }
   }
}
void sangtatdan_tsp()
{
   for(n=0; n<32; n++)
   {
      led32.ledx32=~(0xffffffff>>n);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            n=33;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            n=33;
         }
         if(input(CLR)==0)
         {
            n=33;
            tt=0;
         }
      }
   }
   if(n<33)
   for(m=0; m<32; m++)
   {
      led32.ledx32=(0xffffffff>>m);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            m=32;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            m=32;
         }
         if(input(CLR)==0)
         {
            m=32;
            tt=0;
         }
      }
   }
}
void sangtatdan_nvt()            //sang dan ngoai vao trong
{
   for(n=0; n<16; n++)
   {
      led32.ledx16[0]=~(0xffff<<n);
      led32.ledx16[1]=~(0xffff>>n);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            n=32;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            n=32;
         }
         if(input(CLR)==0)
         {
            n=32;
            tt=0;
         }
      }
   }
   if(n<32)
   for(m=0; m<16; m++)
   {
      led32.ledx16[0]=(0xffff<<m);
      led32.ledx16[1]=(0xffff>>m);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            m=32;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            m=32;
         }
         if(input(CLR)==0)
         {
            m=32;
            tt=0;
         }
      }
   }
}
void sangtatdan_trn()               //sang dan trong ra ngoai
{
   for(n=0; n<16; n++)
   {
      led32.ledx16[0]=~(0xffff>>n);
      led32.ledx16[1]=~(0xffff<<n);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            n=32;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            n=32;
         }
         if(input(CLR)==0)
         {
            n=32;
            tt=0;
         }
      }
   }
   if(n<32)
   for(m=0; m<16; m++)
   {
      led32.ledx16[0]=(0xffff>>m);
      led32.ledx16[1]=(0xffff<<m);
      led32_display();
      for(i=0; i<1000;i++)
      {
         if(inputcd(UP)==0)
         {
            tt++;
            m=32;
         }
         if(inputcd(DW)==0)
         {
            tt--;
            m=32;
         }
         if(input(CLR)==0)
         {
            m=32;
            tt=0;
         }
      }
   }
}
void sangdon_pst()
{
    for(n=0;n<=32;n++) 
    {
       for(m=0;m<32-n;m++) 
       { 
         led32.ledx32= (~(0xffffffff<<n))|(0x80000000>>m); 
         led32_display(); 
         for(i=0; i<1000;i++)
         {
            if(inputcd(UP)==0)
            {
               tt++;
               n=32;
            }
            if(inputcd(DW)==0)
            {
               tt--;
               n=32; 
            }
            if(input(CLR)==0)
            {
               n=32; 
               tt=0;
            }  
         }
       }
    }
}
void sangdon_tsp()
{
    for(n=0;n<=32;n++) 
    {
       for(m=0;m<32-n;m++) 
       { 
         led32.ledx32= (~(0xffffffff>>n))|((int32)1<<m); 
         led32_display(); 
         for(i=0; i<1000;i++)
         {
            if(inputcd(DW)==0)
            {
               tt--;
               n=32; 
            }
            if(input(CLR)==0)
            {
               n=32; 
               tt=0;
            }  
         }
       }
    }
}
void main()
{
   system_init();
   tt=0;
   while(true)
   {
      if(tt==0) choptat();
      if(tt==1) sangtatdan_pst();
      if(tt==2) sangtatdan_tsp();
      if(tt==3) sangtatdan_nvt();
      if(tt==4) sangtatdan_trn();
      if(tt==5) sangdon_pst();
      if(tt==6) sangdon_tsp();
   }
}

