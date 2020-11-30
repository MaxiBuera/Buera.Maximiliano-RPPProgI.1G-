#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTEBOOKS 5

/*
1. Crear una función llamada calcularIVA que reciba como parámetro el precio bruto de
un producto y devuelva el valor del impuesto (el IVA es 21%). Realizar la llamada desde main. */
float calcularIVA(float precioProducto);

 /*2. Crear una función que se llame reemplazarCaracter que reciba una cadena de caracteres como primer
    parámetro, como segundo parámetro el carácter a reemplazar y como tercero el nuevo carácter y devuelva
     la cantidad de veces que se reemplazo el carácter. int reemplazarCaracter(char [], char, char); */
int reemplazarCaracter(char* cadena, char caracterAReemplazar, char nuevoCaracter);

/*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array
 de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main. */
typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

eNotebook arrayNotebooks[NOTEBOOKS] = {
    {0,"HQ","ASD",100000},
    {0,"Intel","Compaq",100000},
    {0,"AMD","ASD",300000},
    {0,"HQ","ASD",200000},
    {0,"HQ","NOSE",100000},
};

void ordenarArray(eNotebook* arrayNotebooks,int orden);

int main()
{

    //1)
    float precioProducto = 20;
    float impuestoProducto = calcularIVA(precioProducto);
    printf("Valor del impuesto: %.2f",impuestoProducto);

    //2)
    char cadena[20] = "universidad" ;
    reemplazarCaracter(cadena,'i','f');
    printf("\n\n%s",cadena);
    printf("\n");

    //3)
    ordenarArray(arrayNotebooks,0);
    int i;
    for(i=0;i<NOTEBOOKS;i++){

        printf("\n%s %.2f",arrayNotebooks[i].marca,arrayNotebooks[i].precio);
    }
    printf("\n");

    return 0;
}


float calcularIVA(float precioProducto){

    return precioProducto * 0.21;
}

int reemplazarCaracter(char* cadena, char caracterAReemplazar, char nuevoCaracter){

    int i=0;
    int contador=0;

    while(cadena[i] != '\0'){

        if(cadena[i] == caracterAReemplazar){

            cadena[i] = nuevoCaracter;
            contador++;
        }
        i++;
    }

    return contador;
}

void ordenarArray(eNotebook* arrayNotebooks,int orden){

    int i,j;
    eNotebook auxiliar;

    if(arrayNotebooks != NULL)
    {
        for(i=0;i<NOTEBOOKS-1;i++){

            for(j=i+1;j<NOTEBOOKS;j++){

                if(strcmp(arrayNotebooks[i].marca, arrayNotebooks[j].marca) > 0){

                    auxiliar = arrayNotebooks[i];
                    arrayNotebooks[i] = arrayNotebooks[j];
                    arrayNotebooks[j] = auxiliar;
                }
                else if(strcmp(arrayNotebooks[i].marca, arrayNotebooks[j].marca) == 0 && arrayNotebooks[i].precio > arrayNotebooks[j].precio){

                    auxiliar = arrayNotebooks[i];
                    arrayNotebooks[i] = arrayNotebooks[j];
                    arrayNotebooks[j] = auxiliar;
                }
            }
        }
    }

}

