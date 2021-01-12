#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define NMAX 100
using namespace std;

int G[NMAX][NMAX];//最大支持NMAX个顶点的邻接矩阵 
int visited[NMAX];
int vqueue[NMAX];
int vqhead = 0;
int vqtail = 0;

int deleted[NMAX] = {0};
int deleted_l = 0; 

//函数定义 
void DFS(int,int);
void DFSbegin(int,int);
void BFS(int,int);
void BFSbegin(int,int);

void CreatG_ND_NW(int*,int*);//无向图不带权重 
void CreatG_D_W(int*,int*);//有向图带权重 

void PrintGV(int);
void DelGV(int,int);
void ApplyGV(int*);
void AddGV_ND_NW();

void Can_in(int,int);
void Can_out(int,int);

void test1(); 
void test2();




int main(){
	
	test1();
	test2();
	
	return 0;
}


//函数实现部分 

void test1(){
	printf("\n\n-------- 无向图全自动示例 --------\n\n");
	freopen("G1in.txt","r",stdin);
	memset(G,0,sizeof(G));
	
	int n,m;
	CreatG_ND_NW(&n,&m);
	
	PrintGV(n);
	
	
	printf("请输入要删除点的编号：");
	int del;
	scanf("%d",&del);
	printf("%d\n",del);
	DelGV(n,del);
	printf("删除成功，已释放该编号！\n");
	PrintGV(n);
	
	ApplyGV(&n);
	PrintGV(n);
	
	AddGV_ND_NW();
	PrintGV(n);
	
	printf("请输入需要查找点的编号：");
	int ques;
	scanf("%d",&ques);
	printf("%d\n该点与这些点相通：",ques);
	Can_in(n,ques);
	printf("\n"); 
	
	printf("\n请输入搜索的起始点编号：");
	int Sstart;
	scanf("%d",&Sstart); 
	printf("%d",Sstart);
	printf("\n深度优先搜索遍历顺序："); 
	DFSbegin(Sstart,n);
	
	printf("\n广度优先搜索遍历顺序："); 
	BFSbegin(Sstart,n);
	
	fclose(stdin); 
	return;
} 

void test2(){
	printf("\n\n-------- 有向带权图全自动示例 --------\n\n");
	freopen("G2in.txt","r",stdin);
	memset(G,0,sizeof(G));
	
	int n,m;
	CreatG_D_W(&n,&m);
	
	PrintGV(n); 
	
	printf("\n请输入搜索的起始点编号：");
	int Sstart;
	scanf("%d",&Sstart); 
	printf("%d",Sstart);
	printf("\n深度优先搜索遍历顺序："); 
	DFSbegin(Sstart,n);
	
	printf("\n广度优先搜索遍历顺序："); 
	BFSbegin(Sstart,n);
	
	fclose(stdin); 
	return;
}



void PrintGV(int n){
	printf("\n邻接表：\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	return;
}

void DelGV(int n,int e){
	for(int i=1;i<=n;i++){
		G[i][e] = 0;
		G[e][i] = 0;
	}
	deleted[deleted_l] = e;
	deleted_l++;
	return;
} 

void ApplyGV(int *n){
	int newl;
	if(deleted_l == 0){
		newl = ++*n;
	}
	else{
		deleted_l--;
		newl = deleted[deleted_l];
		deleted[deleted_l] = 0;
	} 
	printf("申请新结点编号成功，编号为：%d\n",newl);
	return;
}

void AddGV_ND_NW(){
	int x,y;
	printf("请输入要增加边的两个点：");
	scanf("%d %d",&x,&y);
	printf("%d %d\n",x,y);
	
	G[x][y] = 1;
	G[y][x] = 1;
}



void Can_in(int n,int e){
	for(int i=1;i<=n;i++){
		if(G[i][e]){
			printf("%d ",i);
		}
	}
}

void Can_out(int n,int e){
	for(int i=1;i<=n;i++){
		if(G[e][i]){
			printf("%d ",i);
		}
	}
}



void CreatG_D_W(int *n,int *m){
	printf("请输入顶点个数：");
	scanf("%d",n);
	printf("%d\n",*n);
	
	printf("请输入弧的条数："); 
	scanf("%d",m);
	printf("%d\n",*m);
	
	printf("每组输入起始点、终点、权重，以空格隔开：\n");
	
	for(int i=1;i<=*m;i++){
		printf("%d. ",i);
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		printf("%d %d %d\n",a,b,w);
		G[a][b] = w;
	}
}

void CreatG_ND_NW(int *n,int *m){
	printf("请输入顶点个数：");
	scanf("%d",n);
	printf("%d\n",*n);
	
	printf("请输入边的条数："); 
	scanf("%d",m);
	printf("%d\n",*m);
	
	printf("每组输入两个点，以空格隔开：\n");
	
	for(int i=1;i<=*m;i++){
		printf("%d. ",i);
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d\n",a,b);
		G[a][b] = 1;
		G[b][a] = 1;
	}
	return;
}



void DFSbegin(int s,int n){
	memset(visited,0,sizeof(visited));
	printf("%d ",s);
	DFS(s,n);
}

void DFS(int s,int n){
	visited[s] = 1;
	
	int i;
	for(i=1;i<=n;i++){
		if(G[s][i]){
			if(!visited[i]){
				visited[i] = 1;
				printf("%d(%d) ",i,G[s][i]);
				DFS(i,n);
			}
		}
	}
	if(i>n){
		return;
	}
}

void BFSbegin(int s,int n){
	memset(vqueue,0,sizeof(vqueue)); 
	memset(visited,0,sizeof(visited));
	vqhead = 1;
	vqtail = 1;	
	vqueue[vqtail] = s;
	visited[s] = 1;
	vqtail++;
	printf("%d ",s);
	BFS(s,n);
} 

void BFS(int s,int n){
	if(vqhead > n){
		return;
	}
	vqhead++;
	
	int i;
	for(i=1;i<=n;i++){
		if(G[s][i]){
			if(!visited[i]){
				visited[i] = 1;
				vqueue[vqtail] = i;
				printf("%d(%d) ",i,G[s][i]);
				vqtail++;
			}
		}
	}
	int head = vqueue[vqhead];
	BFS(head,n);
}

