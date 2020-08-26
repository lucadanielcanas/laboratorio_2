#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void init()
{
    int option = 0;
    char control;

    int num, base, exp, capicua, suma, menor, dimArchivo = 0;
    int arregloInt[] = {45,32,56,56,32,45,90,100,78,87};
    int validos = 10;
    char archivoNum[]={"recursividad.dat"};

    do{
        printf("1. Calcular el factorial de un número en forma recursiva. \n\n");
        printf("2. Calcular la potencia de un número en forma recursiva. \n\n");
        printf("3. Recorrer un arreglo y mostrar sus elementos en forma recursiva. \n\n");
        printf("4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo). \n\n");
        printf("5. Determinar en forma recursiva si un arreglo es capicúa. \n\n");
        printf("6. Sumar en forma recursiva los elementos de un arreglo de enteros. \n\n");
        printf("7. Buscar el menor elemento de un arreglo en forma recursiva. \n\n");
        printf("8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. \n\n");
        printf("9. Invertir los elementos de un archivo de números enteros de forma recursiva. \n\n");
        printf("10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva. \n\n");
        printf("11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos. \n\n");
        printf("12. Determinar si un arreglo contiene un determinado elemento de forma recursiva. \n\n");

        printf("Seleccione un opcion: \n");
        scanf("%d", &option);

        system("cls");

        switch(option)
        {
            case 1:

                printf("Ingrese un numero entero: \n");
                scanf("%d", &num);

                factorial(num);

                break;
            case 2:

                printf("Ingrese la base: \n");
                scanf("%d", &base);

                printf("Ingrese el exponente: \n");
                scanf("%d", &exp);

                potencia(base, exp);

                break;
            case 3:

                validos = cargarArreglo(arregloInt, 10);

                mostrarArregloRecursivo(arregloInt, validos, 0);

                break;
            case 4:

                mostrarArregloInvertidoRecursivo(arregloInt, validos, 0);

                break;
            case 5:

                capicua = capicuaRecursivo(arregloInt, validos);

                if(capicua == 1)
                {
                    printf("El arreglo es capicua. \n");
                }
                else
                {
                    printf("El arreglo NO es capicua. \n");
                }

                break;
            case 6:

                suma = sumarRecursivo(arregloInt, 0, validos);

                printf("La suma de todos los valores del arreglo es: %d \n", suma);

                break;
            case 7:

                menor = buscarMenorElementoRecursivo(arregloInt, 0, validos);
                printf("El menor elemento es: %d \n", menor);

                break;
            case 8:

                 //cargarArchivoInt(archivoNum);
                 dimArchivo = dimensionArchivo(archivoNum);
                 mostrarArchivoInt(0, archivoNum);

                 menor = menorElementoArchivoRecursivo(0, archivoNum);

                printf("Menor: %d \n", menor);

                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
        }

        printf("Desea ejecutar otro ejercicio? (s | n) \n");
        fflush(stdin);
        scanf("%c", &control);

        system("cls");

    }while(control == 's');

}

int main()
{

    init();

    return 0;
}
