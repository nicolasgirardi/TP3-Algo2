#include "mapa.h"

Mapa::Mapa() { inicio = 0; }

bool Mapa::vacio() {
  if (!inicio)
    return true;
  else
    return false;
}

bool Mapa::ocupado(Coordenada coor) {
  if (!!(this->consulta(coor)))
    return true;
  else
    return false;
}

nodoGrafo* Mapa::consulta(Coordenada coor) {
  int fila = coor.obtenerFila();
  int columna = coor.obtenerColumna();
  nodoGrafo* aux = inicio;
  int n;
  for (n = 1; n < fila; n++) {
    aux = aux->obtenerAbajo();
  }
  for (n = 1; n < columna; n++) {
    aux = aux->obtenerDerecha();
  }

  return aux;
}

void Mapa::alta(Coordenada coor, string tipo) {
  Casilla* casilla;
  nodoGrafo* nuevo;
  nodoGrafo* aux;
  int fila = coor.obtenerFila();
  int columna = coor.obtenerColumna();
  Coordenada coorAux(fila, columna);
  switch (tipo.at(0)) {
    case ('m'):
      casilla = new Montana();
      break;
    case ('p'):
      casilla = new Precipicio();
      break;
    case ('l'):
      casilla = new Lago();
      break;
    case ('v'):
      casilla = new Volcan();
      break;
    case ('c'):
      casilla = new Camino();
      break;
    case ('f'):  // le cambie a 'f' porque no se puede repetir con la de volcan
      casilla = new Vacio();
      break;
  }
  nuevo = new nodoGrafo(casilla);
  if (this->vacio()) {
    inicio = nuevo;
  }
  else {
    if(fila != 1) {
      coorAux.cambiarFilaYColumna(fila - 1, columna);
      aux = this->consulta(coorAux);
      aux->cambiarAbajo(nuevo);
      nuevo->cambiarArriba(aux);

    }
    if(columna != 1) {
      coorAux.cambiarFilaYColumna(fila, columna - 1);
      aux = this->consulta(coorAux);
      aux->cambiarDerecha(nuevo);
      nuevo->cambiarIzquierda(aux);
    }
  }
}

void Mapa::baja(Coordenada coor) {
  int fila = coor.obtenerFila();
  int columna = coor.obtenerColumna();
  nodoGrafo* borrar = this->consulta(coor);
  if (fila != 1) borrar->obtenerArriba()->cambiarAbajo(0);
  if (columna != 1) borrar->obtenerIzquierda()->cambiarDerecha(0);
  delete borrar->obtenerDato();
  delete borrar;
  if (fila == 1 && columna == 1) {
      inicio = 0;
  }
}

void Mapa::mapear(string nombreArchivo) {
  int i, j;
  fstream archivo;
  archivo.open(nombreArchivo);
  Coordenada coor(0, 0);
  string tipo;
  //if(archivo.is_open()){tipo = "esta abierto";}
  for (i = 1; i <= 8; i++) {
    coor.cambiarFila(i);
    for (j = 1; j <= 8; j++) {
      coor.cambiarColumna(j);
      if (j < 8) {
        getline(archivo, tipo, ';');
        this->alta(coor, tipo);
      } else {
        getline(archivo, tipo);
        this->alta(coor, tipo);
      }
    }
  }
  archivo.close();
}

Mapa::~Mapa() {
  int i, j;
  Coordenada coor(0, 0);
  for (i = 8; i >= 1; i--) {
    coor.cambiarFila(i);
    for (j = 8; j >= 1; j--) {
      coor.cambiarColumna(j);
      this->baja(coor);
    }
  }
}
