#include <stdio.h>
#include <stdlib.h>

void init();
int factorial(int num);
int potencia(int base, int exponente);
int cargarArreglo(int A[], int dimension);
void mostrarArregloRecursivo(int A[], int validos, int i);
void mostrarArregloInvertidoRecursivo(int A[], int validos, int i);
int capicuaRecursivo(int A[], int validos);
int sumarRecursivo(int A[], int i, int validos);
int buscarMenorElementoRecursivo(int A[], int i, int validos);
void cargarArchivoInt(char nombreArchivo);
void mostrarArchivoInt(char nombreArchivo);
int dimensionArchivo(char nombreArchivo[]);
void mostrarArchivoInt(int i, char nombreArchivo[]);
int menorElementoArchivoRecursivo(int i, char nombreArchivo);
