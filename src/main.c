/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include <stdint.h>

#include "stm32f4xx.h"
			
#include "FreeRtos.h"
#include "task.h"



TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;


void vTask1_Handler(void *params);
void vTask2_Handler(void *params);

/*Used for semihosting*/
extern void initialise_monitor_handles();

static void prvSetupHardware(void);

int main(void){


#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
	printf("This is hello world example code \n");
#endif

	//1.-Reset the RCC clock configuration to the default reset state
	// HSI ON , PLL OFF , HSE OFF , system clock = 16MHZ , cpu_clock = 16 Mhz

	RCC_DeInit();

	//SystemCoreClock = 16000000;

	//2.-Update the system clock  variable
	SystemCoreClockUpdate();

	prvSetupHardware();

	// 3.- lest create 2 task  task 1 , task 2 , revisar la API

     xTaskCreate(vTask1_Handler,"Task-1",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle1); // Send address
     xTaskCreate(vTask2_Handler,"Task-2",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle2); // Send address

    /*Start the scheduler*/
    vTaskStartScheduler();

    // you will never return here
	for(;;);


}



// Create Handlers for task
void vTask1_Handler(void *params){
	// never return
	while(1){
		//printf("Hello world : from task 1 \n");
	}
}


void vTask2_Handler(void *params){
	// never return
	while(1){
		//printf("Hello world : from task 2 \n");
	}
}


static void prvSetupHardware(void){ // puede ser accesible por otros modulos

	GPIO_InitTypeDef gpio_uart_pins; // se necesita

	// 1.Enable the uart2  peripheral clock
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

    // 2. pa2 is uart2_tx , pa2is uart_rx
    //alternate function configuration of MCU pins to behave as UART2 TX and RX
    gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    gpio_uart_pins.GPIO_Mode = GPIO_Mode_AF;
    gpio_uart_pins.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA,&gpio_uart_pins);

    // 3. AF mode settings for the pins
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); // PA2
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); // PA3

   // 4. UART parameter initializations



}


