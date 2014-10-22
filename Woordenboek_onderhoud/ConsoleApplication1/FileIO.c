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