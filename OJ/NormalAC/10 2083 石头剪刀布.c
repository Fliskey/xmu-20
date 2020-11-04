#include <stdio.h>
#define Rock 1
#define Scissors 2
#define Paper 3

//2083 PP3-1: Rock Scissors Paper

int ans[5][5] = {0};

int value(char c){
	switch(c){
		case 'R':{
			return Rock;
			break;
		}
		case 'S':{
			return Scissors;
			break;
		}
		case 'P':{
			return Paper;
			break;
		}
	}
}

int main(){
	char a,b;
	ans[Rock][Rock] = 0;
	ans[Rock][Scissors] = 1;
	ans[Rock][Paper] = 2;
	
	ans[Scissors][Rock] = 2;
	ans[Scissors][Scissors] = 0;
	ans[Scissors][Paper] = 1;
	
	ans[Paper][Rock] = 1;
	ans[Paper][Scissors] = 2;
	ans[Paper][Paper] = 0;
	
	scanf("%c %c",&a,&b);
	int x = value(a);
	int y = value(b);
	printf("%d",ans[x][y]);
	
	
	return 0;
} 
