#include <iostream>
#include <vector>
#include <string>
#include "sequentialSearch.hpp"
#include "../sort/mergeSort.cpp"

using namespace std;

vector<Info> buscar_claves_binario(const string& entrada, const vector<Info>& lista_ordenada) {
    vector<Info> resultado;
    int izquierda = 0, derecha = lista_ordenada.size() - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        const string& clave = lista_ordenada[medio].ubi;

        if (clave.substr(0, 3) == entrada) {
            
            // Buscar otras claves hacia la izquierda
            int i = medio - 1;
            while (i >= 0 && lista_ordenada[i].ubi.substr(0,3) == entrada) {
                resultado.push_back(lista_ordenada[i]);
                i--;
            }

            // Buscar otras claves hacia la derecha
            int j = medio + 1;
            while (j < lista_ordenada.size() && lista_ordenada[j].ubi.substr(0,3) == entrada) {
                resultado.push_back(lista_ordenada[j]);
                j++;
            }

            break;
        }

        if (clave < entrada) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return resultado;
}

