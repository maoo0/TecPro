//
// Created by mauri on 06/10/2025.
//

#ifndef INC_2025_2_LAB05_ARREGLOS_ORDENADOS_FUNCIONESAUXILIARES_H
#define INC_2025_2_LAB05_ARREGLOS_ORDENADOS_FUNCIONESAUXILIARES_H

#include "Utils.h"

void imprimirReporte(const char *nombre, int *nTotalReproduccionesCanales,double tarifa, //aux y tarifa
                         int *codeIntCanales, char *codeCharCanales, double *ratingCanales, int cantCanales, //Canales
                         int *codeEtiquetas, int *duracionEtiquetas, int cantEtiquetas, //Etiquetas
                         int *codeIntCanalesExC, int *codeEtiquetasExC, char *codeCharCanalesExC, int &cantExC);

void procesarArreglosAux(const char *nombre, int *nTotalReproduccionesCanales, //aux
                         int *codeIntCanales, char *codeCharCanales, double *ratingCanales, int cantCanales, //Canales
                         int *codeIntCanalesExC, int *codeEtiquetasExC, char *codeCharCanalesExC, int &cantExC); //ExC

void cabeceraEtiquetas(ofstream& output, int* codeEtiquetas, int *duracionEtiquetas, int i) ;

void imprimirTitulo(ofstream& output,double tarifa);

int buscarCanal(char codeCharLeido,int codeIntLeido,char* codeCharCanales,int* codeIntCanales, int cantCanales) ;


void cargarExC(const char *nombre, int *codeIntCanalesExC, int *codeEtiquetasExC,
               char *codeCharCanalesExC, int &cantExC);

void probarExC(const char *nombre, int *codeIntCanalesExC, int *codeEtiquetasExC,
               char *codeCharCanalesExC, int cantExC);

void cargarCanales(const char *nombre, int *fechaCanales, int *codeIntCanales,
                   char *codeCharCanales, double *ratingCanales, int &cantCanales);

void probarCanales(const char *nombre, int *fechaCanales, int *codeIntCanales,
                   char *codeCharCanales, double *ratingCanales, int cantCanales);

void cargarEtiquetas(const char *nombre, int *codeEtiquetas, int *duracionEtiquetas, int &cantEtiquetas);

void ordenarEtiquetas(int *codeEtiquetas, int *duracionEtiquetas, int cantEtiquetas);

void probarEtiquetas(const char *nombre, int *codeEtiquetas, int *duracionEtiquetas, int cantEtiquetas);

void swapInt(int &a, int &b);

void swapDouble(double &a, double &b);

void swapChar(char &a, char &b);

//fijas
void abrirEntrada(ifstream &input, const char *);

void abrirSalida(ofstream &output, const char *);

int leerFecha(ifstream &input);

void imprimirFecha(ofstream &output, int fecha);

int leerTiempo(ifstream &input);

void imprimirTiempo(ofstream &output, int tiempo);

void imprimirLinea(ofstream &output, char c);


#endif //INC_2025_2_LAB05_ARREGLOS_ORDENADOS_FUNCIONESAUXILIARES_H
