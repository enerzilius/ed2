#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include "../utils/utils.h"

using namespace std;

template<typename T>
vector<T> getUnique(const vector<T>& v) {
    unordered_set<T> hash; 
    for (T num : v)
    {
        hash.insert(num);
    }

    vector<T> keys;
    for (T key : hash)
    {
        keys.push_back(key);
    }
    return keys;
}

int main(int argc, char** argv) {
    int n =10;

    if(argc > 1) n = atoi(argv[1]);
    
    vector<int> v;
    v = gerar_vetor_aleatorio(n, 99, n);

    imprimir_vetor(v.data(), v.size());
    vector<int> unicos = getUnique(v);
    cout<<"\n";
    
    imprimir_vetor(unicos.data(), unicos.size());

}