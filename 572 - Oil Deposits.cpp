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

int n,m,k;
char s[N][N];
int vis[N][N], adj[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void dfs(int x, int y){
	if(x < 1 or x > n or y < 1 or y > m or vis[x][y] or s[x][y] == '*') return;
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++){
		dfs(x + adj[i][0], y + adj[i][1]);
	}
}

void init(){
	while(scanf("%d%d",&n,&m)==2 and m){
		for(int i = 1; i <= n; i++){
			scanf("%s",s[i]+1);
		}
		memset(vis,0,sizeof(vis));
		k = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(s[i][j] == '@' and !vis[i][j]){
					k++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",k);
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
