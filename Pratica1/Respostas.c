/*
 * Projeto: Todos os projetos da primeira prática
 * Placa: STM32F4VEx
 * Descrição: Programação do GPIO
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"
#include "Utility.h" //Incluindo biblioteca para usar a funções para o tempo


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

#define LED_OFF LED_OFF0; LED_OFF1; LED_OFF2; LED_OFF3; LED_OFF4; LED_OFF5; LED_OFF6; LED_OFF7;

#define BUZZER_OFF8 GPIOA->ODR |= (1<<8)   //Desliga o buzzer
#define BUZZER_ON8 GPIOA->ODR &= ~(1<<8)   //Liga o buzzer

//definindo os botões
#define k0 !(GPIOE->IDR & (1<<4)) //testando se o botão K0 tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define kup (GPIOA->IDR & (1)) //testando se o botão K_UP tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define k1 !(GPIOE->IDR & (1<<3)) //testando o botão K1 á pressionado fazendo um AND com o valor 1 na posição 3 (botão pressionado)

#define MAX 8


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



int main(void)
{


	Configure_Clock(); //Configura o clock da placa para sincronizar as funções delay
	Delay_Start();     //Inicia o temporizador interno da placa para ser usado

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
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

    //Botões
    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
    GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)

    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)

    //Todos os leds começam desligados
    LED_OFF;

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
	questao23();
	//questao24();
	//questao25();
	//questao26();
	//questao27();
	//questao28();
	//questao29();
	//questao30();

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
			Delay_ms(1000);
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
		for(int i=1; i<=9; i++){
			if(i == 1){
				GPIOA->ODR |= (6);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 2){
				GPIOA->ODR |= (91);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 3){
				GPIOA->ODR |= (79);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 4){
				GPIOA->ODR |= (102);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 5){
				GPIOA->ODR |= (109);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 6){
				GPIOA->ODR |= (124);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 7){
				GPIOA->ODR |= (7);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 8){
				GPIOA->ODR |= (127);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
			if(i == 9){
				GPIOA->ODR |= (103);
				Delay_ms(1000);
				LED_OFF;
				Delay_ms(1000);
			}
		}
	}
}

void questao15()
{

}

void questao16()
{

}

void questao17()
{

}

void questao18()
{

}

void questao19()
{

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
				estado = 0;
			}
			else if(estado == 0){
				LED_ON6;
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

}

void questao26()
{

}

void questao27()
{

}

void questao28()
{

}

void questao29()
{

}

void questao30()
{

}
