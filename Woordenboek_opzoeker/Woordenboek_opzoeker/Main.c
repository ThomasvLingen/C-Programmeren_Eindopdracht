/*
This file holds the main function, where the main loop resides.
*/


#include "Woordenboek.h"
#include "Console.h"

#include <stdio.h>
#include <string.h>

int main(){
	int i;
	char input[101];
	char command[30];
	char args[5][30];
	nullifyStringArray(args);

	woordenboek boek;
	//Inits the woordenboek (allocates memory for the array of entries)
	initWoordenboek(&boek, 1);

	//Fills boek according to the contents found in the dat file
	writeFileToWoordenboek(&boek);

	printf("Welcome to the dictionary lookup program, in order to get a list of commands type \"help\"\n\n");
	//Main loop, we get input, seperate the command and arguments and handle the command continuously in here
	while (1){
		fgets(input, 100, stdin);
		//manipulates the user input to make command handling easier
		unCaps(&input);
		nullTerminate(&input);
		getCommandFromInput(&command, &input);
		getArgumentsFromInput(args, &input);

		handleCommand(command, args, &boek);

		//Resets the arguments string array
		nullifyStringArray(args);
	}
}