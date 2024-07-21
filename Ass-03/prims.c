/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){	
	int v;
	int e;
	printf("Enter how many vertices are there ---------> ");
	scanf("%d", &v);
	printf("Enter how many edges are there ------------> ");
	scanf("%d", &e);
	
	int r, c;
	r = c = v + 1;
	int *arr[c];
	for(int i = 0; i< r; i++){
		arr[i] = (int *)malloc(sizeof(int) * r);
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			arr[i][j] = 0;
		}
	}
	
	while(e--){
		printf("Enter the connected pair of vertices and weight of the edge -----> ");
		int v1, v2, w;
		scanf("%d%d%d", &v1, &v2, &w);
		arr[v1][v2] = arr[v2][v1] = w;
	}
	
	for(int i = 1; i < r; i++){
		for(int j = 1; j < c; j++){
			printf("%d ", arr[i][j]); 
		}
		printf("\n");
	}
	
	
	
	return 0;
}*/


#include <limits.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>


int V;

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
				min = key[v], min_index = v;
	return min_index;
}

int printMST(int parent[], int *graph[V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i]+ 1, i + 1,graph[i][parent[i]]);
}

void primMST(int *graph[V])
{
	int parent[V];
	int key[V];

	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	
	printMST(parent, graph);
}

int main()
{
	int e;
	printf("Enter how many vertices are there ---------> ");
	scanf("%d", &V);
	printf("Enter how many edges are there ------------> ");
	scanf("%d", &e);
	int v = V;
	int r, c;
	r = c = v;
	int *graph[c];
	for(int i = 0; i< r; i++){
		graph[i] = (int *)malloc(sizeof(int) * r);
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			graph[i][j] = 0;
		}
	}
	
	while(e--){
		printf("Enter the connected pair of vertices and weight of the edge -----> ");
		int v1, v2, w;
		scanf("%d%d%d", &v1, &v2, &w);
		graph[v1 - 1][v2 - 1] = graph[v2 - 1][v1 - 1] = w;
	}
	
	primMST(graph);
	return 0;
}
