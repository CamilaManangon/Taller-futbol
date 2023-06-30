#include <stdio.h>
#include <math.h>
#include "archivos.h"
#include "torneo.h"
#include "resultados.h"

int main(void){
    int neq=0, equipo=0, opc = 0;
    char equipos[20] = "equipos.txt";
    char puntajes[20] = "puntajes.txt";
    printf("Ingrese un numero para crear el torneo");
    scanf("%d",&neq);
    equipo=pow(2,neq);
    printf("El torneo sera de %d equipos", equipo);
    crearArchivo(equipos);
    registroEquipos(equipos,equipo);

    char matrizEq[equipo][50];

    matrizEquipos(equipos, matrizEq, equipo);

    for(int i = 0; i<equipo;i++){
        printf("%s\n", matrizEq[i]);
    }

    printf("\n");


    printf("Como desea ingresar los resultados de los partidos:\n");
    printf("1. Manualmente\n2.Manera aleatorio\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
        printf("INGRESO DE RESULTADOS MANUALMENTE\n\n");
        generarPartidos(equipos,equipo,matrizEq);
        break;
        case 2:
        printf("GENERAR RESULTADOS DE LOS PARTIDOS ALEATORIAMENTE\n");
        generarRandom(equipos,equipo,matrizEq);
        break;
        default:
        printf("Opcion inválida");
        break;
    }


    printf("\n");
    crearArchivo(puntajes);

    puntosEquipos(equipos, puntajes, equipo, matrizEq);


    return 0;

}