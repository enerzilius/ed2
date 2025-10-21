#include <iostream>
#include "utils.h"

using namespace std;

int main() {
    for (int i = 0; i < 24; i++)
    {
        cout<<i<<": ";
        printBool(isPrime(i), "Primo", "Nao");
    }
    
    return 0;
}