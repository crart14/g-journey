#include <vector>
#include <queue>
#include <iostream>

class LatenciaMonitor{

private:

    std::priority_queue<double> datos;
    double suma;
    int totalDatos;

public:

    void registrarLatencia(double ms){

        datos.push(ms);
        suma+=ms;
        totalDatos+=1;

    }

    double obtenerMaximo(){

        if (!datos.empty()) return datos.top();

        return 0.0;

    }

    double obtenerPromedio(){

        if (totalDatos>0) return suma/totalDatos;

        return 0.0;

    }

};


int main(){

    LatenciaMonitor monitor;
    monitor.registrarLatencia(120.5);
    monitor.registrarLatencia(85.2);
    monitor.registrarLatencia(300.1);

    std::cout<<"Promedio: "<<monitor.obtenerPromedio()<<"ms"<<std::endl;
    std::cout<<"Maximo: "<<monitor.obtenerMaximo()<<"ms"<<std::endl;

    return 0;

}