#include "pila.h"

void inicPila(Pila * pila) //FUNCIONA
{
    (*pila) = inicLista();
}

int pilaVacia(Pila * pila) //FUNCIONA
{
    return ((*pila)==NULL) ? 1 : 0;
}

void apilar(Pila * pila, int dato) //FUNCIONA
{
    (*pila) = agregarAlPrincipio((*pila), crearNodo(dato));
}

int desapilar(Pila * pila) //FUNCIONA
{
    int dato = (*pila)->dato;
    (*pila) = eliminarPrimerNodo(*pila);

    return dato;
}

int tope(Pila * pila) //FUNCIONA
{
    return (*pila)->dato;
}

void leer(Pila * pila) //FUNCIONA
{
    int dato = 0;
    char control = 's';
    while(control == 's' || control == 'S')
    {
        printf("Ingrese un dato: \n");
        scanf("%d", &dato);
        apilar(pila, dato);

        printf("Desea cargar otro dato? (s | n) \n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

void mostrar(Pila * pila) //FUNCIONA
{
    recorrerYmostrar((*pila));
}
