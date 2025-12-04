#include <iostream>
#include "./abb.h"
#include "./node_abb.h"

template<typename C, typename V>
ABB<C, V>::ABB() {
    this->raiz = nullptr;
}

template<typename C, typename V>
ABB<C, V>::~ABB() {
    if(this != nullptr) {
        delete esq;
        delete dir;
    }
}

template<typename C, typename V>
NoABB<C, V>* ABB<C, V>::buscar(C chave) {
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
    else if(chave > node->chave) node->dir = inserirNode(node->dir, chave, valor);
    else node->valor = valor;
    return node;
}

template<typename C, typename V>
int ABB<C, V>::tamanho() {
    return contarNos(raiz);
}

template<typename C, typename V>
int ABB<C, V>::contarNos(NoABB<C, V>* node) {
    if(node == nullptr) return 0;
    return 1+tamanho(node->esq)+tamanho(node->dir);
}

template<typename C, typename V>
int ABB<C, V>::altura() {
    return alturaRecursiva(raiz);
}

template<typename C, typename V>
int ABB<C, V>::alturaRecursiva(NoABB<C, V>* node) {
    if(node == nullptr) return 0;
    int alturaEsquerda = altura(node->esq);
    int alturaDireita = altura(node->dir);
    return alturaEsquerda>alturaDireita ? alturaEsquerda+1 : alturaEsquerda + 1;
}