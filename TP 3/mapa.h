#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include "camino.h"
#include "coordenada.h"
#include "lago.h"
#include "montana.h"
#include "nodo_grafo.h"
#include "precipicio.h"
#include "vacio.h"
#include "volcan.h"

class Mapa {
 private:
  nodoGrafo* inicio;  // el inicio sera la esquina superior izquierda

 public:
  // POS: crea un mapa vacio
  Mapa();

  // POST: devuelve true si el mapa esta vacio
  bool vacio();

  // Verifica si hay un personaje en una coordenada
  // PRE: vacio debe ser falso
  // POS: devuelve true si la casilla esta ocupada
  bool ocupado(Coordenada coor);

  // Consulta el dato del nodo de la fila i columna j
  // PRE: vacio debe ser false
  // POST: devuelve el dato del nodo de la fila i columna j
  nodoGrafo* consulta(Coordenada coor);

  // private:

  // Da de alta un nodo en la posicion fila y columna
  // PRE: debe existir un nodo en la posicion (fila-1,columna) o
  // (fila,columna-1), salvo vacio sea true e fila=columna=1 y de tipo valido
  // POS: crea un nodo en la posicion fila y columna
  void alta(Coordenada coor, string tipo);

  // Da de baja un nodo en la posicion fila y columna
  // PRE: derecha y abajo deben ser nulos en el nodo a borrar
  // POS: elimina un nodo en la posicion fila y columna
  void baja(Coordenada coor);

  // Carga un mapa desde un archivo cvs
  // PRE: vacio debe ser true, el mapa debe ser de 8x8 y solo con las casillas
  // de los tipos monta�a, precipicio, lago, volcan, camino o vacio
  // POS: crea el mapa del archivo

  void mapear(string nombreArchivo);

  void determinarCaracter(int i, int j, char* c, Personaje* personajeActual,Personaje* personajesJugadorUno[MAX_PERSONAJES], Personaje* personajesJugadorDos[MAX_PERSONAJES]);

  void imprimirMapa(Personaje* personajeActual, Personaje* personajesJugadorUno[MAX_PERSONAJES], Personaje* personajesJugadorDos[MAX_PERSONAJES]);

  // POS: libera la memoria
  virtual ~Mapa();
};

#endif  // MAPA_H_INCLUDED
