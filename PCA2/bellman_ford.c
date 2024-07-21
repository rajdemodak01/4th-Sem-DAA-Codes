#include<stdio.h>
#include<limits.h>
#define max 50
int graph[max][3];
int v,e;

void bellman_ford(int s){
    int weight[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
    }
    weight[s]=0;
    for(int j=0;j<v-1;j++){
        for(int i=0;i<e;i++){
            int a=graph[i][0];
            int b=graph[i][1];
            int w=graph[i][2];
            if(weight[a]!=INT_MAX){
                if(weight[a]+w<weight[b]){
                    weight[b]=weight[a]+w;
                }
            }
        }
    }
    for(int i=0;i<e;i++){
        int a=graph[i][0];
        int b=graph[i][1];
        int w=graph[i][2];
        if(weight[a]!=INT_MAX){
            if(weight[a]+w<weight[b]){
                printf("Error");
                return;
            }
        }
    }
    for(int i=0;i<v;i++){
        printf("Distance from %d to %d is %d\n",s,i,weight[i]);
    }
}

int main(){
    printf("Enter the number of vertex and edges\n");
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&graph[i][0],&graph[i][1],&graph[i][2]);
    }
    int s;
    printf("Enter the atarting vertex\n");
    scanf("%d",&s);
    bellman_ford(s);
    return 0;
}