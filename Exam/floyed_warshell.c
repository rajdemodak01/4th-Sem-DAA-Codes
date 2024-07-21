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
                if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(graph[i][j]==INT_MAX){
                printf("INF ");
            }else{
                printf("%d ",graph[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    printf("Enter the connecting vertuices\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j){
                graph[i][j]=0;
            }else{
                graph[i][j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<e;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        graph[a][b]=w;
    }
    floyed_warshell();
    return 0;
}