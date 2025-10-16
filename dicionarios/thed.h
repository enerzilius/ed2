#include <vector>
#include <utility>
#include <iostream>

class TabHashEncadeamento {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEncadeamento(int tamanho, int limiar = 5){
        this->invalido = std::make_pair(-1,-1);
        this->limiar = limiar;
        this->m = tamanho;
        this->n = 0;
        this->redims = 0;
        this->tabela = new std::vector<std::pair<int,int>>[tamanho];
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEncadeamento(){
        delete[] this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor){
        auto& el = this->buscar(chave);
        if(el != this->invalido){
            //chave já está na tabela
            el.second = valor;
            return;
        }

        int fator_carga = this->n / this->m;

        if(fator_carga >= this->limiar) {
            this->redimensionar(this->m * 2);
        }

        int h = hash(chave);
        this->tabela[h].push_back(std::make_pair(chave, valor));
        this->n++;
    }
    
    //Remove o par com a chave da tabeka
    void remover(int chave);
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int>& buscar(int chave) {
        int hashed = hash(chave);
        for(auto& el : this->tabela[hashed]) {
            if(el.first == chave) return el;
        }
        return this->invalido;
    }
    
    //Imprime a tabela
    void imprimir() {
        for (int i = 0; i < this->m; i++)
        {
            std::cout<<i<<": ";
            for (auto e : this->tabela[i])
            {
                std::cout<< "(" << e.first << ", " << e.second << ")";
            }
            std::cout<<"\n";
        }
        
    }

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info() {
        std::cout<<"M= "<<this->m<<", n = " <<this->n<<", Fator de Carga: "<<(float)this->n/(float)this->m<<", Redimencionamentos: "<<this->redims<<"\n";
    }

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido;

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,int>> itens();

private:
    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    int limiar; 
    int redims; // número de redimensionamentos realizados

    std::vector<std::pair<int,int>> *tabela; // tabela hash
    
    int hash(int chave){
        // função hash
        return chave % this->m;
    } 

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m) {
        auto* antiga = this->tabela;
        int old_m = this->m;
        this-> n = 0;
        this->m = novo_m;
        this->tabela = new std::vector<std::pair<int,int>>[novo_m];
        for (int i = 0; i < old_m; i++)
        {
            if(antiga[i].size() > 0) for (auto& e : antiga[i]) this->inserir(e.first, e.second);
            
        }
        this->redims++;
        delete[] antiga;
    }
    
};