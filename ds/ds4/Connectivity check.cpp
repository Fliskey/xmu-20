#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 100

typedef struct Anode{
	int Number;
	int Lenth;
	struct Anode *next;
}*Alink;

typedef struct{
	int data;
	Alink head;
}Vnode;
Vnode v[N];

void GraphCreat(int *n,int *m){
	
}

int main(){
	int n,m;
	GraphCreat(&n,&m);
	
	return 0;
}
