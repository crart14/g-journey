#include <iostream>

class Particula {

public:

    int id;

    Particula(){

        id=0;
        std::cout<<"Particula Creada."<<std::endl;

    }

    ~Particula(){

        std::cout<<"Particula destruida (ID: "<<id<<" )."<<std::endl;

    }

};

class Contenedor {

private:

    Particula* lista;
    int capacidad;

public:

    Contenedor (int tamano){

        capacidad=tamano;
        lista = new Particula[tamano];
        for (int i=0; i<tamano;++i){
            lista[i].id=i+1;
        }
    }

    ~Contenedor(){

        std::cout<<"Limpiando Contenedor..."<<std::endl;
        delete[] lista;

    }

};

int main(){

    std::cout<<"___ Inicio del Programa ___"<<std::endl;

    Contenedor miCaja(20);

    std::cout<<"---El contenedor va a salir del alcance ---"<<std::endl;

    return 0;

}