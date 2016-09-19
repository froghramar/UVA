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

double dp[(1 << 16)];
int n, x[16], y[16];

double dist(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double calc(int mask) {
    if(mask == (1 << n) - 1) return 0;
    if(dp[mask] != 0) return dp[mask];
    double ans = 2e9;
    int p1, p2;
    for(p1 = 0; p1 < n; p1++) {
        if(!(1 & (mask >> p1))) break;
    }
    for(p2 = p1 + 1; p2 < n; p2++) {
        if (!(1 & (mask >> p2))) {
            ans = min(ans, dist(p1, p2) + calc(mask | (1 << p1) | (1 << p2)));
        }
    }
    return dp[mask] = ans;
}

char s[21];
int t;

void init(){
    while (scanf("%d", &n), n) {
        n *= 2;
        for(int i = 0; i < n; i++) {
            scanf("%s %d %d", s, &x[i], &y[i]);
        }
        memset(dp, 0, sizeof(dp));
        double ans = calc(0);
        printf("Case %d: %.2lf\n", ++t, ans);
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
