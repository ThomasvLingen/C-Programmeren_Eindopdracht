/*
This file holds all the functions related to handling commands given by the user through the console.
*/

#include "Console.h"

//Puts the command in dest given an entire line of input
void getCommandFromInput(char* dest, char* src){
	int spaceIndex;

	spaceIndex = getNextSpaceIndex(src);

	strncpy_s(dest, sizeof(dest), src, spaceIndex);
	dest[strlen(dest)] = '\0';
}

//Fills the passed array of strings with the commands in the src string (Given that the src string is the input given by the user)
void getArgumentsFromInput(char stringArray[5][30], char* src){
	int i;
	char buff[101];
	char buff2[101];
	int spaceIndex;

	spaceIndex = getNextSpaceIndex(src);
	strncpy_s(buff, sizeof(buff), src + spaceIndex + 1, strlen(src) - (spaceIndex + 1));

	//buff now contains only the arguments we want to stuff into stringArray
	for (i = 0; i < 5; i++){
		spaceIndex = getNextSpaceIndex(buff);
		//Check if there's another argument to put in the array
		if (spaceIndex > 0){
			strncpy_s(stringArray[i], sizeof(stringArray[i]), buff, spaceIndex);
			strncpy_s(buff2, sizeof(buff2), buff + spaceIndex + 1, strlen(buff) - (spaceIndex + 1));
			strcpy_s(buff, sizeof(buff), buff2);
		}
		else {
			strcpy_s(stringArray[i], sizeof(stringArray[i]), buff);
			break;
		}
	}
}

//I can't use a switch here so a giant if else if ladder will do
//Links all the commands to the appropriate handlers
void handleCommand(char command[], woordenboek *boek){
	if (strcmp(command, "help") == 0){
		helpHandler(boek);
	}
	else if (strcmp(command, "quit") == 0){
		quitHandler(boek);
	}
	else if (strcmp(command, "print") == 0){
		printHandler(boek);
	}
	else {
		printf("I don't recognise the given command \"%s\"\n\n", command);
	}
}

//Handles quitting
void quitHandler(woordenboek *boek){
	//Makes sure the allocated memory is freed again
	free(boek->array);
	exit();
}

//Handles printing the dictionary
void printHandler(woordenboek *boek){
	printWoordenboek(boek);
	printf("\n");
}

void helpHandler(woordenboek *boek){
	printf("Here's a list of possible commands:\n");
	printf("\t\"print\" will print the current contents of the dictionary.\n");
	printf("\t\"quit\" will save all the changes you made and quit the program\n\n");
}