#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
const int intmax=2147483647;
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}Node, *Linklist;



int InitList(Linklist &H){
	H = (Linklist) malloc (sizeof(Node));
	if(!H){
		return 0;
	} 
	H -> next = NULL;
	return 1;
} 

int HeadInsert(Linklist &H,int e){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	p -> next = H -> next;
	H -> next = p;
	return 1;
}

int TailInsert(Linklist &H,int e){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	Linklist q = H;
	while(q -> next){
		q = q -> next;
	}
	p -> next = q -> next;
	q -> next = p;
	return 1;
}

int iInsert(Linklist &H,int e,int i){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	Linklist q = H;
	int j = 0;
	while(j<i-1 && q){
		q = q -> next;
		j++;
	}
	if(q){
		p -> next = q -> next;
		q -> next = p;
		return 1;
	}
	return 0;
}

int nInsert(Linklist &H,int n,int mode,int i){
	int tsum = 0;
	for(int j=1; j<=n; j++){
		int e;
		cin>>e;
		switch(mode){
			case(1):{
				tsum += HeadInsert(H,e);
				break;
			}
			case(2):{
				tsum += TailInsert(H,e);
				break;
			}
			case(3):{
				tsum += iInsert(H,e,i+j-1);
				break;
			}
		}
	}
	if(tsum == n)
		return 1;
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

int DeleteList(Linklist &H,int i){
	Linklist p = H;
	Linklist q = p -> next;
	int j = 0;
	while(q && j<i-1){
		p = q;
		q = q -> next;
		j++;
	}
	if(q){
		p -> next = q -> next;
		free(q);
		return 1;
	}
	return 0;
}

int FindList(Linklist &H,int e){
	Linklist p = H;
	int i = 0;
	while(p){
		if(p -> data == e){
			return i;
		}
		p = p -> next;
		i++;
	}
	return -1;
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
	return csum;
}

int ReadList(Linklist &H,int i){
	Linklist p = H;
	int j = 0;
	while(j<i){
		if(!p){
			return intmax;
		}
		p = p -> next;
		j++;
	}
	return p -> data;
}


struct Index{
	Linklist Head;
	Linklist First;
	Linklist Last;
	int ltd;
//	int hdata = FindList(Head,1);
	int len;
}Idx[500];

int Index_number = -1;

int IndexPage[500];

int PrintIndex(Index I){
	Linklist H = I.Head;
	int i = 0;
	Linklist p = H -> next;
	if(!p){
		return 0;
	}
	while(i<I.len){
		printf("%d ",p -> data);
		p = p -> next;
		i++;
	}
	printf("\n");
	return 1;
}

int IndexInsert(Linklist &H, Linklist &I, int i){
	Linklist q = H;
	for(int j=1; j<=i; j++){
		q = q->next;
	}
	Linklist p = I;
	while(p->next){
		p = p->next;
	}
	p->next = q;
	return 1;
}

int IndexNew(Linklist &H, Index &I, int i){
	Linklist q = H;
	for(int j=1; j<=i; j++){
		q = q->next;
	}
	I.First = q;
	I.Last = q;
	I.len = 1; 
	return 1;
}


int IndexCheck(Linklist &H,int n){
	Index_number = -1;
	int max = -2100000000;
	
	for(int i = 1; i <= n; i++){
		int ai = ReadList(H,i);
		if(ai > max){
			Index_number++;
			max = ai;
			Idx[ Index_number ].ltd = i;
			IndexPage[ Index_number ] = i;
			InitList( Idx[ Index_number ].Head );
			IndexNew(H, Idx[ Index_number ],i);
		}
		else{
			Idx[ Index_number ].Last = Idx[ Index_number ].Last -> next;
			Idx[ Index_number ].len++;
		}
	}
}

int main(){
	
	//测试样例：
	//20
	//3 2 1 6 5 4 8 7 13 12 11 10 9 17 16 15 14 20 19 18 
	//10
	
	Linklist H;
	InitList(H);
	
	cout<<"请输入数据个数："; 
	int n;
	cin>>n;
	
	cout<<"请输入数据："; 
	for(int i=1; i<=n; i++){
		int a;
		cin>>a;
		TailInsert(H,a);
	}
	
	cout<<"当前数据："; 
	PrintList(H);
	
	cout<<"正在建立索引表...请稍后"<<endl<<endl;
	IndexCheck(H,n);
	cout<<"索引表建立完毕！"<<endl<<endl;
	
	cout<<"索引表页码：" ; 
	
	for(int i=0;i<=Index_number;i++){
		cout<<Idx[i].ltd<<" ";
	}
	
  //索引做好了，查找未完工
  
	cout<<"请输入待查找的数：";
	int en;
	cin>>en;
	
  
	
	
	
	
  //以下星号中间的内容是上次课写的，请直接忽略。
	/*
	
  
//	cout<<"请输入建立索引位置个数:" ;
//	int x;
//	cin>>x;
	
//	int nx = n/x;
	
	//建立索引
  
	for(int i=0;i<x;i++){
		InitList(Idx[i].Head);
		if(i != x-1) 
			Idx[i].len = nx;
		else
			Idx[i].len = n%x + nx;
		int w = i*nx+1;	
		printf("%d ",w);
		IndexInsert(H,Idx[i].Head,w);
	}
	printf("\n");
	
	//测试输出索引所指的内容 
	printf("第一块内容：");PrintIndex(Idx[0]);
	printf("第二块内容：");PrintIndex(Idx[1]);
	printf("第三块内容：");PrintIndex(Idx[2]);
  
	//能做到稀疏索引表，暂时无法做到分级查找
	//计划加入根据索引表hdata的值进行排序的功能 
	//后续会去补上分级查找算法的内容 
  
	*/
	
	
	
	return 0;
}
