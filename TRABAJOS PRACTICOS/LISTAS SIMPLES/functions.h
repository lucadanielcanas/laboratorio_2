#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

void loadData(persona data);
void loadFile(char fileName[20]);
void printData(persona data);
void getDataFile(char fileName[20]);
nodo * fileToList(char fileName[20], nodo * list);
int elementInList(nodo * list, char element[50]);
nodo * createANewList(nodo * firstList, nodo * secondList, nodo * thirdList);
nodo * investTheList(nodo * list);

#endif // FUNCTIONS_H_INCLUDED
