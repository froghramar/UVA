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
const int N = 1000005;

long long nCr(int n, int r){
	long long factN = 1, factR = 1;
	r++;
	for(int i = 1; i < r; i++)
		factN *= n--, factR *= i;
	return factN / factR;
}

long long r[11];

void precalc(){
	for(int i = 1; i < 11; i++){
		r[i] = nCr(2*i,i)/(i+1);
	}
}

int n;
bool b;

void init(){
	precalc();
	while(scanf("%d",&n)==1){
		if(b) printf("\n");
		else b = 1;
		printf("%lld\n",r[n]);
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
