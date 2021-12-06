#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

/*
1. Crear una funci�n llamada calcularIVA que reciba como primer par�metro el precio bruto de un producto
y como segundo par�metro la direcci�n de memoria de una variable donde debe escribir el valor del impuesto(el IVA es 21%).
La funci�n retorna 1 si sali� todo bien o 0 si hubo alg�n error. Realizar la llamada desde main. *
*/
int calcularIva(float precio, int* descIva);
/*2. Crear una funci�n que se llame subibaja que reciba una cadena de caracteres
y que los caracteres en min�scula los pase a may�scula
y los que est�n en may�scula los pase a min�scula retorna 1 si esta todo bien o 0 si hubo alg�n error. *
*/
int subiBaja(char cadena[]);

/*3. Dada la estructura Notebook(id, procesador, marca, precio) generar una funci�n que
permita ordenar un array de dicha estructura por marca ascendente
Ante igualdad de marca deber� ordenarse por precio descendente. Hardcodear datos y mostrarlos desde el main. * */

 typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    int precio;

}Notebook;

int ordenarMarcaAscPrecioDesc(Notebook lista[], int largo);

int main()
{
    float precioBruto = 1001;
    int precioFinal = 0;

    puts("--------------------PUNTO UNO-------------------------------------------");
    if (calcularIva(precioBruto, &precioFinal) != 0){
        printf("%d \n", precioFinal);
    }
    puts("-----------------------PUNTO DOS----------------------------------------");
    char cadena[20] = "MaRianO";
	subiBaja(cadena);
	puts(cadena);
    puts("--------------------------PUNTO TRES-------------------------------------");

    Notebook notebooks[5] = {
    {1, "intel", "toshiba", 134.55},
    {2, "amd", "samsung", 96.55},
    {3, "amd", "toshiba", 134.25},
    {4, "amd", "lenovo", 66.14},
    {5, "intel", "lg", 54.55},
    };

    for(int i=0; i< TAM ; i++){
        printf(" %d   %s   %s   %.2f\n", notebooks[i].id ,notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }

    puts("----------------------------------------------------------------------------");
    ordenarMarcaAscPrecioDesc(notebooks,TAM);

    for(int i=0; i< TAM ; i++)
    {
        printf(" %d   %s   %s   %.2f\n", notebooks[i].id ,notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }



    return 0;
}

int calcularIva(float precio, int* descIva){

    int ok = 0;

    if (descIva != NULL)
    {
        *descIva = (precio * 0.21) + precio;
        ok = 1;
    }

    return ok;
}

int subiBaja(char cadena[]){

	int ok = 0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		ok = 1;

		for(int i = 0; i<strlen(cadena); i++)
		{
			if(cadena[i] == toupper(cadena[i]))
			{
				cadena[i] = tolower(cadena[i]);
			}
			else if(cadena[i] == tolower(cadena[i]))
			{
				cadena[i] = toupper(cadena[i]);
			}
		}
	}

	return ok;
}

int ordenarMarcaAscPrecioDesc(Notebook lista[], int largo){

    int ok = 0;
    Notebook auxLista;

    if(lista != NULL && largo > 0)
    {
        for(int i=0; i < largo-1; i++)
        {
            for(int j= i + 1; j < largo ; j++)
            {
                if(strcmp(lista[i].marca,lista[j].marca) >0  ||
                   (strcmp(lista[i].marca,lista[j].marca) == 0 &&
                    lista[i].precio < lista[j].precio ))

                {

                    auxLista= lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxLista;
                }

            }
        }
        ok = 1;
    }
    return ok;
}
