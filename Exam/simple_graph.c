#include<stdio.h>
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

int main(){
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
        int a,b;
        printf("Enter the edge as vertex-vertex\n");
        scanf("%d%d",&a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    printGraph();
    return 0;
}