/*普中开发板P2========PB高八位=============数码管接口*/
#include "stm32f10x.h"
// 此表为共阴极7段数码管 LED 的字模
unsigned char LED7Code[]={0x3F,0x06,0x5B,0x4F, 0x66,0x6D,0x7D,0x07, 0x7F,0x6F,0x77,0x7C, 0x39,0x5E,0x79,0x71};
//0011 1111      0000 0110
u8  Count = 0 ;
void RCC_Configuration(void);
void delay_nms(u16 time);
void GPIO_InitTypeDef();
int main(void)
{
        GPIO_InitTypeDef GPIO_InitStructure;//声明GPIO初始化结构变量。
        RCC_Configuration();//配置时钟
        GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //IO口配置为推挽输出口
        GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    
        //配置管脚PB8‐PB15
        GPIO_Init(GPIOB,&GPIO_InitStructure); //初始化PB8‐PB15
        GPIO_SetBits(GPIOB,GPIO_InitStructure.GPIO_Pin); //关闭PB8‐PB15 1
    
        while(1)
        {
        GPIO_Write(GPIOB,LED7Code[Count%16]<<8); //将Count数据送到GPIOB高八位 取余控制循环
            Count++;//将下一位数码管编码送入
        delay_nms(100);
        }
}


void RCC_Configuration(void)//时钟配置子程序
{
        SystemInit();//72MHz
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOB的时钟
}




void delay_nms(u16 time)//延时子程序
{
        u16 i=0;
        while(time--)
        {  
            i=12000;  //自己定义
            while(i--) ;
        }
}