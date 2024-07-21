#include<stdio.h>
#include <limits.h>
#define max 50
int graph[max][max];
int v,e;
void dijkstra(int source){
    int weight[v];
    int visited[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        visited[i]=0;
    }
    int s=source;
    weight[s]=0;
    visited[s]=1;
    int sum=0;
    for(int i=0;i<e-2;i++){
        int minIndex=0;
        int min_value=INT_MAX;
        // for(int j=0;i<v;j++){
        //     if(visited[j]==0){
        //         minIndex=j;
        //         min_value=weight[j];
        //         break;
        //     }
        // }
        for(int j=0;j<v;j++){
            if(graph[s][j]!=0 && visited[j]==0){
                if((sum+graph[s][j])<weight[j]){
                    weight[j]=sum+graph[s][j];
                }
            }
            if(visited[j]==0 && weight[j]<min_value){
                minIndex=j;
                min_value=weight[j];
            }
        }
        sum=min_value;
        printf("The distance between %d and %d is %d\n",source,minIndex,min_value);
        // printf("%d",sum);
        visited[minIndex]=1;
        s=minIndex;
    }
}
int main(){
    printf("Enter the number of vertices and edges\n");
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        printf("Enter the joining vertex and weight as vertex-vertex-weight\n");
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        graph[a][b]=graph[b][a]=w;
    }
    printf("Enter the source\n");
    int s;
    scanf("%d",&s);
    dijkstra(s);
    return 0;
}