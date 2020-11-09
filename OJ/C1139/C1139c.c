#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int scmp(const void* _a,const void* _b)
{ 
    char *a = (char*) _a;
    char *b = (char*) _b;
    return strcmp(a,b);
}

int main()
{
    char s[10004][104];
    memset(s,0,sizeof(s));
    int k = 0;
    while(gets(s[k++]));
    qsort(s,k-1,sizeof(s[0]),scmp);
    for(int i=0;i<k-1;i++){
        printf("%s\n",s[i]);
    }
    return 0;
}
