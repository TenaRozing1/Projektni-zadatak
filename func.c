#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>
#include <string.h>

NATJECANJE* unosNatjecanja() {
	NATJECANJE* in = (NATJECANJE*)malloc(sizeof(NATJECANJE));
	if (in == NULL) { return NULL; }
	int i;
	int c;
	int menu;
	int rtn = 0;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
	printf("Unesi predmet iz kojeg se natjecanje odvija: \n");
	fgets(in->predmet, 31, stdin);
	printf("Unesi razinu natjecanja (skolsko, zupanijsko ili drzavno): \n");
	while (1) {
		printf("1 - Skolsko \n");
		printf("2 - Zupanijsko \n");
		printf("3 - Drzavno \n");
		rtn = scanf("%d", &menu);
		if (rtn == EOF) {
			fputs("Korisnik prekino input)\n", stderr);
		}
		else if (rtn == 0) {
			fputs("Error: Unesite integer \n \n", stderr);
			do {
				c = getchar();
			} while (c != EOF && c != '\n');
		}
		else {
			if (menu == 1) {
				in->razina_natjecanja = (char*)malloc(8 * sizeof(char));
				if (in->razina_natjecanja == NULL) { return NULL; }
				strcpy(in->razina_natjecanja, "Skolsko");
				break;
			}
			else if (menu == 2) {
				in->razina_natjecanja = (char*)malloc(11 * sizeof(char));
				if (in->razina_natjecanja == NULL) { return NULL; }
				strcpy(in->razina_natjecanja, "Zupanijsko");
				break;
			}
			else if (menu == 3) {
				in->razina_natjecanja = (char*)malloc(8 * sizeof(char));
				if (in->razina_natjecanja == NULL) { return NULL; }
				strcpy(in->razina_natjecanja, "Drzavno");
				break;
			}
		}
	}
	printf("Unesi razred za koji se natjecanje odvija: \n");
	scanf("%s", &in->razred);
	printf("Unesite id natjecanja: \n");
	scanf("%d", &in->id);
	printf("Unesi broj ucenika koji ce sudjelovati na natjecanju: \n");
	scanf("%d", &in->broj_ucenika);
	in->ucenici = (UCENIK*)malloc(in->broj_ucenika * sizeof(UCENIK));
	if (in->ucenici == NULL) { return NULL; }
	for (i = 0; i < in->broj_ucenika; i++) {
		in->ucenici[i] = unosUcenika();
	}
	in->rezultati = 0;
	in->next = NULL;
	return in;
}


void dodajNatjecanje(NATJECANJE* head) {
	NATJECANJE* in = (NATJECANJE*)malloc(sizeof(NATJECANJE));
	NATJECANJE* it = head;
	in = unosNatjecanja();
	while (it->next != NULL) {
		it = it->next;
	}
	it->next = in;
}

void ispisNatjecanja(NATJECANJE* head) {
	NATJECANJE* it = head;
	while (it != NULL) {
		int i;
		printf("Predmet natjecanja: %s \n", it->predmet);
		printf("Razina natjecanja: ");
		for (i = 0; it->razina_natjecanja[i] != '\0'; i++) {
			printf("%c", it->razina_natjecanja[i]);
		}
		printf("\n");
		printf("Razred: %s \n", it->razred);
		printf("ID natjecanja: %d \n \n", it->id);
		it = it->next;
	}

}

NATJECANJE* nadiNatjecanje(NATJECANJE* head, int id) {
	NATJECANJE* it = head;
	while (it != NULL) {
		if (it->id == id) {
			break;
		}
		it = it->next;
	}
	return it;
}

UCENIK unosUcenika() {
	UCENIK in;
	printf("Unesi ime ucenika: \n");
	scanf("%s", &in.ime);
	printf("Unesi prezime ucenika: \n");
	scanf("%s", &in.prezime);
	return in;
}
void unosRezultata(NATJECANJE* natjecanje) {
	int i;
	int rezultat;
	natjecanje->rezultati = 1;
	for (i = 0; i < natjecanje->broj_ucenika; i++){
		do {
			printf("Unesite bodove koje je ucenik %s %s ostvario/la na natjecanju (0-100): \n", natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime);
			scanf("%d", &rezultat);
		} while (rezultat < 0 || rezultat >100);
		natjecanje->ucenici[i].rezultat = rezultat;
	}

}

void ispisRezultata(NATJECANJE* natjecanje) {
	int i;
	if (natjecanje->rezultati == 0) { printf("Za natjecanje nisu uneseni rezultati \n"); }
	else {
		sortRezultati(natjecanje);
		if (!(strcmp(natjecanje->razina_natjecanja, "Skolsko"))) {
			for (i = 0; i < natjecanje->broj_ucenika; i++) {
				if (i == 0) {
					printf("%d. %s %s: %d - Prolazak na zupanijsko \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else if (i == 1) {
					printf("%d. %s %s: %d - Prolazak na zupanijsko \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else if (i == 2) {
					printf("%d. %s %s: %d - Prolazak na zupanijsko\n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else {
					printf("%d. %s %s: %d \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
			}
		}
		if (!(strcmp(natjecanje->razina_natjecanja, "Zupanijsko"))) {
			for (i = 0; i < natjecanje->broj_ucenika; i++) {
				if (i == 0) {
					printf("%d. %s %s: %d - Prolazak na drzavno \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else if (i == 1) {
					printf("%d. %s %s: %d - Knjiga na poklon \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else if (i == 2) {
					printf("%d. %s %s: %d - Knjiga na poklon \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else {
					printf("%d. %s %s: %d \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
			}
		}
		if (!(strcmp(natjecanje->razina_natjecanja, "Drzavno"))) {
			for (i = 0; i < natjecanje->broj_ucenika; i++) {
				if (i == 0) {
					printf("%d. %s %s: %d - Direktan upis na fakultet \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else if (i == 1) {
					printf("%d. %s %s: %d - Pravo na besplatan studentski dom \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else if (i == 2) {
					printf("%d. %s %s: %d - Bodovi za fakultet \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
				else {
					printf("%d. %s %s: %d \n", i + 1, natjecanje->ucenici[i].ime, natjecanje->ucenici[i].prezime, natjecanje->ucenici[i].rezultat);
				}
			}
		}

	}
}

void sortRezultati(NATJECANJE* natjecanje) {
	if (natjecanje->rezultati == 0) { printf("Za natjecanje nisu uneseni rezultati \n \n"); }
	else {
		int i, j;
		for (i = 0; i < natjecanje->broj_ucenika - 1; i++) {
			for (j = 0; j < natjecanje->broj_ucenika - 1 - i; j++) {
				if (natjecanje->ucenici[j].rezultat < natjecanje->ucenici[j + 1].rezultat) {
					UCENIK temp = natjecanje->ucenici[j];
					natjecanje->ucenici[j] = natjecanje->ucenici[j + 1];
					natjecanje->ucenici[j + 1] = temp;
				}
			}
		}
	}
}


void dodijeliNagrade(NATJECANJE* natjecanje) {
	if (natjecanje->rezultati == 0) { printf("Za natjecanje nisu uneseni rezultati \n"); }
	else {
		sortRezultati(natjecanje);
		int i;
		for (i = 0; i < natjecanje->broj_ucenika; i++) {
			if (i < 3) {
				printDiploma(natjecanje->ucenici[i], i + 1, natjecanje);
			}
		}

	}

}
void printDiploma(UCENIK ucenik, int mjesto, NATJECANJE* natjecanje) {
	FILE* fp;
	char* ime_prezime = (char*)malloc(62);
	strcpy(ime_prezime, ucenik.ime);
	strcat(ime_prezime, " ");
	strcat(ime_prezime, ucenik.prezime);
	fp = fopen(strcat(ime_prezime, " - DIPLOMA.txt"), "w");
	if (fp == NULL) {
		perror("Error");
	}
	char* str = (char*)malloc(strlen(natjecanje->razina_natjecanja) + 27 + strlen(natjecanje->predmet));
	strcpy(str, natjecanje->razina_natjecanja);
	strcat(str, "m natjecanju iz predmeta ");
	strtok(natjecanje->predmet, "\n");
	strcat(str, natjecanje->predmet);

	fprintf(fp, "--------------------------------------------------------------------------\n");
	fprintf(fp, "| %*s%*s |\n", 38, "DIPLOMA", 32, "");
	fprintf(fp, "| %*s%*s |\n", 38, " ", 32, "");
	fprintf(fp, "| %*s%*s |\n", 35 + strlen(ime_prezime) / 2, ime_prezime, 35 - strlen(ime_prezime) / 2, "");
	fprintf(fp, "| %*s %d. MJESTO NA: %*s |\n", 34, "ZA OSTVARENO", mjesto, 21, "");
	fprintf(fp, "| %*s%*s |\n", 35 + strlen(str) / 2, str, 35 - strlen(str) / 2, "");
	fprintf(fp, "| %*s%*s |\n", 38, " ", 32, "");
	fprintf(fp, "--------------------------------------------------------------------------\n");
	free(ime_prezime);
	free(str);
	fclose(fp);
}

NATJECANJE* brisiNatjecanje(NATJECANJE* head, int id) {
	NATJECANJE* it = head;
	if (it->next == NULL) {
		free(it->ucenici);
		free(it->razina_natjecanja);
		free(it);
		return NULL;
	}
	else {
		while (it->next != NULL) {
			if (it->next->id == id) {
				break;
			}
			it = it->next;
		}
		NATJECANJE* temp = it->next;
		it->next = it->next->next;
		free(temp->ucenici);
		free(temp->razina_natjecanja);
		free(temp);
		return head;
	}
}

void kraj(NATJECANJE* head) {
	NATJECANJE* it;

	while (head != NULL)
	{
		it = head;
		free(it->ucenici);
		free(it->razina_natjecanja);
		head = head->next;
		free(it);
	}
	free(head);
}

