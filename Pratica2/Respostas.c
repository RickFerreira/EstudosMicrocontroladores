/*
 * Projeto: Todos os projetos da segunda prática
 * Placa: STM32F4VEx
 * Descrição: Programação de DAC e ADC no STM32F407
 * Autores: Patricia Santos e Richard Ferreira
 * Data: Dezembro de 2022
*/

#include "stm32f4xx.h" //Bibliotecas padrão STM32F4
#include "Utility.h"   //Incluindo biblioteca para usar a funções adicionais
#include <stdlib.h>    //Necessário para usar as funções printf e scanf
#include "Audio.h"     //Chamando a pasta com os dados digtais de um audio

//definindo os pinos como ligado ou desligado
#define PINO_4_ON GPIOA->ODR |= (1<<4) //Liga pino 4 do gpioA
#define PINO_4_OFF GPIOA->ODR &= ~(1<<4) //Desliga o pino 4 do gpioA

//Desligar todos os pinos da porta A
#define PINOS_A_OFF PINO_4_OFF;

//Criando lista senoide
const uint16_t samples[200]={1861, 1876, 1892, 1907, 1923, 1938, 1953, 1969, 1984, 1999,
			     2014, 2029, 2043, 2057, 2072, 2086, 2099, 2113, 2126, 2139,
			     2152, 2165, 2177, 2189, 2200, 2211, 2222, 2233, 2243, 2252,
			     2262, 2271, 2279, 2287, 2295, 2302, 2309, 2316, 2322, 2327,
			     2332, 2337, 2341, 2345, 2348, 2350, 2353, 2354, 2356, 2356,
			     2357, 2356, 2356, 2354, 2353, 2350, 2348, 2345, 2341, 2337,
			     2332, 2327, 2322, 2316, 2309, 2302, 2295, 2287, 2279, 2271,
			     2262, 2252, 2243, 2233, 2222, 2211, 2200, 2189, 2177, 2165,
			     2152, 2139, 2126, 2113, 2099, 2086, 2072, 2057, 2043, 2029,
			     2014, 1999, 1984, 1969, 1953, 1938, 1923, 1907, 1892, 1876,
			     1861, 1845, 1829, 1814, 1798, 1783, 1768, 1752, 1737, 1722,
		    	     1707, 1692, 1678, 1664, 1649, 1635, 1622, 1608, 1595, 1582,
			     1569, 1556, 1544, 1532, 1521, 1510, 1499, 1488, 1478, 1469,
			     1459, 1450, 1442, 1434, 1426, 1419, 1412, 1405, 1399, 1394,
			     1389, 1384, 1380, 1376, 1373, 1371, 1368, 1367, 1365, 1365,
			     1365, 1365, 1365, 1367, 1368, 1371, 1373, 1376, 1380, 1384,
			     1389, 1394, 1399, 1405, 1412, 1419, 1426, 1434, 1442, 1450,
			     1459, 1469, 1478, 1488, 1499, 1510, 1521, 1532, 1544, 1556,
			     1569, 1582, 1595, 1608, 1622, 1635, 1649, 1664, 1678, 1692,
			     1707, 1722, 1737, 1752, 1768, 1783, 1798, 1814, 1829, 1845,
};

//Chamando as funções
void questao1(void);
void questao2(void);
void questao3(void);
void questao4(void);
void questao5(void);

int main(void)
{
	Configure_Clock(); //Configura o clock da placa para sincronizar as funções delay
	USART1_Init();     //inicializa a USART1
	Delay_Start();     //Inicia o temporizador interno da placa para ser usado

	//Habilitando os clocks
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
	RCC->APB1ENR |= RCC_APB1ENR_DACEN;   //habilita o clock da interface digital do DAC
	RCC->APB2ENR |= 1 << 8;              //liga o clock da interface digital do ADC1

    	//Inicia pino em modo analogico
	GPIOA->MODER |= 0b11 << 8;	//inicialização o pino PA4 no modo analógico
	GPIOA->MODER |= 0b11 << 10;	//inicialização o pino PA5 no modo analógico

        GPIOA->MODER |= (0b01 << 2);    //configura o pino PA1 como saída (Servo motor)

	//configuração DA
	DAC->CR |= DAC_CR_BOFF1;	//desabilita o buffer analógico do DAC1
	DAC->CR |= DAC_CR_EN1;		//habilita o canal 1 do DAC

	//configuração AD
	ADC->CCR |= 0b01 << 16;     //prescaler /4
	ADC1->SQR1 &= ~(0xF << 20); //conversão de apenas um canal
	ADC1->SQR3 |= 16; 	    //seleção do canal a ser convertido (IN_16)
	ADC1->SMPR1 |= (7 << 18);   //tempo de amostragem igual a 480 ciclos de ADCCLK
	ADC->CCR |= (1 << 23);	    //liga o sensor de temperatura
	ADC1->CR2 |= 1; 	    //liga o conversor AD

    	//Chamando as funções de cada questão
	//questao1();
	//questao2();
	questao3();
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
			Delay_us(25);				//aguarda para a próxima amostra
		}
	}
}

void questao3()
{
	while(1)
	{
		for(uint32_t contador=0; contador<sizeof(Audio); ++contador)
		{
			DAC->DHR8R1 = Audio[contador];	//escreve no DAC1
			Delay_us(22);			//aguarda a próxima amostra
		}
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
	uint32_t *p = (uint32_t *) 0x1FFF7A2C; //cria ponteiro para uma posição de memória
	uint32_t Word = p[0]; //lê o conteúdo da memória
	uint16_t TS_CAL1 = (Word & 0x0000FFFF); //lê o valor de TS_CAL1
	uint16_t TS_CAL2 = (Word & 0xFFFF0000) >> 16; //lê o valor de TS_CAL2

	while(1)
	{
		ADC1->CR2 |= 1 << 30; //inicia a conversão
		while(!(ADC1->SR & 0x02)); //aguarda o fim da conversão
		//calcula a temperatura
		uint8_t temperatura = ((80*(int)(ADC1->DR - TS_CAL1))/(TS_CAL2-TS_CAL1))+30;
		float final = ((temperatura-35)*0.013)+600;

		if(temperatura<=35){
			GPIOA->ODR |= (1<<1);
			Delay_us(600);
			GPIOA->ODR &= ~(1<<1);
			Delay_us(20000);
		}
		else if(temperatura>=60){
			GPIOA->ODR |= (1<<1);
			Delay_us(2400);
			GPIOA->ODR &= ~(1<<1);
			Delay_us(20000);
		}
		else{
			GPIOA->ODR |= (1<<1);
			Delay_us(final);
			GPIOA->ODR &= ~(1<<1);
			Delay_us(20000);
		}
		Delay_ms(100); //aguarda 100ms para fazer a nova leitura
	}
}
