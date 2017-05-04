#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int n, m, a[N];

bool cmp(int a, int b){
	if(a % m != b % m) return a % m < b % m;
	if((a & 1) != (b & 1)) return (a & 1) > (b & 1);
	if(a & 1) return a > b;
	return a < b;
}

void init(){
	while(scanf("%d%d",&n,&m)==2 and !(!n and !m)){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		printf("%d %d\n",n,m);
		for(int i = 0; i < n; i++){
			printf("%d\n",a[i]);
		}
	}
	puts("0 0");
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	init();
	return 0;
}
