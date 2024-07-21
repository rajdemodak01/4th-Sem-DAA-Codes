#include<stdio.h>
#define max 50
int v,e;

void krushkal(int graph[e][3]){
    int weight[v];
    int parent[v];
    int rank[v];
    for(int i=0;i<v;i++){
        parent[i]=-1;
        rank[i]=0;
    }
    for(int i=v;i>=0;i--){
        for(int j=1;j<i;j++){
            if(graph[j][2]<graph[j-1][2]){
                int temp[3];
                temp[0]=graph[j][0];
                temp[1]=graph[j][1];
                temp[2]=graph[j][2];
                graph[j][0]=graph[j-1][0];
                graph[j][1]=graph[j-1][1];
                graph[j][2]=graph[j-1][2];
                graph[j-1][0]=temp[0];
                graph[j-1][1]=temp[1];
                graph[j-1][2]=temp[2];
            }
        }
    }
    // for(int i=0;i<e;i++){
    //     printf("%d %d %d\n",graph[i][0],graph[i][1],graph[i][2]);
    // }
    int count=0;
    int i=0;
    int sum=0;
    while(count<v-1){
        int v1=graph[i][0];
        int v2=graph[i][1];

        int parentv1=v1;
        while(parent[parentv1]!=-1){
            parentv1=parent[parentv1];
        }

        int parentv2=v2;
        while(parent[parentv2]!=-1){
            parentv2=parent[parentv2];
        }
        if(parentv1!=parentv2){
            sum+=graph[i][2];
            count++;
            printf("Connect %d and %d",v1,v2);
            if(rank[parentv1]==rank[parentv2]){
                parent[parentv1]=parentv2;
                rank[parentv2]++;
            }else if(rank[parentv1]<rank[parentv2]){
                parent[parentv1]=parentv2;
            }else{
                parent[parentv2]=parentv1;
            }
        }
        i++;
    }
    printf("\n%d",sum);
}   

int main(){
    printf("Enter the number of vertex and edges in the graph\n");
    scanf("%d%d",&v,&e);
    int graph[e][3];
    for(int i=0;i<e;i++){
        // printf("Enter the connected vertex as vertex vertex weight");
        scanf("%d%d%d",&graph[i][0],&graph[i][1],&graph[i][2]);
    }
    krushkal(graph);
    return 0;
}