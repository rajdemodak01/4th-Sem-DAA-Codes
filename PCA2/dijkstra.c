#include<stdio.h>
#include<limits.h>
#define max 50
int graph[max][max];
int v,e;


void dijkstra(int s){
    int weight[v];
    int visited[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        visited[i]=0;
    }
    weight[s]=0;
    visited[s]=1;
    int sum=0;
    int vertex=s;
    for(int k=0;k<v-1;k++){
        int minIndex=-1;
        int minValue=INT_MAX;
        for(int i=0;i<v;i++){
            // printf("ok\n");
            if(graph[vertex][i]!=0 && visited[i]==0){
                printf("%d",graph[vertex][i]);
                if(sum+graph[vertex][i]<weight[i]){
                    weight[i]=sum+graph[vertex][i];
                }
            }
            if(visited[i]==0){
                // printf("%d",graph[v][i]);
                if(weight[i]<minValue){
                    minValue=weight[i];
                    minIndex=i;
                }
            }
        }
        printf("%d\n",minValue);
        sum+=minValue;
        visited[minIndex]=1;
        vertex=minIndex;
    }
    printf("distance..");
    for(int i=0;i<v;i++){
        printf("%d and %d = %d\n",s,i,weight[i]);
    }
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
    dijkstra(s);
    return 0;
}