#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>

int main() {
	NATJECANJE* head = NULL;
	int menu;
	int menu_natjecanje;
	int rtn = 0;
	int c;

	while (1) {
		printf("  1 - Unos natjecanja\n ");
		printf(" 2 - Popis natjecanja \n");
		printf("  3 - Trazi natjecanje po id-u \n");
		printf("  4 - Kraj\n ");

		printf("Odaberite opciju:\n ");
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
				if (head == NULL) {
					head = unosNatjecanja();
				}
				else {
					dodajNatjecanje(head);
				}
			}
			else if (menu == 2) {
				if (head == NULL) { printf("Nije uneseno nijedno natjecanje \n"); }
				else { ispisNatjecanja(head); }
			}
			else if (menu == 3) {
				int id;
				printf("Unesite id natjecanja: \n");
				scanf("%d", &id);
				NATJECANJE* natjecanje = nadiNatjecanje(head, id);
				if (natjecanje == NULL) { printf("Natjecanje s tim ID-om ne postoji \n"); }
				else {
					while (1) {
						printf("Predmet natjecanja: %s \n", natjecanje->predmet);
						printf("Razina natjecanja: %s \n", natjecanje->razina_natjecanja);
						printf("Razred: %s \n \n", natjecanje->razred);
						printf("1 - Unos rezultata \n");
						printf("2 - Ispis rezultata \n");
						printf("3 - Isprintaj diplome \n");
						printf("4 - Izbrisi natjecanje \n");
						printf("5 - Povratak \n");
						rtn = scanf("%d", &menu_natjecanje);
						if (rtn == EOF) {
							fputs("Korisnik prekino input)\n", stderr);
							return 1;
						}
						else if (rtn == 0) {
							fputs("Error: Unesite integer \n \n", stderr);
							do {
								c = getchar();
							} while (c != EOF && c != '\n');
						}
						else {
							if (menu_natjecanje == 1) {
								unosRezultata(natjecanje);
							}
							else if (menu_natjecanje == 2) {
								ispisRezultata(natjecanje);
							}
							else if (menu_natjecanje == 3) {
								dodijeliNagrade(natjecanje);
							}
							else if (menu_natjecanje == 4) {
								head = brisiNatjecanje(head, id);
								break;
							}
							else if (menu_natjecanje == 5) {
								break;
							}
							else { printf("Pogresan unos! \n"); }
						}
					}
				}
			}
			else if (menu == 4) {
				kraj(head);
				break;
			}
			else {
				printf("Pogresan unos! \n");
			}
		}
	}
	return 0;
}