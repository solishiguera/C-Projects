//
//  Graph.h
//  Act-4.3
//
//  Created by Diego Solis on 12/4/20.
//

#ifndef Graph_h
#define Graph_h

template<class T>
struct Edge {
    T target;
    int weight;
};

template<class T>
class Graph {
private:
    int size;
    vector<T> vertices;
    vector< vector< Edge<T> > > adjList;
    int findVertex(T vertex); // Complejidad O(n)
    void dfsR(T vertex, vector<bool> &status);
public:
    void print(); // Complejidad O(n^2)
    Graph(vector<T> list); // Complejidad O(n)
    void bfs(); // Complejidad O(n)
    void dfs(); // Complejidad O(n)
    void addEdge(T vertex); // Falta por hacer
};

template<class T>
Graph<T>::Graph(vector<T> list) { // Recibe solamente los vértices
    /*
    int source = 0; // Me permite determinar la fuente {{'a','b'}} -> la 'a' es fuente
    int target = 1; // Me permite determinar el destino {{'a','b'}} -> la 'b' es destino
     */
    
    //vector<T> edge;
    
    /*
    // Crear lista de vertices
    for (vector<T> edge: list) {
        // Iterar en toda mi lista
        T temp = edge[source];
        int pos = findVertex(temp);
        if (pos < 0) {
            vertices.push_back(temp);
        }
        temp = edge[target];
        pos = findVertex(temp);
        if (pos < 0) {
            vertices.push_back(temp);
        }
        
    }
     */
     
    vertices = list;
    
    size = (int) vertices.size();
    // Ordenar la lista de vertices
    sort(vertices.begin(), vertices.end());
    
    /*
    //vector< Edge<T> > edgeTemp;
    vector< vector< Edge<T> > > tempList(size);
    adjList = tempList;

    // Agregar los vertices adyacentes a la lista de adyacencias
    for (auto path : list) {
        int pos = findVertex(path[source]);
        Edge<T> edge;
        edge.target = path[target];
        edge.weight = path[weight];
        adjList[pos].push_back(edge);
    
    }
     */
    
    
}

template<class T>
void Graph<T>::print() {
    for (int v = 0; v < size; v++) {
        cout << vertices[v] << "-> ";
        for (auto path : adjList[v]) {
            cout << path.target << " " << path.weight << " ";
        }
        cout << endl;
    }
}

template<class T>
int Graph<T>::findVertex(T vertex) {
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
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

#endif
