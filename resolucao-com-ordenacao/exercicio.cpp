#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

void embaralhar(int *array, size_t n, int seed){
    srand(seed);
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

vector<int> gerar_vetor_aleatorio_sem_reps(int n, int seed){
    int* saida = new int[n];
    
    for(int i = 0; i < n; i++)
        saida[i] = i;
    
    embaralhar(saida, n, seed);
    
    std::vector<int> v;
    v.reserve(n);

    for(int i = 0; i < n; i++)
        v.push_back(saida[i]);
    
    delete[] saida;

    return v;
}

template<typename T>
bool hasRepetitions(vector<T> &vec) {
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size()-1; i++){
        if(vec[i] == vec[i+1]) return true;
    }
    return false;
}

template<typename T>
int getLargest(vector<T> &vec, int k) {
    return vec[vec.size()-1-k];
}

int main(){
    vector<int> vec = { 1, 2, 3 , 4, 5 };

    vector<int> u = { 6, 0, 9, 2, 8, 1, 1 };

    vector<string> s = { "banana", "melao", "mamao" };

    vector<string> s2 = { "banana", "melao", "melao" };

    vector<int> grande = gerar_vetor_aleatorio_sem_reps(100, 99);

    cout<<hasRepetitions(grande) <<endl;
    cout<<getLargest(grande, 1)<<endl;

    return 0;
}