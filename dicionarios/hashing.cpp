#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <utility>
#include "../utils/utils.h"

using namespace std;

//Minimiza o número de colisões
//Espalha uniformimente as chaves pelas posições da tabela
    //Todas as posições da tabela sejam igualmente prováveis de receberam chaves

//Tratamento de colisões por encadeamento
//Encadeia um par chave e valor com mesmo módulo
/*
h(999) = 999 % 10 = 9
h(99) = 99 %10 = 9
9 |  |->(999,1);(99,1);
*/
template<typename T>
void hashing(T x, int M) {
    
    return x % M;
}


int main(int argc, char** argv) {
    return 0;
}