#include "end_aberto.h"

#include <vector>
#include <utility>
#include <iostream>

TabHashEndAberto::TabHashEndAberto(int tamanho, float limiar = 0.5) {
    this->m = tamanho;
    this->n = 0;
    this->limiar = limiar;
    this->tabela = new Elemento[this->m];
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
        redimensionar(m*2);
    }
    
    int hashed = hash(chave);
    hashed = hashed % m;
    while(tabela[hashed].estado == Estado::OCUPADO) {
        hashed = (++hashed) % m;
    }
    tabela[hashed].chave = chave;
    tabela[hashed].valor = valor;
    tabela[hashed].estado = Estado::OCUPADO;
    this->n++;
}

int TabHashEndAberto::buscar_pos(int chave) {
    int h = hash(chave);
    while (this->tabela[h].estado != Estado::LIVRE)
    {
        if (tabela[h].estado == Estado::OCUPADO && tabela[h].chave == chave)
        {
            return h;
        }
        h = (++h)%this->m;
    }
    return -1;
}

std::pair<int, int> TabHashEndAberto::buscar(int chave) {
    int pos = buscar_pos(chave);
    if(pos >= 0) return std::make_pair(tabela[pos].chave, tabela[chave].valor);
    return invalido;
}

int TabHashEndAberto::hash(int chave) {
    return chave % m;
}

void TabHashEndAberto::redimensionar(int novo_m) {
    Elemento* novo = new Elemento[novo_m];
    for (int i = 0; i < novo_m; i++)
    {
        novo[i].estado = Estado::LIVRE;
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