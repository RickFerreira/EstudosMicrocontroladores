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
const uint16_t samples[200]={
		 1861, 1871, 1881, 1891, 1901, 1911, 1921, 1931, 1941, 1951, 1961, 1971, 1981,
		 1991, 2001, 2011, 2021, 2031, 2041, 2051, 2061, 2071, 2081, 2091, 2101, 2111,
		 2121, 2131, 2141, 2151, 2161, 2171, 2181, 2191, 2201, 2211, 2221, 2231, 2241,
		 2251, 2261, 2271, 2281, 2291, 2301, 2311, 2321, 2331, 2341, 2351, 2361, 2371,
		 2381, 2391,2401, 2411, 2421, 2431, 2441, 2451, 2461, 2471, 2481, 2491, 2501};

const uint16_t samples[100]={
		2048, 2176, 2304, 2431, 2557, 2680, 2801, 2919, 3034, 3145,
		3251, 3353, 3449, 3540, 3625, 3704, 3776, 3842, 3900, 3951,
		3995, 4031, 4059, 4079, 4091, 4095, 4091, 4079, 4059, 4031,
		3995, 3951, 3900, 3842, 3776, 3704, 3625, 3540, 3449, 3353,
		3251, 3145, 3034, 2919, 2801, 2680, 2557, 2431, 2304, 2176,
		2048, 1919, 1791, 1664, 1538, 1415, 1294, 1176, 1061, 950,
		844, 742, 646, 555, 470, 391, 319, 253, 195, 144,
		100, 64, 36, 16, 4, 0, 4, 16, 36, 64,
		100, 144, 195, 253, 319, 391, 470, 555, 646, 742,
		844, 950, 1061, 1176, 1294, 1415, 1538, 1664, 1791, 1919};

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
	    	for(uint8_t contador=0; contador<200; ++contador)
		{
			DAC->DHR12R1 = samples[contador];	//escreve no DAC1
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

