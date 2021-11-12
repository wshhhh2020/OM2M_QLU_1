#include "stm32f10x.h"
/********************************硬件接口定义*********************************/
#define LS138A GPIO_Pin_0 //138译码器管脚定义
#define LS138B GPIO_Pin_1
#define LS138C GPIO_Pin_2
/********************************宏定义*********************************/
#define LS138a(x) x ? GPIO_SetBits(GPIOB, LS138A): GPIO_ResetBits(GPIOB, LS138A)
#define LS138b(x) x ? GPIO_SetBits(GPIOB, LS138B): GPIO_ResetBits(GPIOB, LS138B)
#define LS138c(x) x ? GPIO_SetBits(GPIOB, LS138C): GPIO_ResetBits(GPIOB, LS138C)
/******************************** 变量定义 ------------------------------------*/
u8 Count;
u16 Count0;
unsigned long D[16], LedOut[8];
//此表为 LED 的字模, 共阴数码管 0-9 -
unsigned char Disp_Tab[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};
void RCC_Configuration(void);
void GPIO_Configuration(void);//时钟配置子程序
void delay_nms(u16 time);




int main(void)
{
    RCC_Configuration();//配置时钟
    GPIO_Configuration();


    while(1)
{
    unsigned char i;
    Count++;
    if(Count== 100)
    {Count0++;Count= 0;}
    D[1] = D[0] = Count0; // D[1]和D[0]存放计数值
    /********以下将D[1]和D[0]的数据值送到LED数码管显示*************/
    LedOut[0]=Disp_Tab[D[1]%10000/1000]; //千位
    LedOut[1]=Disp_Tab[D[1]%1000/100]; //百位
    LedOut[2]=Disp_Tab[D[1]%100/10]|0x80; //十位
    LedOut[3]=Disp_Tab[D[1]%10]; //个位
    LedOut[4]=Disp_Tab[D[0]%10000/1000]; ;//千位
    LedOut[5]=Disp_Tab[D[0]%1000/100]; ;//百位
    LedOut[6]=Disp_Tab[D[0]%100/10]|0x80;//十位,
    LedOut[7]=Disp_Tab[D[0]%10]; //个位
    for(i=0; i<8; i++)
    { GPIO_Write(GPIOB , LedOut[i]<<8 ); //将LedOut[i]数据送到GPIOB高八位
    switch(i){ //138译码
    case 0: //0 0 0
    LS138c(0); LS138b(0); LS138a(0);
    break;
    case 1: //1 0 0
    LS138c(0); LS138b(0); LS138a(1);
    break;
    case 2: //0 1 0
    LS138c(0); LS138b(1); LS138a(0);
    break;
    case 3: //1 1 0
    LS138c(0); LS138b(1); LS138a(1);
    break;
    case 4: //0 0 1
    LS138c(1); LS138b(0); LS138a(0);
    break;
    case 5: //1 0 1
    LS138c(1); LS138b(0); LS138a(1);
    break;
    case 6: //0 1 1
    LS138c(1); LS138b(1); LS138a(0);
    break;
    case 7: //1 1 1
    LS138c(1); LS138b(1); LS138a(1);
    break;
    }
    delay_nms(1); //延时函数，让第i个数码管点亮1ms,利用视觉暂态效应显示。此值不易大，否则人眼会察觉到数码管的闪烁。
    }
    }
}






/***********************************/




void RCC_Configuration(void)//时钟配置子程序
{
    SystemInit(); //72MHz
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOB的时钟
}




/***********************************/


void GPIO_Configuration(void)//时钟配置子程序
{
    GPIO_InitTypeDef GPIO_InitStructure;//声明GPIO初始化结构变量。
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //IO口配置为推挽输出口
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; //配置管脚PB8-PB15
    
    GPIO_Init(GPIOB,&GPIO_InitStructure); //初始化PB8-PB15
    GPIO_InitStructure.GPIO_Pin=LS138C|LS138B|LS138A; //配置管脚PB2-PB0
    GPIO_Init(GPIOB,&GPIO_InitStructure); //初始化PB2-PB0
    GPIO_SetBits(GPIOB,GPIO_InitStructure.GPIO_Pin); //关闭PB8-PB15
}




/***********************************/




void delay_nms(u16 time)//延时子程序
{
    u16 i=0;
    while(time--)
    {
    i=10000; //自己定义
    while(i--) ;
    }
}