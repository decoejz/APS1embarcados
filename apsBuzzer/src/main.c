/**
 * 5 semestre - Eng. da Computação - Insper
 * APS 1 - Embarcados - Buzzer
 *
 * Andre Ejzenmesser
 * Manoela Cirne Lima de Campos
 *
 */

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"
#include "notes.h"
#include "musicas.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define BUZZER_PIO          PIOA
#define BUZZER_PIO_ID       10
#define BUZZER_PIO_IDX      4u
#define BUZZER_PIO_IDX_MASK (1u << BUZZER_PIO_IDX)


#define BUT_PIO           PIOA // periferico que controla o LED
#define BUT_PIO_ID        10 // ID do periférico PIOC (controla LED)
#define BUT_PIO_IDX       11u // ID do LED no PIO
#define BUT_PIO_IDX_MASK  (1u << BUT_PIO_IDX) // Mascara para CONTROLARMOS o LED

/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/


//*****************************************
int BI = 25;
int BM = 15;

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

void init(void);

/************************************************************************/
/* interrupcoes                                                         */
/************************************************************************/

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

// Função de inicialização do uC
void init(void)
{
	// Initialize the board clock
	sysclk_init();
	
	// Desativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// Ativa o PIO na qual o LED foi conectado
	// para que possamos controlar o LED.
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	
	//Inicializa PC8 como saída
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	// configura pino ligado ao botão como entrada com um pull-up.
	pio_set_input(BUT_PIO,BUT_PIO_IDX,PIO_DEFAULT);
	
	//Configurando o pull-up
	pio_pull_up(BUT_PIO,BUT_PIO_IDX,1);
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
  init();
  
  while (1)
  {
	int pausa=0;
	for (int i=0;i<34;i++){
		double periodo = 1.0/notesI[i];
			
		double duracao=0;
			
		while(duracao < durationI[i]*BI){
				
			if(!pio_get(PIOA,PIO_DEFAULT, BUT_PIO_IDX_MASK)){
				pausa = !pausa;
					
				while(pausa){
					pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
					delay_ms(200);
					if(!pio_get(PIOA,PIO_DEFAULT, BUT_PIO_IDX_MASK)){
						pausa = !pausa;
					}
				}					
			}
				
			if(notesI[i]==0){
				delay_ms(durationI[i]);
				duracao += durationI[i]*BI;
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
			}
			else{
				duracao +=periodo*1000;
				pio_set(PIOA, BUZZER_PIO_IDX_MASK);
				delay_us(periodo*1000000/2);
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
				delay_us(periodo*1000000/2);
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
			}
		}
			
	}
	
	
	
  }
  return 0;
}
