#include "listas.h"

nodo * inicLista(nodo * lista)
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * nodoNuevo = (nodo*)malloc(sizeof(nodo));

    nodoNuevo->dato = dato;
    nodoNuevo->siguiente = NULL;

    return nodoNuevo;
}

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo)
{

    if(lista)
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }

    return lista;
}

void mostrarNodo(nodo * mostrar)
{
    puts("-------------------------------------\n");
    mostrarPersona(mostrar->dato);
    puts("-------------------------------------\n");
}

void recorrerYmostrar(nodo * lista)
{
    nodo * actual;
    actual = lista;

    while(actual != NULL)
    {
        mostrarNodo(actual);
        actual = actual->siguiente;
    }
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * actual = lista;

    if(actual != NULL)
    {
        while(actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
    }
    return actual;
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }

    return lista;
}

nodo * buscarNodo(nodo * lista, char nombre[50])
{
    nodo * actual;
    actual = lista;

    while((actual != NULL) && (strcmp(actual->dato.nombre, nombre) != 0))
    {
        actual = actual->siguiente;
    }

    return actual;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(lista->dato.edad>nuevoNodo->dato.edad)
        {
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo * actual = lista->siguiente;
            nodo * anterior = lista;


            while(actual != NULL && actual->dato.edad<nuevoNodo->dato.edad)
            {
                anterior = actual;
                actual = actual->siguiente;
            }

            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = actual;
        }
    }

    return lista;
}

nodo * borrarNodo(nodo * lista, char nombre[50])
{
    nodo * actual;
    nodo * anterior;

    if(lista != NULL)
    {
        if(strcmp(nombre, lista->dato.nombre) == 0)
        {
            nodo * aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            actual = lista;
            while((actual != NULL) && strcmp(nombre, actual->dato.nombre))
            {
                anterior = actual;
                actual = actual->siguiente;
            }

            if(actual != NULL)
            {
                anterior->siguiente = actual->siguiente;
                free(actual);
            }
        }
    }

    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * actual;
    actual = lista;

    while(actual != NULL)
    {
        proximo = actual->siguiente;
        free(actual);
        actual = proximo;
    }

    return actual;
}

int sumarEdadesLista(nodo * lista)
{
    int suma = 0;
    nodo * actual = lista;

    while(actual != NULL)
    {
        suma = suma + actual->dato.edad;
        actual = actual->siguiente;
    }

    return suma;
}

nodo * eliminarPrimerNodo(nodo * lista)
{
    nodo * actual = lista;

    if(actual)
    {
        lista = actual->siguiente;
        free(actual);
    }
    return lista;
}

nodo * eliminarUltimoNodo(nodo * lista)
{
    nodo * anterior;
    nodo * actual = lista;

    while(actual->siguiente != NULL)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    anterior->siguiente = NULL;
    free(actual);

    return lista;
}

nodo * desvincularPrimerNodo(nodo ** pLista)
{
    nodo * aux = *pLista;
    if(*pLista)
    {
        *pLista = (*pLista)->siguiente;

        aux->siguiente = NULL;
    }
    return aux;
}

