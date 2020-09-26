#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

//EJERCICIO 1
void recorrerYmostrarRecursivo(nodo * lista)
{
    if(lista)
    {
        mostrarNodo(lista);
        recorrerYmostrar(lista->siguiente);
    }
}

//EJERCICIO 2
int sumarListaRecursivo(nodo * lista)
{
    int suma = 0;

    if(lista)
    {
        suma = lista->dato.edad + sumarListaRecursivo(lista->siguiente);
    }

    return suma;
}

//EJERCICIO 3
void mostrarUbicadosParRecursivo(nodo * lista)
{
    if(lista)
    {
        mostrarNodo(lista);
        lista = lista->siguiente;
        if(lista)
        {
         mostrarUbicadosParRecursivo(lista->siguiente);
        }
    }
}

//EJERCICIO 4
nodo * invertirListaRecursivo(nodo * lista)
{
    if(lista)
    {
        nodo * aux = lista; //dato actual a aux
        lista = lista->siguiente; //avanzo sobre lista aproximacion
        aux->siguiente = NULL; //desvinculo el nodo actual

        lista = agregarAlFinal(invertirListaRecursivo(lista), aux);
    }
    return lista;
}

//EJERCICIO 5
nodo * borrarNodoRecursivo(nodo * lista, char nombre[50])
{
    if(lista)
    {
        if(strcmp(lista->dato.nombre, nombre) == 0)
        {
            lista = borrarNodo(lista, lista->dato.nombre);
        }
        else
        {
            lista->siguiente = borrarNodoRecursivo(lista->siguiente, nombre);
        }
    }
    return lista;
}

//EJERCICIO 6
nodo * insertarFinalRecursivo(nodo * lista, persona nuevo)
{
    if(lista == NULL)
    {
        lista = crearNodo(nuevo);
    }
    else
    {
        lista->siguiente = insertarFinalRecursivo(lista->siguiente, nuevo);
    }
    return lista;
}

int main()
{
    return 0;
}
