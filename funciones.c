#include <stdio.h>
#include <string.h>
#include "funciones.h"


int menu(){
    int opc;
    printf("\n------Inventario de productos------\n");
    printf("Seleccione una opcion\n");
    printf("1.Ingresar producto y precio del producto (max 10)\n");
    printf("2.Precio total del inventario\n");
    printf("3.Encontrar producto mas caro y mas barato\n");
    printf("4.Precio promedio\n");
    printf("5.Busqueda de producto\n");
    printf("6.Salir\n");
    printf(">> ");
    scanf("%d",&opc);
    return opc;
}

void ingresarproducto(char producto[][30], float precio[10], int cant[], int contp)
{
    if (contp < 10)
    {
        printf("Ingrese el nombre del producto %d: ", contp + 1);
        fflush(stdin);
        fgets(producto[contp], 30, stdin);

        size_t len = strlen(producto[contp]);
        if (len > 0 && producto[contp][len - 1] == '\n')
        {
            producto[contp][len - 1] = '\0';
        }

        do
        {
            printf("Ingrese el precio del producto %d: ", contp + 1);
            scanf("%f", &precio[contp]);
            if (precio[contp] < 0)
            {
                printf("El precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (precio[contp] < 0);
    }
    else
    {
        printf("No se puede ingresar mas de 10 productos\n");
    }
}

float calcularTotal(float precio[], int contp) {
    float total = 0;
    for (int i = 0; i < contp; i++) {
        total += precio[i];
    }
    return total;
}

void productomayorymenor(float precio[], char producto[][30], int contp)
{
    int pmayor = 0, pmenor = 0;
    for (int i = 1; i < contp; i++)
    {
        if (precio[i] > precio[pmayor])
        {
            pmayor = i;
        }
        if (precio[i] < precio[pmenor])
        {
            pmenor = i;
        }
    }
    printf("Producto mas caro: %s con un precio de: %.2f\n", producto[pmayor], precio[pmayor]);
    printf("Producto mas barato: %s con un precio de: %.2f\n", producto[pmenor], precio[pmenor]);
}

float calcularPromedio(float total, int contp) {
    if (contp == 0) {
        return 0.0;  
    }
    return total / contp;  
}

void buscarproducto(char producto[][30], float precio[], int contp)
{
    char nombreproducto[30];
    printf("Ingrese el nombre del producto para buscar su precio: ");
    fflush(stdin);
    fgets(nombreproducto, 30, stdin);

    size_t len = strlen(nombreproducto);
    if (len > 0 && nombreproducto[len - 1] == '\n')
    {
        nombreproducto[len - 1] = '\0';
    }

    int productoencontrado = 0;
    for (int i = 0; i < contp; i++)
    {
        if (strcmp(producto[i], nombreproducto)== 0)
        {
            printf("Producto: %s, precio: %.2f\n", producto[i], precio[i]);
            productoencontrado=1;
        }
        
    }
    if (productoencontrado == 0) {
        printf("Producto no encontrado.\n");
    }
    
    
}
