#include <stdio.h>

int fa[4000003];
int n,m;
int c;
int fi(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=fi(fa[x]);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int a,b;
	
	int ans = 0;
	
	for(int i=1;i<=m;i++){
		scanf("%d",&c);
		if(c==0){
			scanf("%d %d",&a,&b);
			if(fi(a)!=fi(b)){
				fa[fi(b)]=fa[fi(a)];
			}
		}
		else{
			scanf("%d %d",&a,&b);
			if(fi(a)!=fi(b)){
				ans = ans << 1;
				if(ans >= 998244353){
					ans = ans % 998244353;
				}
			}
			else{
				ans = ans << 1;
				ans += 1;
				if(ans >= 998244353){
					ans = ans % 998244353;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
