#include<stdio.h>
#include <limits.h>

void  bellmanford(int v, int e, int graph[][3], int s){
    int weight[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
    }
    weight[s]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            int a=graph[j][0];
            int b=graph[j][1];
            int w=graph[j][2];
            if(weight[a] != INT_MAX && weight[a]+w<weight[b]){
                weight[b]=weight[a]+w;
            }
            if (weight[b] != INT_MAX && weight[b] + w < weight[a]) {
                weight[a] = weight[b] + w;
            }
        }
    }
    for (int j = 0; j < e; j++) {
        int a = graph[j][0];
        int b = graph[j][1];
        int w = graph[j][2];
        if (weight[a] != INT_MAX && weight[a] + w < weight[b]) {
            printf("Graph contains negative cycle reachable from the source.\n");
            return;
        }
        if (weight[b] != INT_MAX && weight[b] + w < weight[a]) {
            printf("Graph contains negative cycle reachable from the source.\n");
            return;
        }
    }
    for(int i=0;i<v;i++){
        printf("Distance between %d and %d is %d\n",s,i,weight[i]);
    }
}
int main(){
    int v,e;
    printf("Enter the number of vertex and edges: ");
    scanf("%d%d",&v,&e);
    int graph[e][3];
    for(int i=0;i<e;i++){
        int a,b,w;
        // printf("Enter the edge as vertex-vertex-edge: ");
        scanf("%d%d%d",&a,&b,&w);
        graph[i][0]=a;
        graph[i][1]=b;
        graph[i][2]=w;
    }
    int s;
    printf("Enter the starting vertex: ");
    scanf("%d",&s);
    bellmanford(v,e,graph,s);
    return 0;
}