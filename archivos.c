#include <stdio.h>


int crearArchivo(char equipos[])
{
    FILE *fp;
    fp = fopen(equipos, "w+");
    if (fp == NULL)
    {
        printf("No se puede crear el archivo\n");
        return 0;
    }else
    {
        printf("Se ha creado el archivo, %s\n",equipos);
        fclose(fp);
    }   
    return 1;
}

void registroEquipos(char equipos[], int equipo)
{
    FILE *fp;
    fp = fopen("equipos.txt","w+");

    char nomeq[50];

    for (int i = 0; i < equipo; i++) {
        printf("Ingrese el nombre del equipo %d: ", i + 1);
        scanf("%s", nomeq);
        fprintf(fp, "%s\n", nomeq);
    }
    fclose(fp);

}

void leerArchivo(char equipos[])
{
    char equipo[50];
    FILE *fp;
    fp = fopen("equipos.txt", "r+");
    if (fp == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        while (fscanf(fp, "%s", equipo) == 1)
        {
            printf("%s\n", equipo);
        }
        fclose(fp);
    }
}

void matrizEquipos(char equipos[], char matrizEquipos[][50], int equipo){
    FILE *fp;
    fp = fopen("equipos.txt", "r+");
    if (fp == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        for(int i = 0; i<equipo;i++){
            fscanf(fp,"%s", matrizEquipos[i]);
        }
        fclose(fp);
    }
}
