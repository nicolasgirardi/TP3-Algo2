#ifndef MAIN_CPP_JUEGO_H
#define MAIN_CPP_JUEGO_H

#include "menu.h"

class Juego {
private:
    Menu menuPartida;
    Mapa mapaPartida;
    Archivo archivoPartida;
    char estadoJuego;
    Personaje *personajesJugadorUno[MAX_PERSONAJES];
    int cantidadPersonajesUno;
    Personaje *personajesJugadorDos[MAX_PERSONAJES];
    int cantidadPersonajesDos;

public:
    //POST: construye un menu. Se inicializa opcion con un valor distinto a la salida (6) para asegurarse entrar al ciclo aunque sea una vez
    //constuye un menu o un juego???
    Juego();

    void definirPreliminares(Mapa* mapa);

    void ubicarPersonajes();

    void elegirPersonajes();

    void elegirPrimerLugar(bool* empiezaUno);

    Mapa obtenerMapa();

    int contarMuertos(Personaje* personajes[MAX_PERSONAJES],int tope);

    bool consultaEliminado();

    void asignarEstadoJuego(char estado);

    void jugarTurno(Personaje* personajes[MAX_PERSONAJES],int topeUno, int* i);

    bool opcionValida(char opcion);

    void pedirGuardado(char* opcion);

    void procesarGuardado(char opcion, bool* guardo);

    void consultarGuardado(bool* guardo);

    void procesarTurnos(Personaje* personajesPrimero[MAX_PERSONAJES],int topeUno, Personaje* personajesSegundo[MAX_PERSONAJES], int topeDos);

    void asignarPersonaje(Personaje* personajes[MAX_PERSONAJES], int* tope, Personaje* personajeNuevo);

    void cargarPartida();

    void revisarPartida();

    void procesarJuego();

    //POST: ejecuta todos los métodos principales del menú
    //void procesarMenu(); y esta funcion????

    //POST:libera la memoria
    virtual ~Juego();

};

#endif //MAIN_CPP_JUEGO_H
