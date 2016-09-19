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

using namespace std;
const int N = 16;

int d[] = {-1,0,1};
int r,c,n,x,y,dp[N][1 << N];

bool valid(int i, int j){ return i > -1 and j > - 1 and i < r and j < c;}

int calc(int p, int mask){
	if(p == n) return (__builtin_popcount(mask) == 1);
	if(dp[p][mask] != -1) return dp[p][mask];
	int res = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			int src = i * c + j;
			if((mask & (1 << src)) == 0) continue;
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 3; l++){
					if(k == 1 and l == 1) continue;
					if(valid(i+2*d[k],j+2*d[l])){
						int dest = (i + d[k] * 2) * c + (j + d[l]*2);
						int mid = (i + d[k]) * c + (j + d[l]);
						if((mask & (1 << dest)) == 0 and (mask & (1 << mid)) != 0){
							res += calc(p + 1, mask - (1 << src) - (1 << mid) + (1 << dest));
						}
					}
				}
			}
		}
	}
	return dp[p][mask] = res;
}

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		memset(dp,-1,sizeof(dp));
		scanf("%d%d%d",&r,&c,&n);
		int mask = 0;
		for(int i = 0; i < n ; i++){
			scanf("%d%d",&x,&y);
			int ind = (x - 1) * c + (y - 1);
			mask += 1 << ind;
		}
		int res = calc(1,mask);
		printf("Case %d: %d\n",t,res);
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
