#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    int edad;
} persona;

void mostrarPersona(persona dato);

#endif // PERSONA_H_INCLUDED
