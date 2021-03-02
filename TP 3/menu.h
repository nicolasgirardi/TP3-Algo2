#ifndef TP2_MENU_H
#define TP2_MENU_H

#include "agua.h"
#include "aire.h"
#include "archivo.h"
#include "costos.h"
#include "diccionario.h"
#include "fuego.h"
#include "mapa.h"
#include "tierra.h"

class Menu {
protected:
  string opcion;

public:
  // POST: construye un menu. Se inicializa opcion con un valor distinto a la
  // salida (6 menu, 4 submenu) para asegurarse entrar al ciclo aunque sea una
  // vez.
  Menu();



  void concretarMovimiento(Mapa* mapa, Personaje* personaje,Coordenada destino, int costo,bool* mover);

  void asignarOpcion(string d);


  string obtenerOpcion();

  void pedirCoordenada(Coordenada* destino, Personaje* personaje);


        // POST:libera la memoria
  virtual ~Menu();

  //POST: pide y guarda la opción ingresada por el usuario
  void elegirOpcion();

  // POST: pide y guarda el nombre ingresado por el usuario
  void pedirNombre(string* nombre);

  // POST: procesa para mostrar detalles de un personaje a elección
  void verDetalles(Diccionario* diccionarioPersonajes);

  // POST: muestra por pantalla un listado con los nombres de cada personaje de
  // la lista
  void mostrarNombres(Diccionario* diccionarioPersonajes);

  Personaje* buscarNombre(string* nombre,Diccionario* diccionarioPersonajes);

private:



  // POST: imprime por pantalla el menu del juego.
  virtual void mostrarMenu() = 0;


  /*
    // POST: muestra por pantalla un listado con los detalles del personaje cuyo
    // puntero se pasa por parámetro
    void mostrarInformacion(Personaje* personajeBuscado);
  */


  // no deberia ser un metodo de la clase Juego?
  void iniciarJuego(char* estadoJuego);




  bool filaValida(int fila);

  bool columnaValida(int columna);

  void pedirFila(int* fila);

  void pedirColumna(int* columna);

};

#endif  // TP2_MENU_H
