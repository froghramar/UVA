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

int n, x;
unsigned long long int dp[30][160];

unsigned long long int gcd(unsigned long long int n, unsigned long long int m) {
	return m == 0 ? n : gcd(m, n % m);
}

unsigned long long int probability(int n, int score) {
	if(n == 0) return score >= x;
	if(dp[n][score] != -1) return dp[n][score];
	unsigned long long int ans = 0;
	for(int i = 1; i <= 6; i++) {
		ans += probability(n - 1, score + i);
	}
	return dp[n][score] = ans;
}

void init(){
	unsigned long long int occurence, total;
	while(scanf("%d %d", &n, &x), n || x) {
		memset(dp, -1, sizeof(dp));
		total = pow(6, n);
		occurence = probability(n, 0);
		unsigned long long int divider = gcd(total, occurence);
		occurence = occurence / divider;
		total = total / divider;
		if(occurence == 0) printf("0\n");
		else if(total == 1) printf("%llu\n", occurence);
		else printf("%llu/%llu\n", occurence, total);
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
