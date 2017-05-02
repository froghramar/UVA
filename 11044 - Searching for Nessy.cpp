#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int n, m;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d",&n,&m);
		int res = (int)ceil((n - 2)/3.0) * (int)ceil((m - 2)/3.0);
		printf("%d\n",res);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	init();
	return 0;
}
