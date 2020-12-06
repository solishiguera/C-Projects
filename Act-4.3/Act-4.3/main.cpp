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
    
    archivoEntrada.open("bitacoraTest.txt");
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
    
    grafo.print(); 
    return 0;
}


/*
// Initializing a vector
vector<int> v1 = {20, 30, 40, 25, 15};

// Converting vector into a heap
// using make_heap()
make_heap(v1.begin(), v1.end());

// Displaying the maximum element of heap
// using front()
cout << "The maximum element of heap is : ";
cout << v1.front() << endl;


//vector< vector<int> > list = {{0,3,4},{0,4,8},{1,6,5},{2,6,9},{3,7,8},{4,2,3},{5,1,9},{5,6,7},{5,7,8},{7,5,9}};
vector<int> lista = {0,1,2,3,4,5,6,7};
Graph<int> graph(lista); //, lista);

// Origen destino
// Se me ocurre hacer el método para que reciba origen y destino y ya de ahí vemos
// No me queda muy claro cómo contar la cantidad de accesos
// Para usar el max heap, tengo que ver el número de accesos, y guardarlo en un vector de tipo
*/
