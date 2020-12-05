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
#include "Graph.h"

int main() {
    //vector< vector<int> > list = {{0,3,4},{0,4,8},{1,6,5},{2,6,9},{3,7,8},{4,2,3},{5,1,9},{5,6,7},{5,7,8},{7,5,9}};
    vector<int> lista = {0,1,2,3,4,5,6,7};
    Graph<int> graph(lista);//, lista);
    
    // Origen destino
    // Se me ocurre hacer el método para que reciba origen y destino y ya de ahí vemos
    // No me queda muy claro cómo contar la cantidad de accesos
    // Tengo que usar un max heap para ver el número de accesos
    
    return 0;
}
