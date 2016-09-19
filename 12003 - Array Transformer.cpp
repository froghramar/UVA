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
const int N = 550;

struct Ele{
    int val, pos;
}block[N][N];

int n, m, u, l, r, val, p, i, j, x, y, a[N*N];

bool cmp(Ele A, Ele B) {
    return A.val < B.val;
}

int frequency(int l, int r) {
	int cnt, lp, rp, m, tl, tr;
    cnt = 0;
    tl = l;
    tr = r;
    while(l%N && l <= r) {
        if(a[l] < val) cnt++;
        l++;
    }
    while((r+1)%N && l <= r) {
        if(a[r] < val) cnt++;
        r--;
    }
    if(l > r) return cnt;
    lp = l/N, rp = r/N, val--;
    while(lp <= rp) {
        l = 0, r = N-1;
        while(l < r) {
            m = (l+r+1)>>1;
            if(block[lp][m].val <= val) l = m;
            else r = m-1;
        }
        if(block[lp][l].val > val) l--;
        cnt += l+1;
        lp++;
    }
    return cnt;
}

void init(){
    scanf("%d%d%d", &n, &m, &u);
    for(i = 0, j = (n-1)/N; i < N; i++)
        block[j][i].val = INT_MAX, block[j][i].pos = -1;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        block[i/N][i%N].val = a[i];
        block[i/N][i%N].pos = i;
    }
    for(i = (n-1)/N; i >= 0; i--)
        sort(block[i], block[i]+N, cmp);
    while(m--) {
        scanf("%d%d%d%d",&l,&r,&val,&p);
        l--, r--, p--;
        x = frequency(l, r);
        y = (long long)x*u/(r-l+1);
        x = p/N;
        for(i = 0; block[x][i].pos != p; i++);
        while(i < N){
            block[x][i].val = block[x][i+1].val;
            block[x][i].pos = block[x][i+1].pos;
            i++;
        }
        for(i = N-2; i >= 0 && block[x][i].val > y; i--) {
            block[x][i+1].val = block[x][i].val;
            block[x][i+1].pos = block[x][i].pos;
        }
        block[x][i+1].val = y;
        block[x][i+1].pos = p;
        a[p] = y;
    }
    for(i = 0; i < n; i++){
        printf("%d\n", a[i]);
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
