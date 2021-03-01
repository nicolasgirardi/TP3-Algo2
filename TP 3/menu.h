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
 private:
  Diccionario diccionarioPersonajes;
  string opcion;

 public:
  // POST: construye un menu. Se inicializa opcion con un valor distinto a la
  // salida (6 menu, 4 submenu) para asegurarse entrar al ciclo aunque sea una
  // vez.
  Menu();

  // POST: ejecuta todos los métodos principales del menú principal
  void procesarMenuPrincipal(char* estadoJuego);

  // POST: se procesa el menu del juego para comenzar a jugar
  void procesarMenuJuego(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno,
                         Personaje* jugadorDos[MAX_PERSONAJES], int* topeDos);

  // PRE: escudo= 0, 1 ó 2 ; 10 <= vida <= 100 ; elemento es tierra,agua,fuego o
  // aire POST: crea un personaje en la memoria dinámica y lo agrega a la lista
  Personaje* crearPersonaje(string elemento, string nombre, int escudo, int vida);

  // POST: procesa cada turno del juego.
  void procesarTurno(Mapa* mapa, Personaje* personaje, Costos* costos[4], Personaje* enemigos[MAX_PERSONAJES],  Personaje* aliados[MAX_PERSONAJES]);

  // POST: devuelve el diccionario con los personajes.
  Diccionario obtenerDiccionario();

  string obtenerOpcion();

  void moverGratis(Mapa* mapa,Personaje* personaje);

  // POST:libera la memoria
  virtual ~Menu();

private:

    // POST: pide y guarda la opción ingresada por el usuario
  void elegirOpcion();

  // POST: imprime por pantalla el menú principal
  void mostrarMenuPrincipal();

  // POST: imprime por pantalla el menu del juego.
  void mostrarMenuJuego();

  // POST: imprime por pantalla el submenú uno
  void mostrarSubmenuUno();

  // POST: imprime por pantalla el submenú dos
  void mostrarSubmenuDos();

  // POST: devuelve true si el elemento es fuego, aire, agua o tierra
  bool elementoValido(string elemento);

  // POST: pide y guarda un elemento ingresado por el usuario
  void pedirElemento(string* elemento);

  // POST: pide y guarda el nombre ingresado por el usuario
  void pedirNombre(string* nombre);

  // POST: el nombre ingresado es nuevo y no existía en ningún personaje de la
  // lista.
  void ingresarNombre(string* nombre);

  // POST: escudo queda cargado con un valor que puede ser 0 , 1 o 2
  void determinarEscudo(int* escudo);

  // POST: vida queda cargadada con un valor aleatorio entre 10 y 100
  void cargarVida(int* vida);

  // POST: termina reuniendo los datos necesarios para crear un personaje
  void agregarPersonaje();

  // PRE: puntero a una posicion > 0
  // POST: devuelve un puntero al personaje buscado y el puntero se actualiza
  // para apuntar a la posicion de dicho personaje en la lista
  Personaje* buscarNombre(string* nombre);

  // POST: libera la memoria ocupada en la creación del personaje y lo da de
  // baja en la lista
  void eliminarPersonaje();

  // POST: muestra por pantalla un listado con los nombres de cada personaje de
  // la lista
  void mostrarNombres();
  /*
    // POST: muestra por pantalla un listado con los detalles del personaje cuyo
    // puntero se pasa por parámetro
    void mostrarInformacion(Personaje* personajeBuscado);
  */

  // POST: procesa para mostrar detalles de un personaje a elección
  void verDetalles();

  // no deberia ser un metodo de la clase Juego?
  void iniciarJuego(char* estadoJuego);

  void ejecutarOpcionPrincipal(char* estadoJuego);

  // POST: imprime por pantalla que se ha alcanzado el numero maximo de
  // personajes elegidos
  void imprimirError();

  // POST: imprime por pantalla si un personaje esta usado o no
  void imprimirUsado();

  // POST: se encarga de seleccionar un personaje
  void seleccionarPersonaje(Personaje* jugador[MAX_PERSONAJES], int* tope,
                            string* nombre);

  void procesarSeleccion(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno,
                         Personaje* jugadorDos[MAX_PERSONAJES], int* topeDos);

  // POST: se ejecuta la opcion elegida por el usuario del menu del juego
  void ejecutarOpcionJuego(Personaje* jugadorUno[MAX_PERSONAJES], int* topeUno,
                           Personaje* jugadorDos[MAX_PERSONAJES], int* topeDos);

  // POST: reinicia la opcion del menu a 0.
  void limpiarOpcion();
 
  void recuperarAire(Personaje* personaje);

  // POST: lleva a cabo la alimentación de un personaje a elección
  void alimentarPersonaje(Personaje* personaje);


  bool filaValida(int fila);

  bool columnaValida(int columna);

  void pedirFila(int* fila);

  void pedirColumna(int* columna);

  void pedirCoordenada(Coordenada* destino, Personaje* personaje);

  void concretarMovimiento(Mapa* mapa, Personaje* personaje, Coordenada destino, int costo, bool* mover);

  void moverPersonaje(Mapa* mapa, Personaje* personaje, Costos* costos);

  Costos* determinarCosto(string elemento, Costos* costos[4]);

  void ejecutarOpcionSubUno(Mapa* mapa, Personaje* personaje, Costos* costos[4]);

  void ejecutarOpcionSubDos(Personaje* personaje, Personaje* enemigos[MAX_PERSONAJES],  Personaje* aliados[MAX_PERSONAJES]);

  void nombreValido(string* nombre);
};

#endif  // TP2_MENU_H
