#include "submenuUno.h"

SubmenuUno::SubmenuUno() : Menu() {}

void SubmenuUno::mostrarMenu() {
  cout << "Ingrese una de las siguientes opciones:" << endl;
  cout << "1) Alimentar personaje:" << endl;
  cout << "2) Mover personaje." << endl;
  cout << "3) Pasar opcion" << endl;
}

void SubmenuUno::alimentarPersonaje(Personaje* personaje) {
  personaje->alimentar();
}


void SubmenuUno::moverPersonaje(Mapa* mapa, Personaje* personaje, Costos* costos) {
  Coordenada destino(0);
  int costoMovimiento;
  bool mover = false;
  do {
      cout << "Indique las coordenadas a donde desea mover " << personaje->obtenerNombre() << ":" << endl;
      destino.pedirCoordenada();
      costoMovimiento = costos->consultarCosto(personaje->obtenerCoordenada(), &destino);
      if (costoMovimiento <= personaje->obtenerEnergia()) {
        if (mapa->consulta(destino)->obtenerDato()->ocupacion())
            cout << "La casilla de destino se encuentra ocupada, elija otra casilla" << endl;
        else {
            costos->consultarCaminoMinimo(personaje->obtenerCoordenada(), &destino);
            concretarMovimiento(mapa, personaje, destino, costoMovimiento, &mover);
        }
    } else {
        cout << "El personaje no cuenta con suficiente energia para ese movimiento, elija otra casilla" << endl;
    }
  } while (!mover);
}

Costos* SubmenuUno::determinarCosto(string elemento, Costos* costos[4]) {
  int i = 0;
  while (costos[i]->consultarElemento() != elemento) {
    i++;
  }
  return costos[i];
}

void SubmenuUno::ejecutarOpcion(Mapa* mapa, Personaje* personaje, Costos* costos[4]) {
  switch (stoi(obtenerOpcion())) {
    case OPCION_ALIMENTAR:
      alimentarPersonaje(personaje);
      break;
    case OPCION_MOVER:
      moverPersonaje(mapa, personaje,determinarCosto(personaje->obtenerElemento(), costos));
      break;
  }
}

SubmenuUno::~SubmenuUno(){}
