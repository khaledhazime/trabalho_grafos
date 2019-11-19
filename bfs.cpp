#include<iostream> 
#include <list> 
  
using namespace std; 
  

// A classe Graph representa um grafo direcionado usando representação de lista de adjacência
class Graph 
{ 
    int V; // Número de vértices
	list<int> *adj; // Ponteiro para um vetor que contém listas de adjacência    
    
public: 
 	Graph(int V); // Construtor
	void addEdge(int v, int w); //Função para adicionar uma aresta ao grafo 
	void BFS(int s); // Passagem do BFS por uma dada fonte s
};
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Adiciona w para a lista de v
} 
void Graph::BFS(int s) 
{ 
    // Marca todos os vértices com não visitados
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
    // Cria uma fila para BFS
    list<int> queue; 

    // Marca o nodo atual como visitado e o retira da fila
    visited[s] = true; 
    queue.push_back(s); 

    // Utiliza i para receber todos os elementos adjacentes ao vértice
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Retira o vértice da fila e printa
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
   
        //Recebe todos os vértices adjacentes ao que acabou de sair da fila
        //Se um adjacente não foi visitado, marca como visitado e o retira da fila.
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
int main() 
{ 
    // Cria o grafo do diagrama
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Busca em BFS"
			" (começando do vértice 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 