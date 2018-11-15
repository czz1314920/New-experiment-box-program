#include "ioCC2530.h"      

void delay(void)      //��ʱʱ��Լ10ms
{
  unsigned int i;
  unsigned char j;

  for(i=0;i<1500;i++)
  {
    for(j=0;j<20;j++)
    {
      asm("NOP");
    }
  }
} 

void main( void )
{
  P0DIR |= 0x01;  //����P0.0Ϊ�����ʽ
  P2DIR |= 0x01;  //����P2.0Ϊ�����ʽ
  P1DIR &= ~(0x1 << 5); //����P1.0Ϊ���뷽ʽ
  
  P0_0 = 1; 
  P2_0 = 1;   //Ϩ��LED
  
  while(1)
  {
      if(P1_0 == 1){  //OUT=1,�����ӦLED�������������Ӧ                    
          P0_0 = 0;//�װ��ϵ�D2 LED����
          P2_0 = 0;//�װ��ϵ�D3 LED����              
      }
      else{
          P0_0 = 1;//�װ��ϵ�D2 LED����
          P2_0 = 1;//�װ��ϵ�D3 LED����              
      }
      delay();
  }
} // end of main()

