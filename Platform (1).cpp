#include "Platform.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Platform::Platform(int y) : Entity("dirt_plat.png") { 
	_spr.setScale(0.5,0.5); // inicializa la plataforma con la mitad de su tamano;
	srand(time(nullptr));
	_spr.setScale(rand()%600,y); // inicializa la plataforma en una posicion aleatoria en el eje de las x;
	/*switch(num){ esto no sirve ah
		int n;
	case 1: 
		n = (rand()%600);
		_spr.setPosition(n, 130);
		break;
	case 2:  
		n = rand()%600;
		_spr.setPosition(n, 130);
		break;
	case 3:
		n =  rand()%600;
		_spr.setPosition(n, 130);
		break;
	case 4:  
		n = rand()%600;
		_spr.setPosition(n, 130);
		break;
	case 5:
		n = rand()%600;
		_spr.setPosition(n, 130);
		break;
	case 6:  
		n= rand()%600;
		_spr.setPosition(n, 130); 
		break;
	case 7: 
		n = rand()%600;
		_spr.setPosition(n, 130);
		break;
	default: cerr << "error";
	};*/
	
}

Platform::~Platform() {

}
void Platform::Moovment ( ) {

}

void Platform::Update ( ) {
	if(algo que indique que el jugador salto){
		_spr.move(0,1000/6);
	}
}

