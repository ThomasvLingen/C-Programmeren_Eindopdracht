#include <string.h>
#include <stdio.h>

#include "Woordenboek.h"
#include "Util.h"
#include "FileIO.h"

void handleCommand(char command[], woordenboek *boek);

void quitHandler(woordenboek *boek);
void printHandler(woordenboek *boek);
void printHandler(woordenboek *boek);
void addHandler(woordenboek *boek);
void removeHandler(woordenboek *boek);
void editHandler(woordenboek *boek);
void helpHandler(woordenboek *boek);