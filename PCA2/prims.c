#include<stdio.h>
#include<limits.h>
#define max 50
int graph[max][max];
int v,e;

void prim(int s){
    int visited[v];
    int distance[v];
    int parent[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    visited[s]=1;
    distance[s]=0;
    int vertex=s;
    int sum=0;
    for(int j=0;j<v-1;j++){
        int minIndex=-1;
        int minValue=INT_MAX;
        for(int i=0;i<v;i++){
            if(graph[vertex][i]!=0 && visited[i]==0 && graph[vertex][i]<distance[i]){
                distance[i]=graph[vertex][i];
                parent[i]=vertex;
            }
            if(visited[i]==0 && distance[i]<minValue){
                minValue=distance[i];
                minIndex=i;
            }
        }
        printf("Connect %d and %d\n",parent[minIndex],minIndex);
        visited[minIndex]=1;
        sum+=minValue;
        vertex=minIndex;
    }
    printf("\n");
    printf("Sum is %d",sum);
}

int main(){
    printf("Enter the number of vertex and edges\n");
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        // printf("Enter the connected vertex\n");
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        graph[a][b]=graph[b][a]=w;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    int s;
    printf("Enter the starting vertex: ");
    scanf("%d",&s);
    prim(s);
    return 0;
}