#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

template<typename T>
void merge(T *v, int p, int q, int r) {
    int n1 = q-p+1, n2 = r - q;

    T* E[n1];
    T* E[n2];

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

    delete E[];
    delete D[];
}

int main() {
    int v[] = { 1, 7, 8, 9, 3 };
    int p = 0, q = 2, r = 5;
    merge(v, p, q, r) ;
    for (int i = 0; i < r+1; i++)
    {
        cout<<v[i] << endl;
    }
    

    return 0;
}