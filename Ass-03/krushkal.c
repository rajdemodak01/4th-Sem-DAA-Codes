#include<stdio.h>

#define max 50
int n,v;
/*int graph[4][4]={
	{0,2,1,0},
	{2,0,2,0},
	{1,2,0,3},
	{0,0,3,0}
	};*/
	
int graph[max][3];

void findKrushkal(int n){
	for(int i=n;i>=0;i--){
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
	for(int i=0;i<n;i++){
			printf("%d %d %d \n",graph[i][0],graph[i][1],graph[i][2]);
		}
		printf("\n");
	int count=0;
	int parent[v];
	int rank[v];
	for(int i=0;i<v;i++){
		parent[i]=-1;
		rank[i]=0;
	}
	int i=0;
	int sum=0;
	while(count<v-1){
		int v1=graph[i][0];
		int v2=graph[i][1];
		int parentv1=parent[v1];
		while(parentv1!=-1){
			v1=parentv1;
			parentv1=parent[v1];	
		}
		int parentv2=parent[v2];
		while(parentv2!=-1){
			v2=parentv2;
			parentv2=parent[v2];	
		}
		/*for(int j=0;j<v;j++){
			printf("parent:%d rank:%d\n",parent[j],rank[j]);
		}*/
		if(v1!=v2){
			count++;
			int v11=graph[i][0];
			int v22=graph[i][1];
			printf("connect %d and %d\n",v11,v22);
			sum+=graph[i][2];
			if(rank[v1]==rank[v2]){
				parent[v1]=v2;
				rank[v2]++;
			}else if(rank[v1]>rank[v2]){
				parent[v2]=v1;
			}else{
				parent[v1]=v2;
			}
		}
		i++;
	}
	printf("%d",sum);
}

int main(){
	printf("Enter the number of vertex\n");
	scanf("%d",&v);
	printf("Enter the number of edges\n");
	scanf("%d",&n);
	
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j]=0;
		}
	}*/
	for(int i=0;i<n;i++){
		printf("Enter the edge as vertex-vertex-weight: \n");
		scanf("%d%d%d",&graph[i][0],&graph[i][1],&graph[i][2]);
	}
	for(int i=0;i<n;i++){
		printf("%d %d %d \n",graph[i][0],graph[i][1],graph[i][2]);
	}
	findKrushkal(n);
	return 0;
}
