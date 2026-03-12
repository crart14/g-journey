#include <iostream>

class Particula {

    private:

        float* posicionX;

    public:

        Particula(float x_inicial){

            posicionX = new float(x_inicial);
            std::cout<<"particula creada en "<<*posicionX<<std::endl;

        }

        ~Particula(){

            std::cout<<"memoria de la particula "<<*posicionX<<" liberada del sistema."<<std::endl;
            delete posicionX;
            
        }
};

class SistemaFisico{

    private:

        Particula* listadeParticulas[5];

    public:

        SistemaFisico(){

            for (int i=0; i<5;++i){

                listadeParticulas[i]=new Particula(i*1.5);

            };
        }

        ~SistemaFisico(){

            std::cout<<"Destruyendo el sistema fisico..."<<std::endl;

            for (int i=0; i<5;++i){

                delete listadeParticulas[i];

            };            
        }
};

int main() {


    std::cout<<"Creando el sistema"<<std::endl;

    SistemaFisico* miUniverso = new SistemaFisico;

    std::cout<<"Sistema en la RAM"<<std::endl;

    delete miUniverso;

    std::cout<<"Fin del experimento"<<std::endl;

    return 0;
}