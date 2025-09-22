//
// Created by mauri on 22/09/2025.
//

#ifndef PRUEBA4_FUNCIONESAUXILIARES_HPP
#define PRUEBA4_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"

void crearImprimirReporte(const char*,const char*,const char*,const char*);
//
void imprimirResumenFinal(ofstream& output, int TotalRepro, int TotalDur,
    double pagoRepro,double pagoDur);

void imprimirResumenPorCanal(ofstream& output,int  subTotalRepro, int subTotalDur, double pagoRepro,
    double pagoDur, double index);

void imprimirDatosVariables(ifstream& inputCanales,ifstream& inputStreams,ifstream& inputSponsors,
    ofstream& output, int &subTotalRepro, int &subTotalDur);

void imprimirDatosFijos(ifstream &inpupt, ofstream& output, int fecha,int nUser, double&);

void imprimirTitulo(ifstream& input, ofstream& output, int fechaMin, int fechaMax,
    double pagoRepro, double PagoDur)

//
void abrirEntrada(ifstream& input,const char* nombre);

void abrirSalida(ofstream& output,const char* nombre);

//
int leerFecha(ifstream& input);

void imprimirFecha(ofstream& output,int fecha);

int leerTiempo(ifstream& input);

void imprimirTiempo(ofstream& output,int tiempo);

void leerImprmirNombre(ifstream& input,ofstream& output);

void imprimirLinea(ofstream& output, char c);


#endif //PRUEBA4_FUNCIONESAUXILIARES_HPP