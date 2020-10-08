#include <stdio.h>
int a[101]={0},b[101]={0},s[202]={0};
char ca[101] = {0},cb[101] = {0};

int ct[202][202] = {0};
int ans[202] = {0};

int la,lb;
int main(){
	while(scanf("%s %s",ca,cb) != EOF){
		la = 0;
		lb = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(ct,0,sizeof(ct));
		memset(ans,0,sizeof(ans));
		for(int i=0;ca[i] != '\0';i++){
			a[i] = ca[i] - 48;
			la++;
		}
		for(int i=0;cb[i] != '\0';i++){
			b[i] = cb[i] - 48;
			lb++;
		}
		for(int i=1;i<=la;i++){
			for(int j=1;j<=lb;j++){
				int k = a[i] * b[j];
				ct[i][i-1+j-1] += k;
				if(ct[i][i-1+j-1] > 10){
					ct[i][i-1+j] += ct[i][i-1+j-1]/10;
					ct[i][i-1+j-1] %= 10;
				}
				
			}
		}
		int ll=0;
		for(int i=0;i<=202;i++){
			int sum = 0;
			for(int j=1;j<=la;j++){
				sum += ct[j][i];
			}
			ans[i] += sum;
			if(ans[i]>10){
				ans[i+1] += ans[i]/10;
				ans[i] %= 10;
			}
			if(ans[i]!= 0){
				ll = i;
			}
		}
		for(int i=ll;i>=0;i--){
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}
