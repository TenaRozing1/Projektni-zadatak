#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>

int main(){
	UCENIK* head_ucenik = NULL;
	NATJECANJE* natjecanja; //polje natjecanja
	int n; //broj natjecanja
	int menu;

	while(1){
		printf("  1 - Unos natjecanja\n ");
		printf(" 2 - Unos ucenika \n ");
		printf(" 3 - Ispisi ucenike\n ");
		printf(" 4 - Kraj\n ");

		printf("Odaberite opciju:\n ");
		scanf("%d", &menu);

		if (menu == 1){
			printf("Unesite broj natjecanja za tekucu skolsku godinu: \n");
			scanf("%d", &n);
			natjecanja = (NATJECANJE*)malloc(n*sizeof(NATJECANJE));
		}
		else if (menu == 2){
			if (head_ucenik == NULL){
				head_ucenik = unosUcenika();
			}
			else{
				dodajUcenika(head_ucenik);
			}
		}
		else if (menu == 3){
			ispisiUcenike(head_ucenik);
		}
		else if (menu == 4){
			kraj(head_ucenik);
			break;
		}
		else{
			printf("Pogresan unos!\n ");
		}
	}
	system("pause");
	return 0;
}
