#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puntos_interes.h"

void leerPuntosInteres(const char *nombreArchivo, PuntoInteres **puntos, int *numPuntos) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        exit(1);
    }

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), archivo) == NULL) {
        printf("El archivo %s está vacío.\n", nombreArchivo);
        fclose(archivo);
        exit(1);
    }

    int capacidad = 10;
    int contador = 0;
    *numPuntos = 0;
    *puntos = (PuntoInteres *)malloc(capacidad * sizeof(PuntoInteres));

    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        if (contador >= capacidad) {
            capacidad *= 2;
            *puntos = (PuntoInteres *)realloc(*puntos, capacidad * sizeof(PuntoInteres));
        }

        char *nombre = strtok(buffer, ",");
        char *tipo = strtok(NULL, ",");
        char *direccion = strtok(NULL, ",");
        char *horario = strtok(NULL, ",");
        char *descripcion = strtok(NULL, "\n");

        if (nombre != NULL && tipo != NULL && direccion != NULL && horario != NULL && descripcion != NULL) {
            strcpy((*puntos)[contador].nombre, nombre);
            strcpy((*puntos)[contador].tipo, tipo);
            strcpy((*puntos)[contador].direccion, direccion);
            strcpy((*puntos)[contador].horario, horario);
            strcpy((*puntos)[contador].descripcion, descripcion);
            contador++;
        }
    }

    *numPuntos = contador;
    fclose(archivo);
}

void escribirPuntosInteres(const char *nombreArchivo, PuntoInteres *puntos, int numPuntos) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        exit(1);
    }

    fprintf(archivo, "Nombre,Tipo,Direccion,Horario,Descripcion\n");

    for (int i = 0; i < numPuntos; i++) {
        fprintf(archivo, "%s,%s,%s,%s,%s\n", puntos[i].nombre, puntos[i].tipo,
                puntos[i].direccion, puntos[i].horario, puntos[i].descripcion);
    }

    fclose(archivo);
}
