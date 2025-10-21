#include <iostream>
#include "utils.h"

using namespace std;

int main() {
    for (int i = 0; i < 9; i++)
    {
        cout<<i<<": ";
        printBool(isPrime(i), "Primo", "Nao");
    }

    for (int i = 0; i < 33; i++)
    {
        cout<<i<<": ";
        cout<<findNearestPrime(i)<<"\n";
    }
    
    return 0;
}