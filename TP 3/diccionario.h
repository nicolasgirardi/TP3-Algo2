#ifndef MAIN_CPP_DICCIONARIO_H
#define MAIN_CPP_DICCIONARIO_H

#include "nodo.h"


class Diccionario {
 private:
  Nodo* raiz;
  int cantidad;

 public:

  void todoDetalles(Nodo* d);

  // POST: crea un diccionario vacío. Deja cantidad en 0 y raíz apunta a NULL.
  Diccionario();

  // POST: devuelve true si el diccionario está vacío
  bool vacio();

  // PRE: Dato d es un puntero a un personaje que existe
  // POST: se crea un nodo con el dato d y se lo ubica en el árbol binario.
  void alta(Dato d);
  
  // PRE: clave corresponde a un nodo del diccionario
  //POST: llama a baja con el puntero al personaje cuyo nombre corresponde a la clave ingresada por parámetro
  void pedirBaja(string clave);

  // PRE: no existe más de un nodo con la misma clave
  // POST: devuelve el nodo que contiene esta clave
  Nodo* obtenerNodo(string clave, bool* encontrado);

  //PRE: 
  // POST: devuelve el dato del nodo que contiene la clave ingresada por parámetro
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
  void baja(Nodo* nodoBuscado);

  // POST: metodo recursivo de imprimirClaves, se encarga de imprimir las
  // claves de forma recursiva
  void inOrden(Nodo* d);

  // POST: imprime utilizando el metodo inOrden por pantalla todas las claves
  // del diccionario
  void imprimirClaves();


  // POST: devuelve la cantidad de nodos
  int obtenerCantidad();

  void descolgar(Nodo* exhijo,Nodo* padre);

  // POST: libera la memoria
  virtual ~Diccionario();

};

#endif  // MAIN_CPP_DICCIONARIO_H
