#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>

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
    int N, o, p, b;
    string nome;

    
    cin >> N;
    cout<<N<<endl;
    vector<Pais> quadro;
    quadro.reserve(N * sizeof(Pais));
    cout<<"aa"<<endl;

    for(int i = 0; i < N; i++) {
        cin >> nome >> o >> p >> b;
        quadro.emplace_back(nome, o, p, b);
        quadro[i].print();
    }
    return quadro;
}

void sortQuadroMedalhas() {

}

int main() {
    vector<Pais> paises = readCountriesFromFile("../arquivos_suporte/paises.txt");
    return 0;
}