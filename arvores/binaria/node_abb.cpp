#include "node_abb.h"

template<typename C, typename V>
NoABB<C, V>::NoABB(C chave, V valor) : chave(chave), valor(valor), 
            esq(nullptr), dir(nullptr) {}

template<typename C, typename V>
C NoABB<C,V>::getChave() { return chave; }

template<typename C, typename V>
V& NoABB<C,V>::getValor() { return valor; }