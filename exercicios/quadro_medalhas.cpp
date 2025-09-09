#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <fstream>

using namespace std;

struct Pais {
    string nome;
    int ouro, prata, bronze;

    Pais(const string& nome, int o, int p, int b) {
        this->nome = nome;
        this->ouro = o;
        this->prata = p;
        this->bronze = b;
     }

    void print() { 
        cout<< this->nome << " - " << this->ouro << " - " << this->prata << " - " << this->bronze << endl;
    }
};

vector<Pais> readCountriesFromFile(const string& filepath) {
    ifstream fin(filepath);
     if (!fin.is_open()) {
        cerr << "Erro ao abrir arquivo " << filepath << endl;
        return {};
    }

    int N, o, p, b;
    string nome;

    
    fin >> N;
    vector<Pais> quadro;
    quadro.reserve(N);

    for(int i = 0; i < N; i++) {
        fin >> nome >> o >> p >> b;
        quadro.emplace_back(nome, o, p, b);
        quadro[i].print();
    }
    cout<<endl;
    return quadro;
}

bool compararPaises(const Pais& A, const Pais& B) {
    if(A.ouro != B.ouro) return A.ouro > B.ouro;
    if(A.prata != B.prata) return A.prata > B.prata;
    if(A.bronze != B.bronze) return A.bronze > B.bronze;
    return A.nome < B.nome;
}

void sortQuadroMedalhas() {

}

int main() {
    vector<Pais> paises = readCountriesFromFile("arquivos_suporte/paises.txt");
    return 0;
}