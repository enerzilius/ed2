#include <iostream>
#include <algorithm>
#include <cstdio>
#include "../utils/utils.h"

using namespace std;

// PARTICIONAMENTO

template<typename T>
int partition(T* v, int p, int r) {
    T x = v[r];
    int i = p-1;

    for (int j = p; j < r; j++)
    {
        if(v[j] <= x) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[r]);
    
    return i+1;
}

template<typename T>
void quickSort(T* v, int p, int r) {
    if(p < r) {
        int q = partition(v, p, r);
        quickSort(v, p, q-1);
        quickSort(v, q+1, r);
    }
}


int main(int argc, char** argv) {
    int n =10;

    if(argc > 1) n = atoi(argv[1]);

    vector<int> v;
    v = gerar_vetor_aleatorio(n, 99, n*100);
    imprimir_vetor(v.data(), v.size());


    quickSort(v.data(), 0, v.size()-1);
    imprimir_vetor(v.data(), v.size());


    return 0;
}