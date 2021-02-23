#include "agua.h"

//holaaaa soy edu

Agua::Agua(string nombre, int escudo, int vida, int fila, int columna)
    : Personaje(nombre, escudo, vida, fila, columna) {
  alimento = "plancton";
  vecesAlimentado = 0;
  elemento = "agua";
}

string Agua::obtenerElemento() { return elemento; }

string Agua::obtenerAlimento() { return alimento; }

void Agua::alimentar() {
  int energiaSuministrada = 0;
  while (energia < TOPE_ENERGIA && energiaSuministrada < AUMENTO_AGUA &&
         vecesAlimentado < MAX_CANTIDAD_AGUA) {
    energia++;
    energiaSuministrada++;
  }
  if (vecesAlimentado == MAX_CANTIDAD_AGUA) {
    cout << endl;
    cout << "Ha alcanzado el número máximo de alimentos para este personaje!"
         << endl;
  } else {
    vecesAlimentado++;
  }
}

// nuevo, idea

int Agua::obtenerDanio(string elemento) {
  int danio = 20;
  if (elemento == "fuego")
    danio += 10;
  else if (elemento == "tierra")
    danio -= 10;
  return danio;
}

void Agua::pedirObjetivo(Coordenada* lugar) {
  int fila, columna;
  cout << "Ingrese la fila objetivo: ";
  cin >> fila;
  while (fila < 1 || fila > 8) {
    cout << "Fila invalida, ingrese fila entre 1 y 8: ";
    cin >> fila;
  }
  lugar->cambiarFila(fila);
  cout << "Ingrese la columna objetivo: ";
  cin >> columna;
  while (columna < 1 || columna > 8) {
    cout << "columna invalida, ingrese columna entre 1 y 8: ";
    cin >> columna;
  }
  lugar->cambiarColumna(columna);
}

void Agua::ataque(Personaje* enemigos[]) {
  gastarEnergia(5);

  int i;
  Coordenada* lugar = new Coordenada(0);
  this->pedirObjetivo(lugar);
  for (i = 0; i < MAX_PERSONAJES; i++) {
    if (lugar->comparar(enemigos[i]->obtenerCoordenada())) {
      enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
    }
  }
  delete lugar;
}

void Agua::defensa(Personaje* aliados[]) {
  int i;
  gastarEnergia(12);
  asignarVida(this->vida + 50);
  for (i = 0; i < MAX_PERSONAJES; i++) {
    aliados[i]->asignarVida(this->vida + 10);
  }
}
