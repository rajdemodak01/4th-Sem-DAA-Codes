#include<stdio.h>
#include<limits.h>
#define max 50
int v,e;
int graph[max][3];

void bellman_ford(int s){
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
            if(weight[a]!=INT_MAX && weight[a]+w<weight[b]){
                weight[b]=weight[a]+w;
            }
        }
    }
    for(int j=0;j<e;j++){
        int a=graph[j][0];
        int b=graph[j][0];
        int w=graph[j][0];
        if(weight[a]!=INT_MAX && weight[a]+w<weight[b]){
            printf("There exist a negetive dge cycle");
            return;
        }
    }
    for(int i=0;i<v;i++){
        printf("The distance from %d to %d is %d\n",s,i,weight[i]);
    }
}

int main(){
    int s;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    printf("Enter the numebr of edges in the graph: ");
    scanf("%d",&e);
    printf("Enter the edges in the order of weight\n");
    for(int i=0;i<e;i++){
        int a,b,w;
        // printf("Enter the connected vertex as vertex-vertex-weight");
        scanf("%d%d%d",&a,&b,&w);
        graph[i][0]=a;        
        graph[i][1]=b;        
        graph[i][2]=w;  
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&s);
    bellman_ford(s);
    return 0;
}