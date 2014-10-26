#include <string.h>
#include <stdio.h>

#include "Woordenboek.h"
#include "Util.h"
#include "FileIO.h"

void getCommandFromInput(char dest[], char src[]);
void getArgumentsFromInput(char stringArray[5][30], char* src);

void handleCommand(char command[], char args[5][30], woordenboek *boek);

void quitHandler(woordenboek *boek);
void printHandler(woordenboek *boek);
void helpHandler(woordenboek *boek);

void lookupHandler(woordenboek *boek, char args[5][30]);
void printIfExistsInWoordenboek(woordenboek *boek, char str[]);