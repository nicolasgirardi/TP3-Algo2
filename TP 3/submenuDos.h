#ifndef SUBMENUDOS_H_INCLUDED
#define SUBMENUDOS_H_INCLUDED

#include "menu.h"

class SubmenuDos: public Menu {
 public:
 
  //POST: crea un objeto submenudos 
  SubmenuDos();

  // POST: muestra el menu por pantalla
  void mostrarMenu();

  // POST: ejecuta la opcion elegida.
  void ejecutarOpcion(Personaje* personaje, Personaje* enemigos[MAX_PERSONAJES],Personaje* aliados[MAX_PERSONAJES]);

  //POST: procesa el movimiento del personaje sin chequear el costo
  void moverGratis(Mapa* mapa, Personaje* personaje);

  ~SubmenuDos();
};

#endif  // SUBMENUDOS_H_INCLUDED
