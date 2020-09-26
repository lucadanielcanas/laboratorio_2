#ifndef LISTAS_DOBLEMENTE_ENLAZADAS_H_INCLUDED
#define LISTAS_DOBLEMENTE_ENLAZADAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo2{
    int dato;
    struct _nodo2 * anterior;
    struct _nodo2 * siguiente;
}nodo2;

nodo2 * inicList2();
nodo2 * crearNodo(int dato);
nodo2 * agregarAlInicio(nodo2 * lista, nodo2 * nuevo);
nodo2 * buscarUltimo(nodo2 * lista);
nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevo);
nodo2 * agregarEnOrden(nodo2 * lista, nodo2 * nuevo);
nodo2 * eliminarBuscado(nodo2 * lista, int dato);
nodo2 * buscarNodo(nodo2 * lista, int dato);
nodo2 * eliminarPrimero(nodo2 * lista);
nodo2 * eliminarUltimo(nodo2 * lista);
void mostrarNodo(nodo2 * nodo);
void mostrarListasDobles(nodo2 * lista);

#endif // LISTAS_DOBLEMENTE_ENLAZADAS_H_INCLUDED
