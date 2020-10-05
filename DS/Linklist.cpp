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

int main(){
	Linklist l;
	InitList(l);
	
	bool k = 1;
	while(k){
		printf("1：打印链表 2：插入数据 3：访问数据 4：删除数据 0:退出系统\n指令："); 
		int cmd; 
		cin>>cmd;
		switch(cmd){
			case(1):{
				if(PrintList(l))
					printf("Print Succeed\n");
				else
					printf("Print Failed\n");
				break;
			}
			case(2):{
				printf("1:在前插入 2：在后插入 3：中间插入 4:连续插入\n指令："); 
				int cmd2;
				cin>>cmd2;
				switch(cmd2){
					case(1):{
						int i;
						printf("请输入数据：");
						cin>>i;
						if(HeadInsert(l,i))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
						break;
					}
					case(2):{
						int i;
						printf("请输入数据：");
						cin>>i;
						if(TailInsert(l,i))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
						break;
					}
					case(3):{
						int i,j;
						printf("请输入位置：");
						cin>>j;
						
						printf("请输入数据：");
						cin>>i;
						
						if(iInsert(l,i,j))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
						break;
					}
					case(4):{
						int cmd24;
						printf("1:连续在前插入 2：连续在后插入 3：连续中间插入\n请输入指令：");
						cin>>cmd24;
						
						int i = 0;
						if(cmd24 == 3){
							printf("请输入插入位置："); 
							cin>>i;
						}
						
						printf("请输入插入个数：");
						int n;
						cin>>n; 
						
						printf("请输入插入的数据："); 
						
						if(nInsert(l,n,cmd24,i))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
							
						break;
					} 
				}
				break;
			}
			case(3):{
				printf("1: 数据定位 2：数据统计 3：数据读取\n请输入指令：");
				int cmd3;
				cin>>cmd3;
				switch(cmd3){
					case(1):{
						int i;
						printf("请输入数据：");
						cin>>i;
						int r = FindList(l,i);
						if(!r || r == -1)
							printf("Find Failed\n");
						else
							printf("Find Succeed\n数据位于第%d位\n",r); 
						break;
					}
					case(2):{
						int i;
						printf("请输入数据：");
						cin>>i;
						int r = CountList(l,i);
						printf("Count Succeed\n%d共出现%d次\n",i,r); 
						break;
					}
					case(3):{
						int i;
						printf("请输入位置：");
						cin>>i;
						int r = ReadList(l,i);
						if(r == intmax)
							printf("Read Failed\n");
						else
							printf("Read Succeed\n该位置上的数据为%d\n",r); 
						break;
					}
				}
				break;
			}
			case(4):{
				int i;
				printf("请输入删除的位置：");
				cin>>i;
				if(DeleteList(l,i))
					printf("Delete Succeed\n"); 
				else
					printf("Delete Failed\n");
				break;
			}
			case(0):{
				k = 0;
				break;
			}
		}
	} 
	return 0;
} 
