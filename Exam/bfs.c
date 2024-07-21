#include<stdio.h>
#include <stdbool.h>

#define max 50
int graph[max][max];
int n,e;
int queue[max];
int f=-1,r=-1;

void enqueue(int val){
    if(f==-1 && r==-1){
        r++;
    }
    f++;
    queue[f]=val;
}
int dequeue(){
    int val=queue[r];
    r++;
    if(r==f+1){
        f=r=-1;
    }
    return val;
}
bool isEmpty(){
    if(f==-1 && r==-1){
        return true;
    }
    return false;
}

void printGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void bfs(int start,int visited[]){
    enqueue(start);
    visited[start]=1;
    while(!isEmpty()){
        int val=dequeue();
        printf("%d ",val);
        for(int i=0;i<n;i++){
            if(graph[val][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    int start;
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
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printGraph();
    printf("Enter the starting vertex\n");
    scanf("%d",&start);
    bfs(start,visited);
    return 0;
}