//
//  main.cpp
//  Act-4.3
//
//  Created by Diego Solis on 11/22/20.
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include "Registro.h"
#include "Graph.h"

Graph<Registro> listaVertices(vector<Registro> &list, int &cantidadIPs, int &cantidadEntradas) {
    /* Lee archivo de entrada */
    string mes, hora, ipAddress, fallo;
    Registro ipOrigen, ipDestino;
    int dia;
    ifstream archivoEntrada;
    
    archivoEntrada.open("Bitacora.txt");
    //archivoEntrada.open("Bitacora.txt");
    archivoEntrada >> cantidadIPs;
    archivoEntrada >> cantidadEntradas;
    for(int i = 0; i < cantidadIPs; i++) { // Lee toda la información
        archivoEntrada >> ipAddress;
        list.push_back(Registro(ipAddress));
    }
    Graph<Registro> grafo(list);
    
    for (int j = 0; j < cantidadEntradas; j++) {
        archivoEntrada >> mes >> dia >> hora >> ipOrigen.ip >> ipDestino.ip;
        getline(archivoEntrada, fallo);
        //ipOrigen.erase(ipOrigen.size() - 4, ipOrigen.size());
        ipOrigen.deletePort();
        ipDestino.deletePort();
        grafo.addEdge(ipOrigen, ipDestino);

    }
    archivoEntrada.close();
    return grafo;
}

int main() {
    int cantidadIPs = 0, cantidadEntradas = 0;
    vector<Registro> list;
    Graph<Registro> grafo = listaVertices(list, cantidadIPs, cantidadEntradas);
    grafo.giveMeTheGreatest(); // Esta función determina la IP con más adyacencias
    grafo.print(); 
    return 0;
}
