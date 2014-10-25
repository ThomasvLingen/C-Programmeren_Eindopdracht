#ifndef WOORDENBOEK_H
#define WOORDENBOEK_H

#include <string.h>

typedef struct{
	//Nederlands
	char woord[30];
	//Engels
	char vertaling[30];
}woordenboekEntry;

typedef struct{
	//Holds entries
	woordenboekEntry* array;
	//Holds the size of the array
	int totalSize;
	//Holds how many places are in use
	int inUse;
}woordenboek;

void initWoordenboek(woordenboek *a, int sizeToMake);
void addToWoordenboek(woordenboek *a, woordenboekEntry toAdd);
void editWoordenboekEntry(woordenboekEntry *target, char woord[], char vertaling[]);
void printWoordenboek(woordenboek *a);

#endif