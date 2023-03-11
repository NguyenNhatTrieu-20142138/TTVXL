//#define   BOARD     D501
#include<tv_boards.c>  
unsigned int32 i,k,l;
unsigned int32 sangdanpst,sangdantsp;
unsigned int32 nvt1,nvt0;
void main()
{
      system_init();  
      while(true)
      {  
         for(i=0;i<5;i++)
         {
               led32.ledx32=0xffffffff;
               led32_display();
               delay_ms(200);
               led32.ledx32=0;
               led32_display();
               delay_ms(200);
         }
         for(i=0;i<2;i++)
         {     
               sangdanpst=0x00000001;
               for(k=0;k<32;k++)
               {
                  sangdanpst=(sangdanpst<<1)|0x00000001;
                  led32.ledx32=sangdanpst;
                  led32_display();
                  delay_ms(50);
               }
               for(k=0;k<32;k++)
               {
                  sangdanpst=(sangdanpst<<1);
                  led32.ledx32=sangdanpst;
                  led32_display();
                  delay_ms(50);
               }
         }
         for(i=0;i<5;i++)
         {
               led32.ledx32=0xffffffff;
               led32_display();
               delay_ms(200);
               led32.ledx32=0;
               led32_display();
               delay_ms(200);
         }
         for(i=0;i<2;i++)
         {     
               sangdanpst=0x80000000;
               for(k=0;k<32;k++)
               {
                  sangdanpst=(sangdanpst>>1)|0x80000000;
                  led32.ledx32=sangdanpst;
                  led32_display();
                  delay_ms(50);
               }
               for(k=0;k<32;k++)
               {
                  sangdanpst=(sangdanpst>>1);
                  led32.ledx32=sangdanpst;
                  led32_display();
                  delay_ms(50);
               }
         }
         for(i=0;i<5;i++)
         {
               led32.ledx32=0xffffffff;
               led32_display();
               delay_ms(200);
               led32.ledx32=0;
               led32_display();
               delay_ms(200);
         }
         for(l=0;l<2;l++)
         {
            nvt1=0x8000;
            nvt0=0x0001;
            led32.ledx16[0]=nvt0;
            led32.ledx16[1]=nvt1;
            led32_display();
            delay_ms(200);
            for(k=0;k<16;k++)
            {
               nvt1=(nvt1>>1)|0x8000;
               nvt0=(nvt0<<1)|0x0001;
               led32.ledx16[0]=nvt0;
               led32.ledx16[1]=nvt1;
               led32_display();
               delay_ms(200);
            }
         }
         for(i=0;i<5;i++)
         {
               led32.ledx32=0xffffffff;
               led32_display();
               delay_ms(200);
               led32.ledx32=0;
               led32_display();
               delay_ms(200);
         }
         for(l=0;l<2;l++)
         {
            nvt1=0x0001;
            nvt0=0x8000;
            led32.ledx16[0]=nvt0;
            led32.ledx16[1]=nvt1;
            led32_display();
            delay_ms(50);
            for(k=0;k<16;k++)
            {
               nvt1=(nvt1<<1)|0x0001;
               nvt0=(nvt0>>1)|0x8000;
               led32.ledx16[0]=nvt0;
               led32.ledx16[1]=nvt1;
               led32_display();
               delay_ms(50);
            }
         }
      }
}