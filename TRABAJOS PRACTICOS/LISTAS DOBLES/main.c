#include "listas_doblemente_enlazadas.h"

//EJERCICIO 1 YA ES PARTE DE LA LIB DE LISTAS DOBLES.

//EJERCICIO 2
int capicuaListasDobles(nodo2 * inicio, nodo2 * fin)
{
    int capicua = 1;

    if(inicio && fin)
    {
        if(inicio->dato != fin->dato)
        {
            capicua = 0;
        }
        else
        {
            if(inicio == fin || fin->siguiente == inicio)
            {
                capicua = 1;
            }
            else
            {
                capicua = capicuaListasDobles(inicio->siguiente, fin->anterior);
            }
        }
    }
    return capicua;
}

//EJERCICIO 3
nodo2 * borrarNodoMedio(nodo2 * lista)
{
    if(lista)
    {
        if(lista->siguiente == NULL)
        {
            free(lista);
            lista = inicList2();
        }
        else
        {
            nodo2 * inicio = lista;
            nodo2 * fin = buscarUltimo(lista);
            while(inicio != fin && fin->siguiente != inicio)
            {
                inicio = inicio->siguiente;
                fin = fin->anterior;
            }

            nodo2 * ante = inicio->anterior;
            ante->siguiente = inicio->siguiente;

            if(inicio->siguiente != NULL) //Valido que no sea el ultimo nodo.
            {
                nodo2 * sig = ante->siguiente; //En caso de no ser el ultimo lo bajo a una variable sig
                sig->anterior = ante; //Hago que el nodo ante se enlace con el nodo siguiente.
            }
            free(inicio);
        }
    }
    return lista;
}

//TODO: REALIZAR LA LIBRERIA DE FILAS.

int main()
{
    return 0;
}
