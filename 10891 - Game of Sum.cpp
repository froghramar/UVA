#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 105;

long long n, arr[N], dp[N][N];

long long calc(int l, int r){
	if(r < l) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	long long res = -1e18;
	long long sum = 0;
	for(int i = l; i <= r; i++){
		sum += arr[i];
		long long v = sum - calc(i + 1, r);
		res = max(res,v);
	}
	sum = 0;
	for(int i = r; i >= l; i--){
		sum += arr[i];
		long long v = sum - calc(l, i - 1);
		res = max(res,v);
	}
	return dp[l][r] = res;
}

void init(){
	while(scanf("%lld",&n)==1 and n){
		for(int i = 0; i < n; i++){
			scanf("%lld",&arr[i]);
		}
		memset(dp,-1,sizeof(dp));
		long long res = calc(0, n - 1);
		printf("%lld\n",res);
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
