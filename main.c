#include <stdio.h>

int main (int argc, char *argv[]) {



    return 0;
}

int menu(){
    int opc;
    printf("Seleccione una opcion\n");
    printf("1.Ingresar Estudiante\n");
    printf("2.Ingresar Materia\n");
    printf("3.Ingresar notas\n");
    printf("4.Promedio por estudiante\n");
    printf("5.Promedio por materia\n");
    printf("6.Notas altas y bajas por estudiante\n");
    printf("7.Notas altas y bajas por materia\n");
    printf("8.Salir");
    printf(">> ");
    scanf("%d",&opc);
    return opc;
}

void ingresarEstudiante(char nombre[30], int conte){
    if (conte < 5)
    {
        printf("Ingrese el nombre del estudiante %d: ",conte);
        fflush(stdin);
        fgets(nombre,30,stdin);
    }else{
        printf("No se puede ingresar mas de 5 estudiantes\n");
    }
    
   
}

void ingresarMateria(char materia[30], int contm){
    if (contm < 3)
    {
        printf("Ingrese el nombre de la materia %d: ", contm);
        fflush(stdin);
        fgets(materia, 30, stdin);
    }
    else
    {
        printf("No se puede ingresar mas de 5 estudiantes\n");
    }
}

void ingresarNotas(int i, char nombres[5][30], char materias[5][30],
                    float NM1[5], float NM2[5], float NM3[5]){
    printf("Ingrese las notas del estudiante %s: ",nombres[i]);
    printf("Nota materia %s: ",materias[0]);
    scanf("%f",&NM1[i]);
    printf("Nota materia %s: ",materias[1]);
    scanf("%f",&NM2[i]);
    printf("Nota materia %s: ",materias[2]);
    scanf("%f",&NM3[i]);


}