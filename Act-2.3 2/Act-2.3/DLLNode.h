//
//  DLLNode.h
//  Act-2.3
//
//  Created by Diego Solis on 10/7/20.
//

#ifndef DLLNode_h
#define DLLNode_h

template<class T>
struct DLLNode {
    T data;
    DLLNode<T>* next;
    DLLNode<T>* previous;
    DLLNode(T data);
    DLLNode(T data, DLLNode<T>* next, DLLNode<T>* previous);
};

template <class T>
DLLNode<T>::DLLNode(T data) {
    this->data = data;
    this->next = NULL;
    this->previous = NULL;
}

template <class T>
DLLNode<T>::DLLNode(T data, DLLNode<T>* next, DLLNode<T>* previous) {
    this->data = data;
    this->next = next;
    this->previous = previous;
}

#endif /* DLLNode_h */
