#include <iostream>

#define MAX_TAM 10
using namespace std;

class ListaSequencial{
    //Estrutura da lista sequencial
    private:
        int dados[MAX_TAM];
        int tam_atual;
    
    public:

    //Criação da lista sequencial vazia
    ListaSequencial(){
        tam_atual = 0;
    }

    //Verifica se a lista está vazia
    bool vazia (){
        return tam_atual == 0;
    }

    //Verifica se a lista está cheia
    bool cheia (){
        return tam_atual == MAX_TAM;
    }

    //Obter o tamanho da lista
    int tamanho(){
        return tam_atual;
    }

    //Obter o valor de um elemento em determinada posição
    void obterValor(int pos){
        if (pos <= 0 || pos > tam_atual) {
            cout << "Posição inválida!" << endl;
            return;
        }
        cout << "Valor da posicao " << pos << " = " << dados[pos-1] << endl; 
    }

    //Modificar o valor em determinada posição
    void modificarValor(int pos, int novoValor){
        if (pos < 0 || pos > tam_atual) {
            cout << "Posição inválida!" << endl;
            return;
        }
        cout << "Valor modificado de: " << dados[pos - 1] << " para " << novoValor << endl;
        dados[pos-1] = novoValor; 
    }

    //Inserir um valor em determinada posição
    void inserirValor(int pos, int novoValor) {
    if (cheia()) {
        cout << "Lista cheia!" << endl;
        return;
    }
    if (pos < 0 || pos > tam_atual + 1) {
        cout << "Posição inválida!" << endl;
        return;
    }
    for (int i = tam_atual; i >= pos; i--) {
        dados[i] = dados[i - 1];
    }
    dados[pos-1] = novoValor;
    tam_atual++;
    }

    //Remover um valor em determinada posição
    void removerElemento(int pos) {
        if (vazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        if (pos < 0 || pos >= tam_atual) {
            cout << "Posição inválida!" << endl;
            return;
        }

        cout << "Valor retirado: " << dados[pos -1] << endl;

        for (int i = pos -1; i < tam_atual - 1; i++) {
            dados[i] = dados[i + 1];
        }
        tam_atual--;
    }

    void listaCompleta (){
        cout << "Os elementos da lista são: ";
        for(int i = tam_atual - 1; i >= 0; i--){
            if(i == 0)
                cout << dados[i] << "." << endl;
            else
                cout << dados[i] << ",";
        }
    }

    
};

int main(){
    ListaSequencial lista;

    if(lista.vazia())
        cout << "Lista vazia" << endl;

    lista.inserirValor(1,13);
    lista.inserirValor(2,4);
    lista.inserirValor(3,21);

    lista.listaCompleta();
    cout << "Tamanho da lista: " << lista.tamanho() << endl;

    lista.inserirValor(1,85);
    lista.inserirValor(1,212);
    
    lista.listaCompleta();
    cout << "Tamanho da lista: " << lista.tamanho() << endl;

    lista.modificarValor(5,99);
    lista.removerElemento(4);
    lista.obterValor(1);

    lista.listaCompleta();
    cout << "Tamanho da lista: " << lista.tamanho() << endl;
 
    return 0;
}
