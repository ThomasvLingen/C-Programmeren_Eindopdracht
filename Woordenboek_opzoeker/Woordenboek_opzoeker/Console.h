#include <string.h>
#include <stdio.h>

#include "Woordenboek.h"
#include "Util.h"
#include "FileIO.h"

void getCommandFromInput(char* dest, char* src);
void getArgumentsFromInput(char stringArray[5][30], char* src);

void handleCommand(char command[], woordenboek *boek);

void quitHandler(woordenboek *boek);
void printHandler(woordenboek *boek);
void helpHandler(woordenboek *boek);