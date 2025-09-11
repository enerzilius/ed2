#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


template<typename T>
int pos_maior(T *v, int ini, int fim) {
    int maior = ini;
    for(int i = ini+1; i <= fim; i++) {
        if(v[i] > v[maior]) maior = i;
    }
    return maior;
}

template<typename T>
void selectionSort(T *v, int n) {
    for (int i = n-1; i > 0; i--)
    {
        int maior = pos_maior(v, 0, i);
        swap(v[maior], v[i]);
    }
}


int main() {
    int v[] = { 10, 2, 3, 66, 9, 2 };
    cout<<pos_maior<int>(v, 0, 5)<<" - "<<v[pos_maior<int>(v, 0, 5)]<<endl;
    selectionSort(v, 6);
    for (int i = 0; i < 6; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}