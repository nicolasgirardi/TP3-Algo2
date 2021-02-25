#include "archivo.h"

Archivo::Archivo(){
    path = "0";
}

string Archivo::obtenerPath(){
    return path;
}

void Archivo::asignarPath(string path){
    this->path = path;
}

void Archivo::abrirArchivoLectura(){
    archivo.open(path);
}

bool Archivo::procesarArchivo(){
    abrirArchivoLectura();
    if(archivo){
        return true;
    } else {
        return false;
    }
}

bool Archivo::finArchivo() {
    return (archivo.eof() != 0);
}

void Archivo::abrirArchivoEscritura(){
    return archivo.open(path,ios::out);
}

void Archivo::escribirLinea(Personaje* personaje){
    archivo << personaje->obtenerElemento() << "," << personaje->obtenerNombre() << ",";
    archivo << personaje->obtenerEscudo() << "," << personaje->obtenerVida() << ",";
    archivo << personaje->obtenerEnergia() << "," << personaje->obtenerCoordenada()->obtenerFila() << "," << personaje->obtenerCoordenada()->obtenerColumna() << endl;
}

void Archivo::escribirArchivo(Personaje* personajesUno[MAX_PERSONAJES], int topeUno, Personaje* personajesDos[MAX_PERSONAJES], int topeDos){
    if(archivo.is_open()){
        cerrarArchivo();
    }
    abrirArchivoEscritura();
    for(int i = 0; i < topeUno; i++){
        escribirLinea(personajesUno[i]);
    }
    for(int i = 0; i < topeDos; i++){
        escribirLinea(personajesDos[i]);
    }
}

void Archivo::leerElemento(string* elemento, char delim){
    getline(archivo,*elemento,delim);
}

void Archivo::leerNombre(string* nombre, char delim){
    getline(archivo,*nombre,delim);
}

void Archivo::leerEscudo(int* escudo, char delim){
    string escudoStr;
    getline(archivo,escudoStr,delim);
    (*escudo) = stoi(escudoStr);
}

void Archivo::leerVida(int* vida, char delim){
    string vidaStr;
    if (delim == ';'){
        getline(archivo,vidaStr,delim);
    } else {
        getline(archivo, vidaStr);
    }
    (*vida) = stoi(vidaStr);
}

void Archivo::leerEnergia(int* energia, char delim){
    string energiaStr;
    getline(archivo,energiaStr,delim);
    (*energia) = stoi(energiaStr);
}

void Archivo::leerFila(int* fila, char delim){
    string filaStr;
    getline(archivo,filaStr,delim);
    (*fila) = stoi(filaStr);
}

void Archivo::leerColumna(int* columna){
    string columnaStr;
    getline(archivo,columnaStr);
    (*columna) = stoi(columnaStr);
}


void Archivo::descomponerLineaBasica(string* elemento, string* nombre, int* escudo, int* vida){
    leerElemento(elemento,';');
    leerNombre(nombre,';');
    leerEscudo(escudo,';');
    leerVida(vida,'\n');
}

void Archivo::descomponerLineaPartida(string* elemento, string* nombre, int* escudo, int* vida, int* energia, int* fila, int* columna){
    leerElemento(elemento,';');
    leerNombre(nombre,';');
    leerEscudo(escudo,';');
    leerVida(vida,';');
    leerEnergia(energia,';');
    leerFila(fila,';');
    leerColumna(columna);
}

void Archivo::cerrarArchivo(){
    return archivo.close();
}

void Archivo::eliminarArchivo(){
    cerrarArchivo();
    //remove(path);
}


Archivo::~Archivo() {
    if (archivo.is_open()) {
        cerrarArchivo();
    }
}