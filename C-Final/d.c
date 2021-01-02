#include <stdio.h>
#include <string.h>

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char line[200];
	char nfile[200];
	memset(line,0,sizeof(line));
	memset(nfile,0,sizeof(nfile));
	int min = 200;
	int max = 0;
	int fail = 0;
	while(gets(line)){
		int l = 0;
		l+=3;
		int last = line[l]-'0';
		l+=2;
		int ip = 0;
		do{
			ip*=10;
			ip+=line[l]-'0';
			l++;
		}while(line[l]!=',');
		
		if(ip < min){
			min = ip;
		}
		l++;
		while(line[l]!=0){
			if(nfile[ip]){
				if(nfile[ip] == line[l]){
					ip++;
					l++;
				}
				else{
					break;
					fail = 1;
				}
			}
			else{
				nfile[ip] = line[l];
				ip++;
				l++;	
			}
		}
		if(fail){
			break;
		}
		if(max < ip){
			max = ip;
		}
		memset(line,0,sizeof(line));
		if(last){
			break;
		}
	}
	
	if(min != 0){
		fail = 1;
	}
	
	for(int i=0;i<max;i++){
		if(nfile[i] == 0){
			fail = 1;
			break;
		}
	}
	
	if(fail){
		printf("0");
		return 0;
	}
	
	printf("%d\n",max-min);
	for(int i=0;i<max;i++){
		printf("%c",nfile[i]);
	}
	
	return 0;
} 
