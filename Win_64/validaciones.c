#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "validaciones.h"

/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero
 *
 * \param entero char*
 * \return int
 *
 */
int validarEntero(char* entero)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.')
        {
            printf(" Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}



/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a cero o positivo y que no sobrepase el tamaño indicado, si no muestra mensaje de error
 *
 * \param x char*
 * \param largo int
 * \return void
 *
 */
int validarStringTam(char* x, int largo)
{
    int retorno = 0;

    if(x !=NULL)
    {
        while(strlen(x)<=0)
        {
            printf(" El campo no puede estar vacio: ");
            fflush(stdin);
            gets(x);
        }

        for(int i=0; i<strlen(x); i++)
        {
            while((isalpha(x[i]) == 0 && x[i] != '-' && x[i] != ' ')|| strlen(x)>largo || (x+0) == '\0')
            {
                printf(" Reingrese solo caracteres alfabeticos > %d: ",largo);
                fflush(stdin);
                gets(x);
                i=0;
            }
        }

        retorno = 1;
    }

    return retorno;
}


/** \brief Pregunta si desea continuar, en caso de ingresar algo diferente a "s" o "n", muestra mensaje de error
 *
 * \return char
 *
 */
char validarSeguir()
{
    char seguir;

    printf(" Esta seguro? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf(" ERROR. Esta opcion no es valida\n");
        printf(" Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}
