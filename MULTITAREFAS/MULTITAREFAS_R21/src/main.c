/**
 * \file
 *
 * \brief Exemplos diversos de tarefas e funcionalidades de um sistema operacional multitarefas.
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Este arquivo contem exemplos diversos de tarefas e
 * funcionalidades de um sistema operacional multitarefas.
 *
 *
 * \par Conteudo
 *
 * -# Inclui funcoes do sistema multitarefas (atraves de multitarefas.h)
 * -# Inicizalizao do processador e do sistema multitarefas
 * -# Criacao de tarefas de demonstracao
 *
 */

/*
 * Inclusao de arquivos de cabecalhos
 */
#include <asf.h>
#include "stdint.h"
#include "multitarefas.h"

/*
 * Prototipos das tarefas
 */
void tarefa_0(void);
void tarefa_1(void);
void tarefa_2(void);
void tarefa_3(void);
void tarefa_4(void);
void tarefa_5(void);
void tarefa_print(void);
void tarefa_suspend(void);

/*
 * Configuracao dos tamanhos das pilhas
 */
#define TAM_PILHA_0 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_1 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_3 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_4 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_5 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_6 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_7 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_8 (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_PRINT (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_SUSPEND (TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA (TAM_MINIMO_PILHA + 24)

/*
 * Declaracao das pilhas das tarefas
 */
uint32_t PILHA_TAREFA_0[TAM_PILHA_0];
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_3[TAM_PILHA_3];
uint32_t PILHA_TAREFA_4[TAM_PILHA_4];
uint32_t PILHA_TAREFA_5[TAM_PILHA_5];
uint32_t PILHA_TAREFA_6[TAM_PILHA_6];
uint32_t PILHA_TAREFA_7[TAM_PILHA_7];
uint32_t PILHA_TAREFA_8[TAM_PILHA_8];
uint32_t PILHA_TAREFA_PRINT[TAM_PILHA_PRINT];
uint32_t PILHA_TAREFA_SUSP[TAM_PILHA_SUSPEND];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];

/*
 * Funcao principal de entrada do sistema
 */
int main(void)
{
	system_init();

	/* Criacao das tarefas */
	/* Parametros: ponteiro, nome, ponteiro da pilha, tamanho da pilha, prioridade da tarefa */

	CriaTarefa(tarefa_print, "Tarefa Print", PILHA_TAREFA_PRINT, TAM_PILHA_PRINT, 1);
	CriaTarefa(tarefa_4, "Tarefa 4", PILHA_TAREFA_4, TAM_PILHA_4, 2);
	CriaTarefa(tarefa_3, "Tarefa 3", PILHA_TAREFA_3, TAM_PILHA_3, 3);
	CriaTarefa(tarefa_2, "Tarefa 2", PILHA_TAREFA_2, TAM_PILHA_2, 4);
	CriaTarefa(tarefa_1, "Tarefa 1", PILHA_TAREFA_1, TAM_PILHA_1, 5);
	CriaTarefa(tarefa_0, "Tarefa 0", PILHA_TAREFA_0, TAM_PILHA_0, 6);
	CriaTarefa(tarefa_suspend, "Tarefa Suspender", PILHA_TAREFA_SUSP, TAM_PILHA_SUSPEND, 7);

	/* Cria tarefa ociosa do sistema */
	CriaTarefa(tarefa_ociosa, "Tarefa ociosa", PILHA_TAREFA_OCIOSA, TAM_PILHA_OCIOSA, 0);

	/* Configura marca de tempo */
	ConfiguraMarcaTempo();

	/* Inicia sistema multitarefas */
	IniciaMultitarefas();

	/* Nunca chega aqui */
	while (1)
	{
	}
}

volatile uint16_t a = 0;
volatile uint16_t b = 0;
volatile uint16_t c = 0;
volatile uint16_t d = 0;
volatile uint16_t e = 0;

void tarefa_0(void)
{
	for (;;)
	{
		a++;
		TarefaContinua(1);
		TarefaSuspende(6);
	}
}

/* Tarefas de exemplo que usam funcoes para suspender/continuar as tarefas */
void tarefa_1(void)
{
	for (;;)
	{
		b++;
		TarefaContinua(6);
		TarefaSuspende(5);
	}
}

void tarefa_2(void)
{
	for (;;)
	{
		c++;
		TarefaContinua(5);
		TarefaSuspende(4);
	}
}

/* Tarefas de exemplo que usam funcoes para suspender as tarefas por algum tempo (atraso/delay) */
void tarefa_3(void)
{
	for (;;)
	{
		d++;
		TarefaContinua(4);
		TarefaSuspende(3);
	}
}

void tarefa_4(void)
{
	for (;;)
	{
		e++;
		TarefaContinua(3);
		TarefaSuspende(2);
	}
}

void tarefa_print(void)
{
	for (;;)
	{
		volatile uint16_t sum = a + b + c + d + e;
		TarefaSuspende(6);
		TarefaContinua(2);
		TarefaEspera(30000);
	}
}

void tarefa_suspend(void)
{
	for (;;)
	{
		TarefaSuspende(3);
		TarefaSuspende(4);
		TarefaSuspende(5);
		TarefaSuspende(6);
		TarefaSuspende(7);
	}
}

/* Tarefas de exemplo que usam funcoes de semaforo */

semaforo_t SemaforoTeste = {0, 0}; /* declaracao e inicializacao de um semaforo */

void tarefa_5(void)
{

	uint32_t a = 0; /* inicializações para a tarefa */

	for (;;)
	{

		a++; /* código exemplo da tarefa */

		TarefaEspera(3); /* tarefa se coloca em espera por 3 marcas de tempo (ticks) */

		SemaforoLibera(&SemaforoTeste); /* tarefa libera semaforo para tarefa que esta esperando-o */
	}
}

/* Exemplo de tarefa que usa semaforo */
void tarefa_6(void)
{

	uint32_t b = 0; /* inicializações para a tarefa */

	for (;;)
	{

		b++; /* código exemplo da tarefa */

		SemaforoAguarda(&SemaforoTeste); /* tarefa se coloca em espera por semaforo */
	}
}

/* soluçao com buffer compartihado */
/* Tarefas de exemplo que usam funcoes de semaforo */

#define TAM_BUFFER 10
uint8_t buffer[TAM_BUFFER]; /* declaracao de um buffer (vetor) ou fila circular */

semaforo_t SemaforoCheio = {0, 0};			/* declaracao e inicializacao de um semaforo */
semaforo_t SemaforoVazio = {TAM_BUFFER, 0}; /* declaracao e inicializacao de um semaforo */

void tarefa_7(void) // Produtor
{

	uint8_t a = 1; /* inicializações para a tarefa */
	uint8_t i = 0;

	for (;;)
	{
		SemaforoAguarda(&SemaforoVazio);

		buffer[i] = a++;
		i = (i + 1) % TAM_BUFFER;

		SemaforoLibera(&SemaforoCheio); /* tarefa libera semaforo para tarefa que esta esperando-o */
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		TarefaEspera(100); /* tarefa se coloca em espera por 10 marcas de tempo (ticks), equivale a 10ms */
	}
}

/* Exemplo de tarefa que usa semaforo */
void tarefa_8(void) // Consumidor
{
	static uint8_t f = 0;
	volatile uint8_t valor;

	for (;;)
	{
		volatile uint8_t contador;

		do
		{
			REG_ATOMICA_INICIO();
			contador = SemaforoCheio.contador;
			REG_ATOMICA_FIM();

			if (contador == 0)
			{
				TarefaEspera(1000);
			}

		} while (!contador);

		SemaforoAguarda(&SemaforoCheio);
		port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		valor = buffer[f];
		f = (f + 1) % TAM_BUFFER;

		SemaforoLibera(&SemaforoVazio);
	}
}

/* Tarefas de exemplo que usam funcoes de semaforo */

semaforo_t SemaforoTeste = {0, 0}; /* declaracao e inicializacao de um semaforo */

void tarefa_5(void)
{

	uint32_t a = 0; /* inicializações para a tarefa */

	for (;;)
	{

		a++; /* código exemplo da tarefa */

		TarefaEspera(3); /* tarefa se coloca em espera por 3 marcas de tempo (ticks) */

		SemaforoLibera(&SemaforoTeste); /* tarefa libera semaforo para tarefa que esta esperando-o */
	}
}

/* Exemplo de tarefa que usa semaforo */
void tarefa_6(void)
{

	uint32_t b = 0; /* inicializações para a tarefa */

	for (;;)
	{

		b++; /* código exemplo da tarefa */

		SemaforoAguarda(&SemaforoTeste); /* tarefa se coloca em espera por semaforo */
	}
}

/* soluçao com buffer compartihado */
/* Tarefas de exemplo que usam funcoes de semaforo */

#define TAM_BUFFER 10
uint8_t buffer[TAM_BUFFER]; /* declaracao de um buffer (vetor) ou fila circular */

semaforo_t SemaforoCheio = {0, 0};			/* declaracao e inicializacao de um semaforo */
semaforo_t SemaforoVazio = {TAM_BUFFER, 0}; /* declaracao e inicializacao de um semaforo */

void tarefa_7(void) // Produtor
{

	uint8_t a = 1; /* inicializações para a tarefa */
	uint8_t i = 0;

	for (;;)
	{
		SemaforoAguarda(&SemaforoVazio);

		buffer[i] = a++;
		i = (i + 1) % TAM_BUFFER;

		SemaforoLibera(&SemaforoCheio); /* tarefa libera semaforo para tarefa que esta esperando-o */
		port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		TarefaEspera(100); /* tarefa se coloca em espera por 10 marcas de tempo (ticks), equivale a 10ms */
	}
}

/* Exemplo de tarefa que usa semaforo */
void tarefa_8(void) // Consumidor
{
	static uint8_t f = 0;
	volatile uint8_t valor;

	for (;;)
	{
		volatile uint8_t contador;

		do{
			REG_ATOMICA_INICIO();
			contador = SemaforoCheio.contador;
			REG_ATOMICA_FIM();

			if (contador == 0)
			{
				TarefaEspera(1000);
			}

		} while (!contador);

		SemaforoAguarda(&SemaforoCheio);
		port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		valor = buffer[f];
		f = (f + 1) % TAM_BUFFER;

		SemaforoLibera(&SemaforoVazio);
	}
}