#ifndef LAGO_H
#define LAGO_H
#include "casilla.h"

class Lago : public Casilla {
    private:
        
        int costo;

    public:
        // PRE:
        // POST: construje una casilla de lago
        Lago();

        // PRE:
        // POST: devuelve el tipo de la casilla
        string Tipo();

        // PRE:
        // POST: devuelve el costo de llegar
        int obtenerCosto(string elemento);
};

#endif  // LAGO_H
