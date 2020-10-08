#include <stdio.h> 

int main(){
	int a,n,m,x;
	scanf("%d %d %d %d",&a,&n,&m,&x);
	int l = 0;
	int fbnq[300];
	fbnq[0] = 0;
	fbnq[1] = 0;
	fbnq[2] = 1;
	int fbnqc[30];
	for(int i=2;i<=29;i++){
		fbnq[i+1] = fbnq[i] + fbnq[i-1];
	}
	
	int upx = (m - (fbnq[n-2] + 1) * a) / (fbnq[n-1] - 1);
//	printf("%d ",upx);
	int on = (fbnq[x-1]+1) * a + (fbnq[x]-1) * upx;
	printf("%d",on);
	
	return 0;
}
