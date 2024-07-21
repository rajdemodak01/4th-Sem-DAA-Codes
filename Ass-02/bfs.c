#include<stdio.h>
#define max 50
int graph[max][max];
int visited[max];
int queue[max];
int f=-1;
int r=-1;
void enqueue(int n){
	if(f==-1 && r==-1)
		r=0;	
	f++;
	queue[f]=n;
}
int dequeue(){
	int val=queue[r];
	r++;
	if(r==f+1)
		f=r=-1;
	return val;
}
int isEmpty(){
	if(f==-1 && r==-1)
		return 1;
	return 0;
}
void bfs(int i,int n){
	enqueue(i);
	visited[i]=1;
	while(!isEmpty()){
		int v=dequeue();
		printf("%d ",v);
		for(int j=1;j<=n;j++){
			if(graph[v][j]==1 && visited[j]==0){
				enqueue(j);
				visited[j]=1;
			}
		}
	}
}
int main(){
	int n,v;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		visited[i]=0;
		for(int j=1;j<=n;j++)
			graph[i][j]=0;
	}
	int a,b;
	while(1){
		printf("Enter the connected vertex else enter -1 -1 for exit\n");
		scanf("%d%d",&a,&b);
		if(a==-1 && b==-1)
			break;
		graph[a][b]=1;
		graph[b][a]=1;
	}
	printf("Enter the vertex from where you want to start\n");
	scanf("%d",&v);
	bfs(v,n);
	return 0;
}
