#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;

void insertionSort(vector<long int>& numeros){
    int tamanho = numeros.size();
    int aux, i, j;

    for(i = 1; i < tamanho; i++){ 
        aux = numeros[i];

        for(j = i-1; j >= 0; j--){ 
            if(numeros[j] > aux){
                numeros[j+1] = numeros[j];
            }else{
                break;
            }
        }
        numeros[j+1] = aux;
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
    insertionSort(numeros);  
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double,milli> milisegundos = end - start;

    int tamanho = numeros.size();
    cout << "O caso teste com " << tamanho << " elementos foi ordenado em: " << milisegundos.count()/1000 << "segundos." << endl;

    ofstream arquivo;

    arquivo.open("resultados.txt",ios::app);

    arquivo << "O algoritmo InsertionSort demorou: " << milisegundos.count()/1000 << " segundos para ordernar o arquivo \"" << argv[1] << "\"" << endl;
    
    arquivo.close();


    return 0;
    
}