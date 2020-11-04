#include <stdio.h>
//this is my first time to write notes in English
//please forgive me

//global
int max_x = 0;
int max_y = 0;

int min_x = 5000;
int min_y = 5000;

int map[304][5004];//save the answer
int basicmap[54][54];

int setblock(int x,int y){
	
	//define the map's edge
	if(min_y > y){
		min_y = y;
	}
	if(min_x > x){
		min_x = x;
	}
	if(x+6 > max_x){
		max_x = x+6;
	}
	if(y+5 > max_y){
		max_y = y+5;
	}
	
	//middle part
	map[x][y] = '+';
	map[x+4][y] = '+';
	map[x][y+3] = '+';
	map[x+4][y+3] = '+';
	for(int i=1;i<=3;i++){
		map[x+i][y] = '-';
		map[x+i][y+3] = '-';
	}
	for(int j=1;j<=2;j++){
		map[x][y+j] = '|';
		map[x+4][y+j] = '|';
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=2;j++){
			map[x+i][y+j] = ' ';
		}
	}
	
	//edge part
	map[x+1][y+4] = '/';
	map[x+5][y+4] = '/';
	map[x+5][y+1] = '/';
	map[x+2][y+5] = '+';
	map[x+6][y+5] = '+';
	map[x+6][y+2] = '+';
	for(int i=3;i<=5;i++){
		map[x+i][y+5] = '-';
	}
	for(int j=3;j<=4;j++){
		map[x+6][y+j] = '|';
	}
	for(int i=2;i<=4;i++){
		map[x+i][y+4] = ' ';
	}
	for(int j=2;j<=3;j++){
		map[x+5][y+j] = ' ';
	}
}

int main(){
	
	memset(map,0,sizeof(map));
    int m,n;
    scanf("%d %d",&m,&n); 
    
    
    for(int i=1 ; i<=m ; i++){					//scanfmap
        for(int j=1 ; j<=n ; j++){
            scanf("%d",&basicmap[i][j]);
        }
    }

    for(int i=1 ; i<=m ; i++){
        const int ux= 2*(m-i), uy= 2*(m-i);		//start coordinate
        int x=0, y=0;   
        
        for(int j=1 ; j<=n ; j++){
			y = 0;								//init y coordinate
            if(j != 1)							//move along x axis
				x += 4;
			
            int num = basicmap[i][j];			//get the number of blocks here
            
            for(int k=1 ; k<=num ; k++){
                
				if(k != 1)						//move along y axis
					y += 3;
				
            //	printf("%d %d\n",ux+x,uy+y);	//here is a debug sentence
            	
            	setblock(ux+x,uy+y);			//give start coordinate and set blocks
            }
        }
    }
    
    for(int i=max_y ; i>=min_y ; i--){			//Printmap
    	for(int j=min_x ; j<=max_x ; j++){
    		if(map[j][i] == 0){
    			printf(".");
			}
			else{
				printf("%c",map[j][i]);
			}
		}
		printf("\n");
	}

    return 0;
}