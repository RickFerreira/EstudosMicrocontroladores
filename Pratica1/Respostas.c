/*
 * Projeto: Todos os projetos da primeira prática
 * Placa: STM32F4VEx
 * Descrição: Programação do GPIO
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"
#include "Utility.h" //Incluindo biblioteca para usar a funções para o tempo


//definindo leds
#define LED_OFF6 GPIOA->ODR |= (1<<6) //Desliga o led
#define LED_ON6 GPIOA->ODR &= ~(1<<6) //Liga o led

#define LED_OFF7 GPIOA->ODR |= (1<<7)   //Desliga o led
#define LED_ON7 GPIOA->ODR &= ~(1<<7)   //Liga o led

#define BUZZER_OFF8 GPIOA->ODR |= (1<<8)   //Desliga o buzzer
#define BUZZER_ON8 GPIOA->ODR &= ~(1<<8)   //Liga o buzzer


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
void questa022(void);
void questao23(void);
void questao24(void);
void questao25(void);
void questao26(void);
void questao27(void);



int main(void)
{


	Configure_Clock(); //Configura o clock da placa para sincronizar as funções delay
	Delay_Start();     //Inicia o temporizador interno da placa para ser usado

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

    //Leds
    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída (LED D2)
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída (LED D3)

    //Buzzer
    GPIOA->MODER |= (0b01 << 16);    //configura o pino PA8 como saída (BUZZER)

    //GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
    //GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)

    //Botões
    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)




	//questao1();
	//questao2();
	//questao3();
	//questao4();
	questao5();


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


