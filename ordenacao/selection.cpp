#include <iostream>
#include <algorithm>
#include <cstdio>
#include "utils.cpp"

using namespace std;


template<typename T>
int pos_maior(T *v, int ini, int fim) {
    int maior = ini;
    for(int i = ini+1; i <= fim; i++) {
        if(v[i] > v[maior]) maior = i;
    }
    return maior;
}

void selectionSort(int *v, int n) {
    for (int i = n-1; i > 0; i--)
    {
        int maior = pos_maior<int>(v, 0, i);
        trocar(v, maior, i);
    }
}


int main(int argc, char** argv) {
    int n =10;

    if(argc > 1) n = atoi(argv[1]);
    
    vector<int> v;
    v = gerar_vetor_aleatorio(n, 99, n*100);

    imprimir_vetor(v.data(), v.size());
    selectionSort(v.data(), v.size());

    imprimir_vetor(v.data(), v.size());

    return 0;
}