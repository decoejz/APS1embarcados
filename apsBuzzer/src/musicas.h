#include <notes.h>

//*****************************************
//Indiana Jones
int notesI[] = {
	35, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C5, 
	NOTE_D4, NOTE_E4, NOTE_F4, 
	NOTE_G4, NOTE_A4, NOTE_B4, NOTE_F5,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
	NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C5,
	NOTE_D5, NOTE_E5, NOTE_F5,
	NOTE_G4,PAUS, NOTE_G4, NOTE_E5,NOTE_D5,
	NOTE_G4, NOTE_E5, NOTE_D5, NOTE_G4, 
	NOTE_E5, NOTE_D5 
	
};

int durationI[] = {
	35,COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, COLCHEIA, COLCHEIA+MINIMA,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, MINIMA+MINIMA/2,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, COLCHEIA, COLCHEIA+MINIMA,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, SEMINIMA, SEMINIMA, SEMINIMA,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, COLCHEIA, COLCHEIA+MINIMA,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, MINIMA+MINIMA/2,
	COLCHEIA+COLCHEIA/2,PAUST, SEMICOLCHEIA, SEMINIMA,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, SEMINIMA,
	COLCHEIA+COLCHEIA/2, SEMICOLCHEIA, SEMINIMA, MINIMA
};

//*****************************************
//Piratas do Caribe	
int notesD[] = { 
   203, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4,
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, 
   NOTE_D5, NOTE_E5, NOTE_A4, 0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,
   //End of Repeat

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};

int durationD[] = { 
  203, 125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};
//*****************************************

int notesM[] = {
    28, 25, NOTE_E4, PAUS, NOTE_E4, NOTE_GS4, NOTE_F4, NOTE_E4,
    NOTE_GS4, PAUS, NOTE_GS4, NOTE_B4, NOTE_A4, NOTE_GS4,
    NOTE_A4, PAUS, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4,
    NOTE_GS4, NOTE_F4, NOTE_GS4,

    NOTE_E4, PAUS, NOTE_E4, NOTE_GS4, NOTE_F4, NOTE_E4,
    NOTE_GS4, PAUS, NOTE_GS4, NOTE_B4, NOTE_A4, NOTE_GS4,
    NOTE_A4, PAUS, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4,
    NOTE_GS4, NOTE_F4, NOTE_GS4,
    
    NOTE_GS4, PAUS, NOTE_GS4, NOTE_F4, NOTE_E4, PAUS, NOTE_E4,
    NOTE_E4, NOTE_F4, PAUS, NOTE_F4, NOTE_E4, NOTE_D4, PAUS,
    NOTE_D4, PAUS, NOTE_D4, PAUS, NOTE_D4, NOTE_F4, NOTE_E4, 
    NOTE_D4, PAUS, NOTE_D4, NOTE_A4, NOTE_GS4, NOTE_F4,
    NOTE_GS4

};

int durationM[] = {
    28, 25, SEMINIMA, PAUST, SEMINIMA+COLCHEIA, COLCHEIA, COLCHEIA,
    COLCHEIA, SEMINIMA, PAUST, SEMINIMA+COLCHEIA, COLCHEIA, 
    COLCHEIA, COLCHEIA, SEMINIMA, PAUST, SEMINIMA+COLCHEIA, 
    COLCHEIA, COLCHEIA, COLCHEIA, SEMINIMA, SEMINIMA,
    MINIMA,

    SEMINIMA, PAUST, SEMINIMA+COLCHEIA, COLCHEIA, COLCHEIA,
    COLCHEIA, SEMINIMA, PAUST, SEMINIMA+COLCHEIA, COLCHEIA, 
    COLCHEIA, COLCHEIA, SEMINIMA, PAUST, SEMINIMA+COLCHEIA, 
    COLCHEIA, COLCHEIA, COLCHEIA, SEMINIMA, SEMINIMA,
    MINIMA,

    COLCHEIA, PAUST, SEMINIMA, COLCHEIA, COLCHEIA, PAUST, COLCHEIA,
    PAUST, SEMINIMA, COLCHEIA, SEMINIMA, COLCHEIA, COLCHEIA, PAUST,
    COLCHEIA, PAUST, SEMINIMA, SEMINIMA, COLCHEIA+SEMICOLCHEIA,
    SEMICOLCHEIA, COLCHEIA, PAUST, COLCHEIA, SEMICOLCHEIA,
    SEMICOLCHEIA, SEMICOLCHEIA, MINIMA

};