#include <iostream>
#include "./abb.h"
#include "./node_abb.h"

template<typename C, typename V>
ABB<C, V>::ABB() {
    this->raiz = nullptr;
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::buscar(C chave) {  // Note: returns pointer, not object
    NoABB<C, V>* node = this->raiz;
    while(node != nullptr) {
        if(chave == node->chave) break;
        if(chave > node->chave) node = node->dir;
        else node = node->esq;
    }
    return node;
}

template<typename C, typename V>
void ABB<C, V>::inserir(C chave, V valor) {
    this->raiz = inserirNode(this->raiz, chave, valor);
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::inserirNode(NoABB<C, V>* node, C chave, V valor) {
    if(node == nullptr) return new NoABB<C, V>(chave, valor);
    if(chave < node->chave) node->esq = inserirNode(node->esq, chave, valor);
    else if(chave > node->chave) node->dir = inserirNode(node->dir, chave, valor);  // Fixed: was node->esq
    else node->valor = valor;
    return node;  // Don't forget to return the node!
}