#include <stdio.h>
#include <stdlib.h> 
//1263 wxwµÄÏîÁ´ 

char pr[6];

typedef struct Node{
	int ch;
	struct Node* next;
}Node, *Linklist;

int ins_zhuzi(Linklist &H,int d){
	Linklist p;
	p->ch = d;
	
	Linklist q;
	q = H;
	while(q->next){
		q = q->next;
	}
	q->next = p;
	return 1;
}

int del_zhuzi(Linklist &H){
	
}

int pri_zhuzi(Linklist &H){
	Linklist p;
	p = H;
	p = p->next; 
	while(p->next){
		printf("%d ",p->ch);
	}
	printf("\n");
}

int main(){
	
	pr[1] = 'w';
	pr[2] = 'x';
	pr[3] = 'w';
	pr[4] = 'n';
	pr[5] = 'b';
	
	Linklist H;
	&H = (Linklist) malloc(sizeof(Node));
	H->next = NULL;
	H->ch = -1;
	
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int t = i%5;
		if (i == 0){
			i = 5;
		}
		ins_zhuzi(H,i);
	}
	pri_zhuzi(H); 
	
	return 0;
}
