//
//  main.cpp
//  Act-3.4
//
//  Created by Diego Solis on 10/16/20.
//

#include <iostream>
using namespace std;
#include <fstream>
#include "DLL.h"
#include "Heap.h"
#include "Registro.h"

// Complejidad O(n)
void leerArchivo(DoublyLinkedList<string> &list) {
    /* Lee archivo de entrada */
    string mes, hora, ipAddress, fallo;
    int dia;
    ifstream archivoEntrada;
    
    archivoEntrada.open("Bitacora.txt");
    while(archivoEntrada >> mes >> dia >> hora >> ipAddress) { // Lee toda la información
        getline(archivoEntrada, fallo); // Leer el mensaje de error de login
        fallo.erase(fallo.begin());
        list.addLast(ipAddress);
    }
    archivoEntrada.close();
}

// Complejidad O(n^2)
void createObject(DoublyLinkedList<string> list, DoublyLinkedList<Registro> &listaRegistros){
    /* Utiliza la lista ordenada de IPs y crea objetos donde se almacena nombre y cantidad de ocurrencias */
    Registro miRegistro;
    int size = list.getSize();
    int cont = 1;
    int cantVeces = 1;
    string ipActual;
    
    while (cont < size) {
        while(list[cont].substr(0,13) == list[cont + 1].substr(0,13) && cont < size - 1) {
            /* Cuenta la cantidad de veces que se repite un IP, y no toma en cuenta el puerto */
            cantVeces++;
            cont++;
        }
        ipActual = list[cont].substr(0,13);
        miRegistro = Registro(ipActual, cantVeces);
        listaRegistros.addLast(miRegistro); // Se almacena objeto de tipo Registro
        cantVeces = 1;
        cont++;
    }
    
    
}

// Complejidad O(n)
void displayRepeated(Heap<Registro> ipHeap) {
    /* Muestra cinco registros más repetidos */
    cout << " IP Address " << "\tRepeticiones" << endl;
    for (int i = 0; i < 5; i++) {
        Registro mayor = ipHeap.remove();
        cout << mayor.ip << "\t  \t" << mayor.cant << endl;
    }
}

// Complejidad O(n)
void escribeArchivo(DoublyLinkedList<Registro> myList) {
    /* Genera archvi con objetos de tipo Registro */
    ofstream archivoFinal;
    archivoFinal.open("Salida.txt");
    HeapSort(myList, "Descending");
    for (int i = 1; i < myList.getSize(); i++) {
        Registro salida = myList[i];
        archivoFinal << salida.ip << "\t  \t" << salida.cant << endl;
    }
    
    archivoFinal.close();
}

int main() {
    Heap<Registro> ipHeap;
    DoublyLinkedList<string> list; // Almacena IPs de archivo
    DoublyLinkedList<Registro> myList; // Almacena Registros de list
    
    leerArchivo(list);
    HeapSort(list); // los ordena por tipo de ip, los que son iguales quedan juntos
    createObject(list, myList);
    ipHeap = myList;
    
    escribeArchivo(myList);
    displayRepeated(ipHeap);
    
    return 0;
}
