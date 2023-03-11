//#define  BOARD D501
#include <tv_boards.c>
#include <tv_key4x4.c>
unsigned int16 n, i, tt, m;
void choptat()
{
   led32.ledx32=0xffffffff;
   led32_display();
   for(i=0; i<2000;i++)
   {
      if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
            }
   }
   led32.ledx32=0;
   led32_display();
   for(i=0; i<2000;i++)
   {
      if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
            }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     m=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     m=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     m=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
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
         if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     m=32;
                     tt=i;           
                  }
               }
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
            if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
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
             if(key4x4_read()==OK)
             {
               for(i=0; i<7; i++)
               {
                  if(key4x4.key==i)
                  {
                     n=32;
                     tt=i;           
                  }
               }
            }
         }
       }
    }
}
void main()
{
   system_init();
   while(true)
   {
      if(tt==0)
      choptat();
      if(tt==1)
      sangtatdan_pst();
      if(tt==2)
      sangtatdan_tsp();
      if(tt==3)
      sangtatdan_nvt();
      if(tt==4)
      sangtatdan_trn();
      if(tt==5)
      sangdon_pst();
      if(tt==6)
      sangdon_tsp();
   }
}

