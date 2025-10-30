#include "end_aberto.h"

#include <vector>
#include <utility>
#include <iostream>
#include "../utils/utils.h"
#include "./sondagem/sondagem.h"

TabHashEndAberto::TabHashEndAberto(int tamanho, float limiar = 0.5, Sondagem* sondagem = new SondagemLinear()) {
    this->m = tamanho;
    this->n = 0;
    this->limiar = limiar;
    this->tabela = new Elemento[this->m];
    this->sondagem = sondagem;
    this->colisoes = 0;
    this->redims = 0;
    for(int i = 0; i < tamanho; i++) {
        this->tabela[i].estado = Estado::LIVRE;
        this->tabela[i].chave = 0;
        this->tabela[i].valor = 0;
    }
}

TabHashEndAberto::~TabHashEndAberto() {
    delete[] this->tabela;
}

void TabHashEndAberto::inserir(int chave, int valor) {
    int pos = buscar_pos(chave); 
    if(pos >= 0) {
        tabela[pos].valor = valor;
        return;
    }
    if ((float)n / m >= this->limiar)
    {
        redimensionar(findNearestPrime(m*2));
    }
    
    int k = 0;
    int hashed = hash(chave, k);
    while(this->tabela[hashed].estado == Estado::OCUPADO){
        colisoes++;
        k++;
        hashed = hash(chave, k);
        if(k == this->m)
            return;
    }
    tabela[hashed].chave = chave;
    tabela[hashed].valor = valor;
    tabela[hashed].estado = Estado::OCUPADO;
    this->n++;
}

int TabHashEndAberto::buscar_pos(int chave) {
    int k = 0;
    int h = hash(chave, k);
    while (this->tabela[h].estado != Estado::LIVRE)
    {
        if (tabela[h].estado == Estado::OCUPADO && tabela[h].chave == chave)
        {
            return h;
        }
        k++;
        h = (++h)%this->m;
    }
    return -1;
}

std::pair<int, int> TabHashEndAberto::buscar(int chave) {
    int pos = buscar_pos(chave);
    if(pos >= 0) return std::make_pair(tabela[pos].chave, tabela[chave].valor);
    return invalido;
}

int TabHashEndAberto::hash(int chave, int k) {
    int p = sondagem->p(chave, k);
    return (chave % this->m + k) % this->m;
}

void TabHashEndAberto::redimensionar(int novo_m) {
    Elemento* novo = new Elemento[novo_m];
    
    for (int i = 0; i < novo_m; i++)
    {
        novo[i].estado = Estado::LIVRE;
        novo[i].chave = 0;
        novo[i].valor = 0;
    }

    Elemento* antiga = tabela;
    tabela = novo;
    int m_antigo = m;
    n = 0;
    m = novo_m;
    for (int i = 0; i < m_antigo; i++)
    {
        if(antiga[i].estado == Estado::OCUPADO) inserir(antiga[i].chave, antiga[i].valor);
    }
    redims++;
    delete[] antiga;
}