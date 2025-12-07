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

    

    return 0;
}