/*
 * Projeto: Configurando pinos de entrada
 * Placa: STM32F4VEx
 * Descrição: Usando o pe4 e o pe3 e configurando como entrada de dados
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"

void atraso(int controle){
	while (controle > 1) controle--;
}

int main(void)
{
	RCC -> AHB1ENR |= 1;         // Liga o clock do GPIO A (0b1)
	RCC -> AHB1ENR |=  (1 << 4); // Liga o clock do GPIO E (0b10000)

	//Configurando PA6 e PA7 como saída
	GPIOA -> MODER |= (0b01 << 12); // Configura o pino PA6 como saída para ligar led
	GPIOA -> MODER |= (0b01 << 14); // Configura o pino PA7 como saída para ligar led

	//Configurando PE4 e PE3 como entradas
	GPIOE -> MODER &= ~(0b11 << 6);  // Configura o pino PE3 como entrada (K1) de botão
	GPIOE -> MODER &= ~(0b11 << 8);  // Configura o pino PE4 como entrada (K0) de botão

	// Habilita pino PE4 e PE3 no resistor do Pull-UP
	// (Para garantir que o pino ficará em nível lógico alto enquanto não for clicado o botão)
	GPIOE -> PUPDR |= (0b01 << 6); // Habilita resistor de pull-up para o PE3
	GPIOE -> PUPDR |= (0b01 << 8); // Habilita resistor de pull-up para o PE4

	while (1){ // Void loop

		//Lendo o botão K0 exatamente no bit que ele tá(PE4)
		int a = (GPIOE -> IDR & (1 << 4));
		//Lendo o botão K1 exatamente no bit que ele tá(PE3)
		int b = (GPIOE -> IDR & (1 << 3));

		// Teste para o botão K0 ligar led D2 (PA6) 
		if(a){
			GPIOA -> ODR |= (1 << 6);  // Desliga o led do PA6
		}
		else{
			GPIOA -> ODR &= ~(1 << 6); // Liga o led do PA6
		}
		// Teste para o botão K1 ligar led D3 (PA7) 
		if(b){
			GPIOA -> ODR |= (1 << 7);  // Desliga o led do PA7
		}
		else{
			GPIOA -> ODR &= ~(1 << 7); // Liga o led do PA7
		}

	}
}
