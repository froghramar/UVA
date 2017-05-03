#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

char s[20];
int k, res;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%s%d",s,&k);
		if(s[0] == 'd') res += k;
		else printf("%d\n",res);
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
