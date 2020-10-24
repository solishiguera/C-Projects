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
    Registro() {
        
    }
    bool operator>(Registro r2);
    bool operator>=(Registro r2);
    bool operator<(Registro r2);
    bool operator<=(Registro r2);
    bool operator==(Registro r2);
};

Registro::Registro(string ip, int cant) {
    this-> ip = ip;
    this-> cant = cant;
}

bool Registro:: operator>(Registro r2) {
    return cant > r2.cant;
}

bool Registro:: operator<(Registro r2) {
    return cant < r2.cant;
}

bool Registro::operator==(Registro r2) {
    return cant == r2.cant;
}

bool Registro::operator<=(Registro r2) {
    return cant <= r2.cant;
}

bool Registro::operator>=(Registro r2) {
    return cant >= r2.cant;
}
