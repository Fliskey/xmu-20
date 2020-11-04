#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 10000

using namespace std;

//定义数据结构 
typedef struct{
    char data = '\0';
    int Wt;
    int Np,Nl,Nr;
}HTree;
HTree Ht[2*N];

int selected[2*N];

//声明函数
void C_HTree(int); 
void C_HuffCode(int); 
void C_HTreeSave(int);
void Select(int,int*,int*);
void PrintList(int);

int main(){
	
	freopen("HuffTreein.txt","r",stdin);
	memset(selected,0,sizeof(selected));
	printf("请输入叶子结点个数："); 
	int n;
	scanf("%d",&n);
	
	C_HTreeSave(n);
	C_HTree(n);
	
	PrintList(2*n);
	
	printf("\n 哈夫曼编码为：");
	C_HuffCode(n);
	
	return 0;
}


//函数实现 
void C_HTreeSave(int n){
	
	printf("每行输入一个字符，一个权重，用空格键隔开\n"); 
	
	for(int i=1;i<=n;i++){
		char ch;
		int x;
		printf("%d. ",i);
		cin>>ch>>x;
		printf("%c %d\n",ch,x);
		Ht[i].data = ch;
		Ht[i].Wt = x;
	}
	
	printf("\n输入成功!\n");
	PrintList(n);
}

void PrintList(int n){
	printf("\n");
    printf("asset:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",i);
	}
	printf("\n");
	
	printf("data:\t");
    for(int i=1;i<=n;i++){
    	printf("%c\t",Ht[i].data);
	}
	printf("\n");
	
	printf("Wt:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Wt);
	}
	printf("\n");
	
	printf("parent:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Np);
	}
	printf("\n");
	
	printf("leftc:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Nl);
	}
	printf("\n");
	
	printf("rightc:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Nr);
	}
	printf("\n");
	
}

void Select(int n,int *s1,int *s2){
	
	int min1 = 0x7FFFFFFF;
	int min2 = 0x7FFFFFFF;
	int min1i = 0;
	int min2i = 0;
	
	for(int i=1;i<=n-1;i++){
		if(!selected[i])
		if(Ht[i].Wt <= min1){
			min2i = min1i;
			min1i = i;
			
			min2 = min1;
			min1 = Ht[i].Wt;
		}
		else if(min2 == 0x7FFFFFFF){
			min2 = Ht[i].Wt;
			min2i = i;
		}
	}
	
//	printf("%d %d\n",min1i,min2i);
	selected[min1i] = 1;
	selected[min2i] = 1;
	
	*s1 = min1i;
	*s2 = min2i;
}

void C_HTree(int n){
    int s1 = 0;
    int s2 = 0;
    for(int i=n+1 ; i<=2*n-1 ; i++){
    	Select(i,&s1,&s2);
        Ht[i].Wt = Ht[s1].Wt+Ht[s2].Wt;
        
        Ht[i].Nl = s1;
        Ht[i].Nr = s2;
        Ht[s1].Np = Ht[s2].Np = i;
    //	PrintList(i);
    }
}

void C_HuffCode(int n){
    char code[N];	//存放当前叶子结点的哈夫曼编码
	for(int i=1 ; i<=n ; i++)
    {
        int j=i,k=0;   //从当前叶子结点开始标示
		while(Ht[j].Np>0)
        {
            if(Ht[Ht[j].Np].Nl==j)
                code[k++]='0'; 
			else
                code[k++]='1';	//右支为1
			j=Ht[j].Np;
		}
		printf("\n%c: ",Ht[i].data);    //逆向输出编码
		for(j=k-1;j>=0;j--)
            printf("%c",code[j]);
	}
}
