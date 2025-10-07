#include "thed.h"
#include <vector>
#include <utility>

//Construtor: inicializa uma nova tabela com tamanho m
TabHashEncadeamento::TabHashEncadeamento(int tamanho, int limiar = 5) {

}

//Destrutor: libera todos os recursos alocados para a tabela
TabHashEncadeamento::~TabHashEncadeamento() {
    delete[] this->tabela;
}

//Insere um novo par (chave, valor) na tabela
TabHashEncadeamento::void inserir(int chave, int valor){
    auto& el = this->buscar(chave);
    if(el != this->invalido) {
        //chave já está na tabela
        el.second = valor;
        return;
    }

    int hash = hash(chave);
    this->tabela[hash].push_back(std::make_pair(chave, valor));
}

//Remove o par com a chave da tabeka
void remover(int chave);

//Busca o valor associado a chave na tabela
std::pair<int,int>& buscar(int chave);

//Imprime a tabela
void imprimir();

//Imprime informações sobre a tabela (m, n e fator de carga)
void imprimir_info();

//par chave-valor inválido para indicar que a chave não foi encontrada
std::pair<int,int> invalido;

// retorna as chaves da tabela
std::vector<int> chaves();

// retorna todos os pares (chave, valor) da tabela
std::vector<std::pair<int,int>> itens();

int TabHashEncadeamento::hash(int chave){
    return chave % this->m;
}

void TabHashEncadeamento::redimensionar(int novo_m);