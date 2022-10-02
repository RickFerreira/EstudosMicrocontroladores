/*
 * Projeto: Programando botões
 * Placa: STM32F4VEx
 * Descrição: Usando o pe4 e o pe3 como botão e programando para ligar leds apenas quando os dois estiverem apertados
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída

    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada
    GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)
    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    //o LED em PA6 e em PA7 só deve acender ao pressionar primeiro K0 e depois K1 (Nessa ordem)
    while(1)
    {
        GPIOA->ODR |= (1<<6);    //desliga o LED
        GPIOA->ODR |= (1<<7);    //desliga o LED

        if(!(GPIOE->IDR & (1<<4)))    //testando se o botão K0 tá pressionado fazendo um AND com o valor 1 na posição 4
        {
            if(!(GPIOE->IDR & (1<<3)))    //testando o botão K1 á pressionado fazendo um AND com o valor 1 na posição 3
            {
                GPIOA->ODR &= ~(1<<6);    //Liga o led
                GPIOA->ODR &= ~(1<<7);    //Liga o led
            }
            GPIOA->ODR |= (1<<6);    //desliga o LED
            GPIOA->ODR |= (1<<7);    //desliga o LED
        }
    }
}
