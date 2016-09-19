/******************************************************************************
*  ▄██████████▄  ▀█████████▄   ▀██████████▄    ▄████████████▄   ▄██████████▄  *
* ▀▀███    ███▀    ███    ███    ███     ▀██▄  ▀███▀    ▀███▀   █▀    ▄███▀   *
*   ███            ███           ███      ██    ███      ███         ▄███▀    *
*  ▄███▄▄▄██▀    ▄███▄▄▄██▀      ███      ██▀   ███      ███        ▄███▀     *
* ▀▀███▀▀▀██▄   ▀▀███▀▀▀██▄     ▄███▄▄▄▄▄██▀    ███      ███       ▄███▀      *
*   ███            ███         ▀▀███▀▀▀▀▀██▄    ███      ███      ▄███▀       *
*   ███            ███    ███    ███     ███   ▄███▄    ▄███▄    ▄███▀    ▄█  *
* ▄▄████▀        ▄█████████▀    ▄███     ███▄  ▀████████████▀   ▀██████████▀  *
*                                                                             *
*                        *Don't limit your challenges, challenge your limits. *
******************************************************************************/

#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 100490
#define MOD 10000019

using namespace std;
const int N = 1000005;

bool P[MAX];

long long bigmod(long long n, long long p) {
    if(p == 0) return 1;
    else if(p & 1) return (n * bigmod(n, p - 1)) % MOD;
    else {
        long long x = bigmod(n, p / 2);
        return (x * x) % MOD;
    }
}

void seive(){
	memset(P,true,sizeof(P));
	P[1] = false;
	for(int i=2; i<=317; i++)
		if(P[i])
			for(int j=i*i; j<=MAX; j+=i)
				P[j] = false;
}

void init(){
	seive();
	int tc,T,n,t;
	long long res,cnt,divi;
	bool possible;
	scanf("%d",&T);
	for(int tc=1; tc <= T; tc++){
		scanf("%d%d",&n,&t);
		res = 1;
		possible = false;
		for(int m=2; m<=n; m++)
			if(P[m]){
				cnt = 0, divi = m;
				while(divi <= n){
					cnt += n/divi;
					divi *= m;
				}
				if(cnt >= t) possible = true;
				res = (res*bigmod(m,cnt/t))%MOD;
			}
		if(possible) printf("Case %d: %lld\n",tc,res);
		else printf("Case %d: -1\n",tc);
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
