#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 26;

int n;
long long cat[N],sch[N];

void precalc(){
	cat[0] = 1;
	for(int i = 1; i < N; i++){
		cat[i] = 0;
		for(int j = 0; j < i; j++){
			cat[i] += cat[j] * cat[i-j-1];
		}
	}
	sch[0] = sch[1] = 1;
	for(int i = 2; i < N; i++){
		sch[i] = ((6*i - 3) * sch[i-1] - (i - 2) * sch[i-2]) / (i + 1);
	}
}

void init(){
	precalc();
	while(scanf("%d",&n)==1){
		n--;
		printf("%lld\n",sch[n] - cat[n]);
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
