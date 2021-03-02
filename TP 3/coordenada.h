#ifndef COORDENADA_H_INCLUDED
#define COORDENADA_H_INCLUDED

#include "libraries.h"

class Coordenada {
    private:
        
        int fila;
        int columna;

    public:
        //Constructor
        Coordenada();

        // Recibe 2 numeros y crea esa coordenada
        // PRE: fila y columna deben ser entre 1 y 8 y caso particular ambas 0
        // POS: constructor, ambas cero se debe entender como que no est� en tablero
        Coordenada(int fila, int columna);

        // Recibe un numero y crea la coordenada correspondiente
        // PRE: el numero debe estar entre 0 y 63
        // POS: constructor
        Coordenada(int coordenada);

        // PRE: 
        // POST: pide una coordenada al usuario
        void pedirCoordenada();

        // PRE: 
        // POST: verifica si la fila ingresada es valida o no
        bool filaValida(int fila);

        // PRE: 
        // POST: verifica si la columna ingresada es valida o no
        bool columnaValida(int columna);

        // PRE:
        // POST: pide una fila al usuario
        void pedirFila(int* fila);

        // PRE:
        // POST: pide una columna al usuario
        void pedirColumna(int* columna);

        // Devuelve la fila
        // PRE:
        // POS: devuelve la fila
        int obtenerFila();

        // Devuelve la columna
        // PRE:
        // POS: devuelve la columna
        int obtenerColumna();

        // Devuelve la coordenada en 1 solo numero
        // PRE:
        // POS:devuelve la coordenada en 1 solo numero siendo
        // num igual a (fila-1)/8 + (columna-1)%8 (entre 0 y 63)
        int obtenerCoordenada();

        // Cambia la fila
        // PRE: fila debe ser entre 1 y 8
        // POS: cambia la fila
        void cambiarFila(int fila);

        // Cambia la columna
        // PRE:columna debe ser entre 1 y 8
        // POS: cambia la columna
        void cambiarColumna(int columna);

        // Cambia la fila y la columna
        // PRE: fila y columna debe ser entre 1 y 8
        // POS: cambia la fila y columna
        void cambiarFilaYColumna(int fila,int columna);

        // Cambia la coordenada con 1 solo numero
        // PRE: coordenada debe ser entre 0 y 63
        // POS:cambia la coordenada con 1 solo numero
        void cambiarCoordenada(int coordenada);

        // Compara 2 coordenadas y dice si son iguales
        // PRE:
        // POS: devuelve true si ambas coordenadas son iguales
        bool comparar(Coordenada* coor);

        // Destructor de coordenada
        ~Coordenada();
};

#endif  // COORDENADA_H_INCLUDED
