/*
 * Projeto: Variando os pulsos de clock
 * Placa: STM32F4VEx
 * Descrição: Ligando led da placa dando pulsos diferentes cada vez menores
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"

void Delay(int atraso)
{
	while(atraso > 0) --atraso;
}

int main(void)
{
	int apagado; // Declara variavel

	RCC->AHB1ENR |= 1; // Liga o clock do GPIO A
	GPIOA->MODER |= (0b01 << 12); // Configura o pino PA6 como saida

	while(1){ //void loop

		apagado= 10000000; // Inicia o valor da variavel

		while(apagado > 0){ //Enquanto apagado maior que 0 continua decrementando o tempo apagado

			GPIOA->ODR |= (1 << 6); // Nível lógico alto no pino 6
			Delay(apagado); // Aguarda um tempo

			apagado -= 1000000; // Decrementa o valor

			GPIOA->ODR &= ~(1 << 6); // Nível lógico baixo no pino 6
			Delay(100000); // Aguarda um tempo
		}
	}
}
