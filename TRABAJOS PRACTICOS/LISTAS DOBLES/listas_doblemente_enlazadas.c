#include "listas_doblemente_enlazadas.h"

nodo2 * inicList2()
{
    return NULL;
}

nodo2 * crearNodo(int dato)
{
    nodo2 * aux = (nodo2*)malloc(sizeof(nodo2));
    aux->dato = dato;
    aux->siguiente = NULL;
    aux->anterior = NULL;
}

nodo2 * agregarAlInicio(nodo2 * lista, nodo2 * nuevo)
{
    if(lista!=NULL)
    {
        lista->anterior = nuevo;
    }
    nuevo->siguiente = lista;

    return nuevo;
}

nodo2 * buscarUltimo(nodo2 * lista)
{
    nodo2 * seguidor = lista;

    if(seguidor != NULL)
    {
        while(seguidor->siguiente != NULL)
        {
            seguidor = seguidor->siguiente;
        }
    }
    return seguidor;
}

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo2 * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return lista;
}

nodo2 * agregarEnOrden(nodo2 * lista, nodo2 * nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        if(nuevo->dato < lista->dato)
        {
            lista = agregarAlInicio(lista, nuevo);
        }
        else
        {
            nodo2 * seguidor = lista->siguiente;
            while(seguidor != NULL && seguidor->dato < nuevo->dato)
            {
                seguidor = seguidor->siguiente;
            }

            if(seguidor != NULL)
            {
                nodo2 * anterior = seguidor->anterior;
                anterior->siguiente = nuevo;
                nuevo->siguiente = seguidor;
                nuevo->anterior = anterior;
                seguidor->anterior = nuevo;
            }
            else
            {
                lista = agregarAlFinal(lista, nuevo);
            }
        }
    }
    return lista;
}

nodo2 * eliminarBuscado(nodo2 * lista, int dato)
{
    nodo2 * aux;
    if(lista != NULL && dato == lista->dato)
    {
        aux = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        free(aux);
    }
    else
    {
        nodo2 * anterior;
        nodo2 * seg = lista;
        while(seg != NULL && dato != seg->dato)
        {
            anterior = seg;
            seg = seg->siguiente;
        }

        if(seg)
        {
            aux = seg;
            anterior->siguiente = seg->siguiente;
            seg->anterior = anterior;
            free(aux);
        }
    }

    return lista;
}

nodo2 * buscarNodo(nodo2 * lista, int dato)
{
    nodo2 * buscado = lista;

    while((buscado != NULL) && (buscado->dato != dato))
    {
        buscado = buscado->siguiente;
    }

    return buscado;
}

nodo2 * eliminarPrimero(nodo2 * lista)
{
    if(lista)
    {
        nodo2 * actual = lista;
        lista = actual->siguiente;
        lista->anterior = NULL;
        free(actual);
    }
    return lista;
}

nodo2 * eliminarUltimo(nodo2 * lista)
{
    if(lista)
    {
        nodo2 * seguidora = lista;
        nodo2 * anterior;

        while(seguidora->siguiente != NULL)
        {
            anterior = seguidora;
            seguidora = seguidora->siguiente;
        }

        if(seguidora)
        {
            anterior->siguiente = NULL;
            free(seguidora);
        }
    }

    return lista;
}

void mostrarNodo(nodo2 * nodo)
{
    puts("---------------------------------------------\n");
    printf("Dato: %d \n", nodo->dato);
    puts("---------------------------------------------\n");
}

void mostrarListasDobles (nodo2 * lista)
{
    nodo2 * aux = lista;

    while(aux!=NULL)
    {
        mostrarNodo(aux);
        aux = aux->siguiente;
    }
}

///////////////////////////////////////////////////SUBPROGRAMAS//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////SUBPROGRAMAS//////////////////////////////////////////////////////////////////

