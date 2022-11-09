/*
 * Projeto: Todos os projetos da primeira prática
 * Placa: STM32F4VEx
 * Descrição: Programação do GPIO
 * Autores: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"
#include "Utility.h" //Incluindo biblioteca para usar a funções para o tempo
#include <stdlib.h>

//definindo leds
#define LED_OFF0 GPIOA->ODR &= ~(1<<0) //Desliga o led
#define LED_ON0 GPIOA->ODR |= (1<<0) //Liga o led

#define LED_OFF1 GPIOA->ODR  &= ~(1<<1) //Desliga o led
#define LED_ON1 GPIOA->ODR |=(1<<1) //Liga o led

#define LED_OFF2 GPIOA->ODR  &= ~(1<<2) //Desliga o led
#define LED_ON2 GPIOA->ODR |= (1<<2) //Liga o led

#define LED_OFF3 GPIOA->ODR &= ~(1<<3) //Desliga o led
#define LED_ON3 GPIOA->ODR |= (1<<3) //Liga o led

#define LED_OFF4 GPIOA->ODR &= ~(1<<4) //Desliga o led
#define LED_ON4 GPIOA->ODR |=  (1<<4) //Liga o led

#define LED_OFF5 GPIOA->ODR &= ~(1<<5) //Desliga o led
#define LED_ON5 GPIOA->ODR |=  (1<<5) //Liga o led

#define LED_OFF6 GPIOA->ODR &= ~(1<<6) //Desliga o led
#define LED_ON6 GPIOA->ODR |= (1<<6) //Liga o led

#define LED_OFF7 GPIOA->ODR  &= ~(1<<7)   //Desliga o led
#define LED_ON7 GPIOA->ODR |= (1<<7)   //Liga o led

//Desligar todos os LEDs
#define LED_OFF LED_OFF0; LED_OFF1; LED_OFF2; LED_OFF3; LED_OFF4; LED_OFF5; LED_OFF6; LED_OFF7;

//definindo transistores do grupo D
#define TRANSISTOR_0_OFF GPIOD->ODR &= ~(1<<0) //Desliga o transistor
#define TRANSISTOR_0_ON GPIOD->ODR |= (1<<0) //Liga o transistor

#define TRANSISTOR_1_OFF GPIOD->ODR  &= ~(1<<1) //Desliga o transistor
#define TRANSISTOR_1_ON  GPIOD->ODR |=(1<<1) //Liga o transistor

//defininco buzzers
#define BUZZER_ON8 GPIOA->ODR |= (1<<8)     //Desliga o buzzer
#define BUZZER_OFF8 GPIOA->ODR &= ~(1<<8)   //Liga o buzzer

#define BUZZER_ON2 GPIOE->ODR  |= (1<<2)  //Desliga o buzzer
#define BUZZER_OFF2 GPIOE->ODR &= ~(1<<2)   //Liga o buzzer

//definindo reles
#define RELE_ON2 GPIOD->ODR |= (1<<2)
#define RELE_OFF2 GPIOD->ODR &= ~(1<<2)

#define RELE_OFF1 GPIOD->ODR |= (1<<1)
#define RELE_ON1 GPIOD->ODR &= ~(1<<1)

//definindo os botões
#define k0 !(GPIOE->IDR & (1<<4)) //testando se o botão K0 tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define kup (GPIOA->IDR & (1)) //testando se o botão K_UP tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define k1 !(GPIOE->IDR & (1<<3)) //testando o botão K1 á pressionado fazendo um AND com o valor 1 na posição 3 (botão pressionado)
#define k2 !(GPIOE->IDR & (1<<5)) //testando o botão K2 á pressionado fazendo um AND com o valor 1 na posição 5 (botão pressionado)

//definindo sensor distancia
#define DISTANCIA10 !(GPIOD->IDR & (1<<10))
#define DISTANCIA11 !(GPIOD->IDR & (1<<11)) 

#define MAX 8
const mask[16] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 57, 94, 121, 113};

void questao1(void);
void questao2(void);
void questao3(void);
void questao4(void);
void questao5(void);
void questao6(void);
void questao7(void);
void questao8(void);
void questao9(void);
void questao10(void);
void questao11(void);
void questao12(void);
void questao13(void);
void questao14(void);
void questao15(void);
void questao16(void);
void questao17(void);
void questao18(void);
void questao19(void);
void questao20(void);
void questao21(void);
void questao22(void);
void questao23(void);
void questao24(void);
void questao25(void);
void questao26(void);
void questao27(void);
void questao28(void);
void questao29(void);
void questao30(void);
void carrinho(void);

int main(void)
{
	Configure_Clock(); //Configura o clock da placa para sincronizar as funções delay
	Delay_Start();     //Inicia o temporizador interno da placa para ser usado

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; //habilita o clock do GPIOD
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

    //Leds
    GPIOA->MODER |= (0b01 << 0);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 2);    //configura o pino PA7 como saída (LED D3)
    GPIOA->MODER |= (0b01 << 4);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 6);    //configura o pino PA7 como saída (LED D3)
    GPIOA->MODER |= (0b01 << 8);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 10);    //configura o pino PA7 como saída (LED D3)
    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída (LED D3)

    //Buzzer
    GPIOA->MODER |= (0b01 << 16);    //configura o pino PA8 como saída (BUZZER)
    GPIOE->MODER |= (0b01 << 4);    //configura o pino PE2 como saída (BUZZER)

    //Relé
    GPIOD->MODER |= (0b01 << 4);    //configura o pino PD2 como saída (Relé)
    GPIOD->MODER |= (0b01 << 2);    //configura o pino PD1 como saída (Relé)

    //Botões
    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
    GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)

    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)

    GPIOE->MODER &= ~(0b11 << 10);    //configurando o pino PE4 como entrada (botão k2)
    GPIOE->PUPDR |= (0b01 << 10);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)
    
    //Sensor ultrasonico
    GPIOD->MODER &= ~(0b11 << 20);    //configurando o pino PD10 como entrada
    GPIOD->MODER &= ~(0b11 << 22);    //configurando o pino PD11 como entrada

    //Todos os leds começam desligados
    LED_OFF;
    RELE_OFF2;

    //Chamando as funções de cada questão

	//questao1();
	//questao2();
	//questao3();
	//questao4();
	//questao5();
	//questao6();
	//questao7();
	//questao8();
	//questao9();
	//questao10();
	//questao11();
	//questao12();
	//questao13();
	//questao14();
	//questao15();
	//questao16();
	//questao17();
	//questao18();
	//questao19();
	//questao20();
	//questao21();
	//questao22();
	//questao23();
	//questao24();
	//questao25();
	//questao26();
	//questao27();
	//questao28();
	//questao29();
	//questao30();
    carrinho();

}

void questao1()
{
    while(1)
    {
    	LED_ON6;
    	Delay_ms(250);
    	LED_OFF6;
    	Delay_ms(250);
    }
}

void questao2()
{
    while(1)
    {
    	LED_ON6;
    	Delay_ms(100);
    	LED_OFF6;
    	Delay_ms(1900);
    }
}

void questao3()
{
    while(1)
    {
    	LED_ON6;
    	Delay_ms(50);
    	LED_OFF6;
    	Delay_ms(1000);

    	LED_ON6;
    	Delay_ms(50);
    	LED_OFF6;
    	Delay_ms(50);
    	LED_ON6;
    	Delay_ms(50);
    	LED_OFF6;
    	Delay_ms(1000);
    }
}

void questao4()
{
    while(1)
    {
    	for(int i = 0; i <= 20; i++){
        	LED_ON6;
        	Delay_ms(50);
        	LED_OFF6;
        	Delay_ms(950/i);
    	}
    }
}

void questao5()
{
    while(1)
    {
    	for(int i=0; i<=3; i++)
    	{
        	BUZZER_ON8;
        	Delay_ms(50); //Chama a função passando como parametros 100 milissegundos
        	BUZZER_OFF8;
        	Delay_ms(50); //Chama a função passando como parametros 100 milissegundos
    	}
    	BUZZER_OFF8;
    	Delay_ms(1200); //Chama a função passando como parametros 100 milissegundos
    }
}

void questao6()
{
    while(1)
    {
    	LED_ON6;
    	LED_ON7;
    	Delay_us(1000);
    	LED_OFF6;
    	LED_OFF7;
    	Delay_us(9000);
    }
}

void questao7()
{
    while(1)
    {
    	LED_OFF6;
    	LED_OFF7;
    	Delay_us(1000000);

    	for(int i=0; i<=9000; i+=30)
    	{
        	LED_ON6;
        	LED_ON7;
        	Delay_us(i);
        	LED_OFF6;
        	LED_OFF7;
        	Delay_us(9000-i);
    	}
    	for(int i=0; i<=9000; i+=30)
    	{
        	LED_ON6;
        	LED_ON7;
        	Delay_us(9000-i);
        	LED_OFF6;
        	LED_OFF7;
        	Delay_us(i);
    	}
    }
}

void questao8()
{
    while(1)
    {
    	LED_ON6;
    	LED_OFF7;
    	Delay_ms(250);
    	LED_OFF6;
    	LED_ON7;
    	Delay_ms(250);
    }
}

void questao9()
{
    while(1)
    {
    	//00
    	LED_OFF6;
    	LED_OFF7;
    	Delay_ms(1000);
    	//01
    	LED_OFF6;
    	LED_ON7;
    	Delay_ms(1000);
    	//10
    	LED_ON6;
    	LED_OFF7;
    	Delay_ms(1000);
    	//11
    	LED_ON6;
    	LED_ON7;
    	Delay_ms(1000);
    }
}

void questao10()
{
    while(1)
    {
    	for(int i=0; i<=9000; i+=20)
    	{
        	LED_ON6;
        	LED_OFF7;
        	Delay_us(i);
        	LED_OFF6;
        	LED_ON7;
        	Delay_us(9000-i);
    	}
    	for(int i=9000; i>=0; i-=20)
    	{
        	LED_OFF6;
        	LED_ON7;
        	Delay_us(9000-i);
        	LED_ON6;
        	LED_OFF7;
        	Delay_us(i);
    	}
    }
}

void questao11()
{
	while(1){
		for(int i=0; i<256; i++){
			GPIOA->ODR |= (i);
			Delay_ms(100);
			LED_OFF;
		}
	}
}

void questao12()
{
	while(1){
		int cont = 1;
		LED_ON0;
		Delay_ms(100);
		LED_OFF;
		for(int i=1; i<9; i++){
			cont = 2*cont;
			GPIOA->ODR |= (cont);
			Delay_ms(100);
			LED_OFF;
		}
		for(int i=1; i<9; i++){
			cont = cont/2;
			GPIOA->ODR |= (cont);
			Delay_ms(100);
			LED_OFF;
		}
	}
}

void questao13()
{
	while(1){
		GPIOA->ODR |= (33);
		Delay_ms(3000);
		LED_OFF;
		GPIOA->ODR |= (34);
		Delay_ms(2000);
		LED_OFF;
		GPIOA->ODR |= (12);
		Delay_ms(3000);
		LED_OFF;
		GPIOA->ODR |= (20);
		Delay_ms(2000);
		LED_OFF;
	}
}

void questao14()
{
	while(1){
		LED_OFF;
		for(int i=0; i<=14; i++){
			GPIOA->ODR |= (mask[i]);
			Delay_ms(1000);
			LED_OFF;
		}
		for(int i=0; i<=15; i++){
			GPIOA->ODR |= (mask[15-i]);
			Delay_ms(1000);
			LED_OFF;
		}
	}
}

void questao15()
{
	LED_OFF;
	while(1){
		for(int j=0; j<=15; j++){
			for(int k=0; k<=15; k++){
				for(int i=0; i<20; i++){
					TRANSISTOR_1_ON;
					TRANSISTOR_0_OFF;

					if((TRANSISTOR_1_ON) && (TRANSISTOR_0_OFF)){
						GPIOA->ODR |= (mask[k]);
						Delay_ms(10);
						LED_OFF;
						TRANSISTOR_1_OFF;
						TRANSISTOR_0_ON;
					}

					if((TRANSISTOR_0_ON) && (TRANSISTOR_1_OFF)){
						GPIOA->ODR |= (mask[j]);
						Delay_ms(10);
						LED_OFF;
					}
				}
			}
		}

		for(int j=0; j<=15; j++){
			for(int k=0; k<=15; k++){
				for(int i=0; i<20; i++){
					TRANSISTOR_1_ON;
					TRANSISTOR_0_OFF;

					if((TRANSISTOR_1_ON) && (TRANSISTOR_0_OFF)){
						GPIOA->ODR |= (mask[15-k]);
						Delay_ms(10);
						LED_OFF;
						TRANSISTOR_1_OFF;
						TRANSISTOR_0_ON;
					}

					if((TRANSISTOR_0_ON) && (TRANSISTOR_1_OFF)){
						GPIOA->ODR |= (mask[15-j]);
						Delay_ms(10);
						LED_OFF;
					}
				}
			}
		}
	}
}

void questao16()
{

}

void questao17()
{
    while(1)
    {
    	for(int i=600; i<=2400; i+=10){
    		LED_ON0;
			Delay_us(i);
			LED_OFF0;
			Delay_us(20000);
    	}
    	for(int i=2400; i>=600; i-=10){
			LED_ON0;
			Delay_us(i);
			LED_OFF0;
			Delay_us(20000);
		}
    }
}

void questao18()
{

}

void questao19()
{
	RELE_OFF2;
	Delay_ms(1000);
	while(1){
		while(k1){
			RELE_ON2;
		}
		RELE_OFF2;
	}
}

void questao20()
{

}

void questao21()
{
    while(1)
    {
		if(kup){
			LED_ON6;
		}
		else{
			LED_OFF6;
		}
    }
}

void questao22()
{
	while(1)
	{
		if(kup){
			LED_ON6;
			if(k0){
				LED_ON7;
			}
			else{
				LED_OFF7;
			}
		}
		else if(k0){
			LED_ON7;
			if(kup){
				LED_ON6;
			}
			else{
				LED_OFF6;
			}
		}
		else{
			LED_OFF6;
			LED_OFF7;
		}
	}
}

void questao23()
{
	int estado = 0;
	while(1){
		if(k0){
			if(estado == 1){
				LED_OFF6;
				Delay_ms(500);
				estado = 0;
			}
			else if(estado == 0){
				LED_ON6;
				Delay_ms(500);
				estado = 1;
			}
		}
	}
}

void questao24()
{
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

void questao25()
{
	while(1)
	{
		if(k0 && !k1){ //Se k0 pressionado e k1 estiver solto
			while(k0) //Enquanto k0 estiver pressionado vou vendo se o k1 foi acionado tbm
			{
				if(Delay_ms <= 1000){
					break;
				}
				if(k1) //Se k1 pressionado
				{
					LED_ON6;
				}
				else //Se k1 estiver solto
				{
					LED_OFF6;
				}
			}
		}
	}

}

void questao26()
{
	int cont = 600;
	LED_ON0;
	Delay_us(cont);
	LED_OFF0;
	Delay_us(20000);
    while(1)
    {
    	if(k0){
    		if(cont == 600){
				LED_ON0;
				Delay_us(cont);
				LED_OFF0;
				Delay_us(20000);
    		}
    		else{
        		cont -= 100;
    			LED_ON0;
    			Delay_us(cont);
    			LED_OFF0;
    			Delay_us(20000);
    		}
    	}
    	if(k1){
    		cont += 100;
			LED_ON0;
			Delay_us(cont);
			LED_OFF0;
			Delay_us(20000);
    	}
    }
}

void questao27()
{
	while(1){
		LED_OFF;
		if(k0){
			GPIOA->ODR |= (mask[1]);
			Delay_ms(100);
			LED_OFF;
		}
		if(k1){
			GPIOA->ODR |= (mask[2]);
			Delay_ms(100);
			LED_OFF;
		}
		if(k2){
			GPIOA->ODR |= (mask[3]);
			Delay_ms(100);
			LED_OFF;
		}
	}
}

void questao28()
{

}

void questao29()
{

}

void questao30()
{
	int nivel = 1;
	int inicio = 0;
	int acertos = 0;
	int genius[6];
	int respostas[6];
	while(1){
		//INICIA O JOGO
    	for(int i=0; i<=3; i++)
    	{
    		LED_ON0;
    		LED_ON1;
    		LED_ON2;
        	BUZZER_ON8;
        	Delay_ms(50);
        	BUZZER_OFF8;
        	LED_OFF;
        	Delay_ms(50);
    	}
    	BUZZER_OFF8;
    	Delay_ms(1500);

    	//Criando sequência aleatoria e colocando na lista
    	for(int i=inicio; i<6; i++){
    		genius[i] = rand()%3;
    	}
    	//Mostrando sequência
    	for(int j=0; j<nivel; j++){
    		if(genius[j] == 0){
    			LED_ON0;
    			Delay_ms(100);
    			LED_OFF;
    			Delay_ms(1000);
    		}
    		if(genius[j] == 1){
    			LED_ON1;
    			Delay_ms(100);
    			LED_OFF;
    			Delay_ms(1000);
    		}
    		if(genius[j] == 2){
    			LED_ON2;
    			Delay_ms(100);
    			LED_OFF;
    			Delay_ms(1000);
    		}
    	}
    	//Receber as repostas
    	for(int k=0; k<nivel; k++){
    		LED_ON0;
    		LED_ON1;
    		LED_ON2;
        	BUZZER_ON8;
        	Delay_ms(100); //Chama a função passando como parametros 100 milissegundos
        	BUZZER_OFF8;
        	LED_OFF;
        	Delay_ms(1000); //Chama a função passando como parametros 100 milissegundos
    		if(k0){
    			LED_ON0;
    			Delay_ms(200);
    			LED_OFF;
    			Delay_ms(1800);
    			respostas[k] = 0;
    		}
    		if(k1){
    			LED_ON1;
    			Delay_ms(200);
    			LED_OFF;
    			Delay_ms(1800);
    			respostas[k] = 1;
    		}
    		if(k2){
    			LED_ON2;
    			Delay_ms(200);
    			LED_OFF;
    			Delay_ms(1800);
    			respostas[k] = 2;
    		}
    	}
		//Conferir respostas
    	for(int l=0; l<nivel; l++){
    		if(genius[l] == respostas[l]){
    			acertos++;
    		}
    	}
    	//Verificando o nível
    	if(acertos == nivel){
    		if(nivel == 6){
    			for(int m=0; m<5; m++){
            		LED_ON0;
        			BUZZER_ON8;
        			Delay_ms(300); //Chama a função passando como parametros 100 milissegundos
        			BUZZER_OFF8;
        			LED_OFF;
        			Delay_ms(300);
    			}
    			nivel = 1;
				inicio = 0;
    		}
    		else{
    			nivel++;
    			inicio++;
    		}
    	}
    	else{
 			LED_ON1;
			BUZZER_ON8;
			Delay_ms(5000); //Chama a função passando como parametros 100 milissegundos
			BUZZER_OFF8;
			LED_OFF;
			Delay_ms(2000);
			nivel = 1;
			inicio = 0;
    	}
    	acertos = 0;
    }

}

void carrinho()
{
	RELE_OFF2;
	LED_OFF;
	Delay_ms(1000);
	while(1){
		while(k1){
			BUZZER_ON2;
			RELE_ON2;
		}
		BUZZER_OFF2;
		RELE_OFF2;
	}
}
