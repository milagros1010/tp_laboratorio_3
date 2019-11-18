#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    char bId[1024];
    char bNombre[1024];
    char bHorasTrabajadas[1024];
    char bSalario[1024];
    int bandera = 1;
    int retorno = -1;

    while(!feof(pFile))
    {
        if(bandera)
        {
            fscanf(pFile,"%s\n", bId);
            bandera = 0;
        }
        else if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bId, bNombre, bHorasTrabajadas, bSalario)==4)//develve la cant de datos leidos
        {
            pAux = employee_newParametros(bId, bNombre, bHorasTrabajadas, bSalario);
            if(pAux != NULL)
            {
                ll_add(pArrayListEmployee, pAux);
                retorno = 0;
            }
        }
        else
        {
            break;
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxPEmpleado;
    int retorno = -1;
    int cantLineas;
    do
    {
        auxPEmpleado = employee_new();

        cantLineas = fread(auxPEmpleado, sizeof(Employee), 1, pFile);//cantidad de lineas leidas
        if(auxPEmpleado != NULL && cantLineas == 1)
        {
            ll_add(pArrayListEmployee, auxPEmpleado);
            retorno = 0;
        }
    }while(!feof(pFile));

    return retorno;
}
