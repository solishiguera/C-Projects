//
//  main.cpp
//  Act-2.3
//
//  Created by Diego Solis on 10/6/20.
//

#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include "DoublyLinkedList.h"
#include "Registro.h"

void solicitaUsuario(DLL<Registro> &myList, Registro &usuario){
    map<int, string> meses = { {1,"Ene"}, {2, "Feb"}, {3, "Mar"}, {4,"Abr"}, {5,"May"},  {6,"Jun"}, {7,"Jul"}, {8,"Aug"}, {9,"Sep"}, {10,"Oct"}, {11,"Nov"}, {12,"Dic"}};
    string mes, hora, minuto, segundo, ipAddress = "User search Query", fallo = "User search Query";
    int mesNum, dia;
    cout << "Ingresa la fecha para tu búsqueda" << endl;
    cout << "Teclea el número de mes que deseas (número del 1 al 12): ";
    cin >> mesNum;
    cout << "Teclea el día del mes (00): ";
    cin >> dia;
    cout << "Teclea la hora (00): ";
    cin >> hora;
    cout << "Teclea el minuto (00): ";
    cin >> minuto;
    cout << "Teclea el segundo (00): ";
    cin >> segundo;
    
    usuario = Registro(meses[mesNum], dia, hora + ":" + minuto + ":" + segundo, ipAddress, fallo);
    myList.addLast(usuario);
}

void escribeArchivo(DLL<Registro> myList) {
    ofstream archivoFinal;
    archivoFinal.open("BitacoraFin.txt");
    for (int i = 1; i < myList.sizeOf(); i++) {
        archivoFinal << myList[i].imprimeInformacion() << endl;
    }
    archivoFinal.close();
}

int findData(DLL<Registro> myList, int data) {
    int posI = 1;
    int posF = myList.sizeOf()-1;
    int posM = (posI + posF)  / 2;
    bool found = false;
    while(posI <= posF && !found) {
        if(data < myList[posM].key()) {
            posF = posM - 1;
        } else {
            if(data > myList[posM].key()) {
                posI = posM + 1;
            } else {
                if (data == myList[posM].key()) {
                    return posM;
                }
            }
        }
        posM = (posI + posF) / 2;
    }
    return posM;
}


void imprimeRango(DLL<Registro> myList, int inicial, int fin) {
    for(int i = inicial; i <= fin; i++) {
        cout << myList[i].imprimeInformacion() << endl;
    }
}

void cargaArchivo(DLL<Registro> &myList) {
    string mes, hora, ipAddress, fallo;
    int dia;
    ifstream archivoEntrada;
    
    archivoEntrada.open("BitacoraTest.txt");
    while(archivoEntrada >> mes >> dia >> hora >> ipAddress) { // Lee toda la información
        getline(archivoEntrada, fallo); // Leer el mensaje de error de login
        fallo.erase(fallo.begin());
        
        myList.addLast(Registro(mes, dia, hora, ipAddress, fallo)); // Se agrega a LinkedList tipo Registro
    }
    archivoEntrada.close();
}

int main() {
    DLL<Registro> myList;
    Registro usuarioInicial;
    Registro usuarioFinal;
    cargaArchivo(myList);

    cout << "Bienvenid@" << endl;
    cout << "~~~~~~~~~ Datos para fecha incial: ~~~~~~~~~" << endl;
    solicitaUsuario(myList, usuarioInicial);
    //usuarioInicial = Registro("May", 12, "12:12:12", "Nada", "Nada");
    myList.addLast(usuarioInicial);
    cout << "~~~~~~~~~ Datos para fecha final: ~~~~~~~~~" << endl;
    solicitaUsuario(myList, usuarioFinal);
    //usuarioFinal = Registro("Sep", 23, "23:23:23", "Nada", "Nada");
    myList.addLast(usuarioFinal);

    myList.sort();
    int posInic = findData(myList, usuarioInicial.key());
    int posFin = findData(myList, usuarioFinal.key());
    imprimeRango(myList, posInic + 1, posFin - 1);
    escribeArchivo(myList);
    
    return 0;
}
