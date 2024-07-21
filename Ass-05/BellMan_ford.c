#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

void relax(int u, int v, int weight, int distance[]) {
	if (distance[v] > distance[u] + weight) {
		distance[v] = distance[u] + weight;
	}
}

void BellmanFord(int graph[][3], int V, int E, int source) {
	int distance[MAX_VERTICES];
	for (int i = 0; i < V; i++) {
		distance[i] = INT_MAX;
	}
	distance[source] = 0;
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph[j][0];
			int v = graph[j][1];
			int weight = graph[j][2];
			relax(u, v, weight, distance);
		}
	}
	for (int i = 0; i < E; i++) {
		int u = graph[i][0];
		int v = graph[i][1];
		int weight = graph[i][2];
		if (distance[u] != INT_MAX && distance[v] > distance[u] + weight) {
			printf("Graph contains negative-weight cycle\n");
			return;
		}
	}
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++) {
		printf("%d\t\t%d\n", i, distance[i]);
	}
}

int main() {
	int V, E;
	printf("Enter the number of vertices and edges: ");
	scanf("%d %d", &V, &E);

	int graph[MAX_EDGES][3]; // Adjacency list representation: [source, destination, weight]

	printf("Enter the source, destination and weight for each edge:\n");
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
	}

	int source;
	printf("Enter the source vertex: ");
	scanf("%d", &source);

	BellmanFord(graph, V, E, source);

	return 0;
}
//Bellman Ford
