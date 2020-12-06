//
//  Graph.h
//  Act-4.3
//
//  Created by Diego Solis on 12/4/20.
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
    void dfsR(T vertex, vector<bool> &status);
public:
    void print(); // Complejidad O(n^2)
    Graph(vector<T> list); // Complejidad O(n)
    void bfs(); // Complejidad O(n)
    void dfs(); // Complejidad O(n)
    void addEdge(Registro &origen, Registro destino);
};

template<class T>
Graph<T>::Graph(vector<T> list) { // Recibe solamente los vértices
    vertices = list;
    size = (int) vertices.size();

    vector< vector< Registro > > tempList(size);
    adjList = tempList;
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

template<class T>
void Graph<T>::bfs() {
    int pos = vertices[0];
    if (pos >= 0) {
        vector<bool> status(size,false);
        queue<int> q;
        // agregamos el primer vertice a la fila
        q.push(pos);
        // Le cambiamos el status al primer vértice
        status[pos] = true;
        while (!q.empty()) {
            int vertex = q.front();
            cout << vertices[vertex] << " ";
            for (auto adj : adjList[vertex]) {
                int posAdj = findVertex(adj.target);
                if (!status[posAdj]) {
                    q.push(posAdj);
                    status[posAdj] = true;
                }
            }
            q.pop();
        }
        cout << endl;
    }
}


template<class T>
void Graph<T>::dfs() {
    int pos = vertices[0];
    if (pos >= 0) {
        vector<bool> status(vertices.size(),false);
        dfsR(pos,status);
        cout << endl;
    }
}


template<class T>
void Graph<T>::dfsR(T vertex, vector<bool> &status) {
    int pos = findVertex(vertex);
    if (!status[pos]) {
        cout << vertex << " ";
        status[pos] = true;
        for (auto adj : adjList[pos]) {
            int posAdj = findVertex(adj.target);
            if (!status[posAdj]) {
                dfsR(adj.target,status);
            }
        }
    }
}

template<class T>
void Graph<T>::addEdge(Registro &origen, Registro destino) {
    int pos = findVertex(origen);
    adjList[pos].push_back(destino);
    vertices[pos].cant += 1;
}

#endif
