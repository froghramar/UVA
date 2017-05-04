#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 105;

int l;
char s[N];

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%s",s);
		l = strlen(s);
		if(!strcmp(s,"1") or !strcmp(s,"4") or !strcmp(s,"78")) puts("+");
		else if(s[l - 2] == '3' and s[l - 1] == '5') puts("-");
		else if(s[0] == '9' and s[l - 1] == '4') puts("*");
		else puts("?");
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
