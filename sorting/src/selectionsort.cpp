#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;

void troca(long int &a, long int &b){
    long int aux;
    aux = a;
    a = b;
    b = aux;
}

void selectionSort(vector<long int>& vec){
    int tamanho = vec.size()-1;

    long int *menor;
    int i, j;
    for(i = 0; i < tamanho; i++){ 
        menor = &vec[i];
        for(j = i+1; j <= tamanho; j++){ 
            if(vec[j] < *menor){
                menor = &vec[j];
            }
        }

        troca(vec[i], *menor); 
    }
}    

int main(int argc, char** argv){
    
    if(argc < 2){
        cout << "Digite o arquivo para a ordenacao.\n";

        exit(1);
    }
    
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
    
    vector<long int> numeros;
    long int elemento;

    while (inputFile >> elemento){
        numeros.push_back(elemento);
    }
  
    auto start = chrono::high_resolution_clock::now();
    selectionSort(numeros);  
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double,milli> milisegundos = end - start;

    int tamanho = numeros.size();
    cout << "O caso teste com " << tamanho << " elementos foi ordenado em: " << milisegundos.count()/1000 << "segundos." << endl;

    ofstream arquivo;

    arquivo.open("resultados.txt",ios::app);

    arquivo << "O algoritmo SelectionSort demorou: " << milisegundos.count()/1000 << " segundos para ordernar o arquivo \"" << argv[1] << "\"" << endl;

    arquivo.close();

    return 0;
    
}