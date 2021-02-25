#ifndef MAIN_CPP_ARCHIVO_H
#define MAIN_CPP_ARCHIVO_H
#include "libraries.h"
#include "personaje.h"

class Archivo {
private:
    fstream archivo;
    string path;
public:
    //POST: abre el archivo personajes.csv y avisa en caso de no haberlo podido abrir
    Archivo();

    //POST: devuelve el path del archivo
    string obtenerPath();

    void asignarPath(string path);

    void abrirArchivoLectura();

    bool procesarArchivo();

    //POST: devuelve true si es el fin del archivo
    bool finArchivo();

    void abrirArchivoEscritura();

    void escribirLinea(Personaje* personaje);

    void escribirArchivo(Personaje* personajesUno[MAX_PERSONAJES], int topeUno, Personaje* personajesDos[MAX_PERSONAJES], int topeDos);

    void leerElemento(string* elemento, char delim);

    void leerNombre(string* nombre, char delim);

    void leerEscudo(int* escudo, char delim);

    void leerVida(int* vida, char delim);

    void leerEnergia(int* energia, char delim);

    void leerFila(int* fila, char delim);

    void leerColumna(int* columna);

    //POST: guarda los strings separados por ; y convierte en entero el string escudo y vida
    void descomponerLineaBasica(string* elemento, string* nombre, int* escudo, int* vida);

    void descomponerLineaPartida(string* elemento, string* nombre, int* escudo, int* vida, int* energia, int* fila, int* columna);

    void cerrarArchivo();

    void eliminarArchivo();

    //POST: cierra el archivo
    ~Archivo();
};


#endif //MAIN_CPP_ARCHIVO_H
