#include<stdio.h>
#include<limits.h>
#define max 50
int graph[max][max];
int v,e;

int min(int a,int b){
    if(a<=b){
        return a;
    }else{
        return b;
    }
}
void floyed_warshell(){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    printf("Shortest Path Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (graph[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the number of vertex and edges in the graph: ");
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j){
                graph[i][j]=0;
            }else{
                graph[i][j]=INT_MAX;
            }
        }
    }
        // printf("ok"); 
    for(int i=0;i<e;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        // printf("ok");
        graph[a][b]=w;
        // printf("ok");
    }
    floyed_warshell();
    return 0;
}