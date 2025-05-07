#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    int op;
    char productos[10][30];
    float precio[10];
    int contp=0, cant[10];

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            ingresarproducto(productos,precio,cant,contp);
            contp++;
            break;

        case 2:
            if (contp == 0)
            {
                printf("No se han ingresado productos.\n");
            }
            else
            {
                float total = calcularTotal(precio, contp);
                printf("El precio total del inventario es: %.2f\n", total);
            }
            break;

        case 3:
            if (contp == 0)
            {
                printf("No se han ingresado productos.\n");
            }
            else
            {
                productomayorymenor(precio, productos, contp);
            }
            break;

        case 4:
            if (contp == 0)
            {
                printf("No se han ingresado productos.\n");
            }
            else
            {
                float total = calcularTotal(precio, contp);      
                float promedio = calcularPromedio(total, contp); 
                printf("El precio promedio del inventario es: %.2f\n", promedio);
            }
            break;

            case 5:
            if (contp == 0) {
                printf("No se han ingresado productos.\n");
            } else {
                buscarproducto(productos, precio, contp);
            }
            break;
        

        default:
            break;
        }
    } while (op != 6);

    return 0;
}