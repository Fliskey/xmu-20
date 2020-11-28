#include <stdio.h>
#define Max(a,b) ((a)>(b))?(a):(b)



int main()
{
	int t;
	scanf("%d",&t);
	
	for(;t>=1;t--){
		int n;

	    scanf("%d",&n);
	    {
	
	        int ar[n];
	
	        int win = 0;   //win
	        for(int i =0; i<n;i++)
	        {
	            scanf("%d", &(ar[i]));
	                if(ar[i]%2==0)
	                    win++;
	        }
	
	        (win%2!=0)?printf("Win\n"):printf("Lose\n");
	
	    }
	}
    

    return 0;
}

