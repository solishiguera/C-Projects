//
//  Node.h
//  Act-3.4
//
//  Created by Diego Solis on 10/16/20.
//

#pragma once


template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T data);
    Node(T data, Node<T>* next, Node<T>* prev);
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}

