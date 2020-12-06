//
//  Registro.h
//  Act-3.4
//
//  Created by Diego Solis on 10/22/20.
//

#pragma once

struct Registro {
    string ip;
    int cant;
    Registro(string ip, int cant);
    Registro();
    void operator=(const Registro &R);
    bool operator>(Registro r2);
    bool operator>=(Registro r2);
    bool operator<(Registro r2);
    bool operator<=(Registro r2);
    bool operator==(Registro r2);
    bool operator!=(Registro r2);
    
};

// Complejidad O(1)
void Registro::operator=(const Registro &R) {
    ip = R.ip;
    cant = R.cant;
}

// Complejidad O(1)
Registro::Registro(string ip, int cant) {
    this-> ip = ip;
    this-> cant = cant;
}

// Complejidad O(1)
Registro::Registro() {
    ip = "/";
    cant = 0;
}

// Complejidad O(1)
bool Registro:: operator>(Registro r2) {
    return cant > r2.cant;
}

// Complejidad O(1)
bool Registro:: operator<(Registro r2) {
    return cant < r2.cant;
}

// Complejidad O(1)
bool Registro::operator==(Registro r2) {
    return cant == r2.cant;
}

// Complejidad O(1)
bool Registro::operator<=(Registro r2) {
    return cant <= r2.cant;
}

// Complejidad O(1)
bool Registro::operator>=(Registro r2) {
    return cant >= r2.cant;
}
