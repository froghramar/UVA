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
const int N = 105;

char s[N][N];
int n,vis[N][N],k,adj[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x, int y){
	if(x < 1 or x > n or y < 1 or y > n or vis[x][y] or s[x][y] == '.') return;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		dfs(x + adj[i][0], y + adj[i][1]);
	}
}

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			scanf("%s",s[i]+1);
		}
		memset(vis,0,sizeof(vis));
		k = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(s[i][j] == 'x' and !vis[i][j]){
					k++;
					dfs(i,j);
				}
			}
		}
		printf("Case %d: %d\n",t,k);
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
