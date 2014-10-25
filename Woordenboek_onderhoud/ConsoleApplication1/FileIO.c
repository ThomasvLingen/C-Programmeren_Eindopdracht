/*
	This file holds all functions related to writing or reading from a file.
*/
#include "FileIO.h"

//Makes a file if there isn't already one and writes the contents of the woordenboek to it
void writeWoordenboekToFile(woordenboek *boek){
	int i;
	FILE *file;
	fopen_s(&file, "..\\..\\dat", "w+");

	for (i = 0; i < boek->inUse; i++){
		fprintf_s(file, "%s = %s\n", boek->array[i].woord, boek->array[i].vertaling);
	}

	fclose(file);
}

void writeFileToWoordenboek(woordenboek *boek){
	FILE *file;
	fopen_s(&file, "..\\..\\dat", "r+");

	char buff[70]; //What we read from dat won't exceed this (30 + 3 + 30)

	//Read a line/stuff it into buff and check if we haven't reached the end of the file
	while (fgets(buff, sizeof(buff), file) != NULL){
		//Do this for every line in the dat file
		if (strchr(buff, '=') != NULL){ //Some validation
			writeLineToWoordenboek(boek, buff);
		} else {
			printf("Something is wrong with your file, delete or fix it\n");
			fclose(file);
			return;
		}
	}

	fclose(file);
}

void writeLineToWoordenboek(woordenboek *boek, char line[]){
	woordenboekEntry tmp;
	int equalsIndex;
	char woord[30];
	char vertaling[30];

	equalsIndex = getEqualsIndex(line);

	//extract a word and translation
	strncpy_s(woord, sizeof(woord), line, equalsIndex - 1);
	woord[strlen(woord)] = '\0';

	strncpy_s(vertaling, sizeof(vertaling), line + (equalsIndex + 2), strlen(line) - (equalsIndex + 2));
	vertaling[strlen(vertaling) - 1] = '\0';

	//Lastly, add it to the woordenboek
	editWoordenboekEntry(&tmp, woord, vertaling);
	addToWoordenboek(boek, tmp);
}

int getEqualsIndex(char line[]){
	int i;
	for (i = 0; i < strlen(line); i++){
		if (line[i] == '='){
			return i;
		}
	}
}