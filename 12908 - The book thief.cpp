#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int s;

void init(){
	while(scanf("%d",&s)==1 and s){
		int n = sqrt(s);
		while(n * (n + 1) / 2 <= s) n++;
		int x = n * (n + 1) / 2 - s;
		printf("%d %d\n",x, n);
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
