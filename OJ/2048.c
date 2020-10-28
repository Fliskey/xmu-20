#include <stdio.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//定义返回值（保证不重复即可） 
#define CANTMOVE 73205
#define FAILED 41421
#define MOVED 22141


int qp[6][6];//全局变量，共用的棋盘 

//函数声明
int Init_qp();
int Print_qp();
int Creat_qz();
int put_in();

int can_move(int);
int move(int);

//主函数 
int main(){
	srand((int)time(NULL)); 
	Init_qp();
	Print_qp();
	for(int i=1;i<=18;i++){
		Creat_qz();
		Print_qp();
	} 
	
//	while(put_in());
	
	return 0;
}


//---------------- 下面是各个函数 ----------------  


int move(int fx){
	switch(fx){
		int moved = 0;
		case UP:{
			for(int j=1;j<=4;j++)
			{
				if(qp[1][j] == 0){
					int k = 1;
					while(qp[k][j] == 0)	k++;
					if(k > 4)
					{
						continue;
					}
					moved = 1;
					for(int l=1;l<=5-k;l++){
						qp[l][j] = qp[k+l-1][j];
					}
				}
				for(int i=1;i<=3;i++)
				{
					int a,b;
					a = qp[i][j];
					b = qp[i+1][j];
					if(a == b && a!=0)
					{
						moved = 1;
						qp[i][j] *= 2;
						for(int k=i+1;k<=4;k++)
						{
							qp[k][j] = qp[k+1][j];
						}
					}
				}
			}
			return moved;
		}
		case DOWN:{
			for(int j=1;j<=4;j++)
			{
				if(qp[4][j] == 0){
					int k = 4;
					while(qp[k][j] == 0)	k--;
					if(k < 0)
					{
						continue;
					}
					moved = 1;
					for(int l=4;l>=4-k;l++){
					//	qp[l][j] = qp[];--------------------------------(写到这里 )
					}
				}
				for(int i=4;i<=2;i--)
				{
					int a,b;
					a = qp[i][j];
					b = qp[i-1][j];
					if(a == b && a!=0)
					{
						moved = 1;
						qp[i][j] *= 2;
						for(int k=i-1;k>=1;k--)
						{
							qp[k][j] = qp[k-1][j];
						}
					}
				}
			}
			return moved;
		}
		case LEFT:{
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=3;j++)
				{
					int a,b;
					a = qp[i][j];
					b = qp[i][j+1];
					if(a == b && a!=0)
					{
						moved = 1;
						qp[i][j] *= 2;
						for(int k=j+1;k<=4;k++)
						{
							qp[i][k] = qp[i][k+1];
						}
					}
				}
			}
			return moved;
		}
		case RIGHT:{
			for(int i=1;i<=4;i++)
			{
				for(int j=4;j>=2;j--)
				{
					int a,b;
					a = qp[i][j];
					b = qp[i][j-1];
					if(a == b && a!=0)
					{
						moved = 1;
						qp[i][j] *= 2;
						for(int k=j-1;k>=1;k--)
						{
							qp[i][k] = qp[i][k-1];
						}
					}
				}
			}
			return moved;
		}
	}
} 

int put_in(){
	char c = getch();
	switch(c){
		//-32 方向符
		case -32:{
			c = getch();
			int fx = 0;
			switch(c){
				case 72:{
					fx = UP;
					break;
				}
				case 80:{
					fx = DOWN;
					break;
				}
				case 75:{
					fx = LEFT; 
					break;
				}
				case 77:{
					fx = RIGHT;
					break;
				}
			}
			int re = move(fx);
			printf("%d \n",re);
			Print_qp();
			return re;
		}
	}
}

int Print_qp(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			printf("%-4d",qp[i][j]);
		} 
		printf("\n");
	}
	printf("\n");
}

int Init_qp(){
	memset(qp,0,sizeof(qp));
} 

int Creat_qz(){
	int puted = 0;
	
	int tried[6][6];
	int remain = 16;
	
	memset(tried,0,sizeof(tried));
	
	while(!puted){
		int t=rand()%16;
		int i = t/4 +1;
		int j = t%4 +1;
		
		if(remain == 0){
			printf("CAN'T PUT!\n");
			return 0;
		}
		
		if(tried[i][j]){
			continue;
		}
		else if(qp[i][j]){
			if(!tried[i][j]){
				tried[i][j] = 1;
				remain--;
			}
			continue;
		}
		else if(!qp[i][j]){
			int value = 2*(rand()%2+1);
			qp[i][j] = value;
			return 1;
		}
		else{
			printf("ERROR!\n");
		}
		
		
	}
	
}

