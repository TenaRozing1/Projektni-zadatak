#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct UCENIK {
	char ime[31];
	char prezime[31];
	int rezultat;

} UCENIK;


typedef struct NATJECANJE {
	char predmet[31];
	char* razina_natjecanja;
	char razred[2];
	int id;
	int broj_ucenika;
	int rezultati;
	struct NATJECANJE* next;
	UCENIK* ucenici;

} NATJECANJE;

void dodijeliNagrade(NATJECANJE* natjecanje);
NATJECANJE* brisiNatjecanje(NATJECANJE* head, int id);
void printDiploma(UCENIK ucenik, int pozicija, NATJECANJE* natjecanje);
void ispisRezultata(NATJECANJE* natjecanje);
NATJECANJE* nadiNatjecanje(NATJECANJE* headn, int id);
void unosRezultata(NATJECANJE* natjecanje);
void ispisNatjecanja(NATJECANJE* head);
UCENIK unosUcenika();
NATJECANJE* unosNatjecanja();
void dodajNatjecanje(NATJECANJE* head);
void kraj(NATJECANJE* head);
void sortRezultati(NATJECANJE* natjecanje);
#endif