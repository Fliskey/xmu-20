#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//1050 Èý¸ö×Ö·û´®ÅÅÐò 

int scmp(const void* _a,const void* _b)
{ 
	char *a = (char*) _a;
	char *b = (char*) _b;
	return strcmp(a,b);
}

int main()
{
	char s[4][100005];
	scanf("%s %s %s",s[0],s[1],s[2]);
	qsort(s,3,sizeof(s[0]),scmp);
	printf("%s\n%s\n%s",s[0],s[1],s[2]);
	return 0;
} 
