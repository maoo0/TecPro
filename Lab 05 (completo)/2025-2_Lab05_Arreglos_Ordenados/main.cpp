#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    double tarifa = 0.78;

    //19/06/2022     X5514     xQcOW     2.5
    int fechaCanales[maxCanales]{}, codeIntCanales[maxCanales]{}, cantCanales = 0;
    char codeCharCanales[maxCanales]{};
    double ratingCanales[maxCanales]{};
    cargarCanales("ArchivosDeDatos/Canales.txt", fechaCanales, codeIntCanales,
                  codeCharCanales, ratingCanales, cantCanales);
    probarCanales("ArchivosDeReporte/outputCanales.txt", fechaCanales, codeIntCanales,
                  codeCharCanales, ratingCanales, cantCanales);

    //803100    dropsenabled   01:27
    int codeEtiquetas[maxEtiquetas]{}, duracionEtiquetas[maxEtiquetas]{}, cantEtiquetas = 0;

    cargarEtiquetas("ArchivosDeDatos/Etiquetas.txt", codeEtiquetas, duracionEtiquetas, cantEtiquetas);
    ordenarEtiquetas(codeEtiquetas, duracionEtiquetas, cantEtiquetas);
    probarEtiquetas("ArchivosDeReporte/outputEtiquetas.txt", codeEtiquetas, duracionEtiquetas, cantEtiquetas);

    //P7271    113141
    int codeIntCanalesExC[maxExC]{}, codeEtiquetasExC[maxExC]{}, cantExC = 0;
    char codeCharCanalesExC[maxExC]{};

    cargarExC("ArchivosDeDatos/EtiquetasEnCanales.txt", codeIntCanalesExC, codeEtiquetasExC,
              codeCharCanalesExC, cantExC);
    probarExC("ArchivosDeReporte/outputEtiquetasEnCanales.txt", codeIntCanalesExC, codeEtiquetasExC,
              codeCharCanalesExC, cantExC);

    //28/02/2025  E6696      888106      244
    int nTotalReproduccionesCanales[maxCanales];


    procesarArreglosAux("ArchivosDeDatos/ReproduccionesDeEtiquetas.txt", nTotalReproduccionesCanales, //aux
                        codeIntCanales, codeCharCanales, ratingCanales, cantCanales, //Canales
                        codeIntCanalesExC, codeEtiquetasExC, codeCharCanalesExC, cantExC); //ExC


    imprimirReporte("ArchivosDeReporte/output.txt", nTotalReproduccionesCanales, tarifa, //aux y tarifa
                        codeIntCanales, codeCharCanales, ratingCanales, cantCanales, //Canales
                        codeEtiquetas, duracionEtiquetas, cantEtiquetas, //Etiquetas
                        codeIntCanalesExC, codeEtiquetasExC, codeCharCanalesExC, cantExC);
    return 0;
}
