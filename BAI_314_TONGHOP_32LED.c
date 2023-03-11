//#define  BOARD D501
#include <tv_boards.c>
unsigned int8 i=0,hu=0;
void choptat()
{
   led32.ledx32=0xffffffff;
   led32_display();
   delay_ms(200);
    led32.ledx32=0;
   led32_display();
   delay_ms(200);
   hu++;
}
void sangdan_pst()
{
   if(i<32)
   {
      led32.ledx32=~(0xffffffff<<i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void tatdan_pst()
{
   if(i<32)
   {
      led32.ledx32=(0xffffffff<<i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void sangdan_tsp()
{
   if(i<32)
   {
      led32.ledx32=~(0xffffffff>>i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void tatdan_tsp()
{
   if(i<32)
   {
      led32.ledx32=(0xffffffff>>i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void sang_nvt()
{
   if(i<16)
   {
      led32.ledx16[0]=~(0xffff<<i);
      led32.ledx16[1]=~(0xffff>>i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void tat_nvt()
{
   if(i<16)
   {
      led32.ledx16[0]=(0xffff<<i);
      led32.ledx16[1]=(0xffff>>i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void sang_trn()
{
   if(i<16)
   {
      led32.ledx16[0]=~(0xffff>>i);
      led32.ledx16[1]=~(0xffff<<i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void tat_trn()
{
   if(i<16)
   {
      led32.ledx16[0]=(0xffff>>i);
      led32.ledx16[1]=(0xffff<<i);
      led32_display();
      delay_ms(100);
      i++;
   }
   else
   {
      hu++;
      i=0;
   }
}
void main()
{
      system_init();
      while(true)
      {
         if(hu==0)  choptat();   if(hu==1)  choptat();   if(hu==2)  choptat();
         if(hu==3)  choptat();   if(hu==4)  choptat();         //chop tat 5 lan
         
         if(hu==5)  sangdan_pst();  if(hu==6) tatdan_pst();
         if(hu==7)  sangdan_pst();  if(hu==8) tatdan_pst();    //sang tat dan phai sang trai 2 lan
         
         if(hu==9)  choptat();   if(hu==10)  choptat();   if(hu==11)  choptat();
         if(hu==12)  choptat();   if(hu==13)  choptat();        //chop tat 5 lan
         
         if(hu==14)  sangdan_tsp();  if(hu==15) tatdan_tsp();
         if(hu==16)  sangdan_tsp();  if(hu==17) tatdan_tsp();     //sang tat dan trai sang phai 2 lan
         
         if(hu==18)  choptat();   if(hu==19)  choptat();   if(hu==20)  choptat();
         if(hu==21)  choptat();   if(hu==22)  choptat();        //chop tat 5 lan
         
         if(hu==23)  sang_nvt();  if(hu==24) tat_nvt();     //sang tat dan ngoai vao trong 2 lan
         if(hu==25)  sang_nvt();  if(hu==26) tat_nvt();
         
         if(hu==27)  choptat();   if(hu==28)  choptat();   if(hu==29)  choptat();
         if(hu==30)  choptat();   if(hu==31)  choptat();        //chop tat 5 lan
         
         if(hu==32)  sang_trn();  if(hu==33) tat_trn();     // sang tat dan trong ra ngoai 2 lan
         if(hu==34)  sang_trn();  if(hu==35) tat_trn();
         
         if(hu==36)
         hu=0;
      }
}
