//port:A;pin:5
#include <stdint.h>
#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIHP_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE 		(PERIPH_BASE+AHB1PERIHP_OFFSET)
#define GPIOA_OFFSET			(0x000U) //0x 0000 0000

#define GPIOA_BASE 				(AHB1PERIPH_BASE+GPIOA_OFFSET)

#define RCC_OFFSET 				(0x3800UL)//resetting clock control
#define RCC_BASE 				(AHB1PERIPH_BASE+RCC_OFFSET)


#define GPIOAEN					(1U<<0)

#define PIN5 					(1U<<5)
#define LED_PIN 				PIN5

#define __IO volatile

typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;
}RCC_TypeDef;

typedef struct
{
	volatile uint32_t MODER;//GPIO PORT MODE REGISTER
	volatile uint32_t DUMMY[4];//DUMMY REGISTER FOR OMPENSATING THE REGISTER BETWEEN THIS
	volatile uint32_t ODR;//OUTPUT DATA REGISTER

}GPIO_TypeDef;

#define RCC      ((RCC_TypeDef*) RCC_BASE)
#define GPIOA    ((GPIO_TypeDef*) GPIOA_BASE)

int main(void)
{
	//enable clock access to GPIO
	//RCC_AHB1EN_R |= GPIOAEN;
	RCC ->AHB1ENR |= GPIOAEN;
	//SET PA5 as output pin
	//GPIOA_MODE_R |=(1U<<10);//set bit 10=1;
	//GPIOA_MODE_R &=!(1U<<11);//set bit 11=0;
	GPIOA ->MODER |=(1U<<10);
	GPIOA ->MODER &=!(1U<<11);
	while (1)
	{
		//GPIOA_OD_R=LED_PIN;
		//GPIOA_OD_R ^=LED_PIN;
		GPIOA ->ODR^=LED_PIN;
		for (int i=0;i<100000;i++)
		{}
	}
}







