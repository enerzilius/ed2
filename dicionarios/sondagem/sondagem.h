#pragma once
#include <string>
#include <iostream>

class Sondagem {
public:
    std::string name;
    virtual int p(int chave, int k) = 0;
    virtual void redim_callback(int novo_m) { }
};

class SondagemLinear : public Sondagem {
public:
    std::string name = "linear";
    int p(int chave, int k) {
        return k;
    }
};
class SondagemQuadratica : public Sondagem {
public:
    std::string name = "quadratica";
    int p(int chave, int k) {
        return k*k;
    }
};
class SondagemHashDuplo : public Sondagem {
public:
    SondagemHashDuplo(int s) {
        this->s = s;
    }

    void redim_callback(int novo_m) {
        this->s = novo_m-1;
    }

    std::string name = "hash duplo";
    int p(int chave, int k) {
        return k*((chave));
    }
private:
    int s;
};

