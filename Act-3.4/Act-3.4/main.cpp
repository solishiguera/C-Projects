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


/*
 GIT
 cd Documents/TEC/"SEMESTRE 3"/"Estructura de datos"/MyEvidences
 */

void leerArchivo(DoublyLinkedList<string> &list) {
    string mes, hora, ipAddress, fallo;
    int dia;
    ifstream archivoEntrada;
    
    archivoEntrada.open("BitacoraTest.txt");
    while(archivoEntrada >> mes >> dia >> hora >> ipAddress) { // Lee toda la información
        getline(archivoEntrada, fallo); // Leer el mensaje de error de login
        fallo.erase(fallo.begin());
        ipAddress = ipAddress.substr(0,13);
        list.addLast(ipAddress);
    }
    archivoEntrada.close();
}

void createObject(DoublyLinkedList<string> list, DoublyLinkedList<Registro> &listaRegistros){
    Registro miRegistro;
    int size = list.getSize();
    int cont = 1;
    int cantVeces = 0;
    string ipActual;
    
    while (cont < size) {
        while(list[cont] == list[cont + 1]) {
            cantVeces++;
            cont++;
        }
        miRegistro = Registro(ipActual, cantVeces);
        listaRegistros.addLast(miRegistro);
        cantVeces = 0;
        cont++;
    }
    
    
}

int main() {
    DoublyLinkedList<string> list;
    DoublyLinkedList<Registro> myList;
    Heap<string> ipHeap;
    leerArchivo(list);
    HeapSort(list);
    createObject(list, myList);
    // Me quedé en que mi programa no carga Registros en createObject
    return 0;
}
