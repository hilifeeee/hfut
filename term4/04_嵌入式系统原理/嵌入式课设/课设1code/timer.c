#include "stdio.h"
#define GPKCON0     		(*((volatile unsigned long *)0x7F008800))
#define GPKDATA     			(*((volatile unsigned long *)0x7F008808))
#define GPFCON          (*((volatile unsigned long *)0x7F0080A0))
#define GPFDAT          (*((volatile unsigned long *)0x7F0080A4))

#define EINT0CON0  			(*((volatile unsigned long *)0x7F008900))
#define EINT0MASK  			(*((volatile unsigned long *)0x7F008920))
#define EINT0PEND  			(*((volatile unsigned long *)0x7F008924))
#define PRIORITY 	    	(*((volatile unsigned long *)0x7F008280))
#define SERVICE     		(*((volatile unsigned long *)0x7F008284))
#define SERVICEPEND 		(*((volatile unsigned long *)0x7F008288))
#define VIC0IRQSTATUS  		(*((volatile unsigned long *)0x71200000))
#define VIC0FIQSTATUS  		(*((volatile unsigned long *)0x71200004))
#define VIC0RAWINTR    		(*((volatile unsigned long *)0x71200008))
#define VIC0INTSELECT  		(*((volatile unsigned long *)0x7120000c))
#define VIC0INTENABLE  		(*((volatile unsigned long *)0x71200010))
#define VIC0INTENCLEAR 		(*((volatile unsigned long *)0x71200014))
#define VIC0PROTECTION 		(*((volatile unsigned long *)0x71200020))
#define VIC0SWPRIORITYMASK 	(*((volatile unsigned long *)0x71200024))
#define VIC0PRIORITYDAISY  	(*((volatile unsigned long *)0x71200028))
#define VIC0ADDRESS        	(*((volatile unsigned long *)0x71200f00))

#define		PWMTIMER_BASE			(0x7F006000)
#define		TCFG0    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x00)) )
#define		TCFG1    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x04)) )
#define		TCON      	( *((volatile unsigned long *)(PWMTIMER_BASE+0x08)) )
#define		TCNTB0    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x0C)) )
#define		TCMPB0    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x10)) )
#define		TCNTO0    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x14)) )
#define		TCNTB1    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x18)) )
#define		TCMPB1    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x1C)) )
#define		TCNTO1    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x20)) )
#define		TCNTB2    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x24)) )
#define		TCMPB2    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x28)) )
#define		TCNTO2    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x2C)) )
#define		TCNTB3    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x30)) )
#define		TCMPB3    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x34)) )
#define		TCNTO3    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x38)) )
#define		TCNTB4    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x3C)) )
#define		TCNTO4    	( *((volatile unsigned long *)(PWMTIMER_BASE+0x40)) )
#define		TINT_CSTAT 	( *((volatile unsigned long *)(PWMTIMER_BASE+0x44)) )

typedef void (isr) (void);
extern void asm_timer_irq();
extern int ishalf;
extern int num;
extern int flag1;
extern int i;
extern int j;
void irq_init(void)
{
	/* 在中断控制器里使能timer0中断 */
	VIC0INTENABLE |= (1<<23);

	VIC0INTSELECT =0;

	isr** isr_array = (isr**)(0x7120015C);

	isr_array[0] = (isr*)asm_timer_irq;
	

	//配置GPF14为输出
	GPFCON |= 1<<28;
	GPFCON &= ~(1<<29);
	
}




// timer0中断的中断处理函数
void do_irq()
{
	unsigned long uTmp;
    //led亮/不亮 
	if(flag1 == 1){//key1被按下
		GPKDAT ^= 0x000000f0;	
	}
	
	if (flag1 == 2)        //key2 被按下
	{
		i++;
		if(i == 0)
			GPKDAT = 0x000000e0;
		else if(i == 2)
			GPKDAT = 0x000000d0;
		else if(i == 4)
			GPKDAT = 0x000000b0;
		else if(i == 6)
			GPKDAT = 0x00000070;
		else if(i == 1 || i == 3 || i == 5 || i == 7)
			GPKDAT = 0x000000f0;
		else if(i == 8)
			i = 0;
	}
		
	if (flag1 == 3)          //key3被按下
	{
		j++;
		if(j == 0)
			GPKDAT = 0x000000e0;
		else if(j == 2)
			GPKDAT = 0x000000d0;
		else if(j == 4)
			GPKDAT = 0x000000b0;
		else if(j == 6)
			GPKDAT = 0x00000070;
		else if(j == 1 || j == 3 || j == 5 || j == 7)
			GPKDAT = 0x000000f0;
		else if(j == 8)
			j = 0;
	}
	
	//清timer0的中断状态寄存器
	uTmp = TINT_CSTAT;
	TINT_CSTAT = uTmp;
	VIC0ADDRESS=0x0;	
}

// 初始化timer
void timer_init(unsigned long utimer,unsigned long uprescaler,unsigned long udivider,unsigned long utcntb,unsigned long utcmpb)
{
	unsigned long temp0;

	// 定时器的输入时钟 = PCLK / ( {prescaler value + 1} ) / {divider value} = PCLK/(65+1)/16=62500hz

	//设置预分频系数为66
	temp0 = TCFG0;
	temp0 = (temp0 & (~(0xff00ff))) | (uprescaler<<0);
	TCFG0 = temp0;

	// 16分频
	temp0 = TCFG1;
	temp0 = (temp0 & (~(0xf<<4*utimer))& (~(1<<20))) |(udivider<<4*utimer);
	TCFG1 = temp0;

	// 1s = 62500hz
	TCNTB0 = utcntb;
	TCMPB0 = utcmpb;

	// 手动更新
	TCON |= 1<<1;

	// 清手动更新位
	TCON &= ~(1<<1);

	// 自动加载和启动timer0
	TCON |= (1<<0)|(1<<3);

	// 使能timer0中断
	temp0 = TINT_CSTAT;
	temp0 = (temp0 & (~(1<<utimer)))|(1<<(utimer));
	TINT_CSTAT = temp0;
}



