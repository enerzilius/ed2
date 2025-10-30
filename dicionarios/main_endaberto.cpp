#include "end_aberto.h"
#include "./sondagem/sondagem.h"

using namespace std;

Sondagem* buildSondagem(std::string name, int m) {
    std::cout<<name<<std::endl;
    if(name == "linear") return new SondagemLinear();
    if(name == "quadratica") return new SondagemQuadratica();
    if(name == "duplo") return new SondagemHashDuplo(m);
    return NULL;
}

int main(int argc, char** argv) {
    int m = 10;
    int n = 5;
    float limiar = 0.5;
    string name = "linear";
    if(argc > 1) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        limiar = atof(argv[3]);
        name = argv[4];
    }

    Sondagem* sondagem = buildSondagem(name, m);
   // Sondagem* sondagem = new SondagemLinear();
    cout<< sondagem->name <<"\n";
    TabHashEndAberto tabela(m, sondagem, limiar);

    for (int i = 0; i < n; i++)
    {
        tabela.inserir(rand() % (n*100), rand() % (n*100));
    }

    tabela.imprimir_info();
    tabela.imprimir();
    return 0;
}