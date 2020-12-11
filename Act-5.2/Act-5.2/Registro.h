//
//  Registro.h
//  Act-5.2
//
//  Created by Diego Solis on 12/6/20.
//

#pragma once

struct Registro {
    string ip;
    int key;
    Registro(string ip);
    Registro();
    void addKey(int key);
    void deletePort(); // Borrar puerto
    int length();
    void operator=(const Registro &R);
    bool operator>(const Registro r2) const;
    bool operator>=(Registro r2);
    bool operator<(const Registro r2) const;
    bool operator<=(Registro r2);
    bool operator==(Registro r2);
    bool operator==(int r2);
    int operator[](int r);
};

int Registro::operator[](int r) {
    return ip[r];
}

int Registro::length() {
    return (int) ip.length();
}

void Registro::deletePort() {
    ip.erase(ip.size() - 5, 5);
}

// Complejidad O(n)
void Registro::addKey(int newKey) {
    key = newKey;
}

// Complejidad O(1)
void Registro::operator=(const Registro &R) {
    ip = R.ip;
    key = R.key;
}

// Complejidad O(1)
Registro::Registro(string ip){
    this-> ip = ip;
    this-> key = 0;
}

// Complejidad O(1)
Registro::Registro() {
    ip = "/";
    key = 0;
}

// Complejidad O(1)
bool Registro:: operator>(Registro r2) const {
    return key > r2.key;
}

// Complejidad O(1)
bool Registro::operator<(Registro r2) const {
    return key < r2.key;
}

// Complejidad O(1)
bool Registro::operator==(Registro r2) {
    return this->ip == r2.ip;
}
bool Registro::operator==(int r2) {
    return this->key == r2;
}

// Complejidad O(1)
bool Registro::operator<=(Registro r2) {
    return this->key <= r2.key;
}

// Complejidad O(1)
bool Registro::operator>=(Registro r2) {
    return this->key >= r2.key;
}
