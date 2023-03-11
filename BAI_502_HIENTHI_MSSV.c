//#define   BOARD     D501
#include<tv_boards.c> 
signed int8 n,chuky=0,m;
void main()
{
      system_init();  
      // 2. Nhung noi dung khong thay doi thi giai ma truoc while(true)
      s7seg.led[7] = m7d[2];       
      s7seg.led[6] = m7d[0]; 
      s7seg.led[5] = m7d[1];  
      s7seg.led[4] = m7d[4]; 
      s7seg.led[3] = m7d[2];   
      s7seg.led[2] = m7d[1];
      s7seg.led[1] = m7d[3]; 
      s7seg.led[0] = m7d[8]; 
      while(true)
      {     
         s7seg_display();
      }
}


  
