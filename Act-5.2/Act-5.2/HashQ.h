//
//  HashQ.h
//  Act-5.1
//
//  Created by Diego Solis on 12/6/20.
//

#ifndef HashQ_h
#define HashQ_h

class HashQ {
private:
    vector<Registro> table;
    vector<int> status;
    int size;
    int qty;
    bool isFull();
    int quadProbe(int index, int cont);
public:
    HashQ(int size);
    HashQ();
    HashQ(vector<Registro> list);
    void addStr(Registro &str); // Complejidad O(n)
    int findStr(Registro str); // Complejidad O(n)
    void print(); // Complejidad O(n)
    int hashing(Registro &str);
    int key = 0; // La inicialicé, puede causar errores
    void operator=(const vector<Registro> &list);
};

void HashQ::operator=(const vector<Registro> &list) {
    qty = 0;
    size = (int) list.size();
    vector<Registro> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size, 0);
    status = tempStatus;
    for(auto str : list) {
        addStr(str);
    }
}

HashQ::HashQ() {
    qty = 0;
    size = 0;
}

// Complejidad O(n)
HashQ::HashQ(vector<Registro> list) {
    qty = 0;
    size = (int) list.size();
    vector<Registro> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size, 0);
    status = tempStatus;
    for(auto str : list) {
        addStr(str);
    }
}

HashQ::HashQ(int size) {
    this-> size = size;
    qty = 0;
    vector<Registro> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size, 0);
    status = tempStatus;
}

// Complejidad O(n)
int HashQ::findStr(Registro str) {
    int cont = 1;
    int index = hashing(str);
    while (status[index] != 0 && cont < size) {
        if(status[index] == 1 && table[index] == str) {
            return index;
        }
        index = quadProbe(index, cont);
        cont++;
    }
    return -1;
}

int HashQ::hashing(Registro &str) {
    int len = (int) str.ip.length();
    int key = 0; // La inicialicé, puede causar errores
    if (len == 12) {
        key = int(str[0]);
    } else {
        if (len == 14) {
            key = int(str[0]) + int(str[1]);
        } else {
            if (len >= 16) {
                key = int(str[1]) + int(str[2]);
            }
        }
    }
    return key % size;
}

// Complejidad O(n)
void HashQ::addStr(Registro &str) {
    
    if(!isFull()) {
        int index = hashing(str);
        if (status[index] == 0 || status[index] == 2) {
            table[index] = str;
            status[index] = 1;
            str.key = index;
            qty++;
        } else {
            // Validar si ya existe
            int cont = 1;
            int newIndex = quadProbe(index, cont);
            while (status[newIndex] == 1) {
                if (str == table[newIndex]) {
                    throw runtime_error("El valor ya existe en la tabla");
                }
                cont++;
                newIndex = quadProbe(index, cont);
            }
            table[newIndex] = str;
            str.key = newIndex;
            status[newIndex] = 1; // Ocupado
            qty++;
        }
    } else {
        throw out_of_range("La tabla ya está llena");
    }
    
}

int HashQ::quadProbe(int index, int cont) {
    int newIndex;
//    if (index + int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)) < 0) {
//        newIndex = size - fmod(size - int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)), size);
//    } else {
//        newIndex = fmod(index + int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)), size);
//    }
    newIndex = fmod(index + int(pow(-1, cont - 1)) * int(pow((cont + 1) / 2, 2)), size);
    return newIndex;
}

bool HashQ::isFull() {
    return qty == size;
}

void HashQ::print() {
    cout << "Hash Table" << endl;
    
    for(int i = 0; i < size; i++) {
        cout << i << ": " << table[i].ip << endl;
    }
//    for(auto str : table) {
//        cout << str.ip << endl;
//    }
}


#endif /* HashQ_h */
