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
const int N = 1005;

string linea,lineb;
int a,b;
int dp[N][N];

void init(){
	ios_base :: sync_with_stdio(false); cin.tie(0);
	while(getline(cin,linea) && getline(cin,lineb)){
		a  = linea.length();
		b = lineb.length();
		for(int i = 0; i < a; i++)
			for(int j = 0; j< b; j++){
				if(linea[i] == lineb[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
				else dp[i + 1][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);
			}
		printf("%d\n",dp[a][b]);
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
