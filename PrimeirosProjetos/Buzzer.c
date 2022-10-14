/*
 * Projeto: Usando buzzer
 * Placa: STM32F4VEx
 * Descrição: Usar buzina como se fosse um alarme para acordar
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"
#include "Utility.h" //Incluindo biblioteca para usar a funções para o tempo

//definindo leds
#define LED_OFF6 GPIOA->ODR |= (1<<6) //Desliga o led
#define LED_ON6 GPIOA->ODR &= ~(1<<6) //Liga o led

#define LED_OFF7 GPIOA->ODR |= (1<<7)   //Desliga o led
#define LED_ON7 GPIOA->ODR &= ~(1<<7)   //Liga o led

#define BUZZER_OFF8 GPIOA->ODR |= (1<<8)   //Desliga o buzzer
#define BUZZER_ON8 GPIOA->ODR &= ~(1<<8)   //Liga o buzzer

int main(void)
{
	Configure_Clock(); //Configura o clock da placa para sincronizar as funções delay
	Delay_Start();     //Inicia o temporizador interno da placa para ser usado

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

    //Leds
    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída (LED D3)

    //Buzzer
    GPIOA->MODER |= (0b01 << 16);    //configura o pino PA8 como saída (BUZZER)

    //GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
    //GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)

    //Botões
    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)

    while(1)
    {
    	for(int i=0; i<=3; i++)
    	{
        	LED_ON6;
        	LED_ON7;
        	BUZZER_ON8;
        	Delay_ms(50); //Chama a função passando como parametros 100 milissegundos
        	LED_OFF6;
        	LED_OFF7;
        	BUZZER_OFF8;
        	Delay_ms(50); //Chama a função passando como parametros 100 milissegundos
    	}
    	LED_OFF6;
    	LED_OFF7;
    	BUZZER_OFF8;
    	Delay_ms(1200); //Chama a função passando como parametros 100 milissegundos
    }

}
