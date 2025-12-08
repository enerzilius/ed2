#include "abb.h"
#include "../../utils/utils.h"
#include <iostream>

int main(int argc, char** argv) {
    int n =10;

    if(argc > 1) n = atoi(argv[1]);

    std::cout<<"\n";
    std::vector<int> v = gerar_vetor_aleatorio(n, 99, n*100);
    imprimir_vetor(v.data(), n);
    divider();

    ABB<int, int> arvore;
    arvore.inserir(7, 7);
    arvore.inserir(3, 3);
    arvore.inserir(1, 3);
    arvore.inserir(10, 3);
    
    arvore.imprimir();

    NoABB<int, int>* menor = arvore.minimo();
    menor->imprimir();
    NoABB<int, int>* maior = arvore.maximo();
    maior->imprimir();

    return 0;
}