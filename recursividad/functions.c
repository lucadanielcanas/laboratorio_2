#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Calculo el factorial de un numero n positivo de forma recursiva.
int factorial(int num) //recibo el numero por parametro
{
    int rta = 0;

    if(num == 1 || num == 0){ //condicion de corte
        rta = 1; //Caso base
    }else{
        rta = num * factorial(num - 1); //llamada a funcion recursiva y acercamiento a condicion de corte
    }
    return rta;
}

//Calculo la potencia de un numero n positivo de forma recursiva.
int potencia(int base, int exponente)
{

    int rta = 0;

    if(base == 1 || exponente == 0){
        rta = 1;
    }else{
        rta = base * potencia(base, (exponente - 1));
    }
    return rta;
}

//Funcion para cargar el arreglo, recibo el arreglo y la dimension maximas que va a tener dicho arreglo
int cargarArreglo(int A[], int dimension)
{
    int i = 0;
    int valor = 0;
    char control = 's';

    while(control == 's' && i < dimension){
        printf("Ingrese un dato entero: \n");
        scanf("%d", &valor);
        A[i] = valor;

        i++;

        printf("Desea seguir cargando datos? (s | n): \n");
        fflush(stdin);
        scanf("%c", &control);

        system("cls");
    }
    return i;
}

//Muestro arreglo de manera recursiva, recibo el arreglo, los validos y el index que va a ir incrementando.
void mostrarArregloRecursivo(int A[], int validos, int i)
{

    if(i == validos - 1) //condicion de corte explicita
    {
        printf("[ %d ] \n", A[i]);
    }
    else
    {
        printf("[ %d ] ", A[i]);
        mostrarArregloRecursivo(A, validos, i+1); //acercamiento a condicion de corte.
    }
}

//Muestro arreglo invertido de manera recursiva, recibo el arreglo, los validos y el index que va a ir incrementando.
void mostrarArregloInvertidoRecursivo(int A[], int validos, int i)
{

    if(i == validos - 1)
    {
        printf("[ %d ] ", A[i]); //condicion de corte explicita
    }
    else
    {
        mostrarArregloInvertidoRecursivo(A, validos, i+1); //acercamiento a condicion de corte.
        printf("[ %d ] ", A[i]);
    }
}

//Determino si un arreglo es capicua de forma recursiva, recibo el arreglo, los validos y el index.
int capicuaRecursivo(int A[], int validos)
{
    int rta = 0;
    int i = 0;

    switch(validos)
    {

    case 0:
        rta = 0;
        break;

    case 1:
        rta = 1;
        break;

    default:

        if(A[validos - 1] == A[i])
        {
            i++;
            validos--;
            capicuaRecursivo(A, validos);

            rta = 1;
        }

        break;
    }
    return rta;
}

int sumarRecursivo(int A[], int i, int validos)
{

    int rta = 0;

    if(i == validos)
    {
        rta = 0; //condicion de corte explicita
    }
    else
    {
        rta = A[i] + sumarRecursivo(A, i + 1, validos); //acercamiento a condicion de corte
    }

    return rta;
}

int buscarMenorElementoRecursivo(int A[], int i, int validos)
{

    int rta;

    if(i < validos)
    {
        rta = buscarMenorElementoRecursivo(A, i + 1, validos);
        if(A[i] < A[i + 1])
        {
            rta = A[i];
        }
    }

    return rta;
}

void cargarArchivoInt(char nombreArchivo[])
{
    FILE * File;
    File = fopen(nombreArchivo, "ab");

    int dato;
    char control;

    if(File != NULL)
    {
        do
        {
            printf("Ingrese un numero entero: \n");
            scanf("%d", &dato);

            system("cls");

            fwrite(&dato, sizeof(int), 1, File);

            printf("Desea ingresar otro dato? (s | n) \n");
            fflush(stdin);
            scanf("%c", &control);

            system("cls");

        }while(control == 's');

        fclose(File);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
}

int dimensionArchivo(char nombreArchivo[])
{
    FILE * File;
    File = fopen(nombreArchivo, "rb");

    int validos = 0;

    if(File)
    {
        fseek(File, 0, SEEK_END);
        validos = ftell(File)/sizeof(int);
        fclose(File);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }

    return validos;
}

void mostrarArchivoInt(int i, char nombreArchivo[])
{
    FILE * File;
    File = fopen(nombreArchivo, "rb");

    int dato, val;

    if(File)
    {
        val = dimensionArchivo(nombreArchivo);

        if(i < val)
        {
           fseek(File, i*sizeof(int), SEEK_SET);

           fread(&dato, sizeof(int), 1, File);

           printf("%d \n", dato);

           mostrarArchivoInt(i + 1, nombreArchivo);
        }

        fclose(File);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
}

int menorElementoArchivoRecursivo(int i, char nombreArchivo[])
{
    FILE * File;
    File = fopen(nombreArchivo, "rb");

    int dato, val;
    int valores[val];

    if(File)
    {
        val = dimensionArchivo(nombreArchivo);

        if(i < val)
        {
            fseek(File, i*sizeof(int), SEEK_SET);

            fread(&dato, sizeof(int), 1, File);

            valores[i] = dato;

            if(valores[i - 1] > dato)
            {
                valores[i] = dato;
            }

            menorElementoArchivoRecursivo(i + 1, nombreArchivo);
        }
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }

    return valores[i];
}
