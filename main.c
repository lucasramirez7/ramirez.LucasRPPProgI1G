#include <stdio.h>
#include <stdlib.h>
/*
 1- Dada una estructura ePais cuyos campos son id(int), nombre(20 caracteres), infectados(int), recuperados(int) y muertos(int).
 Desarrollar una función llamada actualizarRecuperados que reciba el país
 y los recuperados del dia y que acumule estos a los que ya tiene el país. La función no devuelve nada. *

 2- Crear una función que se llame invertirCadena que reciba una cadena de caracteres como parámetro
 y su responsabilidad es invertir los caracteres de la misma. Ejemplo si le pasamos UTN-FRA la deja como ARF-NTU

*/

typedef struct{
 int id;
 char nombre[20];
 int infectados;
 int recuperados;
 int muertos;
}ePais;

void actualizarRecuperados(ePais pais[],int size, int* recuperados); //HICE UN ARRAY DE PAIS PARA QUE ACUMULE LOS RECUPERADOS SEGUN EL PAIS.
int invertirCadena(char cadena[]);
int ordenarCaracteres(char cadena[]);

int main()
{
    ePais pais[20] = {{1000, "ARGENTINA", 8000, 6800, 300} , {1001, "PERU", 7500, 6300, 250}}; // HARDCODEO UN POCO EL ARRAY COMO TESTING

    int acumuladorArgentina = 0;
    int acumuladorPeru = 0;

    actualizarRecuperados(pais,0, &acumuladorArgentina); // TESTING
    printf("%d %s \n", acumuladorArgentina, pais[0].nombre);

    actualizarRecuperados(pais,0, &acumuladorArgentina);
    printf("%d %s\n", acumuladorArgentina, pais[0].nombre);

    actualizarRecuperados(pais,1, &acumuladorPeru);
    printf("%d %s\n", acumuladorPeru, pais[1].nombre);

    actualizarRecuperados(pais,1, &acumuladorPeru);
    printf("%d %s\n", acumuladorPeru, pais[1].nombre); // FIN DEL TESTING DE LA ESTRUCTURA
    puts("-------------------------------------------");

    char cadena[] = "UTN-FRA";
    puts(cadena);
    invertirCadena(cadena);
    puts(cadena);

    puts("-------------------------------------------");

    char cadena2[] = "algoritmo";

    puts(cadena2);
    ordenarCaracteres(cadena2);
    puts(cadena2);

    puts("-------------------------------------------");

    return 0;
}

void actualizarRecuperados(ePais pais[], int size, int* acumulador){  // FUNCION PUNTO UNO

    (*acumulador) += pais[size].recuperados;
}

int invertirCadena(char cadena[]){

    int largo = strlen(cadena);
    int ok = 0;
    char aux;
    if(cadena != NULL){
    for (int i=0; i < strlen(cadena)/2 ; i++){
        aux = cadena[i];
        cadena[i] = cadena[largo - i - 1];
        cadena[largo - i - 1] = aux;
        ok = 1;
    }
    }
 return ok;
}

int ordenarCaracteres(char cadena[]){

    int ok=0;

    char auxCadena;
    int largo;

    largo = strlen(cadena);

    if (cadena!= NULL){
        for (int i = 0; i < largo -1; i++){

            for (int j = i+1; j < largo; j++){

                if (cadena[i] > cadena[j]){
                    auxCadena = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = auxCadena;
                }
            }
        }
        ok = 1;

    }
    return ok;
}
