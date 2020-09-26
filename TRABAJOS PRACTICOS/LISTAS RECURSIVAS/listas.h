#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

typedef struct _nodo{
    persona dato;
    struct _nodo * siguiente;
} nodo;

nodo * inicLista();
nodo * crearNodo(persona dato);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo);
void mostrarNodo(nodo * mostrar);
void recorrerYmostrar(nodo * lista);
nodo * buscarUltimo(nodo * lista);
nodo * agregarAlFinal(nodo * lista, nodo * nuevoNodo);
nodo * buscarNodo(nodo * lista, char nombre[50]);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * borrarNodo(nodo * lista, char nombre[50]);
nodo * borrarTodaLaLista(nodo * lista);
int sumarEdadesLista(nodo * lista);
nodo * eliminarPrimerNodo(nodo * lista);
nodo * eliminarUltimoNodo(nodo * lista);

#endif // LISTAS_H_INCLUDED
