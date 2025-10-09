#include <iostream>
#include "thed.h"
#include "./print_pair.h"

using namespace std;

void test3(int argc, char** argv){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int limiar = atoi(argv[3]);

    TabHashEncadeamento tab(m, limiar);

    for(int i = 0; i < n; i++){
        tab.inserir(rand() % (n*100), rand() % (n*100));
    }

    tab.imprimir_info();
    //tab.imprimir();

}


int main(int argc, char** argv) {
    test3(argc, argv);

    return 0;
}