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

void removeFromWoordenboek(woordenboek *a, int indexToRemove){
	woordenboekEntry* temp = (woordenboekEntry *)malloc((a->totalSize - 1) * sizeof(woordenboekEntry));//Make a temporary array of entries

	memcpy(temp, a->array, (indexToRemove) * sizeof(woordenboekEntry));//Copy everything before the entry we want removed into temp
	memcpy(	temp + indexToRemove,
			a->array + indexToRemove + 1,
			(a->inUse - indexToRemove - 1) * sizeof(woordenboekEntry));//Copy everything after the removed entry into temp

	//Realloc the woordenboek's array and copy the temp array's contents to it
	a->array = (woordenboekEntry *)realloc(a->array, ((a->totalSize - 1) * sizeof(woordenboekEntry)));
	memcpy(a->array, temp, (a->totalSize - 1) * sizeof(woordenboekEntry));

	//Update the woordenboek's properties
	a->totalSize--;
	a->inUse--;

	free(temp);
}

void editFromWoordenboek(woordenboek *a, int indexToEdit, char newTranslation[]){
	strcpy_s(a->array[indexToEdit].vertaling, strlen(newTranslation) + 1, newTranslation);
}

void printWoordenboek(woordenboek *a){
	int i;
	printf("All words currently present in the dictionary:\n");
	for (i = 0; i < a->inUse; i++){
		printf("On index %d: %s = %s\n", i, a->array[i].woord, a->array[i].vertaling);
	}
	printf("--------------------------------\n");
}
