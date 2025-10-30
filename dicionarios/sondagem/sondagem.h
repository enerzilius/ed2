#pragma once

class Sondagem {
public:
    virtual int p(int chave, int k) = 0;
    virtual void redim_callback() { }
};

class SondagemLinear : public Sondagem {
public:
    int p(int chave, int k) {
        return k;
    }
};
class SondagemQuadratica : public Sondagem {
public:
    int p(int chave, int k) {
        return k*k;
    }
};
class SondagemHashDuplo : public Sondagem {
public:
    int p(int chave, int k) {
        return k*((chave));
    }
};

