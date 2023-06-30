#include <stdio.h>
#include <string.h>

int crearArchivo2(char puntajes[])
{
    FILE *fp;
    fp = fopen(puntajes, "w+");
    if (fp == NULL)
    {
        printf("No se puede crear el archivo\n");
        return 0;
    }else
    {
        printf("Se ha creado el archivo, %s\n",puntajes);
        fclose(fp);
    }   
    return 1;
}

int comprobacionEquipo(char matrizEq[][50], int equipo, char eq[50]){
    int cont = 0;
    int comp = 0;
    do{
        for(int i = 0; i < equipo; i++){
            comp = strcmp(matrizEq[i], eq);
            if(comp==0){
                cont = cont + i;
            }
    }
    }while(comp==1);

    return cont;
}

void puntosEquipos(char equipos[], char puntajes[], int equipo, char matrizEq[][50]){

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
    }
    
    while (!feof(Partidos))
    {
        fscanf(Partidos, "%s %s %d %d", eq1, eq2, &gol1, &gol2);
        if(gol1>gol2){
            puntos[comprobacionEquipo(matrizEq, equipo, eq1)] += 3;
        }else if(gol2>gol1){
            puntos[comprobacionEquipo(matrizEq, equipo, eq2)] += 3;
        }else{
            puntos[comprobacionEquipo(matrizEq, equipo, eq1)] += 1;
            puntos[comprobacionEquipo(matrizEq, equipo, eq2)] += 1;
        }
           
    }

    for(int i = 0; i < equipo; i++){
        fprintf(Puntajes, "%s %d\n", matrizEq[i], puntos[i]);
    }

    fclose(Partidos);
    fclose(Puntajes);

}
