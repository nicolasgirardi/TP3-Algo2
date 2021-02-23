#ifndef MAIN_CPP_DICCIONARIO_H
#define MAIN_CPP_DICCIONARIO_H

#include "nodo.h"


class Diccionario {
 private:
  Nodo* raiz;
  int cantidad;

 public:
  // POST: crea una lista vacia. Deja primero y cantidad en 0.
  Diccionario();

  // POST: devuelve true si la lista está vacía
  bool vacio() const;

  // POST: inserta el dato d en la posición 1 que es la primera y ademas
  // incrementa cantidad en 1
  void alta(Dato d);

  void modificarContenido(string nombre,int escudo,int vida,int energia,int fila,int columna);

  // POST: devuelve el nodo que esta en la clave
  Nodo* obtenerNodo(string clave, bool* encontrado);

  // POST: devuelve el dato de la clave
  Dato consultaNodo(string clave);

  // POST: devuelve la informacion del dato de la clave
  void consultaInfo(string clave);

  // POST: devuelve verdadero o falso si hay un nodo con dicha clave
  bool consultaClave(string clave);

  Nodo* minimo(Nodo* d);

  void reemplazar(Nodo* nodoViejo, Nodo* nodoNuevo);

  // POST: devuelve al nodo raiz del diccionario
  Nodo* obtenerRaiz();

  // PRE: 0 < pos <= cantidad
  // POST: saca el elemento que esta en pos
  void baja(string clave);

  // POST: metodo recursivo de imprimirClaves, se encarga de imprimir las
  // claves de forma recursiva
  void inOrden(Nodo* d);

  // POST: imprime utilizando el metodo inOrden por pantalla todas las claves
  // del diccionario
  void imprimirClaves();


  // POST: devuelve la cantidad de nodos
  int obtenerCantidad();

  // POST: libera la memoria
  virtual ~Diccionario();

};

#endif  // MAIN_CPP_DICCIONARIO_H
