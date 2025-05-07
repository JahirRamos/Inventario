#include <stdio.h>

int main (int argc, char *argv[]) {

char producto[10][30]; 
float precio[10];
int cant[10];
int contp=0;
int suma_precio=0;

  {
    if (contp < 10)
    {
        printf("Ingrese el nombre del producto %d: ",contp+1);
        fflush(stdin);
        fgets(producto[contp],30,stdin);
        printf("Ingrese el precio del producto %d: ",contp+1);
        scanf("%f", &precio[contp]);
        

    }else{
        printf("No se puede ingresar mas de 10 productos\n");
    }
}
    return 0;
}