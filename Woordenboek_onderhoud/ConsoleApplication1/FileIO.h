#include <stdio.h>
#include "Woordenboek.h"

void writeWoordenboekToFile(woordenboek *boek);
void writeFileToWoordenboek(woordenboek *boek);
void writeLineToWoordenboek(woordenboek *boek, char line[]);
int getEqualsIndex(char line[]);