#pragma once

#include <iostream>
#include "abb.h"


template <typename C, typename V>
class NoABB
{
    public:
        NoABB(C chave, V valor) : chave(chave), valor(valor), esq(nullptr), dir(nullptr);

        ~NoABB();

        C getChave() { return chave; }
        V& getValor() { return valor; }

    private:
        C chave;
        V valor;
        NoABB *esq;
        NoABB *dir;

    friend class ABB<C, V>;
};