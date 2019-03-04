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

#define LED1_PIO          PIOA
#define LED1_PIO_ID       10
#define LED1_PIO_IDX      2u
#define LED1_PIO_IDX_MASK (1u << LED1_PIO_IDX)

#define LED2_PIO          PIOA
#define LED2_PIO_ID       10
#define LED2_PIO_IDX      24u
#define LED2_PIO_IDX_MASK (1u << LED2_PIO_IDX)


/*#define BUT_PIO           PIOA // periferico que controla o LED
#define BUT_PIO_ID        10 // ID do periférico PIOC (controla LED)
#define BUT_PIO_IDX       11u // ID do LED no PIO
#define BUT_PIO_IDX_MASK  (1u << BUT_PIO_IDX) // Mascara para CONTROLARMOS o LED*/

#define BMUS_PIO           PIOD
#define BMUS_PIO_ID        16
#define BMUS_PIO_IDX       22u
#define BMUS_PIO_IDX_MASK  (1u << BMUS_PIO_IDX)

#define BNEX_PIO           PIOD
#define BNEX_PIO_ID        16
#define BNEX_PIO_IDX       21u
#define BNEX_PIO_IDX_MASK  (1u << BNEX_PIO_IDX)

/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/


//*****************************************
int BI = 25;
int BM = 15;
int BD = 1.5;

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
	
	// Ativa o PIO na qual o BUZZER foi conectado
	// para que possamos controlar o LED.
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pmc_enable_periph_clk(BMUS_PIO_ID);
	
	//Inicializa PC8 como saída
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	pio_set_output(LED1_PIO, LED1_PIO_IDX_MASK, 0, 0, 0);
	pio_set_output(LED2_PIO, LED2_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_input(BMUS_PIO,BMUS_PIO_IDX,PIO_DEGLITCH);
	pio_pull_up(BMUS_PIO,BMUS_PIO_IDX,1);
	
	pio_set_input(BNEX_PIO,BNEX_PIO_IDX,PIO_DEGLITCH);
	pio_pull_up(BNEX_PIO,BNEX_PIO_IDX,1);
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
  init();
  
  int pausa=1;
  int proxima=0;
  
  while(pausa){
	if(!pio_get(PIOD,PIO_DEGLITCH, BMUS_PIO_IDX_MASK)){
		pausa = !pausa;
	}
  }
  
  while (1)
  {
	pio_set(PIOA, LED1_PIO_IDX_MASK);
	pio_clear(PIOA, LED2_PIO_IDX_MASK);
	for (int i=1;i<notesI[0];i++){
		if(proxima){
			proxima=0;
			break;
		}
		
		double periodo = 1.0/notesI[i];
			
		double duracao=0;
			
		while(duracao < durationI[i]*BI){
			if(!pio_get(PIOD,PIO_DEGLITCH, BMUS_PIO_IDX_MASK)){
				pausa = !pausa;
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
				
				while(pausa){
					delay_ms(170);
					if(!pio_get(PIOD,PIO_DEGLITCH, BMUS_PIO_IDX_MASK)){
						pausa = !pausa;
					}
					delay_ms(170);
				}
			}
			
			if(!pio_get(PIOD,PIO_DEGLITCH, BNEX_PIO_IDX_MASK)){
				proxima = 1;
				break;
			}
					
			if(notesI[i]==0){
				delay_ms(durationI[i]);
				duracao += durationI[i]*BI;
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
			}
			
			else{
				duracao += periodo*1000;
				pio_set(PIOA, BUZZER_PIO_IDX_MASK);
				delay_us(periodo*1000000/2);
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
				delay_us(periodo*1000000/2);
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
			}
		}
			
	}
	
	pio_set(PIOA, LED2_PIO_IDX_MASK);
	pio_clear(PIOA, LED1_PIO_IDX_MASK);
	for (int i=1;i<notesD[0];i++){
		if(proxima){
			proxima=0;
			break;
		}
		
		double periodo = 1.0/notesD[i];
		
		double duracao=0;
		
		while(duracao < durationD[i]*BD){
			if(!pio_get(PIOD,PIO_DEGLITCH, BMUS_PIO_IDX_MASK)){
				pausa = !pausa;
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
				
				while(pausa){
					delay_ms(170);
					if(!pio_get(PIOD,PIO_DEGLITCH, BMUS_PIO_IDX_MASK)){
						pausa = !pausa;
					}
					delay_ms(170);
				}
			}
			
			if(!pio_get(PIOD,PIO_DEGLITCH, BNEX_PIO_IDX_MASK)){
				proxima = 1;
				break;
			}
			
			if(notesD[i]==0){
				delay_ms(durationD[i]);
				duracao += durationD[i]*BI;
				pio_clear(PIOA, BUZZER_PIO_IDX_MASK);
			}
			
			else{
				duracao += periodo*1000;
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
