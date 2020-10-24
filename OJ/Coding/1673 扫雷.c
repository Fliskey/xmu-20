#include <stdio.h>
//1673 扫雷
int mark[5][10004]; 
int suc[10004]; //标志右行有没有被确定 
int ml[5];
int mis[10004]; //标志左行有无雷 

#define MUSTB 999
#define MUSTN 666
#define DONE 233


/*总体思路：
	读入
	分别标记mis，suc 
		标3
		标2
		标1
	如果遇到矛盾的直接返回
	suc为0的进行递归，假设剩了n个，则时间复杂度n^2 

*/ 
int check(int n){
	for(int i=1 ; i<=n ; i++)
	{
		int up = i-1;
		int now = i;
		int down = i+1;
		
		int count = 1;
		
	}
}

int set(int mode,int l){
	switch(l){
		case(3):{
			int up = l-1;
			int now = l;
			int down = l+1;
			if(mis[up] != MUSTN)
				if(mis[now] != MUSTN)
				if(mis[down] != MUSTN)
			{
				mis[up] = MUSTB;
				mis[now] = MUSTB;
				mis[down] = MUSTB;
				suc[now] = DONE;
				return 1;
			}
			return 0;
		}
		case(2):{
			int up = l-1;
			int now = l;
			int down = l+1;
			
			int count_free = 0;
			
			if(mis[up] != MUSTN)	count_free++;
			if(mis[now] != MUSTN)	count_free++;
			if(mis[down] != MUSTN)	count_free++;
			
			if(count_free == 2){
				if(mis[up] != MUSTN)		mis[up] = MUSTB;
				if(mis[now] != MUSTN)		mis[now] = MUSTB;
				if(mis[down] != MUSTN)		mis[down] = MUSTB;
				suc[now] = DONE;
				return 1;
			}
			
			if(count_free < 2){
				return 0;
			}
			if(count_free > 2){
				return 1;
			}
			break;
		}
		case(1):{
			int up = l-1;
			int now = l;
			int down = l+1;
			
			int count_free = 0;
			
			if(mis[up] != MUSTN)	count_free++;
			if(mis[now] != MUSTN)	count_free++;
			if(mis[down] != MUSTN)	count_free++;
			
			if(count_free == 1){
				if(mis[up] != MUSTN)		mis[up] = MUSTB;
				if(mis[now] != MUSTN)		mis[now] = MUSTB;
				if(mis[down] != MUSTN)		mis[down] = MUSTB;
				suc[now] = DONE;
				return 1;
			}
			
			if(count_free == 0){
				return 0;
			}
			if(count_free > 1){
				return 1;
			}
			break;
		}
	}
	
	
}

int main(){
	//memset
	memset(mark,0,sizeof(mark));
	memset(ml,0,sizeof(ml));
	memset(mis,MUSTN,sizeof(mis));
	memset(suc,0,sizeof(suc)); 
	
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		mis[i] = 0;
	}
	
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		
		//按雷数标记 
		mark[a][ml[a]] = 1;
		ml[a]++;
		
		//按顺序标记 
		suc[i] = a;
		
		if(!set(a,i)){
			printf("0\n");
			break;
		}
		
	}
	return 0;
}  
