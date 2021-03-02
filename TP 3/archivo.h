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

        // POST: recibe path y se lo asigna al archivo
        void asignarPath(string path);

        // POST: abre el archivo en modo lectura
        void abrirArchivoLectura();

        // POST: devuelve verdadero en caso de que el archivo exista
        bool procesarArchivo();

        //POST: devuelve true si es el fin del archivo
        bool finArchivo();

        // POST: abre el archivo en modo escritura
        void abrirArchivoEscritura();

        // POST: escribe una linea en el archivo
        void escribirLinea(Personaje* personaje,int i,int ultimoPersonaje);

        // POST: escribe el archivo
        void escribirArchivo(Personaje* personajesUno[MAX_PERSONAJES], int topeUno, Personaje* personajesDos[MAX_PERSONAJES], int topeDos);

        // POST: lee el elemento
        void leerElemento(string* elemento, char delim);

        // POST: lee el nombre
        void leerNombre(string* nombre, char delim);

        // POST: lee el escudo
        void leerEscudo(int* escudo, char delim);

        // POST: lee la vida
        void leerVida(int* vida, char delim);

        // POST: lee la energia
        void leerEnergia(int* energia, char delim);

        // POST: lee la fila
        void leerFila(int* fila, char delim);

        // POST: lee la columna
        void leerColumna(int* columna);

        //POST: guarda los strings separados por ; y convierte en entero el string escudo y vida
        void descomponerLineaBasica(string* elemento, string* nombre, int* escudo, int* vida);

        // POST: guarda los strings separados por ; y convierte en entero el string escudo, vida, energia, fila y columna
        void descomponerLineaPartida(string* elemento, string* nombre, int* escudo, int* vida, int* energia, int* fila, int* columna);

        // POST: cierra el archivo
        void cerrarArchivo();

        // POST: se ocupa de eliminar el archivo
        void eliminarArchivo();

        //POST: cierra el archivo
        ~Archivo();
};


#endif //MAIN_CPP_ARCHIVO_H
