
//#define   BOARD     D503
#include<tv_boards.c>  
#include<tv_key4x4.c> 
unsigned int32 i,k,l,m,n,e,f,g,h,a;
signed int32 hu=0,td=1000,ch;//hu=0 la hieu ung so 1
unsigned int1  tt_mod=0,lx=0,bre=0,bret=0;
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
void nn()
{
   if(key4x4_read()==OK)
   {
      if(key4x4.key==15) tt_mod=~tt_mod;
      if(tt_mod==0)//chinh hieu ung
      {
         led32.ledx1[0]=0;
         led32_display();
         if(key4x4.key==0) {hu=0;bre=~bre;break;}
         if(key4x4.key==1) {hu=1;bre=~bre;break;}
         if(key4x4.key==2) {hu=2;bre=~bre;break;}
         if(key4x4.key==3) {hu=3;bre=~bre;break;}
         if(key4x4.key==4) {hu=4;bre=~bre;break;}
         if(key4x4.key==5) {hu=5;bre=~bre;break;}
         if(key4x4.key==6) {hu=6;bre=~bre;break;}
         if(key4x4.key==7) {hu=7;bre=~bre;break;}
         if(key4x4.key==8) {hu=8;bre=~bre;break;}
         if(key4x4.key==9) {hu=9;bre=~bre;break;}
         if(inputcd(up)==0){lx=~lx;}
         if(inputcd(dw)==0){lx=~lx;}
         if(hu>9) hu=0;
         if(hu<0) hu=10;
      }
      if(tt_mod==1)//chinh toc do
      {
         led32.ledx1[0]=1;
         led32_display();
         if(key4x4.key==0) td=0;
         if(key4x4.key==1) td=1;
         if(key4x4.key==2) td=2;
         if(key4x4.key==3) td=3;
         if(key4x4.key==4) td=4;
         if(key4x4.key==5) td=5;
         if(key4x4.key==6) td=6;
         if(key4x4.key==7) td=7;
         if(key4x4.key==8) td=8;
         if(key4x4.key==9) td=9;
         if(td>1000) td=1000;
         if(td<100) td=100;
      }
   }
}
void hu1()
{
            hu10=0;//de led tat het
         for(i=0;i<24;i++)
         {
            hu10=(hu10>>1)|0x08000000;
            led32.ledx32=hu10;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         } 
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu2()
{
            hu20=0;//de led tat het
         for(k=0;k<24;k++)
         {
            hu20=(hu20<<1)|0x00000010;
            led32.ledx32=hu20;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         } 
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu3()
{
            hu30=0;
         hu31=0;
         for(l=0;l<12;l++)
         {
            hu30=(hu30>>1)|0x8000;
            hu31=(hu31<<1)|0x0001;
            led32.ledx16[0]=hu30;
            led32.ledx16[1]=hu31;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu4()
{
            hu40=0;
         hu41=0;
         for(m=0;m<12;m++)
         {
            hu40=(hu40<<1)|0x0010;
            hu41=(hu41>>1)|0x0800;
            led32.ledx16[0]=hu40;
            led32.ledx16[1]=hu41;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu5()
{
            hu50=0x0f000000;
         for(n=0;n<20;n++)
         {
            hu50=hu50>>1;
            led32.ledx32=hu50;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         hu++;
}
void hu6()
{
         hu60=0x000000f0;
         for(e=0;e<20;e++)
         {
            hu60=hu60<<1;
            led32.ledx32=hu60;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}         
void hu7()
{
            hu70=0x0ffffff0;
         for(f=0;f<5;f++)
         {
            led32.ledx32=hu70;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            led32.ledx32=0;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu8()
{
            hu80=0;
         hu81=0;
         for(g=0;g<5;g++)
         {
            hu80=0xfff0;
            hu81=0x0fff;
            led32.ledx16[0]=hu80;
            led32.ledx16[1]=0;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            led32.ledx16[0]=0;
            led32.ledx16[1]=hu81;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu9()
{
            hu90=0;
         hu91=0;
         for(h=0;h<12;h++)
         {
            hu90=(hu90>>1)|0x8000;
            hu91=(hu91>>1)|0x0800;
            led32.ledx16[0]=hu90;
            led32.ledx16[1]=hu91;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void hu10()
{
            hue0=0;
         hue1=0;
         for(a=0;a<12;a++)
         {
            hue0=(hue0<<1)|0x0010;
            hue1=(hue1<<1)|0x0001;
            led32.ledx16[0]=hue0;
            led32.ledx16[1]=hue1;
            if(tt_mod==1)led32.ledx1[0]=1;
            led32_display();
            for(ch=0;ch<td;ch++) nn();
            if(bret!=bre) {bret=bre;break;}
         }
         if(bret!=bre) {bret=bre;break;}
         if(lx==0)hu++;
         if(lx==1)hu--;
         if(hu>9) hu=0;
         if(hu<0) hu=10;
}
void main()
{
      system_init();  
      while(true)
      {     
         if(hu==0) hu1();
         if(hu==1) hu2();
         if(hu==2) hu3();
         if(hu==3) hu4();
         if(hu==4) hu5();
         if(hu==5) hu6();
         if(hu==6) hu7();
         if(hu==7) hu8();
         if(hu==8) hu9();
         if(hu==9) hu10();
         if(hu==10) hu=0;
      }
}
