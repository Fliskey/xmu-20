#include <stdio.h>

int a[1050],b[1050];
char sa[1050],sb[1050];
int ans[1050];
int jcq[1050][1050];

int cf(int *x,int *y,int xl,int yl){
	
	memset(jcq,0,sizeof(jcq));
	memset(ans,0,sizeof(ans));
	int zl = xl + yl;
	
	for(int i=1 ; i<=yl ; i++){
		int k = 0;
		for(int j=zl-i ; j >= zl-i-xl+1 ; j--){
			k++;
			jcq[i][j] += y[yl-i] * x[xl-k];
			if(jcq[i][j] >= 10){
				jcq[i][j-1] += jcq[i][j]/10;
				jcq[i][j] %= 10;
			}
		}
	//	for(int j=0 ; j<zl ; j++){
	//		printf("%d ",jcq[i][j]);
	//	}
	//	printf("\n");
	}
	for(int i=zl-1;i>=0;i--){
		int sum = 0;
		for(int j = 1 ; j<= yl ; j++){
			sum += jcq[j][i];
		}
		ans[i] += sum;
		if(ans[i] >= 10){
			ans[i-1] += ans[i]/10;
			ans[i] %= 10;
		}
	}

	
	if(ans[0] != 0){
		printf("%d",ans[0]);
	}
	for(int i=1;i<=zl-1;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
}

int main(){
//	freopen("1130j.txt","w",stdout);
//	scanf("%s %s",&sa,&sb);
	while(scanf("%s %s",&sa,&sb) != EOF){
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(ans,0,sizeof(ans));
		int la = 0;
		int lb = 0;
		int i;
		
		for(i=0 ; sa[i]!='\0' ; i++){
			a[i] = sa[i] - '0';
		}
		la = i;
		
		for(i=0 ; sb[i]!='\0' ; i++){
			b[i] = sb[i] - '0';
		}
		lb = i;
		
	//	printf("la:%d lb:%d\n",la,lb);
		
		if(lb < la){
			cf(a,b,la,lb);
		}
		else{
			cf(b,a,lb,la);
		}
		
		
	}
	
	
	return 0;
}
