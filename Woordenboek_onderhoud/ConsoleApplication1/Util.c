/*
	This file holds all functions that weren't important enough or relevant enough to get their own file.
	You can see this as a pool of general utility functions.
*/

#include "Util.h"

//Replaces the newline at the end of a string retrieved through fgets with a \0
void nullTerminate(char str[]){
	str[strlen(str) - 1] = '\0';
}

//Makes the given string uncapitalised
void unCaps(char str[]){
	int i;
	for (i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
}

//Capitalises the given string
void capitaliseWord(char str[]){
	str[0] = toupper(str[0]);
}