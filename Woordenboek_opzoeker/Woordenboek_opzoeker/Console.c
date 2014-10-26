/*
This file holds all the functions related to handling commands given by the user through the console.
*/

#include "Console.h"

//Puts the command in dest given an entire line of input
void getCommandFromInput(char dest[], char src[]){
	int spaceIndex;

	spaceIndex = getNextSpaceIndex(src);
	strncpy_s(dest, 29, src, spaceIndex);
	dest[strlen(dest)] = '\0';
}

//Fills the passed array of strings with the commands in the src string (Given that the src string is the input given by the user)
void getArgumentsFromInput(char stringArray[5][30], char* src){
	int i;
	char buff[101];
	char buff2[101];
	int spaceIndex;

	spaceIndex = getNextSpaceIndex(src);
	//If this is the case, we can conclude that there were no arguments
	if (spaceIndex < 0){
		return;
	}
	strncpy_s(buff, 71, src + spaceIndex + 1, strlen(src) - (spaceIndex + 1));

	//buff now contains only the arguments we want to stuff into stringArray
	for (i = 0; i < 5; i++){
		spaceIndex = getNextSpaceIndex(buff);
		//Check if there's another argument to put in the array
		if (spaceIndex > 0){
			strncpy_s(stringArray[i], 30, buff, spaceIndex);
			strncpy_s(buff2, 71, buff + spaceIndex + 1, strlen(buff) - (spaceIndex + 1));
			//Make buff the part that we still have to process
			strcpy_s(buff, 71, buff2);
		}
		else {
			strcpy_s(stringArray[i], 30, buff);
			break;
		}
	}
}

//I can't use a switch here so a giant if else if ladder will do
//Links all the commands to the appropriate handlers
void handleCommand(char command[], char args[5][30], woordenboek *boek){
	if (strcmp(command, "help") == 0){
		helpHandler(boek);
	} else if (strcmp(command, "quit") == 0){
		quitHandler(boek);
	} else if (strcmp(command, "print") == 0){
		printHandler(boek);
	}
	else if (strcmp(command, "lookup") == 0){
		lookupHandler(boek, args);
	} else {
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

//Gives a little help screen showing all possible commands
void helpHandler(woordenboek *boek){
	printf("Here's a list of possible commands:\n");
	printf("\t\"print\" will print the current contents of the dictionary.\n");
	printf("\t\"quit\" will save all the changes you made and quit the program.\n");
	printf("\t\"lookup <argument1> <argument2>\" etc. will look up a word.\n\n");
}

//Looks up the translations of given words
void lookupHandler(woordenboek *boek, char args[5][30]){
	int i;

	//Gets run if we aren't given any arguments
	if (args[0][0] == '\0'){
		printf("Type in one or more words to look up\n\n");
		return;
	}

	for (i = 0; i < 5; i++){
		if (args[i][0] != '\0'){
			printIfExistsInWoordenboek(boek, args[i]);
		}
	}

	printf("\n");
}

//Prints the word and translation of given input if it's present in the woordenboek
void printIfExistsInWoordenboek(woordenboek *boek, char str[]){
	int i;

	for (i = 0; i < boek->inUse; i++){
		capitaliseWord(str);
		//Check if it's in the woordenboek
		if (strcmp(boek->array[i].woord, str) == 0){
			printf("%s --> %s\n", boek->array[i].woord, boek->array[i].vertaling);
			return;
		}
	}

	//If we get here, it's not in the woordenboek
	printf("%s --> ???\n", str);
}