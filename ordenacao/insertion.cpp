#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include "../utils/utils.cpp"

template<typename T>
void insertionSort(T* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        T x = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > x) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j] = x;
    }
    
}

int main(int argc, char** argv) {
    int n =10;

    if(argc > 1) n = atoi(argv[1]);

    std::vector<int> v = gerar_vetor_aleatorio(n, 99, n*100);
    imprimir_vetor(v.data(), n);
    insertionSort(v.data(), n);
    imprimir_vetor(v.data(), n);
    
    return 0;
}