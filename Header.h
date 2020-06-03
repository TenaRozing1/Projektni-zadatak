#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct NATJECANJE {
	char predmet[31];
	char razina_natjecanja;
	int razred;
	int *ucenici;

} NATJECANJE;
typedef struct UCENIK {
	char ime[31];
	char prezime[31];
	int id;
	struct UCENIK* next;
	struct NATJECANJE* natjecanja;
} UCENIK;

UCENIK* unosUcenika();
void dodajUcenika(UCENIK* head_ucenik);
void ispisiUcenike();
void kraj(UCENIK* head_ucenik);
//typedef struct NAGRADE {
//
//} NAGRADE;
#endif