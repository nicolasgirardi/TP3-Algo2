//falta escribir personaje->obtenerCoordenada y que devuelva 
//un puntero a objeto de clase Coordenada 
//tambien faltan las funciones atacar de cada elemento
//atacar de tierra recibe una variable extra, la zona, siendo 1 marron oscuro
//2 marron y 3 marron claro.
/*
void Menu::ataqueAire(Mapa mapa,Personaje* personaje){
	int i,da�o;
	string elemento;
	Coordenada coor(0);
	for(i=0;i<64;i++){
		coor->cambiarCoordenada(i);
		if(mapa->consulta(coor)->obtenerDato()->ocupacion){
			elemento = mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->obtenerElemento(); 
			da�o = personaje->atacar(elemento);
			mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->cambiarVida(-da�o);
		}
	}
}
//nuevo
void Menu::ataqueAgua(Mapa mapa,Personaje* personaje){ 
	int da�o;
	string elemento;
	Coordenada coor(0);
	pedirCoordenada(&coor);
	if(mapa->consulta(coor)->obtenerDato()->ocupacion){
			elemento = mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->obtenerElemento(); 
			da�o = personaje->atacar(elemento);
			mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->cambiarVida(-da�o);
	}
	else
		cout<<"El ataque fall�"<<endl;
}

//nuevo
void Menu::ataqueFuego(Mapa mapa,Persoanje* personaje){
	int i,da�o,coorCero;
	string elemento;
	Coordenada coor(0);
	coor->cambiarCoordenada(personaje->consultarCoordenada->obtenerFila - 1);
	coor->cambiarColumna(1);
	coorCero = coor->obtenerCoordenada();
	int(i=coorCero;i<24+Coorcero;i++){
		coor->cambiarCoordenada(i);
		if(mapa->consulta(coor)->obtenerDato()->ocupacion){
			elemento = mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->obtenerElemento(); 
			da�o = personaje->atacar(elemento);
			mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->cambiarVida(-da�o);
		}
	}
		
} 

//nuevo

void Menu::ataqueTierra(Mapa mapa,Personaje* personaje){
	int i,da�o,zona, dFila,dColumna;
	string elemento;
	Coordenada coor(0);
	for(i=0;i<64;i++);{
		coor->cambiarCoordenada(i);
		dFila = abs(coor->obtenerFila() - personaje->obtenerCoordenada->obtenerFila);
		dColumna = abs(coor->obtenerColumna() - personaje->obtenerCoordenada->obtenerColumna)
		if((dFila <= 2) && (dColumna <= 2))
			zona = 1;
		else
			if((dFila <= 4) && (dColumna <= 4))
				zona = 2;
			else
				zona = 3;	
		if(mapa->consulta(coor)->obtenerDato()->ocupacion){
			elemento = mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->obtenerElemento(); 
			da�o = personaje->atacar(elemento,zona);
			mapa->consulta(coor)->obtenerDato()->obtenerPersonaje()->cambiarVida(-da�o);
		}
	}	
}

void Menu::atacarPersonaje(Mapa mapa,Personaje* personaje){
	if(personaje->obtenerElemento() == "aire")
		ataqueAire(mapa,personaje);
	if(personaje->obtenerElemento() == "agua")
		ataqueAgua(mapa,personaje);
	if(personaje->obtenerElemento() == "fuego")
		ataqueFuego(mapa,personaje);
	if(personaje->obtenerElemento() == "tierra")
		ataqueTierra(mapa,personaje);			
}
*/