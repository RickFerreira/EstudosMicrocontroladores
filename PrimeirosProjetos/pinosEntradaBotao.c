/*
 * Projeto: Configurando pinos de entrada
 * Placa: STM32F4VEx
 * Descrição: Usando o pe4 e o pe3 e configurando como entrada de dados
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"

void atraso(int delay)
{
	while(delay > 0) --delay;
}

int main(void)
{
	RCC->AHB1ENR |= 1; // Liga o clock do GPIO A
	GPIOA->MODER |= (0b01 << 12); // Configura o pino PA6 como saida
	
	//Configurando PE3 e PE4 como entradas
	GPIOE->MODER &= ~(0b11 << 6); // Configura o pino PE3 como entrada (K1)
	GPIOE->MODER &= ~(0b11 << 8); // Configura o pino PE4 como entrada (K0)

	while(1){ //void loop
		
		//Ligando e desligando led
		GPIOA->ODR |= (1 << 6); // Nível lógico alto no pino 6 (seta bits)
		atraso(1000000); // Aguarda um tempo
		GPIOA->ODR &= ~(1 << 6); // Nível lógico baixo no pino 6 (reseta bits)
		atraso(1000000); // Aguarda um tempo
		
		
	}
}
