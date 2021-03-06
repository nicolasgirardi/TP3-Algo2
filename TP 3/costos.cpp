#include "costos.h"

Costos::Costos(string elemento, Mapa* mapa) {
    int i, j;
    this->elemento = elemento;
    Coordenada* coor = new Coordenada(0);
    costo = new int*[64];
    recorridos = new int*[64];
    for (i = 0; i < 64; i++) {
        costo[i] = new int[64];
        recorridos[i] = new int[64];
        coor->cambiarCoordenada(i);
        for (j = 0; j < 64; j++) {
            coor->cambiarCoordenada(j);
            if (j == i){
                costo[i][j] = 0;
            }
            else if (((j == i + 1 || j == i - 1) && ((j / 8 == i / 8))) || j == i + 8 || j == i - 8){
                costo[i][j] = ((mapa->consulta(*coor))->obtenerDato())->obtenerCosto(elemento);
            }
            else{
                costo[i][j] = 0xffff;
            }
            recorridos[i][j] = j;
        }
    }
    delete coor;
}

string Costos::consultarElemento(){
    return elemento;
}

void Costos::minimizar() {
    int i, j, k;
    j = 0;
    for (k = 0; k < 64; k++) {
        for (i = 0; i < 64; i++) {
            if (i != k && j != k && i != j) {
                if ((costo[i][k] + costo[k][j]) < costo[i][j]) {
                    costo[i][j] = costo[i][k] + costo[k][j];
                    recorridos[i][j] = recorridos[k][j];
                }
            }
        }
    }
}

int Costos::consultarCosto(Coordenada* inicial, Coordenada* final) {
    return this->costo[inicial->obtenerCoordenada()][final->obtenerCoordenada()];
}

void Costos::consultarCaminoMinimo(Coordenada* inicial,Coordenada* final) {
    int i, j;
    Pila camino;
    i = inicial->obtenerCoordenada();
    j = final->obtenerCoordenada();
    Coordenada* aux = new Coordenada(j);
    camino.apilar(aux);

    while (j != this->recorridos[i][j]) {
        aux = new Coordenada(this->recorridos[i][j]);

        camino.apilar(aux);

        j = aux->obtenerCoordenada();
    }
    aux = new Coordenada(i);

    camino.apilar(aux);
    cout << "Camino tomado: "<< endl;
    i = 1;
    while(!camino.vacia()){
        cout << i << "-: " << camino.consultar()->obtenerFila() << " - " << camino.consultar()->obtenerColumna() << endl;
        camino.desapilar();
        i++;
    }
}

Costos::~Costos() {
    int i;
    for (i = 0; i < 64; i++) {
        delete[] costo[i];
        delete[] recorridos[i];
    }
    delete[] costo;
    delete[] recorridos;
}
