//
// Created by mauri on 09/10/2025.
//

#include "FuncionesAuxiliares.h"


void procesarImprimirReporte(const char *ubiLibros, const char *ubiClientes, const char *ubiVentas,
                             const char *ubiOutput, int fechaMenor, int fechaMayor) {
    ifstream inputLibros, inputClientes, inputVentas;
    abrirEntrada(inputLibros, ubiLibros);
    abrirEntrada(inputClientes, ubiClientes);
    abrirEntrada(inputVentas, ubiVentas);

    ofstream output;
    abrirSalida(output, ubiOutput);

    imprimirTitulo(output, fechaMenor, fechaMayor);

    int codigoLibro;
    double precio;
    while (true) {
        inputLibros >> codigoLibro;
        if (inputLibros.eof()) break;
        output << "LIBRO: ";
        leerImprimirNombre(inputLibros, output);
        output << setw(20) << ' ' << "AUTOR: ";
        leerImprimirNombre(inputLibros, output);
        inputLibros >> precio;
        break;
    }
}

void imprimirTitulo(ofstream& output, int fechaMenor, int fechaMayor) {
    output << setw((anchoDoc-10)/2) << "REPORTE DE VENAS POR LIBROS";
    imprimirLineas(output, '=');

}

//
void abrirEntrada(ifstream &input, const char *nombre) {
    input.open(nombre, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo de nombre: " << nombre << endl;
        exit(1);
    }
}

void abrirSalida(ofstream &output, const char *nombre) {
    output.open(nombre, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir el archivo de nombre: " << nombre << endl;
        exit(1);
    }
}

//fijas
int leerFecha(ifstream &input) {
    int fecha, anio, mes, dia;
    char c;
    input >> dia >> c >> mes >> c >> anio;
    fecha = anio * 10000 + mes * 100 + dia;
    return fecha;
}

void imprimirFecha(ofstream &output, int fecha) {
    output << setfill('0');
    output << right << setw(2) << fecha % 100 << '/' << setw(2) << (fecha / 100) % 100 << '/' << setw(4) << fecha /
            10000;
    output << setfill(' ');
}

int leerTiempo(ifstream &input) {
    int tiempo, hora = 0, min, seg;
    char c;
    input >> min >> c >> seg;
    tiempo = hora * 3600 + min * 60 + seg;
    return tiempo;
}

void imprimirTiempo(ofstream &output, int tiempo, bool esMinSeg) {
    output << setfill('0');
    if (esMinSeg)
        output << right << setw(2) << (tiempo / 60) % 60 << ':' << setw(2) << tiempo % 60;
    else
        output << right << setw(2) << tiempo / 3600 << ':' << setw(2) << (tiempo / 60) % 60 << ':' << setw(2) << tiempo
                % 60;
    output << setfill(' ');
}

void imprimirLineas(ofstream &output, char c) {
    for (int i = 0; i < anchoDoc; ++i) output << c;
    output << endl;
}

void leerImprimirNombre(ifstream &input, ofstream& output) {
    char c;
    int contador=0;
    input >> ws;
    while(true) {
        c=input.get();
        if (c==' ') break;
        if (c=='[' or c==']' or c=='*') continue;
        output.put(c);
        contador++;
    }
    output << setw(15-contador) << ' ';
}