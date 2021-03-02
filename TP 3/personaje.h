#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H
#include "coordenada.h"
#include "libraries.h"

class Personaje {
    protected:
            
        string nombre;
        int escudo;
        int vida;
        int energia;
        Coordenada coordenada;
        bool jugando;


    public:
        // PRE: escudo = 0, 1 ó 2 ;  10 <= vida <= 100
        // POST: construye un personaje con el nombre, escudo, energía y vida
        // adecuados
        Personaje(string nombre, int escudo, int vida);

        // POST: devuelve el nombre del personaje
        string obtenerNombre();

        // POST: devuelve el valor del escudo del personaje
        int obtenerEscudo();

        // POST: devuelve el valor de vida del personaje
        int obtenerVida();

        // POST: devuelve el valor de energía del personaje
        int obtenerEnergia();

        // POST devuelve la coordenada como objeto
        Coordenada* obtenerCoordenada();

        // POST: devuelve si el personaje esta jugando o no.
        bool obtenerCondicion();

        // POST: asigna un nuevo escudo al personaje.
        void asignarEscudo(int escudoNuevo);

        // POST: asigna una nueva energia al personaje.
        void asignarEnergia(int energiaNueva);

        // POST: asigna una nueva vida al personaje.
        void asignarVida(int vidaNueva);

        // POST: asigna una nueva coordenada de la posicion del personaje en el mapa.
        void asignarCoordenada(int fila,int columna);

        // POST: asigna el valor de condicion del personaje, si es que el personaje
        // esta en juego o no.
        void asignarCondicion(bool condicion);

        // Recibe un valor de energia para gastar
        // POST: devuelve verdadero si la energia del personaje menos esa energia
        // gastada es valida.
        bool energiaValida(int energiaGastada);

        // Recibe la energia que se gasta.
        // POST: le resta la energia ingresada a la energia del propio personaje
        void gastarEnergia(int energiaGastada);

        // POST: devuelve el elemento del personaje
        virtual string obtenerElemento() = 0;

        // POST: devuelve el alimento del personaje
        virtual string obtenerAlimento() = 0;

        // POST: deja al personaje alimentado
        virtual void alimentar() = 0;

        // Realiza el ataque
        // PRE: debe tener energia suficiente para atacar
        // POS: ejecuta su acaque sobre el equipo enemigo
        virtual void ataque(Personaje* enemigos[MAX_PERSONAJES]) = 0;

        // Le quita la vida al personaje segun su escudo y el da�o base que recibe
        // PRE:
        // POS:le quita vida al personaje segun su escudo y el da�o base que recibe
        void daniar(int daniar);

        // Realiza la defensa
        // PRE: debe tener energia suficiente para defenderse
        // POST: ejecuta la defensa
        virtual void defensa(Personaje* aliados[MAX_PERSONAJES]) = 0;

        // Resetea variables relacionadas a la defensa
        // PRE:
        // POST: resetea a falso variables relacionadas con la defensa
        virtual void reseteoDefensa();

        // PRE: 
        // POST: suma energia al atributo de energia
        virtual void recuperarEnergia();

        // POST: devuelve verdadero en caso de que tenga suficiente energia para atacar
        virtual bool puedeAtacar() = 0;

        // POST: devuelve verdadero en caso de que tenga suficiente energia para defenderse
        virtual bool puedeDefender() = 0;

        // POST: devuelve los datos del personaje
        void consultaDatos();

        // Destructor
        virtual ~Personaje();
};

#endif  // TP2_PERSONAJE_H
