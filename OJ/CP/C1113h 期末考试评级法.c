#include <stdio.h>
//C1113h ÆÚÄ©¿¼ÊÔÆÀ¼¶·¨


int main(){
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(n > 100 || n < 0)
		{
			printf("Score is error!\n");
			continue;
		}
		if(n >= 90)
		{
			printf("A\n");
			continue;
		}
		if(n >= 80)
		{
			printf("B\n");
			continue;
		}
		if(n >= 70)
		{
			printf("C\n");
			continue;
		}
		if(n >= 60)
		{
			printf("D\n");
			continue;
		}
		printf("E\n");
	}
	return 0;
}
