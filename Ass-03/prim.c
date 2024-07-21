#include<stdio.h>
#include<limits.h>

#define max 50
int n;
int graph[max][max];
// ={
// 	{0,2,1,0},
// 	{2,0,2,0},
// 	{1,2,0,3},
// 	{0,0,3,0}
// 	};
void findPrim(){
	int visited[n];
	int weight[n];
	int parent[n];
	int sum=0;
	for(int i=0;i<n;i++){
		visited[i]=0;
		weight[i]=INT_MAX;
	}
	visited[0]=1;
	weight[0]=0;
	int v=0;
	for(int j=0;j<n-1;j++){
		int min=INT_MAX;
		int minIndex=0;
		for(int i=0;i<n;i++){
			if(graph[v][i]>0 && visited[i]==0 && graph[v][i]<weight[i]){
				weight[i]=graph[v][i];
				parent[i]=v;
			}
			if(visited[i]==0 && weight[i]<min){
				min=weight[i];
				minIndex=i;
			}
		}
		sum+=min;
		v=minIndex;
		printf("%d %d\n",parent[v],v);
		visited[v]=1;
	}
	printf("%d",sum);
}
int main(){
	printf("Enter the number of vertex\n");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j]=0;
		}
	}
	int e;
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(int i=0;i<e;i++){
		printf("Enter the connected vertex as vertex-vertex-weight");
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		graph[a][b]=graph[b][a]=w;
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		printf("%d ",graph[i][j]);
	// 	}
	// 	printf("\n");
	// }
	findPrim();
	return 0;
}
