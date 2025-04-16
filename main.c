#include <stdio.h>

int menu();
void ingresarEstudiante(char nombre[30], int conte);
void ingresarMateria(char materia[30], int contm);
void ingresarNotas(int i, char nombres[][30], char materias[][30],
                   float NM1[5], float NM2[5], float NM3[5], int contm);
void imprimirPromedioEstudiante(float NM1[5], float NM2[5], float NM3[5],
                                int conte, int contm, char nombres[][30]);
void imprimirPromedioMateria(float NM1[5], float NM2[5], float NM3[5],
                             int conte, int contm, char materias[][30]);

int main (int argc, char *argv[]) {

    int op;
    char nombres[5][30], materias[3][30];
    float NM1[5], NM2[5], NM3[5];
    int conte=0, contm=0;

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            ingresarEstudiante(nombres[conte], conte);
            conte++;
            break;
        case 2:
            ingresarMateria(materias[contm], contm);
            contm++;
            break;
        case 3:
            int aux = 0;
            printf("Seleccione el numero de estudiante que desea ingresar las notas\n");
            printf("#\tNombre\n");
            for (int i = 0; i < conte; i++)
            {
                printf("%d\t%s\n", i, nombres[i]);
            }
            printf(">> ");
            scanf("%d", &aux);
            ingresarNotas(aux, nombres, materias, NM1, NM2, NM3, contm);
            break;
        case 4:
            imprimirPromedioEstudiante(NM1, NM2, NM3, conte, contm, nombres);
            break;
        case 5:
            imprimirPromedioMateria(NM1, NM2, NM3, conte, contm, materias);
            break;

        default:
            break;
        }
    } while (op != 8);

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
                    float NM1[5], float NM2[5], float NM3[5], int contm){
    printf("Ingrese las notas del estudiante %s: ",nombres[i]);
    if (contm > 0){
        printf("Nota materia %s: ",materias[0]);
        scanf("%f",&NM1[i]);
    }
    if (contm > 1){
        printf("Nota materia %s: ",materias[1]);
        scanf("%f",&NM2[i]);
    }
    if (contm > 2){
        printf("Nota materia %s: ",materias[2]);
        scanf("%f",&NM3[i]);
    }

}

void imprimirPromedioEstudiante(float NM1[5], float NM2[5], float NM3[5],
                                int conte, int contm, char nombres[5][30]){
    float prom;
    for (int i = 0; i < conte; i++)
    {   prom=0;
        if (contm > 0)
        {
            prom = NM1[i];
        }
        if (contm > 1)
        {
            prom += NM2[i];
        }
        if (contm > 2)
        {
            prom += NM3[i];
        }
        prom/=contm;
        printf("El promedio de %s es: %.2f\n",nombres[i],prom);
    }
}

void imprimirPromedioMateria(float NM1[5], float NM2[5], float NM3[5],
                            int conte, int contm, char materias[3][30]){
    float prom1, prom2, prom3;
    for (int i = 0; i < conte; i++)
    {   
        if (contm > 0)
        {
            prom1 += NM1[i];
        }
        if (contm > 1)
        {
            prom2 += NM2[i];
        }
        if (contm > 2)
        {
            prom3 += NM3[i];
        }
    }
    prom1/=conte;
    prom2/=conte;
    prom3/=conte;
    if (contm > 0)
    {
        printf("El promedio de la materia: %s es %.2f\n",materias[0],prom1);
    }
    if (contm > 1)
    {
        printf("El promedio de la materia: %s es %.2f\n",materias[1],prom2);
    }
    if (contm > 2)
    {
        printf("El promedio de la materia: %s es %.2f\n",materias[2],prom3);
    }
}