#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generarPartidos(char equipos[], int equipo, char matrizEq[][50])
{
    int gol1 = 0, gol2 = 0;
    FILE *fp;
    fp = fopen("partidos.txt", "w+");

    if (fp == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }else{
        for (int i = 0; i < equipo; i++)
        {
            for (int j = 0; j < equipo; j++)
            {
                if(i != j){
                    printf("%s vs %s\n",matrizEq[i], matrizEq[j]);
                    printf("Ingrese la cantidad de goles de %s: ", matrizEq[i]);
                    scanf("%d", &gol1);
                    printf("Ingrese la cantidad de goles de %s: ", matrizEq[j]);
                    scanf("%d", &gol2);
                    printf("\n");
                    fprintf(fp, "%s %s %d %d\n",matrizEq[i], matrizEq[j], gol1, gol2);
                }
            }
        }

        fclose(fp);
    }

}

void generarRandom(char equipos[], int equipo, char matrizEq[][50]){
    int gol1 = 0, gol2 = 0;
    FILE *fp;
    fp = fopen("partidos.txt", "w+");

    if (fp == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }else{
        srand(time(NULL)); // time(NULL) devuelve la hora del sistema

        for (int i = 0; i < equipo; i++)
        {
            for (int j = 0; j < equipo; j++)
            {
                if(i != j){
                
                    gol1 = rand() % 7;
                    gol2 = rand() % 7;
                    fprintf(fp, "%s %s %d %d\n",matrizEq[i], matrizEq[j], gol1, gol2);
                }
            }
        }
        fclose(fp);
    }
}

