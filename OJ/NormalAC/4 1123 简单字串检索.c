#include <stdio.h>
//1123 ¼òµ¥×Ö´®¼ìË÷

int main(){
	char s1[5004];
	char s2[5004];
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	
	
	while(scanf("%s %s",&s1,&s2) != EOF)
	{
		for(int i=0 ; s2[i]!='\0' ; i++)
		{
			int right = 0;
			
			if (s2[i] == s1[0])
			{
				right = 1;
				for(int j=0 ; s1[j]!='\0'; j++)
				{
					if(s1[j] != s2[i+j]){
						right = 0;
						break;
					}
				}
				
				if (right == 1)
				{
					printf("%d ",i);
				}
			}
			
		}
		printf("-1\n");
		
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
	}
	
	return 0;
} 
