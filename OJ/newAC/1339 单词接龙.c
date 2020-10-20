#include <stdio.h>
#include <stdlib.h>
//1339 单词接龙

int n;
char dc[30][1000];
int used[30];
int l[30];

int search(int lo, int len){
//	printf("---lo:%d len:%d---\n",lo,len);
	int bol = 0;
	int max = 0;
	for(int i = 1;i<=n;i++)
	{
	
		//是否能首尾相接 
		int cbol = 0;
		int iq = 0;
		int clen = 0;
		
	//	printf("dc[%d]:%s dc[%d]:%s\n",lo,dc[lo],i,dc[i]);
	//	printf("l[%d]:%d\n",lo,l[lo]); 
		for(int j=l[lo];j>=0 && (l[lo]-j) < l[i];j--)
		{
			if(j == 0)
			{
				if(l[lo] == l[i])
				{
					break;
				}
			}
			iq = 0;
		//	printf("\tiq:%d dc[%d][%d]:%c dc[%d][%d]:%c\n",iq,lo,j,dc[lo][j],i,iq,dc[i][iq]);
			if(!cbol & dc[lo][j] == dc[i][iq])
			{
				cbol = 1;
				for(int k=j; dc[lo][k] != '\0' && cbol; k++)
				{
				//	printf("\t\tiq:%d dc[%d][%d]:%c dc[%d][%d]:%c\n",iq,lo,k,dc[lo][k],i,iq,dc[i][iq]);
					if(cbol && dc[lo][k] != dc[i][iq])
					{
						cbol = 0;
					}
					iq++;
				}
				//存下当前比对lo串首字符下标 
				if(cbol)
				{
					clen = j;
				}
			}
		}
	//	printf("cbol:%d\n",cbol);
		
		if(used[i] != 2 && cbol)
		{
		//	printf("dc[%d]:%s dc[%d]:%s clen:%d\n",lo,dc[lo],i,dc[i],clen);
			bol = 1;
			used[i] ++;
			
			int dt = 0;
		//	printf("in\n");
			dt = search(i,len + l[i] + clen - l[lo]);
		//	printf("out\n");
			used[i] --;
			
			if(dt > max)
			{
				max = dt;
			}
		}
	}
	if(bol == 0)
	{
		return len;
	}
	return max;
}

int main()
{
	memset(used,0,sizeof(used));
	memset(l,0,sizeof(l));
	memset(dc,0,sizeof(dc));
	
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)
	{
		scanf("%s",&dc[i]);
	}
	dc[n+1][1] = dc[n+1][0];
	dc[n+1][2] = '\0'; 
	
	for(int i=1;i<=n+1;i++)
	{
		int j = 0;
		for(j=0;dc[i][j] != '\0';j++);
		l[i] = j;
	}
//	for(int i=1;i<=n+1;i++)
//	{
//		printf("%d:%d ",i,l[i]);
//	}
//	printf("\n");
	
	int ans = search(n+1,1);
	printf("%d",ans);
	
	return 0;
} 
