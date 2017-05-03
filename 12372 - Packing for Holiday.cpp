#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int L, W, H;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d%d",&L,&W,&H);
		if(L > 20 or W > 20 or H > 20) printf("Case %d: bad\n",t);
		else printf("Case %d: good\n",t);
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
