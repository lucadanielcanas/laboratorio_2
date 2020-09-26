#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    menu();

    return 0;
}

void menu()
{
    int option = 0;
    char control = 's';

    char fileName[] = {"myFile.bin"};
    char fileName2[] = {"myFile2.bin"};
    nodo * list;
    nodo * list2;
    nodo * list3;
    nodo * investedList;
    nodo * aux;
    list = inicLista(list);
    list2 = inicLista(list2);
    list3 = inicLista(list3);
    investedList = inicLista(investedList);
    aux = inicLista(aux);
    int data = 0;

    printf("\t\t MENU DE OPCIONES! \n");

    while(control == 'S' || control == 's')
    {
        printf("1. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada. \n");
        printf("2. Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada. \n");
        printf("3. Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos. \n");
        printf("4. Codificar el TDA Pila con las funciones necesarias, implementada con una lista enlazada (Similar al ejercicio hecho con arreglo). \n");
        printf("5. Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos) \n");
        printf("6. Utilizando el TDA Pila creado en el punto 5, cargar la pila con números enteros. \n");
        printf("7. Eliminar de la lista cargada en el ejercicio anterior, aquellos nodos que contengan valores menores a 10. s\n");

        puts("Seleccione una opcion: \n");
        scanf("%d", &option);

        system("cls");

        switch(option)
        {
            case 1:
                    puts("FILE TO LIST --------------------- \n");
                    list = fileToList(fileName, list);
                    recorrerYmostrar(list);
                break;
            case 2:

                data = elementInList(list, "Luca");
                printf("DATA NUMBER: %d \n", data);

                break;
            case 3:

                list = fileToList(fileName, list);
                list2 = fileToList(fileName2, list2);

                printf("LISTA 1 PADREEEEEE: \n");
                recorrerYmostrar(list);

                system("pause");

                printf("LISTA 2 PADREEEEEEEEEEEEEE: \n");
                recorrerYmostrar(list2);

                system("pause");

                list3 = createANewList(list, list2, list3);

                printf("LISTA 3 PADREEEEE: \n");

                recorrerYmostrar(list3);

                break;
            case 4:
                break;
            case 5:

                list = fileToList(fileName, list);
                printf("LISTA 1 PADREEEEEE: \n");
                recorrerYmostrar(list);

                system("pause");

                investedList = investTheList(list);
                recorrerYmostrar(investedList);

                break;
            case 6:
                break;
            case 7:

                list = fileToList(fileName, list);
                printf("LISTA 1 PADREEEEEE: \n");
                recorrerYmostrar(list);

                system("pause");

                aux = deleteIfLowerToTen(list);

                printf("LISTA AUX PADREEEEEE: \n");
                recorrerYmostrar(aux);

                break;
        }

        puts("Desea ejecutar otra opcion? (s | n) \n");
        fflush(stdin);
        scanf("%c", &control);

        system("cls");
    }
}
