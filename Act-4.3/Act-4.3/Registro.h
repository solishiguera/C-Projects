//
//  Registro.h
//  Act-4.3
//
//  Created by Diego Solis on 12/5/20.
//


#pragma once

struct Registro {
    string ip;
    int cant;
    Registro(string ip);
    Registro();
    void addAdy();
    void deletePort(); // Borrar puerto
    void operator=(const Registro &R);
    bool operator>(Registro r2);
    bool operator>=(Registro r2);
    bool operator<(Registro r2);
    bool operator<=(Registro r2);
    bool operator==(Registro r2);
};

void Registro::deletePort() {
    ip.erase(ip.size() - 5, 5);
}

// Complejidad O(n)
void Registro::addAdy() {
    cant += 1;
}

// Complejidad O(1)
void Registro::operator=(const Registro &R) {
    ip = R.ip;
    cant = R.cant;
}

// Complejidad O(1)
Registro::Registro(string ip){
    this-> ip = ip;
    this-> cant = 0;
}

// Complejidad O(1)
Registro::Registro() {
    ip = "/";
    cant = 0;
}

// Complejidad O(1)
bool Registro:: operator>(Registro r2) {
    return this->cant > r2.cant;
}

// Complejidad O(1)
bool Registro:: operator<(Registro r2) {
    return this->cant < r2.cant;
}

// Complejidad O(1)
bool Registro::operator==(Registro r2) {
    return this->cant == r2.cant;
}

// Complejidad O(1)
bool Registro::operator<=(Registro r2) {
    return this->cant <= r2.cant;
}

// Complejidad O(1)
bool Registro::operator>=(Registro r2) {
    return this->cant >= r2.cant;
}
