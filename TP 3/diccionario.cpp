#include "diccionario.h"

void Diccionario::todoDetalles(Nodo* d) {
    if (d != 0) {
        todoDetalles(d->obtenerIzquierdo());
        cout << "\t" << d->obtenerClave() << ", condicion: " << d->obtenerDato()->obtenerCondicion()<< endl;
        todoDetalles(d->obtenerDerecho());
    }
}
Diccionario::Diccionario() {
  raiz = 0;
  cantidad = 0;
}

bool Diccionario::vacio(){
    return (cantidad == 0);
}

void Diccionario::alta(Dato d) {
  Nodo* nuevo = new Nodo(d);  // Esto en otro método??
  Nodo* aux = raiz;
  Nodo* anterior;
  while (aux != 0) {
    anterior = aux;
    if ((nuevo->obtenerClave()).compare(aux->obtenerClave()) < 0) {
      aux = aux->obtenerIzquierdo();
    } else {
      aux = aux->obtenerDerecho();
    }
  }
  if (vacio()) {
    raiz = nuevo;
  } else {
    if((nuevo->obtenerClave()).compare(anterior->obtenerClave()) < 0){
      anterior->asignarIzquierdo(nuevo);
    } else {
      anterior->asignarDerecho(nuevo);
    }
    nuevo->asignarPadre(anterior);
  }
  cantidad++;
}

void Diccionario::modificarContenido(string nombre,int escudo,int vida,int energia,int fila,int columna){
    bool encontrado = false;

    obtenerNodo(nombre, &encontrado)->obtenerDato()->asignarEscudo(escudo);
    encontrado = false;
    obtenerNodo(nombre, &encontrado)->obtenerDato()->asignarVida(vida);
    encontrado = false;
    obtenerNodo(nombre, &encontrado)->obtenerDato()->asignarEnergia(energia);
    encontrado = false;
    obtenerNodo(nombre, &encontrado)->obtenerDato()->asignarCoordenada(fila, columna);
}

Nodo* Diccionario::obtenerNodo(string clave, bool* encontrado)
{
  if (!vacio()) {
    Nodo* aux = raiz;
    while ((aux != 0) && !(*encontrado)) {
      if (clave == (aux->obtenerClave())) {
        (*encontrado) = true;
      } else if (clave.compare(aux->obtenerClave()) > 0) {
        aux = aux->obtenerDerecho();
      } else {
        aux = aux->obtenerIzquierdo();
      }
    }
    return aux;
  } else {
    return raiz;
  }
}

Dato Diccionario::consultaNodo(string clave) {  // imprimo la info acá o en
                                                // menú?
  bool encontrado = false;
  return obtenerNodo(clave, &encontrado)->obtenerDato();
}

void Diccionario::consultaInfo(string clave) {
  bool encontrado;
  Personaje* personajeBuscado = obtenerNodo(clave, &encontrado)->obtenerDato();
  cout << endl;
  cout << "Nombre:" << (personajeBuscado->obtenerNombre()) << endl;
  cout << "Elemento:" << (personajeBuscado->obtenerElemento()) << endl;
  cout << "Vida:" << (personajeBuscado->obtenerVida()) << endl;
  cout << "Escudo:" << (personajeBuscado->obtenerEscudo()) << endl;
  cout << "Energía:" << (personajeBuscado->obtenerEnergia()) << endl;
  cout << "Alimento:" << (personajeBuscado->obtenerAlimento()) << endl;
  cout << "Jugando:" << (personajeBuscado->obtenerCondicion()) << endl;
  cout << endl;
}

bool Diccionario::consultaClave(string clave) {
  bool encontrado;
  obtenerNodo(clave, &encontrado);
  return encontrado;
}

Nodo* Diccionario::minimo(Nodo* d) {
    Nodo* aux = d;
    while(aux->obtenerIzquierdo())
        aux = aux->obtenerIzquierdo();

    return aux;
    /*if (d == 0) {  // si el puntero está vacío retorna 0
    return d;
  }
  if (d->obtenerIzquierdo() != 0) {
    return minimo(d->obtenerIzquierdo());  // Si tiene hijo izquierdo,
  } else {     // buscamos la parte más izquierda posible
    return d;  // Si no tiene hijo izquierdo retornamos el mismo nodo
  }*/
}

// lo que hago es al padre asignarle un nuevo hijo, y al hijo un nuevo padre.
void Diccionario::reemplazar(Nodo* nodoViejo, Nodo* nodoNuevo)
{
  if (nodoViejo->obtenerPadre() != 0) {  // al padre hay que asignarle su nuevo hijo

    if((nodoViejo->obtenerClave()) == (nodoViejo->obtenerPadre()->obtenerIzquierdo()->obtenerClave()))
    {
      nodoViejo->obtenerPadre()->asignarIzquierdo(nodoNuevo);
    }

    else if ((nodoViejo->obtenerClave()) == (nodoViejo->obtenerPadre()->obtenerDerecho()->obtenerClave()))
    {
      nodoViejo->obtenerPadre()->asignarDerecho(nodoNuevo);
    }

    if (nodoNuevo != 0)
    {
      nodoNuevo->asignarPadre(nodoViejo->obtenerPadre());
    }

  }

  else{// se está eliminando la raíz (tiene un solo hijo)

      if (nodoNuevo != 0)
      {
        nodoNuevo->asignarPadre(0);
      }
      this->raiz = nodoNuevo;
  }
}

Nodo* Diccionario::obtenerRaiz() { return raiz; }

void Diccionario::baja(string clave)
{
  bool encontrado = false;

  Nodo* nodoBuscado = obtenerNodo(clave, &encontrado);
  if (encontrado) {
      if ((nodoBuscado->obtenerIzquierdo() != 0) && (nodoBuscado->obtenerDerecho() != 0)) {
          // caso 1: tiene 2 hijos
          Nodo *menor = minimo(nodoBuscado->obtenerDerecho());
          delete nodoBuscado->obtenerDato();
          nodoBuscado->cambiarDato(menor->obtenerDato());  // tengo que cambiar los atributos
          nodoBuscado->asignarClave(menor->obtenerClave());
          descolgar(menor, menor->obtenerPadre());
          delete nodoBuscado->obtenerDato();
          delete menor;
      } else if (nodoBuscado->obtenerIzquierdo() != 0) {
          // caso 2: tiene un solo hijo y es izq
          reemplazar(nodoBuscado, nodoBuscado->obtenerIzquierdo());
          delete nodoBuscado->obtenerDato();
          delete nodoBuscado;  // no es otro método?
      } else if (nodoBuscado->obtenerDerecho() != 0) {
          // caso 2: tiene un solo hijo y es izq
          reemplazar(nodoBuscado, nodoBuscado->obtenerDerecho());
          delete nodoBuscado->obtenerDato();
          delete nodoBuscado;
      } else {
          reemplazar(nodoBuscado, 0);  // no tiene hijos
          delete nodoBuscado->obtenerDato();
          delete nodoBuscado;
      }

      cantidad--;
  }
  else{
      cout << "Nombre no encontrado." << endl;
  }
}

void Diccionario::inOrden(Nodo* d) {
  if (d != 0) {
    inOrden(d->obtenerIzquierdo());
    cout << "\t" << d->obtenerClave() << endl;
    inOrden(d->obtenerDerecho());
  }
}

void Diccionario::imprimirClaves() {
  if (this->raiz != 0) {
    inOrden(raiz);
  }
}

int Diccionario::obtenerCantidad() { return cantidad; }

void Diccionario::descolgar(Nodo* exhijo,Nodo* padre)
{
    if(exhijo->obtenerDerecho()) {
        padre->asignarDerecho(0);
        exhijo->obtenerDerecho()->asignarPadre(padre);
    }
}

Diccionario::~Diccionario() {
  while (!vacio()) {
    baja((this->raiz)->obtenerClave());
  }
}

