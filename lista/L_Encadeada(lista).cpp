#include <iostream>

using namespace std;

class No{
    
    public:
        int conteudo;
        No *proximo;

    No(){
        conteudo = 0;
        proximo = nullptr;
    };
};

class ListaEncadeada{
    //Estrutura da lista encadeada
    private:
        No *cabeca;
        int tam_atual;
    
    public:

    //Criação da lista sequencial vazia
    ListaEncadeada(){
        cabeca = nullptr;
        tam_atual = 0;
    }

    //Verifica se a lista está vazia
    bool vazia (){
        return tam_atual == 0;
    }

    //Obter o tamanho da lista
    int tamanho(){
        return tam_atual;
    }

    //Obter o valor de um elemento em determinada posição
    void obterValor(int pos){
        if (vazia() || pos <= 0 || pos > tam_atual) {
            cout << "Operação inválida!" << endl;
            return;
        }

        No *aux = cabeca;
        for (int i = 1; i < pos; ++i) {
            aux = aux->proximo;
        }
        cout << "Valor da posicao " << pos << "=" << aux->conteudo << endl;

        return;
    }

    //Modificar o valor em determinada posição
    void modificarValor(int pos, int novoValor){
        if (vazia() ||pos <= 0 || pos > tam_atual) {
            cout << "Posição inválida!" << endl;
            return;
        }
        
        No *aux = cabeca;
        for (int i = 1; i < pos; ++i) {
            aux = aux->proximo;
        }
        int valorAntigo = aux->conteudo;
        aux->conteudo = novoValor;

        cout << "Valor modificado de " << valorAntigo << " para " << novoValor << endl;
    }

    //Inserir um valor em determinada posição
    void inserirValor(int pos, int novoValor) {
        if (pos < 1 || pos > tam_atual + 1) {
            cout << "Posição inválida!" << endl;
            return;
        }

        No *novoNo = new No();
        novoNo->conteudo = novoValor;

        if (pos == 1) {
            novoNo->proximo = cabeca;
            cabeca = novoNo;
        } else {
            No *aux = cabeca;

            for (int i = 1; i < pos - 1; ++i) {
                aux = aux->proximo;
            }
            novoNo->proximo = aux->proximo;
            aux->proximo = novoNo;
        }
        //cout << "Valor " << novoValor << " inserido na pos " << pos << endl;
        ++tam_atual;
    }

    //Remover um valor em determinada posição
    void removerElemento(int pos) {
        if (pos <= 0 || pos > tamanho()) {
            cout << "Posição inválida!" << endl;
            return;
        }
        No *removido;

        if (pos == 1) {
            removido = cabeca;
            cabeca = cabeca->proximo;
        } else {
            No *aux = cabeca;
            for (int i = 1; i < pos - 1; ++i) {
                aux = aux->proximo;
            }
            removido = aux->proximo;
            aux->proximo = removido->proximo;
        }
        cout << "Dado removido: " << removido->conteudo << endl;
        delete removido;
        --tam_atual;
    }

    void listaCompleta (){
        No *aux = cabeca;
        cout << "Lista completa:" ;
        while (aux != nullptr) {
            cout << aux->conteudo << " ";
            aux = aux->proximo;
        }
        cout << endl;
    }

    
};

int main(){
    ListaEncadeada lista;
    

    lista.inserirValor(1,20);
    lista.inserirValor(2,40);
    lista.inserirValor(3,60);

    lista.listaCompleta();
    lista.modificarValor(2,80);

    lista.inserirValor(4,100);
    lista.obterValor(2);
    lista.obterValor(4);

    lista.listaCompleta();
    lista.removerElemento(4);
    lista.removerElemento(1);
    lista.listaCompleta();

    return 0;
}
