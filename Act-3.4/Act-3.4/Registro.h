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
};

Registro::Registro(string ip, int cant) {
    this-> ip = ip;
    this-> cant = cant;
}
