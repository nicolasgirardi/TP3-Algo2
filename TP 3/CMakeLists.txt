cmake_minimum_required(VERSION 3.16)
project(TP_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP_3
        agua.cpp
        agua.h
        aire.cpp
        aire.h
        archivo.cpp
        archivo.h
        camino.cpp
        camino.h
        casilla.cpp
        casilla.h
        constantes.h
        coordenada.cpp
        coordenada.h
        costos.cpp
        costos.h
        diccionario.cpp
        diccionario.h
        fuego.cpp
        fuego.h
        juego.cpp
        juego.h
        lago.cpp
        lago.h
        libraries.h
        main.cpp
        mapa.cpp
        mapa.h
        menu.cpp
        menu.h
        menuJuego.cpp
        menuJuego.h
        menuPrincipal.cpp
        menuPrincipal.h
        montana.cpp
        montana.h
        nodo.cpp
        nodo.h
        nodo_grafo.cpp
        nodo_grafo.h
        nodo_pila.cpp
        nodo_pila.h
        personaje.cpp
        personaje.h
        pila.cpp
        pila.h
        precipicio.cpp
        precipicio.h
        submenuDos.cpp
        submenuDos.h
        submenuUno.cpp
        submenuUno.h
        tierra.cpp
        tierra.h
        vacio.cpp
        vacio.h
        volcan.cpp
        volcan.h)
