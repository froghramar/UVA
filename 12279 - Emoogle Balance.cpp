#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int t, n, v, cnt;

void init(){
	while(scanf("%d",&n)==1 and n){
		cnt = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&v);
			cnt += !v;
		}
		printf("Case %d: %d\n", ++t, n - cnt - cnt);
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
