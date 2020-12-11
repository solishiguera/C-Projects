//
//  HashC.h
//  Act-5.2
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef HashC_h
#define HashC_h

class HashC {
private:
    vector< vector<Registro> > table;
    int size;
    int qty;
    bool isFull();
    bool alreadyExist(vector<Registro> collisions, Registro str);
public:
    HashC();
    HashC(int size);
    HashC(vector<Registro> list);
    void addStr(Registro str);
    bool findStr(Registro str);
    void print();
    int hashing(Registro str);
    int key = 0; // La inicialicé, puede causar errores
    void operator=(const vector<Registro> &list);
};

HashC::HashC() {
    qty = 0;
    size = 0;
}
void HashC::operator=(const vector<Registro> &list) {
    qty = 0;
    size = (int) list.size();
    vector< vector<Registro> > tempTable(size);
    table = tempTable;
    for(auto str : list) {
        addStr(str);
    }
}

HashC::HashC(vector<Registro> list) {
    qty = 0;
    size = (int) list.size();
    vector< vector<Registro> > tempTable(size);
    table = tempTable;
    for(auto str : list) {
        addStr(str);
    }
}

HashC::HashC(int size) {
    this-> size = size;
    qty = 0;
    vector< vector<Registro> > tempTable(size);
    table = tempTable;
}

bool HashC::findStr(Registro str) {
    int index = hashing(str);
    return alreadyExist(table[index], str);
}

int HashC::hashing(Registro str) {
    int len = (int) str.ip.length();
    if (len == 1) {
        key = int(str.ip[0]);
    } else {
        if (len == 2) {
            key = int(str.ip[0]) + int(str.ip[1]);
        } else {
            if (len >= 3) {
                key = int(str.ip[1]) + int(str.ip[2]);
            }
        }
    }
    return key % size;
}

void HashC::addStr(Registro str) {
    if(!isFull()) {
        int index = hashing(str);
        if (!alreadyExist(table[index], str)) {
            table[index].push_back(str);
            qty++;
        }
    } else {
        throw out_of_range("La tabla ya está llena");
    }
}

bool HashC::isFull() {
    return qty == size;
}

void HashC::print() {
    cout << "Hash Table" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ": ";
        for(auto str : table[i]) {
            cout << str.ip << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool HashC::alreadyExist(vector<Registro> collisions, Registro str) {
    for(auto collision : collisions) {
        if (str.ip == collision.ip) {
            return true;
        }
    }
    return false;
}

#endif /* HashC_h */
