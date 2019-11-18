#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
#include "parser.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag = 0;

     do{

    printf("\n MENU:");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)" );
    printf("\n 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
    printf("\n 3. Alta de empleado");
    printf("\n4. Modificar datos de empleado ");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)");
    printf("\n10. Salir");
    printf("\n  Ingrese una opcion (1/10): ");
    scanf("%d" , & opcion);

        switch(opcion)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                flag= 1;
                break;


            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                flag =1;
                break;


            case 3:
                if(flag==1){
                controller_addEmployee(listaEmpleados);
                }
                else{
                    printf("primero cargue los datos");
                }
                break;

            case 4:
                if(flag!=0){
                controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if(flag!=0){
                controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if(flag!=0){
                controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                if(flag!=0){
                controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                if(flag!=0){
                controller_saveAsText("data.csv",listaEmpleados);
                }
                break;

            case 9:
                if(flag!=0){
                controller_loadFromBinary("data.bin",listaEmpleados);
                }
                break;
            case 10: printf("salir");

        }
    }while(opcion != 10);
    return 0;
}
