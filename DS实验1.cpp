#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
	int data;
	struct Node *next;
}Node, *Linklist;

int InitList(Linklist &H){
	H = (Linklist) malloc (sizeof(Node));
	if(!H){
		return 0;
	}
	H -> next = NULL;
	return 1;
}

int HeadInsertList(Linklist &H, int e){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	p -> next = H -> next;
	H -> next = p;
}

int TailInsertList(Linklist &H, int e){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	p -> next = NULL;
	Linklist tp = H;
	while(tp -> next){
		tp = tp -> next;
	}
	tp -> next = p;
	return 1;
}

int InsertList(Linklist &H, int i, int e){
	Linklist d = (Linklist) malloc (sizeof(Node));
	d -> data = e;
	Linklist p = H, q = H -> next;
	int j = 0;
	while(p && j<i-1){
		p = q;
		q = q -> next;
		j++;
	}
	if(q){
		p -> next = d;
		d -> next = q;
		return 1;
	}
	return 0;
}


int PrintList(Linklist &H){
	Linklist p = H -> next;
	if(!p){
		return 0;
	}
	while(p){
		printf("%d ",p -> data);
		p = p -> next;
	}
	printf("\n");
	return 1;
}

int DeleteNode(Linklist &H, int i){
	int j = 1;
	Linklist p = H -> next;
	Linklist q = H;
	while((p) && j<i){
		q = p;
		p = p -> next;
		j++;
	}
	if(p){
		q -> next = p -> next;
		free(p);
		return 1;
	}
	return 0;
}

int DestroyList(Linklist &H){
	Linklist p = H;
	Linklist q = H -> next;
	if(!q){
		return 0;
	}
	while(q){
		free(p);
		p = q;
		q = q -> next;
	}
	return 1;
}

int AddList(Linklist &H,int n){
	int q = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",&q);
		TailInsertList(H,q);
	}
}

int SearchList(Linklist &H,int e){
	Linklist p = H;
	int i = 0;
	while(p){
		if(p -> data == e){
			printf("%d at %d\n",e,i);
			return 1;
		}
		p = p -> next;	
		i++;	
	}
	printf("Not Found!\n");
	return 0;
}

int CountList(Linklist &H,int e){
	Linklist p = H;
	int csum = 0;
	while(p){
		if(p -> data == e){
			csum++;
		}
		p = p -> next;
	}
	printf("%d Count %d\n",e,csum);
}

int main(){

	//建立链表 （int型）
	Linklist l;
	InitList(l);
	
	//头尾插入数字
	TailInsertList(l,5);
	PrintList(l);

	HeadInsertList(l,6);
	PrintList(l);

	HeadInsertList(l,8);
	PrintList(l);

	TailInsertList(l,7);
	PrintList(l);

	TailInsertList(l,9);
	PrintList(l);

	HeadInsertList(l,10);
	PrintList(l);

	//给数字位置删除数字
	DeleteNode(l,2);
	PrintList(l);
	DeleteNode(l,3);
	PrintList(l);

	//中间插入数字
	InsertList(l,3,2);
	PrintList(l);
	InsertList(l,4,1);
	PrintList(l);

	/*
	//连续插入数字到末尾
	printf("请输入n：");
	int n=0;
	scanf("%d",&n);
	printf("请输入n个数插到链表末尾：");
	AddList(l,5);
	PrintList(l);
	*/

	//找出数字在链表中第一位位置
	SearchList(l,7);

	//统计数字在链表中出现的个数
	CountList(l,5);

	/*
	//销毁链表(beta)
	DestroyList(l);
	*/

	return 0;

}

