#include <iostream>
#include <vector>
#include <memory>


class Particula {

    protected:

        float* posicionX;

    public:

        Particula(float x_inicial){

            posicionX = new float(x_inicial);
            std::cout<<"Base: particula creada en "<<*posicionX<<std::endl;

        }

        virtual ~Particula(){

            std::cout<<"Destructor base: memoria de la particula "<<*posicionX<<" liberada del sistema."<<std::endl;
            delete posicionX;
            
        }

        virtual void mostrar(){

            std::cout<< "Soy una particula normal en: "<<*posicionX<<std::endl;

        }

        virtual void actualizar()=0;
};

class ParticulaColorida : public Particula{

    private:
        int color;

    public:

        ParticulaColorida(float x, int c):Particula(x), color(c){

            std::cout << "Constructor hijo: Color asignado"<<color<<std::endl;

        }

        ~ParticulaColorida(){

            std::cout<<"Destructor hijo: Limpiando cosas de colores"<<std::endl;

        }

        void mostrar() override{

            std::cout<<"Soy una particula de color "<<color<<" en "<<*posicionX<<std::endl;

        }

        void actualizar() override{

            std::cout<<"metodo concreto en particulas coloridas"<<std::endl;


        }

};

class ParticulaCargada : public Particula{

    private:
        int carga;

    public:

        ParticulaCargada(float x, int c):Particula(x), carga(c){

            std::cout << "Constructor hijo: Carga asignada"<<carga<<std::endl;

        }

        ~ParticulaCargada(){

            std::cout<<"Destructor hijo: Limpiando particula cargada"<<std::endl;

        }

        void mostrar() override{

            std::cout<<"Soy una particula de carga "<<carga<<" en "<<*posicionX<<std::endl;

        }

        void actualizar() override{

            std::cout<<"metodo concreto en particulas cargadas"<<std::endl;


        }

};

class SistemaFisico{

    private:

        Particula* listadeParticulas[5];

    public:

        SistemaFisico(){

            for (int i=0; i<5;++i){

                listadeParticulas[i]=new ParticulaColorida(i*1.5,9);

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

    std::vector<std::unique_ptr<Particula>> misParticulas;

    misParticulas.push_back(std::make_unique<ParticulaColorida>(10.5f,255));

    misParticulas.push_back(std::make_unique<ParticulaCargada>(1.5f,439));
    misParticulas.push_back(std::make_unique<ParticulaColorida>(12.5f,230));
    misParticulas.push_back(std::make_unique<ParticulaCargada>(13.5f,43));

    for (const auto& p: misParticulas){

        p->mostrar();

    }

/*
    for (Particula* p: misParticulas){

        delete p;

    }

    misParticulas.clear();*/
    return 0;

/*
    std::cout<<"Creando el sistema"<<std::endl;

    SistemaFisico* miUniverso = new SistemaFisico;

    std::cout<<"Sistema en la RAM"<<std::endl;

    delete miUniverso;

    std::cout<<"Fin del experimento"<<std::endl;

    return 0;*/
}