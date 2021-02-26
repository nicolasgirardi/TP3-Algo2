#ifndef MAIN_CPP_JUEGO_H
#define MAIN_CPP_JUEGO_H

#include "menu.h"

class Juego {
 private:
  Menu menuPartida;
  Mapa mapaPartida;
  Archivo archivoPartida;
  Archivo archivoPersonajes;
  char estadoJuego;
  Personaje* personajesJugadorUno[MAX_PERSONAJES];
  int cantidadPersonajesUno;
  Personaje* personajesJugadorDos[MAX_PERSONAJES];
  int cantidadPersonajesDos;
  Costos* costos[4];


 public:
  // POST: construye un menu. Se inicializa opcion con un valor distinto a la
  // salida (6) para asegurarse entrar al ciclo aunque sea una vez constuye un
  // menu o un juego???
  Juego();

  void inicializarCostos();

  void borrarCostos();
  // POST: se encarga de definir y procesar los preliminares. Se encarga
  // de procesar el archivo de los "personajes.csv" que brinda el juego y
  // tambien procesa el menu principal.
  void definirPreliminares();

  // POST: verifica si la coordenada ingresada es valida.
  void coorValidas(Coordenada* coor);

  void ubicarPersonajes();

  // POST: elige los personajes de cada jugador.
  void elegirPersonajes();

  // POST: devuelve un valor que define el primer turno del juego. (Define quien
  // arranca a jugar)
  void elegirPrimerLugar(bool* empiezaUno);

  // POST: devuelve el mapa de la partida.
  Mapa obtenerMapa();
 
 //POST:imprime por pantalla un mensaje indicando que el jugador 1 empieza
 void imprimirMensajeUno();
 
  //POST:imprime por pantalla un mensaje indicando que el jugador 2 empieza
 void imprimirMensajeDos();

  // POST: devuelve el valor de cuantos jugadores de un equipo no tienen vida.
  int contarMuertos(Personaje* personajes[MAX_PERSONAJES], int tope);

  // POST: devuelve verdadero en caso de que un jugador ha perdido.
  bool consultaEliminado();

  void asignarEstadoJuego(char estado);

  // PRE: siempre se juega el turno si quedan jugadores vivos de ambos equipos.
  // POST: se realiza el turno de un jugador.
  void jugarTurno(Personaje* personajes[MAX_PERSONAJES], int topeUno, int* i, Personaje* enemigos[MAX_PERSONAJES]);

  // POST: devuelve si la opcion es valida (entre AFIRMATIVO o NEGATIVO).
  bool opcionValida(char opcion);
 
  void cargarPersonajes();
 
  bool filaValida(int fila);
 
  bool columnaValida(int columna);
  
  void pedirFila(int* fila);
   
  void pedirColumna(int* columna);
    
  void consultarCoordenada(Coordenada* coor, Personaje* personajes[MAX_PERSONAJES], int i);
     
  void posicionarPersonaje(Personaje* personajes[MAX_PERSONAJES], int i);
 
  void procesarUbicacion(bool empiezaUno);



  // POST: pide al usuario si quiere guardar la partida o no.
  void pedirGuardado(char* opcion);

  // POST: procesa la partida guardada.
  void procesarGuardado(char opcion, bool* guardo);

  // POST: administra la partida guardada, llamando a las funciones de
  // pedirGuardado() y procesarGuardado().
  void consultarGuardado(bool* guardo);

  // POST: se encarga de procesar los turnos
  void procesarTurnos(Personaje* personajesPrimero[MAX_PERSONAJES], int topeUno,
                      Personaje* personajesSegundo[MAX_PERSONAJES],
                      int topeDos);

  // POST: procesa los personajes de un jugador de una partida guardada y los
  // asigna al vector personajes[].
  void asignarPersonaje(Personaje* personajes[MAX_PERSONAJES], int* tope,
                        Personaje* personajeNuevo);

  // POST: carga una partida que ya estaba guardada anteriormente.
  void cargarPartida();

  // POST: revisa si existe una partida guardada o no.
  void revisarPartida();

  // POST: ejecuta todos los métodos principales del menú
  void procesarJuego();

  // POST:libera la memoria
  virtual ~Juego();
};

#endif  // MAIN_CPP_JUEGO_H
