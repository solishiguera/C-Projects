//
//  Graph.h
//  Act-5.2
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef Graph_h
#define Graph_h

template<class T>
class Graph {
private:
    int size;
    vector<Registro> vertices;
    vector< vector< Registro > > adjList;
    int findVertex(Registro vertex); // Complejidad O(n)
public:
    HashQ hashTable;
    Graph(vector<T> list); // Complejidad O(n)
    void print(); // Complejidad O(n^2)
    void addEdge(Registro &origen, Registro destino);
    //void giveMeTheGreatest();
    void dameAdyacencias(string input);
};

template<class T>
Graph<T>::Graph(vector<T> list) { // Recibe solamente los vértices
    vertices = list;
    size = (int) vertices.size();
    vector< vector< Registro > > tempList(size);
    adjList = tempList;
    hashTable = vertices;
}

template<class T>
void Graph<T>::print() {
    for (int v = 0; v < size; v++) {
        cout << vertices[v].ip << "-> ";
        for (auto path : adjList[v]) {
            cout << path.ip << "   ";
        }
        cout << endl;
    }
}

template<class T>
int Graph<T>::findVertex(Registro vertex) {
    for (int i = 0; i < size; i++) {
        if (vertex.ip == vertices[i].ip) {
            return i;
        }
    }
    return - 1;
}

// Complejidad O(n)
template<class T>
void Graph<T>::addEdge(Registro &origen, Registro destino) {
    int pos = findVertex(origen);
    adjList[pos].push_back(destino);
}

template<class T>
void Graph<T>::dameAdyacencias(string input) {
    int pos = findVertex(Registro(input)), i;
    cout << "Adyacencias de " << input << ":" << endl;
    cout << "     IP      \t" << "key" << endl;
    for(i = 0; i < adjList[pos].size(); i++) {
        cout << adjList[pos][i].ip << "\t" << " "<< adjList[pos][i].key << endl;
    }
    cout << endl << endl;
}
/*
//Complejidad O(nLog(n))
template<class T>
void Graph<T>::giveMeTheGreatest() {
    vector<Registro> myHeap = vertices;
    
    make_heap(myHeap.begin(), myHeap.end());
    
    cout << "El más cool y social es: " << myHeap.front().ip << " con: " <<  myHeap.front().cant << " adyacencias :) " << endl;
    ofstream archivoFinal;
    archivoFinal.open("Salida.txt");
    archivoFinal << " IP " << "\t \t \t Adyacencias" << endl;
    
    for (int i = 0; i < size; i++) {
        archivoFinal << myHeap.front().ip <<  "\t \t \t" << myHeap.front().cant << endl;
        pop_heap(myHeap.begin(), myHeap.end());
        myHeap.pop_back();
    }
    
    archivoFinal.close();
    
}
 */
#endif
