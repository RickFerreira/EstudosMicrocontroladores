/*
 * Projeto: Programando botões
 * Placa: STM32F4VEx
 * Descrição: Usando o pe4 e o pe3 como botão e programando para ligar leds apenas quando os dois estiverem apertados em uma determinada ordem
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"

//definindo os botões
#define k0 !(GPIOE->IDR & (1<<4)) //testando se o botão K0 tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define k1 !(GPIOE->IDR & (1<<3)) //testando o botão K1 á pressionado fazendo um AND com o valor 1 na posição 3 (botão pressionado)

//definindo leds
#define LED_OFF6 GPIOA->ODR |= (1<<6) //Desliga o led
#define LED_ON6 GPIOA->ODR &= ~(1<<6) //Liga o led

#define LED_OFF7 GPIOA->ODR |= (1<<7)   //Desliga o led
#define LED_ON7 GPIOA->ODR &= ~(1<<7)   //Liga o led

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída (LED D3)


    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
    GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)
    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    //o LED em PA6 e em PA7 só deve acender ao pressionar primeiro K0 e depois K1 (Nessa ordem) <==================================
    while(1)
    {
    	//Deslisga os dois leds por default pois os botões estão soltos
		LED_OFF6;
		LED_OFF7;

    	if(k0 && !k1){ //Se k0 pressionado e k1 estiver solto
    		while(k0) //Enquanto k0 estiver pressionado vou vendo se o k1 foi acionado tbm
    		{
    			if(k1) //Se k1 pressionado
    			{
    				//liga os dois leds
    				LED_ON6;
    				LED_ON7;
    			}
    			else //Se k1 estiver solto
    			{
    				//desliga os dois leds
    	    		LED_OFF6;
    	    		LED_OFF7;
    			}
    		}
    	}
    }
}
