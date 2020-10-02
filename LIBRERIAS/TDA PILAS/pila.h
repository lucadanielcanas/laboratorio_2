#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "listas.h"
#define Pila nodo *

void inicPila(Pila * pila);
int pilaVacia(Pila * pila);
void apilar(Pila * pila, int dato);
int desapilar(Pila * pila);
int tope(Pila * pila);
void leer(Pila * pila);
void mostrar(Pila * pila);

#endif // PILA_H_INCLUDED
