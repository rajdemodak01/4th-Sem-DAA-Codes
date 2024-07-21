#include<stdio.h>
#define max 50
int v,e;
int graph[max][3];

void krushkal(){
    int count=0;
    int i=0;
    int parent[v];
    int rank[v];
    for(int i=0;i<v;i++){
        parent[i]=-1;
        rank[i]=0;
    }
    int sum=0;
    while(count<v-1){
        int a=graph[i][0];
        int b=graph[i][1];
        int w=graph[i][2];
        while(parent[a]!=-1){
            a=parent[a];
        }
        while(parent[b]!=-1){
            b=parent[b];
        }
        if(a!=b){
            int v1=graph[i][0];
            int v2=graph[i][1];
            count++;
            printf("Connect vertex %d and vertex %d\n",v1,v2);
            sum+=w;
            if(rank[a]==rank[b]){
                parent[b]=a;
                rank[a]++;
            }else if(rank[a]>rank[b]){
                parent[b]=a;
            }else{
                parent[a]=b;
            }
        }
        i++;
    }
    printf("%d",sum);
}
int main(){
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    printf("Enter the numebr of edges in the graph: ");
    scanf("%d",&e);
    printf("Enter the edges in the sorted order of weight\n");
    for(int i=0;i<e;i++){
        int a,b,w;
        // printf("Enter the connected vertex as vertex-vertex-weight");
        scanf("%d%d%d",&a,&b,&w);
        graph[i][0]=a;        
        graph[i][1]=b;        
        graph[i][2]=w;  
    }
    krushkal();
    return 0;
}