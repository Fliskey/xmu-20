#include <stdio.h>
struct{
	char id[20];
	char name[20];
	int a1;
	int a2;
	int a3;
}sd[5000];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d %d %d",&sd[i].id,&sd[i].name,&sd[i].a1,&sd[i].a2,&sd[i].a3);
	}
	double p1 = 0,p2 = 0,p3 = 0;
	int max = 0;
	int w = -1;
	for(int i=0;i<n;i++){
		p1 += sd[i].a1;
		p2 += sd[i].a2;
		p3 += sd[i].a3;
		int sum = sd[i].a1+sd[i].a2+sd[i].a3;
		if(sum > max){
			max = sum;
			w = i;
		}
	}
	p1 /= n;
	p2 /= n;
	p3 /= n;	
	printf("%.0f %.0f %.0f\n",p1,p2,p3);
	printf("%s %s %d %d %d",sd[w].id,sd[w].name,sd[w].a1,sd[w].a2,sd[w].a3) ;
	return 0;
}
