#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

// Recebe a Matriz de Adj e a transforma em uma Lista de Adj.
vector<vector<pair<int, int>>> ListaAdj(const vector<vector<int>>& matrizAdj) {
    int V = matrizAdj.size();  
    vector<vector<pair<int, int>>> listaAdj(V);  // Lista de adjacência

    // Percorre a matriz e adiciona a lista os adjacentes. 
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (matrizAdj[i][j] != 0) {  
                listaAdj[i].push_back({j, matrizAdj[i][j]});  // Adiciona par (vértice, peso)
            }
        }
    }
    
    // Exibir a lista de adjacência
    cout << "Lista de Adjacencia: " << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertice " << i << ": ";
        for (const auto& vizinho : listaAdj[i]) {
            cout << "(" << vizinho.first << ", " << vizinho.second << "),";
        }
        cout << endl;
    }
    
    return listaAdj;
}

void bfs(const vector<vector<pair<int, int>>>& listaAdj, int s, int t) {
    int V = listaAdj.size(); 
    vector<bool> visitado(V, false);  // Verificar os vértices visitados
    vector<int> parente(V, -1);   // Armazenar os vertice anterior

    queue<int> fila;
   
    // O vertice inicial ja começa visitado
    visitado[s] = true;
    fila.push(s);

    bool encontrou = false;

    while (!fila.empty()) {
        int atual = fila.front();  // Auxiliar indica os vizinhos do vertice atual para visitar
        fila.pop();

        // Percorre todos os vizinhos
        for (const auto& vizinho : listaAdj[atual]) {
            int adjacente = vizinho.first; 

            if (!visitado[adjacente]) {
                visitado[adjacente] = true;
                parente[adjacente] = atual; 
                fila.push(adjacente);

                // Se encontrar o alvo
                if (adjacente == t) {
                    encontrou = true;
                    break;
                }
            }
        }

        if (encontrou) break;
    }

    // Reconstruir o caminho se o vértice t foi encontrado
    if (!encontrou) {
        cout << "Não há caminho entre os vértices " << s << " e " << t << endl;
    } else {

        stack<int> caminho;
        int v = t;          // Volta o caminho apartir dos parentes do alvo
        while(v != -1){
            caminho.push(v);
            v = parente[v];
        }
        
        // Imprimir o caminho
        cout << "Caminho entre " << s << " e " << t << ": ";
        while (!caminho.empty()) {
            cout << caminho.top();
            caminho.pop();
            if (!caminho.empty()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

void dfs(const vector<vector<pair<int, int>>>& listaAdj, int s, int t) {
    int V = listaAdj.size();  
    vector<bool> visitado(V, false);  
    vector<int> parente(V, -1); 

    stack<int> pilha;
    
    // O vertice inicial ja começa visitado
    pilha.push(s);
    visitado[s] = true;

    bool encontrou = false;

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();

        // Se encontramos o vértice de destino, paramos
        if (atual == t) {
            encontrou = true;
            break;
        }

        // Percorre todos os vizinhos do vértice atual
        for (const auto& vizinho : listaAdj[atual]) {
            int vizinhoVertice = vizinho.first; // Obtem o vértice vizinho
            if (!visitado[vizinhoVertice]) {
                visitado[vizinhoVertice] = true;
                parente[vizinhoVertice] = atual;  // Armazena o pai
                pilha.push(vizinhoVertice);
            }
        }
    }

    // Reconstruir o caminho se encontrou o alvo t
    if (!encontrou) {
        cout << "Não há caminho entre os vértices " << s << " e " << t << endl;
    } else {
        stack<int> caminho;
        for (int v = t; v != -1; v = parente[v]) {
            caminho.push(v);  // Volta de t até s usando os parentes
        }

        // Imprimir o caminho
        cout << "Caminho entre " << s << " e " << t << ": ";
        while (!caminho.empty()) {
            cout << caminho.top();
            caminho.pop();
            if (!caminho.empty()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char** argv){
    
    if(argc < 2){
        cout << "Digite o arquivo de entrada.\n";

        exit(1);
    }
    
    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    int V;  // Qtd de vértices
    inputFile >> V;

    vector<vector<int>> matriz(V,vector<int>(V));

    cout << "Matriz de Adjacencia: " << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            inputFile >> matriz[i][j];
            cout << matriz[i][j] <<  " "; 
        }
        cout << endl;
    }

    inputFile.close();

    vector<vector<pair<int, int>>> lista = ListaAdj(matriz);
    cout << "\nDigite o vertice de inicio e de fim: ";
    int s,t; // start, destino
    
    cin >> s >> t;

    cout << "Algoritmo BFS: " << endl;
    bfs(lista, s, t);

    cout << "Algoritmo DFS: " << endl;
    dfs(lista, s, t);

   
}