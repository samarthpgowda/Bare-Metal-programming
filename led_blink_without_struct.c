//port:A;pin:5
#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIHP_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE 		(PERIPH_BASE+AHB1PERIHP_OFFSET)
#define GPIOA_OFFSET			(0x000U) //0x 0000 0000

#define GPIOA_BASE 				(AHB1PERIPH_BASE+GPIOA_OFFSET)

#define RCC_OFFSET 				(0x3800UL)//resetting clock control
#define RCC_BASE 				(AHB1PERIPH_BASE+RCC_OFFSET)

#define AHB1EN_R_OFFSET 		(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE+AHB1EN_R_OFFSET))//reg

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R 			(*(volatile unsigned int *)(GPIOA_BASE+MODE_R_OFFSET))//reg

#define OD_R_OFFSET 			( 0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))//reg

#define GPIOAEN					(1U<<0)

#define PIN5 					(1U<<5)
#define LED_PIN 				PIN5

//1U<<10
//&=~(1U<11)

int main(void)
{
	//enable clock access to GPIO
	RCC_AHB1EN_R |= GPIOAEN;
	//SET PA5 as output pin
	GPIOA_MODE_R |=(1U<<10);//set bit 10=1;
	GPIOA_MODE_R &=~(1U<<11);//set bit 11=0;
	while (1)
	{
		//GPIOA_OD_R=LED_PIN;
		GPIOA_OD_R ^=LED_PIN;
		for (int i=0;i<100000;i++)
		{}
	}
}







