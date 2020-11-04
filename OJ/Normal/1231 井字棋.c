#include <stdio.h>
//1231 ¾®×ÖÆå

int main(){
	int qp[10][10];
	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&qp[i][j]);
		}
	}
	
	for(int k=1;k<=3;k++)
	{
		if (qp[k][1]==1 && qp[k][2]==1 && qp[k][3]==1)
		{
			printf("Yes");
			return 0;
		}
		else if (qp[1][k]==1 && qp[2][k]==1 && qp[3][k]==1)
		{
			printf("Yes");
			return 0;
		} 
	}
	
	//Ð±Ïò 
	if(qp[1][1]==1 && qp[2][2]==1 && qp[3][3]==1)
	{
		printf("Yes");
		return 0;
	}
	if(qp[1][3]==1 && qp[2][2]==1 && qp[3][1]==1)
	{
		printf("Yes");
		return 0;
	}

	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if (qp[i][j] == 0)
			{
				qp[i][j] = 1;
				
				//ºáÏòÊúÏò 
				for(int k=1;k<=3;k++)
				{
					if (qp[k][1]==1 && qp[k][2]==1 && qp[k][3]==1)
					{
						printf("Yes");
						return 0;
					}
					else if (qp[1][k]==1 && qp[2][k]==1 && qp[3][k]==1)
					{
						printf("Yes");
						return 0;
					} 
				}
				
				//Ð±Ïò 
				if(qp[1][1]==1 && qp[2][2]==1 && qp[3][3]==1)
				{
					printf("Yes");
					return 0;
				}
				if(qp[1][3]==1 && qp[2][2]==1 && qp[3][1]==1)
				{
					printf("Yes");
					return 0;
				}
				
				qp[i][j] = 0; 
			}
		}
	}
	
	printf("No");
	return 0;
} 
