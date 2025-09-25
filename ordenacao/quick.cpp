#include <iostream>
#include <algorithm>
#include <cstdio>
#include "utils.cpp"

using namespace std;

// PARTICIONAMENTO

template<typename T>
int partition(int* v, int p, int r) {
    int x = v[r];
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


int main(int argc, char** argv) {
    return 0;
}