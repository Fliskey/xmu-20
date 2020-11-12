#include <stdio.h>
//1250 奥特曼家系普查 并查集
//用了自己三年前的模板，会写的就直接copy了，顺便还整了一下格式 

int fa[100004];
int n,m;
int c;


int fi(int x){ 
	if(fa[x]==x){ //父亲是自己，找到祖宗 
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
	
	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if (fi(a) != fi(b)) //两父亲不同
		{
			fa[fi(b)] = fa[fi(a)]; // 令b的父亲是a的父亲 
		}
	}
			
	int t;
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		int a,b; 
		scanf("%d %d",&a,&b);
		if (fi(a) != fi(b))
		{
			printf("NO"); 
		}
		else
		{
			printf("YES");
		}
		printf("\n");
	}
	
	return 0;
}
