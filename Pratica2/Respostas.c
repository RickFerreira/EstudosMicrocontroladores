/*
 * Projeto: Todos os projetos da segunda prática
 * Placa: STM32F4VEx
 * Descrição: Programação de DAC e ADC no STM32F407
 * Autores: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h" //bibliotecas padrão STM32F4
#include "Utility.h"   //Incluindo biblioteca para usar a funções adicionais
#include <stdlib.h>    //necessário para usar as funções printf e scanf

//definindo os pinos como ligado ou desligado
#define PINO_4_ON GPIOA->ODR |= (1<<4) //Liga pino 4 do gpioA
#define PINO_4_OFF GPIOA->ODR &= ~(1<<4) //Desliga o pino 4 do gpioA

//Desligar todos os pinos da porta A
#define PINOS_A_OFF PINO_4_OFF;

//Criando lista senoide
const mask[200]={1861,2357,1861,1365,1861};


//Chamando as funções
void questao1(void);
void questao2(void);
void questao3(void);
void questao4(void);
void questao5(void);

int main(void)
{
	Configure_Clock(); //Configura o clock da placa para sincronizar as funções delay
	Delay_Start();     //Inicia o temporizador interno da placa para ser usado

	//Habilitando os clocks
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
	RCC->APB1ENR |= RCC_APB1ENR_DACEN;	 //habilita o clock da interface digital do DAC

    //Inicia pino em modo analogico
	GPIOA->MODER |= 0b11 << 8;				//inicialização o pino PA4 no modo analógico
	GPIOA->MODER |= 0b11 << 10;				//inicialização o pino PA4 no modo analógico

	DAC->CR |= DAC_CR_BOFF1;	//desabilita o buffer analógico do DAC1
	DAC->CR |= DAC_CR_EN1;		//habilita o canal 1 do DAC

    //Chamando as funções de cada questão
	//questao1();
	questao2();
	//questao3();
	//questao4();
	//questao5();
}

void questao1()
{
	while(1)
	{
		for(int i=150; i<256; ++i)
		{
			DAC->DHR8R1 = i;	//escreve no DAC1
			Delay_us(30000);	//aguarda para a próxima amostra
		}
		for(int j=255; j>=150; --j)
		{
			DAC->DHR8R1 = j;	//escreve no DAC1
			Delay_us(30000);	//aguarda para a próxima amostra
		}
	}
}

void questao2()
{
    while(1)
    {
		for(int i=0; i<200; ++i)
		{
			DAC->DHR12R1 = (mask[i]);	//escreve no DAC1
			Delay_us(100);				//aguarda para a próxima amostra
		}
    }
}

void questao3()
{
    while(1)
    {

    }
}

void questao4()
{
    while(1)
    {

    }
}

void questao5()
{
    while(1)
    {

    }
}

