#include <stdio.h>
#include <assert.h>
#include <string.h>
//C1113j 信号的卷积运算

int m[104],n[104];

int main(){
	
	int ml,nl;
	memset(m,0,sizeof(m));
	memset(n,0,sizeof(n));
	
	
	scanf("%d %d",&ml,&nl);
	
	for(int i=1;i<=ml;i++){
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=nl;i++){
		scanf("%d",&n[i]);
	}
	
	for(int i=2;i<=nl+ml;i++)
	{
		int sum = 0;
		for(int j=1;j<=ml;j++)
		{
			int nx;
			nx = i-j;
			if(nx >= 0){
				sum += m[j] * n[nx];
			}
		}
		
		if(i == nl + ml)
			printf("%d",sum);
		else
			printf("%d ",sum);
		
	}
	return 0;
}
