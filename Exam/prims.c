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

void prims(){
    int weight[n];
    int visited[n];
    int parent[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
        visited[i]=0;
        parent[i]=-1;
    }
    int count=0;
    weight[0]=0;
    visited[0]=1;
    int v=0;
    int sum=0;
    while(count<n-1){
        int minIndex=-1;
        int minValue=INT_MAX;
        for(int i=0;i<n;i++){
            if(graph[v][i]>0 && visited[i]==0){
                if(weight[i]>graph[v][i]){
                    weight[i]=graph[v][i];
                    parent[i]=v;
                }
            }
            if(weight[i]<minValue && visited[i]==0){
                minIndex=i;
                minValue=weight[i];
            }
        }
        printf("minValue=%d\n",minValue);
        sum+=minValue;
        visited[minIndex]=1;
        printf("Connect %d and %d\n",minIndex,parent[minIndex]);
        v=minIndex;
        count++;
    }
    printf("sum=%d",sum);
}

int main(){
    printf("Enter the number of vertices in the graph\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;       
        }
    }
    printf("Enter the number of edges in the graph\n");
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        int a,b,w;
        // printf("Enter the edge as vertex-vertex-weight\n");
        scanf("%d%d%d",&a,&b,&w);
        graph[a][b]=graph[b][a]=w;
    }
    printGraph();
    prims();
    return 0;
}