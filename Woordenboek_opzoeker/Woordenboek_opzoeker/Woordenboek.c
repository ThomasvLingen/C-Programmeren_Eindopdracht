/*
This file holds all functions related to manipulating an instance of the woordenboek struct.
*/

#include "Woordenboek.h"

void editWoordenboekEntry(woordenboekEntry *target, char woord[], char vertaling[]){
	strcpy_s(target->woord, strlen(woord) + 1, woord);
	strcpy_s(target->vertaling, strlen(vertaling) + 1, vertaling);
}

void initWoordenboek(woordenboek *a, int sizeToMake){
	a->array = (woordenboekEntry *)malloc(sizeToMake * sizeof(woordenboekEntry));
	a->inUse = 0;
	a->totalSize = sizeToMake;
}

void addToWoordenboek(woordenboek *a, woordenboekEntry toAdd){
	//Check if the array is full
	if (a->inUse == a->totalSize){
		a->totalSize++;
		a->array = (woordenboekEntry *)realloc(a->array, a->totalSize * sizeof(woordenboekEntry));
	}
	a->array[a->inUse] = toAdd;
	a->inUse++;
}

void printWoordenboek(woordenboek *a){
	int i;
	printf("All words currently present in the dictionary:\n");
	for (i = 0; i < a->inUse; i++){
		printf("On index %d: %s = %s\n", i, a->array[i].woord, a->array[i].vertaling);
	}
	printf("--------------------------------\n");
}
