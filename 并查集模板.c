#include<stdio.h>

int fa[50003];
int n,m;
int c;


int fi(int x){ 
	if(fa[x]==x){ //父亲是自己 
		return x;
	}
	return fa[x]=fi(fa[x]); //找祖宗，顺便把一路上的父亲都改成祖宗
}

int main(){
	
	scanf("%d %d",&n,&m);
	
	//初始所有人的爹都是自己 
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&c);
		if (c == 1) //a b是亲戚 
		{
			scanf("%d %d",&a,&b);
			if (fi(a) != fi(b)) //两父亲不同
			{
				fa[fi(b)] = fa[fi(a)]; // b的父亲是a的父亲 
			}
		}
		else//判断亲属关系 
		{
			scanf("%d %d",&a,&b);
			if (fi(a) != fi(b))
			{
				printf("N"); 
			}
			else
			{
				printf("Y");
			}
			printf("\n");
		}
	}
	return 0;
}
