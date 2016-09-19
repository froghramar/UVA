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

char a[102],b[102];
int a0, b0, wh, w0, w1;

void init(){
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%s",a);
        scanf("%s",b);
        a0 = b0 = wh = w0 = w1 = 0;
        for(int i = 0; a[i]; i++){
            if(a[i] == '?'){
                wh++;
                if(b[i] == '0') b0++;
            }
            else if(a[i] != b[i]){
                if(a[i] == '0') w0++, a0++;
                else w1++, b0++;
            }
            else{
                if(a[i] == '0') a0++, b0++; 
            }
        }
        if(b0 > a0 + wh) printf("Case %d: -1\n",t);
        else printf("Case %d: %d\n",t,w0 + w1 + wh - min(w0,w1));
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
