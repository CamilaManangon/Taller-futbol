#include <stdio.h>
#include <string.h>


int comprobacionEquipo(char matrizEq[][50], int equipo, char eq[50]){
    int cont = 0;
    int comp = 0;

        for(int i = 0; i < equipo; i++){
            comp = strcmp(matrizEq[i], eq);
            if(comp==0){
                cont = i;
            }
        }

    return cont;
}

void puntosEquipos(char equipos[], char puntajes[], int equipo, char matrizEq[][50]){
    int temp = 0;
    char cambio[50];
    char eq1[50];
    char eq2[50];
    int gol1=0, gol2=0;
    int puntos[equipo];

    FILE *Partidos; 
    FILE *Puntajes;
    Partidos = fopen("partidos.txt", "r+");
    Puntajes = fopen("puntajes.txt", "w+");

    for (int i = 0; i < equipo; i++) {
        puntos[i] = 0;
    }

    if (Partidos == NULL || Puntajes == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }else{
        while (fscanf(Partidos, "%s %s %d %d", eq1, eq2, &gol1, &gol2) == 4)
        {
            if(gol1>gol2){
                puntos[comprobacionEquipo(matrizEq, equipo, eq1)] += 3;
            }else if(gol2>gol1){
                puntos[comprobacionEquipo(matrizEq, equipo, eq2)] += 3;
            }else{
                puntos[comprobacionEquipo(matrizEq, equipo, eq1)] += 1;
                puntos[comprobacionEquipo(matrizEq, equipo, eq2)] += 1;
            }
            
        }

        //ordenamiento
        for (int i = 0; i < equipo - 1; i++) {
            for (int j = i + 1; j < equipo; j++) {
                if (puntos[i] < puntos[j]) {
                    temp = puntos[j];
                    puntos[j] = puntos[i];
                    puntos[i] = temp;

                    strcpy(cambio, matrizEq[j]);
                    strcpy(matrizEq[j], matrizEq[i]);
                    strcpy(matrizEq[i], cambio);
                }
            }
        }

        for(int i = 0; i < equipo; i++){
            fprintf(Puntajes, "%s %d\n", matrizEq[i], puntos[i]);
        }

        fclose(Partidos);
        fclose(Puntajes);

    }
    
}

void imprimirPartidos(){
    char eq1[50], eq2[50];
    int r1=0, r2=0;

    FILE *fp;
    fp = fopen("partidos.txt", "r+");
    if (fp == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        printf("RESULTADOS PARTIDOS\n");
        printf("-----------------------------------------------------\n");
        printf("|        Partido         |      Resultado     |\n");
        while (fscanf(fp, "%s %s %d %d", eq1, eq2, &r1, &r2) == 4)
        {
            printf("-----------------------------------------------------\n");
            printf("|    %s vs %s     |      %d-%d     |\n",eq1, eq2, r1, r2);
        }
        printf("-----------------------------------------------------\n");
        fclose(fp);
    }
}

void imprimirPuntos(){
    char equipo[50];
    int p;
    FILE *fp;
    fp = fopen("puntajes.txt", "r+");
    if (fp == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        printf("PUNTAJES FINALES\n");
        printf("--------------------------------------------\n");
        printf("|        Equipo         |      Puntos     |\n");
        while (fscanf(fp, "%s %d", equipo, &p) == 2)
        {
            printf("--------------------------------------------\n");
            printf("|    %s     |      %d     |\n",equipo, p);
        }
        printf("--------------------------------------------\n");
        fclose(fp);
    }
}