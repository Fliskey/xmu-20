#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <windows.h> 
using namespace std;

/*test data
(Please copy datas below to test the program)

7
11
1 2 19
2 3 5
2 4 7
3 4 3
1 5 14
2 5 12
4 5 8
4 6 21
6 7 27
1 7 18
5 7 16

*/

#define NMAX 100
int G[NMAX][NMAX];
int visited[NMAX];
int prim_value[NMAX];
int father[NMAX];

void CreatG_ND_W(int*,int*);
void PrintGV(int);
void PrimInit();
void Prim_V(int,int);
void Prim(int,int);

int main(){
	freopen("Prim_in.txt","r",stdin);
    int n,m;
    CreatG_ND_W(&n,&m);
    PrintGV(n);
    Prim(1,n);
    return 0;
}


void CreatG_ND_W(int *n,int *m){
	printf("Please enter the number of vertexs: ");
	scanf("%d",n);
	printf("%d\n",*n);
	
	printf("Please enter the number of edges: "); 
	scanf("%d",m);
	printf("%d\n",*m);
	
	printf("Each group includes start, end, weight ;split by block:\n");
	
	for(int i=1;i<=*m;i++){
		printf("%d. ",i);
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		printf("%d %d %d\n",a,b,w);
		G[a][b] = w;
		G[b][a] = w;
	}
}

void PrintGV(int n){
	printf("\nGragh adjacency matrix:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%-4d",G[i][j]);
		}
		printf("\n");
	}
}

void PrimInit(){
	memset(visited,0,sizeof(visited));
	memset(father,0,sizeof(father));
	memset(prim_value,0,sizeof(prim_value));
}

void Prim_V(int start,int n){
	visited[start] = 1;
	int min = 0;
	int mini = 0;
	for(int i=1; i<=n; i++){
		if(visited[i] == 0)
		if(G[start][i]){
			father[i] = start;
			prim_value[i] = G[start][i];
			
			if(min == 0){
				min = G[start][i];
				mini = i;
			}
			else if(G[start][i] < min){
				min = G[start][i];
				mini = i;
			}
		}
	}
	if(min == 0){
		return;
	}
	else{
		prim_value[mini] = min;
		Prim_V(mini,n);
	}
	
}

void Prim(int start,int n){
	PrimInit();
	visited[start] = 1;
    Prim_V(start,n);
    printf("\nMinimum Spanning Tree:\n");
    
    printf("Node Number:  ");
    for(int i=1;i<=n;i++){
    	printf("%-5d",i);
	}
	printf("\n");
	
	printf("Father Number:") ;
    for(int i=1;i<=n;i++){
    	printf("%-5d",father[i]);
	}
	printf("\n");
	
	printf("Weight:       ");
	for(int i=1;i<=n;i++){
		printf("%-5d",prim_value[i]);
	} 
	printf("\n");
} 
