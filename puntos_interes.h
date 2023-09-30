#ifndef PUNTOS_INTERES_H
#define PUNTOS_INTERES_H

typedef struct {
    char nombre[100];
    char tipo[50];
    char direccion[100];
    char horario[50];
    char descripcion[200];
} PuntoInteres;

void leerPuntosInteres(const char *nombreArchivo, PuntoInteres **puntos, int *numPuntos);
void escribirPuntosInteres(const char *nombreArchivo, PuntoInteres *puntos, int numPuntos);

#endif
