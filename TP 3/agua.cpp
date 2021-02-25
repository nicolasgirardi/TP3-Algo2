#include "agua.h"


Agua::Agua(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
  alimento = "plancton";
  vecesAlimentado = 0;
}


string Agua::obtenerAlimento() { return alimento; }

string Agua::obtenerElemento(){
	return "agua";
}

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


int Agua::obtenerDanio(string elemento) {
  int danio = 20;
  if (elemento == "fuego")
    danio += 10;
  else if (elemento == "tierra")
    danio -= 10;
  return danio;
}

bool Agua::filaValida(int fila){
    return (fila >= MINIMO_TABLERO && fila <= MAXIMO_TABLERO);
}

bool Agua::columnaValida(int columna){
    return (columna >= MINIMO_TABLERO && columna <= MAXIMO_TABLERO);
}

void Agua::pedirFila(int* fila){
    cout << "Ingrese fila: ";
    cin >> *fila;
    while (!filaValida(*fila)){
        cout << "Fila ingresada en el rango incorrecto, debe ingresar una fila entre 1 y 8: ";
        cin >> *fila;
    }
}

void Agua::pedirColumna(int* columna){
    cout << "Ingrese columna: ";
    cin >> *columna;
    while (!columnaValida(*columna)){
        cout << "Columna ingresada en el rango incorrecto, debe ingresar una columna entre 1 y 8: ";
        cin >> *columna;
    }
}

void Agua::pedirObjetivo(Coordenada* lugar) {
  int fila, columna;
  cout << "Ingrese las coordenadas del objetivo: ";
  pedirFila(&fila);
  lugar->cambiarFila(fila);
  pedirColumna(&columna);
  lugar->cambiarColumna(columna);
}



void Agua::ataque(Personaje* enemigos[MAX_PERSONAJES]) {
  gastarEnergia(ENERGIA_ATAQUE_AGUA);
  int i;
  Coordenada* lugar = new Coordenada(0);
  this->pedirObjetivo(lugar);
  for (i = 0; i < MAX_PERSONAJES; i++) { //tiene en cuenta que solo puede haber como máximo
    if (lugar->comparar(enemigos[i]->obtenerCoordenada())) {
      enemigos[i]->daniar(this->obtenerDanio(enemigos[i]->obtenerElemento()));
    }
  }
  delete lugar;
}

void Agua::defensa(Personaje* aliados[MAX_PERSONAJES]) {
  int i;
  gastarEnergia(ENERGIA_DEFENSA_AGUA);
  asignarVida(this->vida + 50);
  for (i = 0; i < MAX_PERSONAJES; i++) {
    aliados[i]->asignarVida(this->vida + 10);
  }
}

bool Agua::puedeAtacar(){
	if(this->energia >= ENERGIA_ATAQUE_AGUA)
		return true;
	else
		return false;	
}

bool Agua::puedeDefender(){
	if(this->energia >= ENERGIA_DEFENSA_AGUA)
		return true;
	else
		return false;	
}
