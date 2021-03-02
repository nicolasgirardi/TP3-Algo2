

#include "menuPrincipal.h"

MenuPrincipal::MenuPrincipal():Menu(){

}

void MenuPrincipal::procesarMenuPrincipal(char* estadoJuego, Diccionario* diccionarioPersonajes) {
    while (stoi(opcion) != SALIDA_MENU_PRINCIPAL && stoi(opcion) != OPCION_JUGAR) {
        mostrarMenu();
        elegirOpcion();
        ejecutarOpcionPrincipal(estadoJuego,diccionarioPersonajes);
    }
}

void MenuPrincipal::determinarEscudo(int* escudo) { (*escudo) = rand() % 3; }

void MenuPrincipal::cargarVida(int* vida) { (*vida) = rand() % 100 + 10; }

bool MenuPrincipal::elementoValido(string elemento) {
    return (elemento == "tierra" || elemento == "agua" || elemento == "aire" ||
            elemento == "fuego");
}

void MenuPrincipal::pedirElemento(string* elemento) {
    cout << endl;
    cout << "Ingrese el elemento del personaje. Puede ser: fuego, tierra, aire o agua" << endl;
    cin >> (*elemento);
    while (!elementoValido(*elemento)) {
        cout << "Elemento incorrecto. Favor de ingresar: fuego, tierra, aire o agua" << endl;
        cin >> (*elemento);
    }
}

void MenuPrincipal::ingresarNombre(string* nombre,Diccionario* diccionarioPersonajes) {
    pedirNombre(nombre);
    while (diccionarioPersonajes->consultaClave(*nombre)) {
        cout << "Este nombre ya está en uso. Favor de ingresar un nuevo nombre" << endl;
        pedirNombre(nombre);
    }
}

void MenuPrincipal::agregarPersonaje(Diccionario* diccionarioPersonajes) {
    string elemento, nombre;
    int escudo, vida;

    pedirElemento(&elemento);
    ingresarNombre(&nombre,diccionarioPersonajes);
    determinarEscudo(&escudo);
    cargarVida(&vida);
    crearPersonaje(elemento, nombre, escudo, vida, diccionarioPersonajes);
}

void MenuPrincipal::eliminarPersonaje(Diccionario* diccionarioPersonajes) {
    string nombre;
    pedirNombre(&nombre);
    diccionarioPersonajes->pedirBaja(nombre);  // Hechar vistazo a dicc.
}




void MenuPrincipal::iniciarJuego(char* estadoJuego) { *estadoJuego = JUGANDO; }

void MenuPrincipal::ejecutarOpcionPrincipal(char* estadoJuego, Diccionario* diccionarioPersonajes) {
    switch (stoi(opcion)) {
        case OPCION_NUEVO_PERSONAJE:
            agregarPersonaje(diccionarioPersonajes);
            break;
        case OPCION_ELIMINAR_PERSONAJE:
            eliminarPersonaje(diccionarioPersonajes);
            break;
        case OPCION_MOSTRAR_NOMBRES:
            mostrarNombres(diccionarioPersonajes);
            break;
        case OPCION_BUSCAR_PERSONAJE:
            verDetalles(diccionarioPersonajes);
            break;
        case OPCION_JUGAR:
            iniciarJuego(estadoJuego);
            break;
    }
}

void MenuPrincipal::crearPersonaje(string elemento, string nombre, int escudo, int vida, Diccionario* diccionarioPersonajes) {
    Personaje* personajeCreado;
    if (elemento == "tierra") {
        personajeCreado = new Tierra(nombre, escudo, vida);
    } else if (elemento == "agua") {
        personajeCreado = new Agua(nombre, escudo, vida);
    } else if (elemento == "aire") {
        personajeCreado = new Aire(nombre, escudo, vida);
    } else if (elemento == "fuego") {
        personajeCreado = new Fuego(nombre, escudo, vida);
    }
    diccionarioPersonajes->alta(personajeCreado);
}

Personaje* MenuPrincipal::crearPersonajeNuevo(string elemento, string nombre, int escudo, int vida) {
    Personaje* personajeCreado;
    if (elemento == "tierra") {
        personajeCreado = new Tierra(nombre, escudo, vida);
    } else if (elemento == "agua") {
        personajeCreado = new Agua(nombre, escudo, vida);
    } else if (elemento == "aire") {
        personajeCreado = new Aire(nombre, escudo, vida);
    } else if (elemento == "fuego") {
        personajeCreado = new Fuego(nombre, escudo, vida);
    }
    return personajeCreado;
}

void MenuPrincipal::mostrarMenu() {
    cout << endl;
    cout << "Menú" << endl;
    cout << "1) Agregar personaje" << endl;
    cout << "2) Eliminar personaje" << endl;
    cout << "3) Mostrar todos los nombres de los personajes" << endl;
    cout << "4) Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "5) Comenzar juego" << endl;
    cout << "6) Salir" << endl;
    cout << endl;
}

MenuPrincipal::~MenuPrincipal(){

}



