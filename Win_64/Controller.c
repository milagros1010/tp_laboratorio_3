#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "r");

        if(pArchivo != NULL)
        {

            if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
            {
                printf(" Carga en modo texto exitosa\n");
                retorno = 0;
            }
            else
            {
                printf("error al cargar el archivo .csv\n");
            }
        }
        else
        {
            printf(" El archivo no se pudo abrir correctamente\n");
        }

        fclose(pArchivo);
    }

    return retorno;




    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

        pFile = fopen(path,"rb");

        if(pFile !=NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                printf(" Carga en modo binario exitosa\n");
                retorno = 0;
            }
            else
            {
                printf("error al cargar el archivo .bin\n");
            }

        fclose(pFile);
    }

    return retorno;


}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    if(employee_Alta(pArrayListEmployee))
    {

        printf("Alta exitosa \n");

        retorno = 0;
    }
    else
    {
        printf("Error empleado no dado de alta\n");
    }
    return retorno;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    if(employee_modificar(pArrayListEmployee))
    {
        system("cls");
        printf(" EL empleado fue modificado\n");

        retorno = 0;
    }
    else
    {

        printf("no modificado \n");

    }
    return retorno;


}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
  int retorno =- 1;

    if(pArrayListEmployee != NULL)
    {

        if(employee_baja(pArrayListEmployee))
        {
            printf("Empleado borrado\n");
            retorno=0;
        }
        else
        {
            printf("Empleado no borrado\n");
        }
    }
    return retorno;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

int retorno = -1;

    if(pArrayListEmployee != NULL)
    {

        if(employee_listar(pArrayListEmployee))
        {
            printf(" Empleados listados con exito\n");
            retorno = 0;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;


}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

  int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");
        if(!ll_sort(pArrayListEmployee,employee_sortByName,1))
        {
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
        }
    }

    return retorno;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

 int retorno = -1;
    FILE* pFile;
    Employee* nuevoEmpleado;


    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"w");

        if(pFile !=NULL)
        {
            fprintf(pFile,"Id,Nombre,Horas,Sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fprintf(pFile,"%d,%s,%d,%d\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
                }
            }

            printf(" Empleados cargados en modo texto con exito\n");
            retorno = 0;
        }
        else
        {
             printf(" Hubo un error al guardar el archivo .csv\n");
        }

        fclose(pFile);
    }

    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

 int retorno = -1;
    FILE* pFile;
    Employee* nuevoEmpleado;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"wb");

        if(pFile !=NULL)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fwrite(nuevoEmpleado,sizeof(Employee),1,pFile);
                }
            }

            printf(" Empleados cargados en modo binario con exito\n");
            retorno = 0;
        }
        else
        {
            printf(" Hubo un error al guardar el archivo .bin\n");
        }

        fclose(pFile);
    }

    return retorno;


}

