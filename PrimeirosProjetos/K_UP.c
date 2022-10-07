/*
 * Projeto: Usando K_UP
 * Placa: STM32F4VEx
 * Descrição: Implementando botão K_UP
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"
#include "Utility.h" //Incluindo biblioteca para usar a funções para o tempo

//definindo os botões
#define k0 !(GPIOE->IDR & (1<<4)) //testando se o botão K0 tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define kup (GPIOA->IDR & (1)) //testando se o botão K_UP tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
//#define k1 !(GPIOE->IDR & (1<<3)) //testando o botão K1 á pressionado fazendo um AND com o valor 1 na posição 3 (botão pressionado)

//definindo leds
#define LED_OFF6 GPIOA->ODR |= (1<<6) //Desliga o led
#define LED_ON6 GPIOA->ODR &= ~(1<<6) //Liga o led

#define LED_OFF7 GPIOA->ODR |= (1<<7)   //Desliga o led
#define LED_ON7 GPIOA->ODR &= ~(1<<7)   //Liga o led

void atraso()
{
	int controle = 8000000;
	while(controle > 1) controle--;
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída (LED D3)

    //GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
    //GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)

    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)



    //o LED em PA6 e em PA7 só deve acender ao pressionar primeiro K0 e depois K1 (Nessa ordem)
    while(1)
    {
		if(kup){
			LED_ON6;
			LED_ON7;
		}
		else{
			LED_OFF6;
			LED_OFF7;
		}
    }
}
