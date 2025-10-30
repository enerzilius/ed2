#include "end_aberto.h"
#include "./sondagem/sondagem.h"

using namespace std;

int main(int argc, char** argv) {
    int m = 10;
    int n = 5;
    float limiar = 0.5;
    if(argc > 1) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        limiar = atof(argv[3]);
    }

    Sondagem* sondagem = new SondagemLinear();
    TabHashEndAberto tabela(m, limiar, sondagem);

    for (int i = 0; i < n; i++)
    {
        tabela.inserir(rand() % (n*100), rand() % (n*100));
    }

    tabela.imprimir_info();
    tabela.imprimir();
    return 0;
}