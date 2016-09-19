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

int n,k,x,y,v[N][N];
bool vis[N][N], b, mark[N];
string str;

void dfs(int i, int j){
	if(i < 1 or i > n or j < 1 or j > n or vis[i][j] or v[i][j] != k) return;
	vis[i][j] = 1;
	dfs(i-1,j);
	dfs(i,j-1);
	dfs(i+1,j);
	dfs(i,j+1);
}

void init(){
	while(cin >> n and n){
		getline(cin,str);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				vis[i][j] = 1;
			}
			mark[i] = 1;
		}
		for(int i = 1; i < n; i++){
			getline(cin,str);
			istringstream iss(str);
			while(iss >> x >> y){
				v[x][y] = i;
				vis[x][y] = 0;
			}
		}
		k = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(vis[i][j]){
					++k;
					vis[i][j] = 0;
					v[i][j] = n;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(mark[v[i][j]]){
					k = v[i][j];
					dfs(i,j);
					mark[v[i][j]] = 0;
				}
			}
		}
		b = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(!vis[i][j]){
					b = 0;
				}
			}
		}
		if(b) printf("good\n");
		else printf("wrong\n");
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
