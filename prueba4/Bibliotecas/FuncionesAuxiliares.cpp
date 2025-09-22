//
// Created by mauri on 22/09/2025.
//

#include "FuncionesAuxiliares.hpp"


void crearImprimirReporte(const char * ubiCanales, const char * ubiSponsors, const char *ubiStreams, const char *ubiOutput) {
    ifstream inputCanales, inputSponsors, inputStreams;
    abrirEntrada(inputCanales, ubiCanales);
    abrirEntrada(inputSponsors, ubiSponsors);
    abrirEntrada(inputStreams, ubiStreams);
    ofstream output;
    abrirSalida(output, ubiOutput);
    int fechaMin, fechaMax, fecha, nUsers=0, subTotalRepro=0, subTotalDur=0, TotalRepro=0, TotalDur=0;
    double pagoRepro, pagoDur, index;
    imprimirTitulo(inputCanales, output, fechaMin,  fechaMax, pagoRepro, pagoDur);
    while (true) {
        if (inputCanales.eof()) break;
        fecha = leerFecha(inputCanales);
        if (!(fechaMin <= fecha and fechaMax >= fecha)) {
            inputCanales.ignore(380, '\n');
            continue;
        }
        nUsers++;
        imprimirDatosFijos(inputCanales, output, fecha, nUsers, index);
        imprimirDatosVariables(inputCanales, inputStreams, inputSponsors, output,
            subTotalRepro, subTotalDur);
        imprimirResumenPorCanal(output, subTotalRepro, subTotalDur, pagoRepro, pagoDur, index);
        TotalRepro += subTotalRepro;
        TotalDur += subTotalDur;
    }
    imprimirResumenFinal(output, TotalRepro, TotalDur, pagoRepro, pagoDur);
}
//cosos
void imprimirResumenFinal( ofstream& output, int TotalRepro, int TotalDur,
    double pagoRepro,double pagoDur) {

}

void imprimirResumenPorCanal(ofstream& output,int  subTotalRepro, int subTotalDur, double pagoRepro,
    double pagoDur, double index) {

}

void imprimirDatosVariables(ifstream& inputCanales,ifstream& inputStreams,ifstream& inputSponsors,
    ofstream& output, int &subTotalRepro, int &subTotalDur) {
}

void imprimirDatosFijos(ifstream &inpupt, ofstream& output, int fecha,int nUser,double & index) {

}

void imprimirTitulo(ifstream& input, ofstream& output, int fechaMin, int fechaMax, double pagoRepro, double PagoDur) {


}


//abrir
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
    int fecha, dia, mes, anio;
    char c;
    input >> dia >> c >> mes >> c >> anio;
    fecha=anio*10000+mes*100+dia;
    return fecha;
}

void imprimirFecha(ofstream &output, int fecha) {
    output << setfill('0');
    output << right << setw(2) << fecha%100 << "/" << setw(2) << (fecha/100)%100 << "/" << setw(4) << (fecha/10000);
    output << setfill(' ');
}

int leerTiempo(ifstream &input) {
    int tiempo, hora, min, seg;
    char c;
    input >> seg >> c >> min >> c >> hora;
    tiempo=hora*3600+min*60+seg;
    return tiempo;
}

void imprimirTiempo(ofstream &output, int tiempo) {
    output << setfill('0');
    output << right << setw(2) << tiempo/3600 << ":" << setw(2) << (tiempo/60)%60 << ":" << setw(2) << tiempo%60;
    output << setfill(' ');
}

void leerImprmirNombre(ifstream &input, ofstream &output) {
    char c;
    int contador=0;
    input >> ws;
    while (true) {
        c= input.get();
        if (c==' ') break;
        if (c>= 'a' and c<= 'z') c=c-'a'+'A';
        output.put(c);
        contador++;
    }
    output << setw(15-contador) << ' ';
}

void imprimirLinea(ofstream &output, char c) {
    for (int i=0; i<anchoDoc; ++i) cout << c;
    cout << endl;
}



