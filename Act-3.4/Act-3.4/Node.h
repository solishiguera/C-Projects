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
    Node<T>* left;
    Node<T>* right;
    Node(T data);
    Node(T data, Node<T>* left, Node<T>* right);
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T>* left, Node<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}
