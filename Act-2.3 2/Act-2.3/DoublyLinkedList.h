//
//  DoublyLinkedList.h
//  Act-2.3
//
//  Created by Diego Solis on 10/6/20.
//

#include "DLLNode.h"
#include "Queue.h"
#include "Registro.h"

template <class T>
class DLL {
private:
    DLLNode<T>* head;
    DLLNode<T>* tail;
    int size;
    void mergeSort(int inicio, int fin);
    void merge(int ini, int mid, int fin);
public:
    DLL();
    T& operator[](int index);
    void operator=(initializer_list<T> LinkedList);
    void addFirst(T data);
    void addLast(T data);
    void printElements();
    bool isEmpty();
    T getData(int index);
    void updateAt(int position, T data);
    int sizeOf();
    void clear();
    void sort();
};

template<class T>
int DLL<T>::sizeOf(){
    return size;
}

template<class T>
void DLL<T>::operator=(initializer_list<T> list) {
    if(isEmpty()) {
        for(T i : list) {
            addLast(i);
        }
    } else {
        throw runtime_error("Error: la lista no está vacía");
    }
}

template<class T>
T& DLL<T>::operator[](int index) {
    if (index >= 1 && index <= size) {
        DLLNode<T>* aux = head;
        int i = 1;
        while (aux != NULL) {
            if (i == index) {
                return aux-> data;
            }
            aux = aux->next;
            i++;
        }
    }
    throw out_of_range("Posición inválida");
}

template <class T>
DLL<T>::DLL() {
    head = NULL;
    size = 0;
}

template <class T>
bool DLL<T>::isEmpty() {
    return size == 0;
}


template <class T>
void DLL<T>::addFirst(T data) {
    DLLNode<T>* newData = new DLLNode<T>(data);
    newData->next = head;
    if(head != NULL) {
        head->previous = newData;
    }
    head = newData;
    size++;
}

template <class T>
void DLL<T>::addLast(T data) {
    DLLNode<T>* newData = new DLLNode<T>(data);
    if(!isEmpty()) {
        
        tail-> next = newData;
        newData->previous = tail;
        tail = newData;
        size++;
    } else {
        head = newData;
        tail = newData;
        size++;
    }
}

template <class T>
void DLL<T>::printElements() {
    DLLNode<T>* aux = head;
    for (int i = 0; i < size; i++) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
T DLL<T>::getData(int index) {
    if (index >= 1 && index <= size) {
        DLLNode<T>* aux = head;
        int i = 1;
        while (aux != NULL) {
            if (i == index) {
                return aux-> data;
            }
            aux = aux->next;
            i++;
        }
    }
    throw out_of_range("Posición inválida.");
}

template <class T>
void DLL<T>::updateAt(int index, T newData) {
    if (index >= 1 & index <= size)
    {
        if(index < size/2)
        {
            DLLNode<T>* aux = head;
            int i = 1;
            while (aux != NULL)
            {
                if (i == index)
                {
                    aux ->data = newData;
                    return;
                }
                aux = aux->next;
                i++;
            }
        }
        else
        {
            DLLNode<T>* aux = tail;
            int i = size;
            while (aux != NULL)
            {
                if (i == index)
                {
                    aux->data = newData;
                    return;
                }
                aux = aux->previous;
                i--;
            }
        }
    }
    throw out_of_range("Position invalid");
}

template<class T>
void DLL<T>::merge(int ini, int mid, int fin) {
    // Revisar UpdateAt
    // Revisar GetData
    // Revisar Queue
    Queue<T> listaL;
    Queue<T> listaR;
    int pos, f1, f2, i, j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;
    
    for(i = 0; i < f1; i++) {
        listaL.enqueue(getData(ini + i));
    }
    
    for(j = 0; j < f2; j++) {
        listaR.enqueue(getData(mid + 1 + j));
    }
    
    i = 0;
    j = 0;
    pos = ini;
    
    while(i < f1 && j < f2) {
        if((listaL.front()).key() <= (listaR.front()).key()) {
            updateAt(pos, listaL.dequeue());
            i++;
        } else {
            updateAt(pos, listaR.dequeue());
            j++;
        }
        pos++;
    }
    
    while(i < f1) {
        updateAt(pos, listaL.dequeue());
        i++;
        pos++;
    }
    
    while(j < f2) {
        updateAt(pos, listaR.dequeue());
        j++;
        pos++;
    }
}

template<class T>
void DLL<T>::mergeSort(int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSort(inicio, medio);
        mergeSort(medio + 1, fin);
        
        merge(inicio,medio,fin);
    }
}

template<class T>
void DLL<T>::sort() {
    mergeSort(1, size);
}

template <class T>
void DLL<T>::clear() {
    for(int i = 1; i < size; i++) {
        DLLNode<T>* aux = head;
        head = aux-> next;
        delete aux;
        i++;
    }
    size = 0;
}
