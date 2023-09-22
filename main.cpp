#include "./search/sequentialSearch.cpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string entrada = "4TL";
    try {
        std::vector<Info> bitacora = parse("bitacora.txt");
        mergeSort(bitacora, 0, bitacora.size() - 1);

       for (auto &&i : bitacora) {
            std::cout << "dia: " << i.dateTime.tm_mday << " ";
            std::cout << "mes: " << i.dateTime.tm_mon << " ";
            std::cout << "año: " << i.dateTime.tm_year << " ";
            std::cout << "hora: " << i.dateTime.tm_hour << " ";
            std::cout << "minutos: " << i.dateTime.tm_min << " ";
            std::cout << "entrada: " << i.enterPoint << " ";
            std::cout << "ubi: " << i.ubi << "\n";
        }
        std::vector<Info> resultado = buscar_claves_binario(entrada, bitacora);
        for (auto &&i : resultado) {
            std::cout << "dia: " << i.dateTime.tm_mday << " ";
            std::cout << "mes: " << i.dateTime.tm_mon << " ";
            std::cout << "año: " << i.dateTime.tm_year << " ";
            std::cout << "hora: " << i.dateTime.tm_hour << " ";
            std::cout << "minutos: " << i.dateTime.tm_min << " ";
            std::cout << "entrada: " << i.enterPoint << " ";
            std::cout << "ubi: " << i.ubi << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}