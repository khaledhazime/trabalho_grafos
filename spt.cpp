// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <limits.h> 
#include <stdio.h> 

// Número de vértices no grafo
#define V 9 
// A função calcula o vértice com a menor distância, entre os vértices não incluídos
// no conjunto SPT ainda.
int minDistance(int dist[], bool sptSet[]) 
{ 
	// Inicia o menor valor
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 
// A função printa o vetor de distâncias armazenadas
int printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 
// Função que implementa o algoritmo de Dijkstra SPT para um grafo utilizando
// representação por matriz de adjacência
void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; // dist[i] irá armazenar a menor distância do src para i

	bool sptSet[V]; // sptSet[i] sempre será verdadeiro se i não estiver no SPT
	// Inicia todas as distâncias como infinitas e sptSet[i] como falso
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	dist[src] = 0;  // A distância do src para si mesmo é sempre 0
	// Encontra o menor caminho para todos os vértices
	for (int count = 0; count < V - 1; count++) { 
		// Pega a menor distância entre os vértices não analisados
		int u = minDistance(dist, sptSet); 
		// Marca o vértice escolhido como true
		sptSet[u] = true; 

		// Atualiza a distância dos vértices adjacentes 
		for (int v = 0; v < V; v++) 
            // Atualiza dist[v] apenas se não estiver no sptSet e se a distância for
            // menor que o valor atual de dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 
	// Printa o vetor de distância
	printSolution(dist); 
} 
int main() 
{ 
	/* Cria um grafo de exemplo */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	dijkstra(graph, 0); 

	return 0; 
} 
