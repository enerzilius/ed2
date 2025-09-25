#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include "utils.h"

using namespace std;

template<typename T>
void merge(T *v, int p, int q, int r) {
    int n1 = q-p+1, n2 = r - q;

    T* E = new T[n1];
    T* D = new T[n2];

    for(int i = 0; i < n1; i++) E[i] = v[p+i];
    for(int i = 0; i <  n2; i++) D[i] = v[q+1+i];

    int k = p;
    int i = 0, j = 0;

    while (i<n1 && j<n2)
    {
        if(E[i] <= D[j]){
            v[k] = E[i];
            i++;
        } else {
            v[k] = D[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        v[k] = E[i];
        i++, k++;
    }
    while(j < n2) {
        v[k] = D[j];
        j++, k++;
    }

    delete[] E;
    delete[] D;
}

template<typename T>
void mergeSort(T* v, int p, int r) {
    if(r > p) {
        int q = p + (r - p) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q+1, r);
        merge(v, p, q, r);
    }
}

int main(int argc, char** argv) {
    using namespace std;

    int n =10;

    if(argc > 1) n = atoi(argv[1]);

    vector<int> v = gerar_vetor_aleatorio(n, 99, n*100);
    imprimir_vetor(v.data(), n);
    mergeSort(v.data(), 0, n-1);
    imprimir_vetor(v.data(), n);
    

    return 0;
}