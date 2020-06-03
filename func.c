#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <stdlib.h>


UCENIK* unosUcenika(){
	UCENIK* in = (UCENIK*)malloc(sizeof(UCENIK));
	printf("Unesi ime ucenika: \n");
	scanf("%s", &in->ime);
	printf("Unesi prezime ucenika: \n");
	scanf("%s", &in->prezime);
	printf("Unesi id ucenika: \n");
	scanf("%d", &in->id);
	in->next = NULL;
	return in;
}

void dodajUcenika(UCENIK* head_ucenik){
	UCENIK* in = (UCENIK*)malloc(sizeof(UCENIK));
	UCENIK* it = head_ucenik;
	in = unosUcenika();
	while(it->next != NULL){
		it = it->next;
	}
	it->next = in;
}

void ispisiUcenike(UCENIK* head_ucenik){
	UCENIK* it = head_ucenik;
	while (it != NULL){
		printf("Ime ucenika: %s \n", it->ime);
		printf("Prezime ucenika: %s \n", it->prezime);
		printf("ID ucenika: %d \n \n", it->id);
		it = it->next;
	}
}

void kraj(UCENIK* head_ucenik){
	UCENIK* it = head_ucenik;
	while (it != NULL){
		UCENIK* temp = it;
		free(temp);
		it = it->next;
	}
	free(it);
	free(head_ucenik);
}