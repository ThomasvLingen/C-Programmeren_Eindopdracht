#include "Woordenboek.h"
#include "Console.h"

#include <stdio.h>
#include <string.h>

int main(){
	char buff1[30];

	woordenboek boek;
	initWoordenboek(&boek, 1);

	//Fills boek according to the contents found in the dat file
	writeFileToWoordenboek(&boek);
	
	printf("Welcome to the dictionary, in order to get a list of commands type \"help\"\n");
	//Main loop, we get input and handle the command continuously in here
	while (1){
		fgets(buff1, 29, stdin);
		//fgets doesn't null terminate your input
		unCaps(&buff1);
		nullTerminate(&buff1);
		handleCommand(buff1, &boek);
	}
}