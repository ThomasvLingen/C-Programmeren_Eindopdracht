/*
This file holds all the functions related to handling commands given by the user through the console.
*/

#include "Console.h"

//I can't use a switch here so a giant if else if ladder will do
//Links all the commands to the appropriate handlers
void handleCommand(char command[], woordenboek *boek){
	if (strcmp(command, "quit") == 0){
		quitHandler(boek);
	}
	else if (strcmp(command, "print") == 0){
		printHandler(boek);
	}
	else if (strcmp(command, "add") == 0){
		addHandler(boek);
	}
	else if (strcmp(command, "remove") == 0){
		removeHandler(boek);
	}
	else if (strcmp(command, "edit") == 0){
		editHandler(boek);
	}
	else if (strcmp(command, "help") == 0){
		helpHandler(boek);
	}
	else {
		printf("I don't recognise the given command \"%s\"\n\n", command);
	}
}

//Handles quitting
void quitHandler(woordenboek *boek){
	//Writes the whole thing to a file
	writeWoordenboekToFile(boek);

	//Makes sure the allocated memory is freed again
	free(boek->array);
	exit();
}

//Handles printing the dictionary
void printHandler(woordenboek *boek){
	printWoordenboek(boek);
	printf("\n");
}

//Handles adding a word to the dictionary using user input
//We get the input, remove any capital characters, null terminate it properly and then capitalise it
void addHandler(woordenboek *boek){
	woordenboekEntry tmp;
	char buff1[30];
	char buff2[30];

	printf("Please type the dutch word you want to put in the dictionary:\n");
	fgets(buff1, 29, stdin);
	unCaps(&buff1);
	nullTerminate(&buff1);
	capitaliseWord(&buff1);

	printf("Secondly, type the english translation of that word:\n");
	fgets(buff2, 29, stdin);
	unCaps(&buff2);
	nullTerminate(&buff2);
	capitaliseWord(&buff2);

	if (strchr(buff1, '=') != NULL || strchr(buff2, '=') != NULL){
		printf("You entered a \'=\' somewhere along the way and as such, we will not add this to the dictionary\n\n");
		return;
	}

	editWoordenboekEntry(&tmp, buff1, buff2);

	addToWoordenboek(boek, tmp);
	printf("%s added to dictionary\n\n", buff1);
}

//Handles removing an entry from the dictionary using the user's input
void removeHandler(woordenboek *boek){
	char buff1[30];
	int i;

	printf("Please type the dutch word you want to remove from dictionary:\n");
	fgets(buff1, 29, stdin);
	unCaps(&buff1);
	nullTerminate(&buff1);
	capitaliseWord(&buff1);

	for (i = 0; i < boek->inUse; i++){
		if (strcmp(boek->array[i].woord, buff1) == 0){
			removeFromWoordenboek(boek, i);
			printf("%s removed from dictionary\n\n", buff1);
			return;
		}
	}
	//We will only get here if we couldn't find an entry with buff1 as the key
	printf("Couldn't find \"%s\" in the dictionary!\n\n", buff1);

}

//Handles editing an entry in the dictionary using the user's input
void editHandler(woordenboek *boek){
	char buff1[30];
	char buff2[30];
	int i;

	printf("Please type the dutch word you want to edit:\n");
	fgets(buff1, 29, stdin);
	unCaps(&buff1);
	nullTerminate(&buff1);
	capitaliseWord(&buff1);

	for (i = 0; i < boek->inUse; i++){
		if (strcmp(boek->array[i].woord, buff1) == 0){
			printf("What will be the new translation for %s?\n", buff1);
			fgets(buff2, 29, stdin);
			unCaps(&buff2);
			nullTerminate(&buff2);
			capitaliseWord(&buff2);

			editFromWoordenboek(boek, i, buff2);
			printf("%s is now translated as %s\n\n", buff1, buff2);
			return;
		}
	}

	//We will only get here if we couldn't find an entry with buff1 as the key
	printf("Couldn't find \"%s\" in the dictionary!\n\n", buff1);
}

void helpHandler(woordenboek *boek){
	printf("Here's a list of possible commands:\n");
	printf("\t\"print\" will print the current contents of the dictionary.\n");
	printf("\t\"add\" will add a word to the dictionary.\n");
	printf("\t\"remove\" will remove a word from the dictionary.\n");
	printf("\t\"edit\" will edit a word's translation from the dictionary.\n");
	printf("\t\"quit\" will save all the changes you made and quit the program.\n\n");
}