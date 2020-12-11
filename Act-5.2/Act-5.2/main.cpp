//
//  main.cpp
//  Act-5.2
//
//  Created by Diego Solis on 12/6/20.
//

#include <iostream>
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <math.h>
#include "Registro.h"
#include "HashC.h"
#include "HashQ.h"
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
    string input;
    int cantidadIPs = 0, cantidadEntradas = 0;
    vector<Registro> list;
    cout << "Procesando datos..." << endl; 
    Graph<Registro> grafo = listaVertices(list, cantidadIPs, cantidadEntradas);
    
    cout << "Qué IP desea buscar?: ";
    cin >> input;
    grafo.dameAdyacencias(input);
    return 0;
}
