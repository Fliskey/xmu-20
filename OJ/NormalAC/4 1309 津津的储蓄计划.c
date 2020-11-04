#include <stdio.h> 

int y=0,m=0,c=0;
int main(){
	for(int i=1;i<=12;i++){
		int a;
		scanf("%d",&a);
		if((300+y-a)<0)
			if(m==0)
				m=i;
		y=y+300-a;
		while(y>100){
			y-=100;
			c+=100;
		}
	} 
	if(m!=0)
		printf("-%d",m);
	else{
		c *= 1.2;
		c += y;
		printf("%d",c);
	}
		
	return 0;
}
