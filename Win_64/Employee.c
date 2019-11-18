#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"

/** \brief Lllama a los set del empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */

Employee* employee_newParametros(char* idStr,char* NameStr,char* HoursWorkedStr, char* SalaryStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL || employee_setId(this, atoi(idStr)) || employee_setNombre(this, NameStr) || employee_setHorasTrabajadas(this,atoi(HoursWorkedStr)) ||employee_setSueldo(this,atof(SalaryStr)))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}

/** \brief Set del id del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{

    int retorno = 1;

    if( this != NULL && id > 0)
    {

        this->id = id;
        retorno = 0;
    }

    return retorno;

}



/** \brief Obtiene el ID del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{

    int retorno = 1;

    if( this != NULL && id != NULL)
    {

        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


/** \brief Set del nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = 1;

    if(this != NULL && nombre != NULL && validarStringTam(nombre,128))
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;

}

/** \brief Obtiene el nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

    int retorno = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief Set de horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 1;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene las horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;

}

/** \brief Set de el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 1;

    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;

}

/** \brief Obtiene el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

/** \brief Ingresa datos del empleado a dar de alta
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int employee_Alta(LinkedList* pArrayListEmployee){

   int retorno = 0;
    Employee* nuevoEmpleado;
    char nombre[128];
    char valHoras[10];
    char valSueldo[10];
    int horas;
    int sueldo;

    nuevoEmpleado = employee_new();

    if(nuevoEmpleado !=NULL)
    {
        system("cls");

        printf("Alta Empleado\n");

        printf(" Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre);

        employee_setNombre(nuevoEmpleado,nombre);

        printf("\n");

        printf(" Ingrese Horas: ");
        fflush(stdin);
        gets(valHoras);

        horas = validarEntero(valHoras);

        employee_setHorasTrabajadas(nuevoEmpleado,horas);

        printf("\n");

        printf(" Ingrese sueldo: ");
        fflush(stdin);
        gets(valSueldo);

        sueldo = validarEntero(valSueldo);

        employee_setSueldo(nuevoEmpleado,sueldo);

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->id = generadorId(pArrayListEmployee);
            ll_add(pArrayListEmployee,nuevoEmpleado);

            retorno = 1;
        }
    }

    return retorno;


}



/** \brief Carga de manera incremental el id de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int generadorId(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int cant;
    int id;
    int maxID = -1;
    int i;

        cant = ll_len(pArrayListEmployee);

        for(i=0; i<cant; i++)
        {
            if(aux !=NULL)
            {
                aux = ll_get(pArrayListEmployee, i);
                employee_getId(aux, &id);

                if(id > maxID)
                {
                    maxID = id;
                }
            }
        }


    maxID += 1;

    return maxID;
}

/** \brief Modifica los datos a elegir por parte del usuario segun su id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_modificar(LinkedList* pArrayListEmployee){

    int retorno = 0;
    Employee* pEmp;
    int id;
    char idAux[5];
    int indice;
    int opcion;
    char opcionAux[2];
    char seguir;
    char nuevoNombre[128];
    int horas;
    char horasAux[10];
    int sueldo;
    char sueldoAux[10];


    if(pArrayListEmployee !=NULL)
    {
        system("cls");

        printf("Modificar Empleado\n");

        system("pause");

        employee_listar(pArrayListEmployee);

        printf(" Ingrese el id del empleado: ");
        fflush(stdin);
        gets(idAux);

        id = validarEntero(idAux);

        printf("\n");

        indice = searchId(id,pArrayListEmployee);//busca el indice

        if(indice == -1)
        {
            printf(" El ID %d no existe\n",id);
            printf("\n");
        }
        else
        {
            system("cls");

            printf("Empleado\n");

            printf("   Id   Nombre   Horas   Sueldo\n");

            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));
            pEmp = (Employee*)ll_get(pArrayListEmployee,indice);//guarda el empleado con el indice especificado en pEmp
            printf("\n");

            printf(" Que desea modificar?\n");
            printf(" 1. Nombre\n  ");
            printf(" 2. Horas\n");
            printf(" 3. Sueldo\n");
            printf(" Ingrese opcion: ");
            fflush(stdin);
            gets(opcionAux);

            opcion = validarEntero(opcionAux);

            switch(opcion)
            {
            case 1:
                system("cls");

                printf("Modificar Nombre\n");

                printf("\n");

                printf(" Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nuevoNombre);

                validarStringTam(nuevoNombre,128);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    strcpy(pEmp->nombre,nuevoNombre);

                    ll_set(pArrayListEmployee,indice,pEmp);
                    retorno = 1;

                    printf("\n");
                    printf(" Modificacion exitosa\n");
                }
                else
                {
                    retorno = 0;
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            case 2:

                system("cls");

                printf("Modificar Horas\n");

                printf("\n");

                printf(" Ingrese horas trabajadas: ");
                fflush(stdin);
                gets(horasAux);

                horas = validarEntero(horasAux);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    pEmp->horasTrabajadas = horas;

                    ll_set(pArrayListEmployee,indice,pEmp);

                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion exitosa\n");
                }
                else
                {
                    retorno = 0;
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            case 3:

                system("cls");

                printf("Modificar Sueldo\n");

                printf("\n");

                printf(" Ingrese sueldo: ");
                fflush(stdin);
                gets(sueldoAux);

                sueldo = validarEntero(sueldoAux);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    pEmp->sueldo = sueldo;

                    ll_set(pArrayListEmployee,indice,pEmp);

                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion exitosa\n");
                }
                else
                {
                    retorno = 0;
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            default:
                retorno = 0;
                printf("\n");
                printf(" Esta opcion no existe\n");
            }
        }
    }

    return retorno;

}



/** \brief Busca el id de un empleado
 *
 * \param pAux Employee*
 * \param id int
 * \param pArrayEmp LinkedList*
 * \return int
 *
 */
int searchId(int id, LinkedList* pArrayEmp)
{
    int indice = -1;
    Employee* pAux;

    if(pArrayEmp !=NULL)
    {
        for(int i=0; i<ll_len(pArrayEmp); i++)
        {
            pAux = (Employee*)ll_get(pArrayEmp,i);

            if(pAux !=NULL && pAux->id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


/** \brief Da de baja a un empleado segun su id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_baja(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    char valId[5];
    int indice;
    char seguir;

        system("cls");

        printf("Baja Empleado\n");

        system("pause");

        employee_listar(pArrayListEmployee);

        printf(" Ingrese ID del empleado: ");
        fflush(stdin);
        gets(valId);

        id = validarEntero(valId);

        printf("\n");

        indice = searchId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" El ID %d no existe\n",id);
        }
        else
        {
            system("cls");

            printf("Empleado\n");

            printf("   Id   Nombre   Horas   Sueldo\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));

            printf("\n");

            seguir = validarSeguir();

            if(seguir == 'S'  || seguir == 's')
            {
                ll_remove(pArrayListEmployee,indice);

                printf("\n");

                printf(" Empleado eliminado con exito\n");
                 retorno = 1;
            }
            else
            {
                printf("\n");
                printf(" Baja cancelada\n");
            }
        }





    return retorno;
}

/** \brief Obtiene a los empleados y lo muestra
 *
 * \param pEmp Employee*
 * \return void
 *
 */
void mostrarEmpleado(Employee* pEmp)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(pEmp !=NULL)
    {
        if(!employee_getId(pEmp,&id) && !employee_getNombre(pEmp,nombre) && !employee_getHorasTrabajadas(pEmp,&horas) && !employee_getSueldo(pEmp,&sueldo))
        {
            printf("%5d %8s %6d %8d\n",id,nombre,horas,sueldo);
        }
    }
}


/** \brief Muestra los datos de todos los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_listar(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 1;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {

             if(i%23==0)
            {

            system("pause");
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getNombre(auxPunteroEmpleado,nombre);
            employee_getSueldo(auxPunteroEmpleado,&sueldo);
            employee_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);

            printf("\tID: %d",id);
            printf("\tNombre: %s",nombre);
            printf("\tSueldo: %d",sueldo);
            printf("\tHoras trabajadas: %d",horasTrabajadas);
            printf("\n");
            }
            else
            {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getNombre(auxPunteroEmpleado,nombre);
            employee_getSueldo(auxPunteroEmpleado,&sueldo);
            employee_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);

            printf("\tID: %d",id);
            printf("\tNombre: %s",nombre);
            printf("\tSueldo: %d",sueldo);
            printf("\tHoras trabajadas: %d",horasTrabajadas);
            printf("\n");


            }
        }
    }
    system("pause");
    return retorno;
}





/** \brief Libera memoria
 *
 * \param emp Employee*
 * \return int
 *
 */
int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;

}


/** \brief Base a tomar para un ordenamiento de empleados por nombre.
 *
 * \param thisA void*
 * \param thisB void*
 * \return int
 *
 */
int employee_sortByName(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreA[50];
    char nombreB[50];

   employee_getNombre(thisA,nombreA);
   employee_getNombre(thisB,nombreB);

   if(strcmp(nombreA,nombreB)>0)
   {
    retorno = 1;
   }
   else if(strcmp(nombreA,nombreB)< 0)
   {
    retorno = -1;
   }
    return retorno;
}

