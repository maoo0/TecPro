//
// Created by mauri on 09/10/2025.
//

#ifndef ARCHIVOS_PREPARCIAL_MIO_FUNCIONESAUXILIARES_H
#define ARCHIVOS_PREPARCIAL_MIO_FUNCIONESAUXILIARES_H

#include "Utils.h"
void procesarImprimirReporte(const char *ubiLibros, const char *ubiClientes, const char *ubiVentas,
                             const char *ubiOutput, int fechaMenor, int fechaMayor);

void imprimirTitulo(ofstream& output, int fechaMenor, int fechaMayor);

void abrirEntrada(ifstream& input, const char* nombre);

void abrirSalida(ofstream& output, const char* nombre);

int leerFecha(ifstream& input);

void imprimirFecha(ofstream& output, int);

int leerTiempo(ifstream &input);

void imprimirTiempo(ofstream &output, int tiempo, bool esMinSeg);

void imprimirLineas(ofstream& output, char c);

void leerImprimirNombre(ifstream &input, ofstream& output);

#endif //ARCHIVOS_PREPARCIAL_MIO_FUNCIONESAUXILIARES_H