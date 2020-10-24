#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int fa[200004];
int n,m;

int fi(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=fi(fa[x]);
}

struct points{
	int x;
	int y;
	int value;
}point[200004];

bool rule(points x,points y){
	return x.value<y.value;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>point[i].x;
		cin>>point[i].y;
		cin>>point[i].value;
	}
	sort(point+1,point+m+1,rule);
	long k=1,sum=0,i=0;
	int a,b; 
	while(k<n&&i<=m){
		i++;
		a=fi(point[i].x);
		b=fi(point[i].y);
		if(fa[a]!=fa[b]){
			fa[a]=b;
			k++;
			sum+=point[i].value;
		}
	}
	cout<<sum;
	return 0;
}
