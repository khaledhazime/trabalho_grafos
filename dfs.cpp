// C++ program to print DFS traversal from 
// a given vertex in a given graph 
#include<iostream> 
#include<list> 
using namespace std; 


// A classe Graph representa um grafo direcionado usando representação de lista de adjacência

class Graph 
{ 
	int V; // Número de vértices
	list<int> *adj; // Ponteiro para um vetor que contém listas de adjacência 
	void DFSUtil(int v, bool visited[]); // Função recursiva utilizada pelo DFS

public: 
	Graph(int V); // Construtor
	void addEdge(int v, int w); //Função para adicionar uma aresta ao grafo 
	void DFS(int v); // Passagem do DFS para os vértices alcansáveis de V
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

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	visited[v] = true; // Marca o nodo atual como visitado
	cout << v << " ";  // Printa o nodo

	list<int>::iterator i; // Repete para todos os vértices adjacentes ao vértice v 
z	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

void Graph::DFS(int v) // Passagem do DFS para os vértices alcansáveis de V utilizando a recursividade
{ 
	// Marca todos os vértices como não visitados
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 
	DFSUtil(v, visited); // Chama a função recursiva para printar a passagem de DFS
} 

int main() 
{  
	Graph g(4); // Cria o grafo do diagrama
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Busca em DFS"
			" (começando do vértice 2) \n"; 
	g.DFS(2); 

	return 0; 
} 
