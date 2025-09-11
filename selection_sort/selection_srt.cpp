#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


template<typename T>
int pos_maior(T *v, int ini, int fim) {
    T maior = v[ini];
    int i_maior = ini;
    for(int i = ini+1; i < fim; i++) {
        if(v[i] > maior) {
            maior = v[i];
            i_maior = i;
        }
    }
    return i_maior;
}

int main() {
    int v[] = { 10, 2, 3, 66, 9, 10 };
    cout<<pos_maior<int>(v, 0, 5)<<" - "<<v[pos_maior<int>(v, 0, 5)]<<endl;
    return 0;
}