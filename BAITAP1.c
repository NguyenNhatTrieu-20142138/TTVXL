
//#define   BOARD     D503
#include<tv_boards.c>  
unsigned int32 i,k,l,m,n,e,f,g,h,a;
unsigned int32 hu10,hu11;//sang dan tu trai sang phai
unsigned int32 hu20,hu21;//sang dan tu phai sang trai
unsigned int32 hu30,hu31;//sang tu trong ra ngoai
unsigned int32 hu40,hu41;//sang tu ngoai vao trong
unsigned int32 hu50,hu51;//4 led chayj tu trai sang phai
unsigned int32 hu60,hu61;//4 led chayj tu phai sang trai
unsigned int32 hu70,hu71;//sang 24 led chop tat 5 lan
unsigned int32 hu80,hu81;//sang ben trai va phai lan luot 5 lan
unsigned int32 hu90,hu91;//12 led ben trai sang tu trai vao, ben phai la tu trai vao 
unsigned int32 hue0,hue1;// nguoc lai so 9
void main()
{
      system_init();  
      while(true)
      {     
         hu10=0;//de led tat het
         for(i=0;i<24;i++)
         {
            hu10=(hu10>>1)|0x08000000;
            led32.ledx32=hu10;
            led32_display();
            delay_ms(200);
         } 
         hu20=0;//de led tat het
         for(k=0;k<24;k++)
         {
            hu20=(hu20<<1)|0x00000010;
            led32.ledx32=hu20;
            led32_display();
            delay_ms(200);
         }   
         hu30=0;
         hu31=0;
         for(l=0;l<12;l++)
         {
            hu30=(hu30>>1)|0x8000;
            hu31=(hu31<<1)|0x0001;
            led32.ledx16[0]=hu30;
            led32.ledx16[1]=hu31;
            led32_display();
            delay_ms(200);
         }
         hu40=0;
         hu41=0;
         for(m=0;m<12;m++)
         {
            hu40=(hu40<<1)|0x0010;
            hu41=(hu41>>1)|0x0800;
            led32.ledx16[0]=hu40;
            led32.ledx16[1]=hu41;
            led32_display();
            delay_ms(200);
         }
         hu50=0x0f000000;
         for(n=0;n<20;n++)
         {
            hu50=hu50>>1;
            led32.ledx32=hu50;
            led32_display();
            delay_ms(200);
         }
         hu60=0x000000f0;
         for(e=0;e<20;e++)
         {
            hu60=hu60<<1;
            led32.ledx32=hu60;
            led32_display();
            delay_ms(200);
         }
         hu70=0x0ffffff0;
         for(f=0;f<5;f++)
         {
            led32.ledx32=hu70;
            led32_display();
            delay_ms(200);
            led32.ledx32=0;
            led32_display();
            delay_ms(200);
         }
         hu80=0;
         hu81=0;
         for(g=0;g<5;g++)
         {
            hu80=0xfff0;
            hu81=0x0fff;
            led32.ledx16[0]=hu80;
            led32.ledx16[1]=0;
            led32_display();
            delay_ms(200);
            led32.ledx16[0]=0;
            led32.ledx16[1]=hu81;
            led32_display();
            delay_ms(200);
         }
         hu90=0;
         hu91=0;
         for(h=0;h<12;h++)
         {
            hu90=(hu90>>1)|0x8000;
            hu91=(hu91>>1)|0x0800;
            led32.ledx16[0]=hu90;
            led32.ledx16[1]=hu91;
            led32_display();
            delay_ms(200);
         }
         hue0=0;
         hue1=0;
         for(a=0;a<12;a++)
         {
            hue0=(hue0<<1)|0x0010;
            hue1=(hue1<<1)|0x0001;
            led32.ledx16[0]=hue0;
            led32.ledx16[1]=hue1;
            led32_display();
            delay_ms(200);
         }
      }
}
