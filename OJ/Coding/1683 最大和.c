#include <stdio.h>
//1683 最大和
//预感会TLE 

int main(){
	int n;
	int n[104];
	int z[104];
	while(scanf("%d",&n) != EOF)
	{
		for(int i=1 ; i<=n ; i++)
		{
			scanf("%d",&n[i]);
			
			if(n[i] > 0)
				z[i] = 1;
			else
				z[i] = 0;
		}
		
		
	}
	return 0;
} 
