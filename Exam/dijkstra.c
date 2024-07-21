#include<stdio.h>
#include<limits.h>
#define max 50
int graph[max][max];
int n,e;

void printGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int s){
    int visited[n];
    int weight[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        weight[i]=INT_MAX;
    }
    
    visited[s]=1;
    weight[s]=0;
    int count=0;
    int v=s;
    int sum=0;
    while(count<n-1){
        int minIndex=-1;
        int minValue=INT_MAX;
        for(int i=0;i<n;i++){
            if(graph[v][i]>0 && visited[i]==0){
                if(sum+graph[v][i]<weight[i]){
                    weight[i]=sum+graph[v][i];
                }
            }
            if(weight[i]<minValue && visited[i]==0){
                minIndex=i;
                minValue=weight[i];
            }
        }
        printf("The distance between %d and %d is %d\n",s,minIndex,minValue);
        v=minIndex;
        sum=minValue;
        visited[minIndex]=1;
        count++;
    }
}

int main(){
    int s;
    printf("Enter the number of vertices in the graph\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;       
        }
    }
    printf("Enter the number od edges in the graph\n");
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        int a,b,w;
        // printf("Enter the edge as vertex-vertex\n");
        scanf("%d%d%d",&a,&b,&w);
        graph[a][b]=graph[b][a]=w;
    }
    printGraph();
    printf("Enter the startig vertex\n");
    scanf("%d",&s);
    dijkstra(s);
    return 0;
}