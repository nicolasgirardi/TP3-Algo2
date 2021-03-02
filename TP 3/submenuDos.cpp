#include "submenuDos.h"

SubmenuDos::SubmenuDos() : Menu() {}

void SubmenuDos::mostrarMenu() {
  cout << "Ingrese una de las siguientes opciones:" << endl;
  cout << "1) Atacar personaje:" << endl;
  cout << "2) Defender personaje." << endl;
  cout << "3) Pasar opcion" << endl;
}

void SubmenuDos::ejecutarOpcion(Personaje* personaje,
                                Personaje* enemigos[MAX_PERSONAJES],
                                Personaje* aliados[MAX_PERSONAJES]) {
  switch (stoi(obtenerOpcion())) {
    case OPCION_ATACAR:
      if (personaje->puedeAtacar()) {
        personaje->ataque(enemigos);
      }
      break;
    case OPCION_DEFENDER:
      if (personaje->puedeDefender()) {
        personaje->defensa(aliados);
      }
      break;
  }
}

void SubmenuDos::moverGratis(Mapa *mapa, Personaje *personaje) {
    Coordenada destino(0);
    int costoMovimiento = 0;
    bool mover = false;
    do {
        pedirCoordenada(&destino,personaje);
        if (mapa->consulta(destino)->obtenerDato()->ocupacion())
            cout << "La casilla de destino se encuentra ocupada, elija otra casilla" << endl;
        else {
            concretarMovimiento(mapa,personaje,destino,costoMovimiento,&mover);
        }
    } while (!mover);
}

SubmenuDos::~SubmenuDos(){}