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
const int N = 10005;

int n, w[N], b[N], W, B, wb;
char s[N];

void init(){
    s[0] = 'X';
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%s",s + 1);
        n = strlen(s + 1);
        W = B = wb = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == 'B'){
                b[B++] = i;
                if(s[i - 1] == 'W') wb++;
            }
            else{
                w[W++] = i;
            }
        }
        if(B == wb) puts("IMPOSSIBLE");
        else if(W == 0 or B == 0) puts("IMPOSSIBLE");
        else if(W == 1 and B == 1) puts("1\n2 1 2");
        else if(wb == 0){
            printf("1\n%d",n);
            for(int i = 1; i <= n; i++){
                printf(" %d",i);
            }
            puts("");
        }
        else if(W == 1 or B == 1) puts("IMPOSSIBLE");
        else if(s[1] == 'W' or s[n] == 'B') puts("IMPOSSIBLE");
        else{
            puts("2");
            printf("%d %d",W,b[0]);
            for(int i = 0; i < W - 1; i++){
                printf(" %d",w[i]);
            }
            printf("\n");
            printf("%d",B);
            for(int i = 1; i < B; i++){
                printf(" %d",b[i]);
            }
            printf(" %d\n",w[W - 1]);
        }
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
