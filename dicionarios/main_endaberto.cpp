#include "end_aberto.h"

using namespace std;

int main(int argc, char** argv) {
    TabHashEndAberto tabela(10, 0.5);

    tabela.inserir(10, 0);
    tabela.inserir(21, 0);
    tabela.inserir(44, 0);
    tabela.inserir(32, 0);
    tabela.inserir(12, 0);
    tabela.inserir(37, 0);
    tabela.inserir(43, 0);
    tabela.inserir(23, 0);
    tabela.inserir(54, 0);

    tabela.imprimir();
    return 0;
}