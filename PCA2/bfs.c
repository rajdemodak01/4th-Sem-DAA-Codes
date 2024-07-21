#include<stdio.h>
#define max 50
int graph[max][max];
int v,e;
int queue[max];
int f=-1,r=-1;
void enqueue(int value){
    if(f==-1 && r==-1){
        f++;
        r++;
        queue[f]=value;
    }else{
        f++;
        queue[f]=value;
    }
}
int dequeue(){
    int value=queue[r];
    r++;
    if(r==f+1){
        f=r=-1;
    }
    return value;
}
int isEmpty(){
    if(f==-1 && r==-1){
        return 1;
    }
    return 0;
}

void bfs(int s){
    int visited[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
    visited[s]=1;
    enqueue(s);
    while(!isEmpty()){
        // printf("ok");
        int vertex=dequeue();
        printf("%d ",vertex);
        for(int i=0;i<v;i++){
            if(graph[vertex][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }
        // for(int i=r;i<=f;i++){
        //     printf("%d ",queue[i]);
        // }
        // printf("\n");
    }
}

int main(){
    printf("Enter the number of vertex and edges\n");
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        printf("Enter the connected vertex\n");
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    // printf("%d%d",v,e);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    int s;
    printf("Enter the starting point of the traversal\n");
    scanf("%d",&s);
    bfs(s);
    return 0;
}