#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <time.h>

struct Fecha {
    int dia;
    int mes;
    int anio;
};
struct Info {
    Fecha fecha;
    std::string hora;
    char puntoEntrada;
    std::string ubi;
};
Fecha guardarFecha(std::string foko) {

    Fecha fecha;
    char slash;
    std::istringstream iss(foko);
    iss >> fecha.dia >> slash >> fecha.mes >> slash >> fecha.anio;
    return fecha;
}

std::vector<Info> guardarInformacion() {
    std::vector<std::string> lineas = {
        "28/12/2023 15:27 R 0KIQ7"};

    std::vector<Info> registros;

    for (const std::string& linea : lineas) {
        std::istringstream iss(linea);
        Info registro;
        registro.fecha = guardarFecha(linea);
        iss >> registro.hora >> registro.puntoEntrada >> registro.ubi;
        registros.push_back(registro);
    }

    return registros;
}


int main() {
    std::ofstream archivo("bitacora.txt");

    
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<Info> registros = guardarInformacion();

    // Imprimir los registros almacenados
    for (const Info& registro : registros) {
       std::cout << "Fecha: " << registro.fecha.dia  << "/" << registro.fecha.mes << "/" << registro.fecha.anio << "Hora: " << registro.hora
                 << " Punto de Entrada: " << registro.puntoEntrada << " UBI: " << registro.ubi << std::endl;
    }



    // Cerrar el archivo
    archivo.close();

    std::cout << "Datos guardados exitosamente en informacion.txt" << std::endl;

    return 0;
}