#include <stdio.h>
//1154 正义的开开 


int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	int tcount[1000006];
	memset(tcount,0,sizeof(tcount));
	
	for(int i=1;i<=n;i++){
		int t_in;
		scanf("%d",&t_in);
		tcount[t_in]++;
	}
	
	int t_have_data[1000006];
	memset(t_have_data,0,sizeof(t_have_data));
	int t_find = 0;
	
	for(int i=0;i<=1000000;i++){
		if(tcount[i] != 0){
			t_have_data[t_find] = i;
			t_find++;
		}
	}
	
	t_find--;
	int lastday = t_have_data[t_find];
	
	
	return 0;
}
