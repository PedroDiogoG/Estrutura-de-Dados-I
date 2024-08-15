#include <iostream>

using namespace std;

const int TAM_MAX = 5;

class FilaSeq{

    //Estrutura da fila sequencial
    private:
        int dados[TAM_MAX];
        int inicio;
        int fim;
        int nElementos;

    public:

    //Criação da lista sequencial vazia
    FilaSeq(){
        inicio = 0;
        fim = -1;
        nElementos = 0;
    }

    //Verifica se a lista está vazia
    bool vazia (){
        if(nElementos == 0)
            return true;
        else 
            return false;
    }

    //Verifica se a lista está cheia
    bool cheia (){
    if(nElementos == TAM_MAX)
        return true;
    else 
        return false;
    }

    //Obter o tamanho da lista
    int tamanho(){
        return nElementos;
    }

    //Obter o valor de um elemento em determinada posição
    int primeiroElemento(){
        if(vazia()){
            cerr << "Erro: Fila vazia!" << endl;
            return -1;
        }
        return dados[inicio];
    }

    //Inserir elementos no final da lista
    bool inserir(int valor){
        if(cheia()){
            cerr << "Erro: Fila cheia!" << endl;
            return false;
        }

        fim = (fim + 1) % TAM_MAX; // circularidade
        dados[fim] = valor;

        nElementos++;
        return true;
    }

    //Remover o elemento do início da fila
    int remover(){
        if(vazia()){
            cerr << "Erro: Fila vazia!" << endl;
            return -1;
        }
        int valorRetirado = primeiroElemento();

        inicio = (inicio + 1) % TAM_MAX; //circularidade
        nElementos--;

        return valorRetirado;
    }

    void exibeFila(){
        if(vazia()){
            cerr << "Erro: Fila vazia!" << endl;
            return;    
        }
        cout << "Fila atual: ";
        for(int i = 0; i < nElementos; i++){
            int aux = (inicio + i) % TAM_MAX;
            cout << dados[aux];
            if(i < nElementos -1)
                cout << ",";
        }
        cout << endl;
    }
    
};

int main(){
    FilaSeq fila;

    if(fila.vazia())
        cout << "Fila Vazia." << endl;

    fila.inserir(45);
    cout << "Tamanho atual da fila: " << fila.tamanho() << endl;

    fila.inserir(65);
    fila.inserir(100);
    fila.inserir(2);
    fila.inserir(43);

    if(fila.cheia())
        cout << "Fila Cheia." << endl;
    cout << "Tamanho atual da fila: " << fila.tamanho() << endl;

    cout << "Elemento do inicio da fila: " << fila.primeiroElemento() << endl;

    fila.exibeFila();

    cout << "Elemento removido " << fila.remover() << endl;
    cout << "Elemento removido " << fila.remover() << endl;
    cout << "Elemento removido " << fila.remover() << endl;

    fila.exibeFila();

    fila.inserir(27);
    fila.inserir(13);

    fila.exibeFila();
    cout << "Tamanho da fila: " << fila.tamanho() << endl;;
    return 0;
}
