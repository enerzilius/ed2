#include <iostream>

template<typename C, typename V>
class ABB;

template <typename C, typename V>
class NoABB
{
    public:
        NoABB(C chave, V valor) : chave(chave), valor(valor), 
            esq(nullptr), dir(nullptr) {}

        ~NoABB() { delete esq; delete dir; };
 
        C getChave() { return chave; }
        V& getValor() { return valor; }

    private:
        C chave;
        V valor;
        NoABB *esq;
        NoABB *dir;

    friend class ABB<C, V>;
};

template <typename C, typename V>
class ABB
{
public:
    ABB() {
        this->raiz = nullptr;
    }

    ~ABB() {
        if(this != nullptr) {
            delete raiz;
        }
    }

    //insere o par (chave, valor) na árvore
    void inserir(C chave, V valor) {
        inserirNode(raiz, chave, valor);
    }

    //retorna o endereço do nó com a chave especificada
    NoABB<C, V>* buscar(C chave) {
    NoABB<C, V>* node = this->raiz;
        while(node != nullptr) {
            if(chave == node->chave) break;
            if(chave > node->chave) node = node->dir;
            else node = node->esq;
        }
        return node;
    }
    //remove o nó com a chave especificada
    void remover(C chave);
    //imprime a árvore

    void imprimir() {
        this->imprimirNode(raiz, 0, 'R');
    }

    //retorna o endereço do nó com a menor chave da árvore
    NoABB<C, V>* minimo();
    //retorna o endereço do nó com a menor chave da subárvore enraizada no nó especificado
    NoABB<C, V>* minimo(NoABB<C, V>* no);

    //retorna o endereço do nó com a maior chave da árvore
    NoABB<C, V>* maximo();
    //retorna o endereço do nó com a maior chave da subárvore enraizada no nó especificado
    NoABB<C, V>* maximo(NoABB<C, V>* no);

    //retorna o endereço do nó com a chave sucessora da chave especificada
    NoABB<C, V>* sucessor(C chave);
    //retorna o endereço do nó com a chave sucessora à chave do nó especificado
    NoABB<C, V>* sucessor(NoABB<C, V>* no);

    //retorna o endereço do nó com a chave antecessora da chave especificada
    NoABB<C, V>* antecessor(C chave);
    //retorna o endereço do nó com a chave antecessora à chave do nó especificado
    NoABB<C, V>* antecessor(NoABB<C, V>* no);

    //retorna o número de nós da árvore
    int tamanho() {
        return contarNos(raiz);
    }
    //retorna true se a árvore estiver vazia
    bool vazia();

    int altura() {
        return alturaRecursiva(raiz);
    }

private:
    NoABB<C, V>* inserirNode(NoABB<C, V>* node, C chave, V valor) {
        if(node == nullptr) return new NoABB<C, V>(chave, valor);
        if(chave < node->chave) node->esq = inserirNode(node->esq, chave, valor);
        else if(chave > node->chave) node->dir = inserirNode(node->dir, chave, valor);
        else node->valor = valor;
        return node;
    }

    int contarNos(NoABB<C, V>* node) {
        if(node == nullptr) return 0;
        return 1+tamanho(node->esq)+tamanho(node->dir);
    }
    int alturaRecursiva(NoABB<C, V>* node) {
        if(node == nullptr) return 0;
        int alturaEsquerda = altura(node->esq);
        int alturaDireita = altura(node->dir);
        return alturaEsquerda>alturaDireita ? alturaEsquerda+1 : alturaEsquerda + 1;
    }

    NoABB<C, V>* fNode(NoABB<C, V>* no, C chave, V valor);
    NoABB<C, V>* removerNode(NoABB<C, V>* no, C chave);
   
    void imprimirNode(NoABB<C, V> *no, int nivel, char lado) {
        for(int i = 0; i < nivel; i++){
            std::cout << "-->";
        }
        if(no == NULL)
            std::cout << "(" << lado << ") (VAZIO)" << std::endl;
        else{
            std::cout << "(" << lado << ") (" 
                        << no->chave << ", " << no->valor << ")" << std::endl;

            imprimirNo(no->esq, nivel + 1, 'E');
            imprimirNo(no->dir, nivel + 1, 'D');
        }
    }

    NoABB<C, V>* raiz;
};