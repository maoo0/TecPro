//
// Created by mauri on 06/10/2025.
//

#include "FuncionesAuxiliares.h"

void imprimirReporte(const char *nombre, int *nTotalReproduccionesCanales,double tarifa, //aux y tarifa
                         int *codeIntCanales, char *codeCharCanales, double *ratingCanales, int cantCanales, //Canales
                         int *codeEtiquetas, int *duracionEtiquetas, int cantEtiquetas, //Etiquetas
                         int *codeIntCanalesExC, int *codeEtiquetasExC, char *codeCharCanalesExC, int &cantExC) {//ExC

    ofstream output;
    abrirSalida(output, nombre);
    imprimirTitulo(output, tarifa);
    output << fixed << setprecision(2);
    int posCanal, k=0;
    for (int i = 0; i < cantEtiquetas; i++) {
        cabeceraEtiquetas(output, codeEtiquetas, duracionEtiquetas, i);
        // matchearCanalEtiquetas
        k=1;
        for (int j = 0; j < cantExC; j++) {
            if (codeEtiquetas[i]==codeEtiquetasExC[j]) {
                int etiquetas, exc;
                etiquetas = codeEtiquetas[i];
                exc = codeEtiquetasExC[j];
                posCanal = buscarCanal(codeCharCanalesExC[j], codeIntCanalesExC[j],
                    codeCharCanales, codeIntCanales, cantCanales);
                if (posCanal!=-1) {
                    output << left << setw(1) << ' ' << k << setw(4) << ')';
                    output << left <<  codeCharCanales[posCanal] << setw(20)<<codeIntCanales[posCanal];
                    output << left << setw(35)<< ratingCanales[posCanal];
                    output << left << setw(35)<< nTotalReproduccionesCanales[posCanal];
                    imprimirTiempo(output, nTotalReproduccionesCanales[posCanal]*duracionEtiquetas[i]);
                    output << endl;
                    k++;
                }
                else cout << "q fo " << i << ' ' << j<< ' ' << k << endl;
            }
        }
        imprimirLinea(output, '=');
    }





    output.close();

}

void cabeceraEtiquetas(ofstream& output, int* codeEtiquetas, int *duracionEtiquetas, int i) {
    output << "ETIQUETA No. " << i+1 << endl;
    output << setw(3) << ' ' << "CODIGO: " << codeEtiquetas[i] << endl;
    output << setw(3) << ' ' << "DURACION: ";
    imprimirTiempo(output, duracionEtiquetas[i]);
    output << endl;
    imprimirLinea(output, '-');
    output << setw(3) << ' ' << "CANALES DONDE SE PRODUCE:" << endl;
    output << left << setw(6)<< "No.";
    output << left << setw(15)<< "CODIGO";
    output << left << setw(25)<< "RATING DE CALIDAD";
    output << left << setw(35)<< "NUMERO TOTAL DE REPRODUCCIONES";
    output << "TIEMPO TOTAL DE REPRODUCCIONES" << endl;
}

void imprimirTitulo(ofstream& output,double tarifa) {
    output << right << setw((anchoDoc-20)/2) << "PLATAFORMA TP_Twitch" << endl;
    output << setw(50) << "TARIFA POR DURACION DE LAS ETIQUETAS: " << tarifa << " POR CADA MINUTO Y FRACCION" << endl;
    imprimirLinea(output, '=');
}

void procesarArreglosAux(const char *nombre, int *nTotalReproduccionesCanales, //aux
                         int *codeIntCanales, char *codeCharCanales, double *ratingCanales, int cantCanales, //Canales
                         int *codeIntCanalesExC, int *codeEtiquetasExC, char *codeCharCanalesExC, int &cantExC) { //ExC

    ifstream inputRepro;
    abrirEntrada(inputRepro, nombre);
    //28/02/2025  E6696      888106      244
    int fecha, codeIntLeido, codeEtiquetasLeido, posCanal;
    char codeCharLeido;
    while (true) {
        fecha = leerFecha(inputRepro);
        if (inputRepro.eof()) break;
        inputRepro >> codeCharLeido >> codeIntLeido >> codeEtiquetasLeido;
        posCanal = buscarCanal(codeCharLeido, codeIntLeido, codeCharCanales, codeIntCanales, cantCanales);
        if (posCanal != -1) {
            inputRepro >> nTotalReproduccionesCanales[posCanal];
        }
        else cout << "Canal " << posCanal << " no encontrado" << endl;
    }
    inputRepro.close();
}


int buscarCanal(char codeCharLeido,int codeIntLeido,char* codeCharCanales,int* codeIntCanales, int cantCanales) {
    for (int i = 0; i < cantCanales; i++) {
        if (codeCharCanales[i] == codeCharLeido and codeIntCanales[i] == codeIntLeido) return i;
    }
    return -1;
}

void cargarExC(const char *nombre, int *codeIntCanalesExC, int *codeEtiquetasExC,
               char *codeCharCanalesExC, int &cantExC) {
    ifstream inputExC;
    abrirEntrada(inputExC, nombre);
    char codeChar;
    while (true) {
        inputExC >> codeCharCanalesExC[cantExC];
        if (inputExC.eof()) break;
        inputExC >> codeIntCanalesExC[cantExC] >> codeEtiquetasExC[cantExC];
        cantExC++;
    }
    inputExC.close();
}

void probarExC(const char *nombre, int *codeIntCanalesExC, int *codeEtiquetasExC,
               char *codeCharCanalesExC, int cantExC) {
    ofstream outputExC;
    abrirSalida(outputExC, nombre);

    outputExC << setw((anchoDoc + 6) / 2) << "ETIQUETAS" << endl;
    imprimirLinea(outputExC, '=');
    outputExC << right << setw((anchoDoc) / 4) << "CODIGO CANAL";
    outputExC << right << setw((anchoDoc) / 2) << "CODIGO ETIQUETA" << endl;
    imprimirLinea(outputExC, '-');

    for (int i = 0; i < cantExC; i++) {
        outputExC << right << setw((anchoDoc / 4) - 8) << codeCharCanalesExC[i] << codeIntCanalesExC[i];
        outputExC << right << setw((anchoDoc / 2)) << codeEtiquetasExC[i] << endl;
    }
}

void cargarCanales(const char *nombre, int *fechaCanales, int *codeIntCanales,
                   char *codeCharCanales, double *ratingCanales, int &cantCanales) {
    ifstream inputJuegos;
    abrirEntrada(inputJuegos, nombre);
    int fecha;
    while (true) {
        //19/06/2022     X5514     xQcOW     2.5
        fecha = leerFecha(inputJuegos);
        if (inputJuegos.eof()) break;
        fechaCanales[cantCanales] = fecha;
        inputJuegos >> codeCharCanales[cantCanales] >> codeIntCanales[cantCanales] >> ws;
        inputJuegos.ignore(50, ' ');
        inputJuegos >> ratingCanales[cantCanales] >> ws;
        cantCanales++;
    }
}

void probarCanales(const char *nombre, int *fechaCanales, int *codeIntCanales,
                   char *codeCharCanales, double *ratingCanales, int cantCanales) {
    ofstream outputCanales;
    abrirSalida(outputCanales, nombre);

    outputCanales << setw((anchoDoc + 6) / 2) << "CANALES" << endl;
    imprimirLinea(outputCanales, '=');
    outputCanales << right << setw((anchoDoc) / 6) << "FECHA";
    outputCanales << right << setw((anchoDoc) / 3) << "CODIGO";
    outputCanales << right << setw((anchoDoc) / 3) << "RATING" << endl;
    imprimirLinea(outputCanales, '-');

    for (int i = 0; i < cantCanales; i++) {
        outputCanales << fixed << setprecision(2);
        outputCanales << right << setw((anchoDoc / 6) - 7) << ' ';
        imprimirFecha(outputCanales, fechaCanales[i]);
        outputCanales << right << setw((anchoDoc / 3) - 8) << codeCharCanales[i] << codeIntCanales[i];
        outputCanales << right << setw((anchoDoc / 3)) << ratingCanales[i] << endl;
    }
}

void cargarEtiquetas(const char *nombre, int *codeEtiquetas, int *duracionEtiquetas, int &cantEtiquetas) {
    ifstream inputEtiquetas;
    abrirEntrada(inputEtiquetas, nombre);
    int code;
    while (true) {
        //501201   dragon_slayer      12:45
        inputEtiquetas >> code >> ws;
        if (inputEtiquetas.eof()) break;
        codeEtiquetas[cantEtiquetas] = code;
        inputEtiquetas.ignore(40, ' ');
        duracionEtiquetas[cantEtiquetas] = leerTiempo(inputEtiquetas);
        cantEtiquetas++;
    }
    inputEtiquetas.close();
}

void ordenarEtiquetas(int *codeEtiquetas, int *duracionEtiquetas, int cantEtiquetas) {
    for (int i = 0; i < cantEtiquetas - 1; i++) {
        for (int j = i + 1; j < cantEtiquetas; j++) {
            if (duracionEtiquetas[j] > duracionEtiquetas[i]) {
                swapInt(codeEtiquetas[i], codeEtiquetas[j]);
                swapInt(duracionEtiquetas[i], duracionEtiquetas[j]);
            }
        }
    }
}

void probarEtiquetas(const char *nombre, int *codeEtiquetas, int *duracionEtiquetas, int cantEtiquetas) {
    ofstream outputEtiquetas;
    abrirSalida(outputEtiquetas, nombre);

    outputEtiquetas << setw((anchoDoc + 6) / 2) << "ETIQUETAS" << endl;
    imprimirLinea(outputEtiquetas, '=');
    outputEtiquetas << right << setw((anchoDoc) / 4) << "CODIGO";
    outputEtiquetas << right << setw((anchoDoc) / 2) << "DURACION" << endl;
    imprimirLinea(outputEtiquetas, '-');

    for (int i = 0; i < cantEtiquetas; i++) {
        outputEtiquetas << right << setw((anchoDoc) / 4) << codeEtiquetas[i];
        outputEtiquetas << right << setw((anchoDoc / 2) - 8) << ' ';
        imprimirTiempo(outputEtiquetas, duracionEtiquetas[i]);
        outputEtiquetas << endl;
    }
}

void swapInt(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void swapDouble(double &a, double &b) {
    double aux = a;
    a = b;
    b = aux;
}

void swapChar(char &a, char &b) {
    char aux = a;
    a = b;
    b = aux;
}


//fijas
void abrirEntrada(ifstream &input, const char *nombre) {
    input.open(nombre, ios::in);
    if (!input) {
        cout << "Error al abrir el archivo de nombre: " << nombre << endl;
        exit(1);
    }
}

void abrirSalida(ofstream &output, const char *nombre) {
    output.open(nombre, ios::out);
    if (!output) {
        cout << "Error al abrir el archivo de nombre: " << nombre << endl;
        exit(1);
    }
}

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

void imprimirLinea(ofstream &output, char c) {
    for (int i = 0; i < anchoDoc; i++) output << c;
    output << endl;
}

int leerTiempo(ifstream &input) {
    int min, seg;
    char c;
    input >> min >> c >> seg;
    return min * 60 + seg;
}

void imprimirTiempo(ofstream &output, int tiempo) {
    output << setfill('0');
    output << right << setw(2) << tiempo / 3600 << ':' << setw(2) << (tiempo / 60) % 60 << ':' << setw(2) << tiempo %
            60;
    output << setfill(' ');
}
