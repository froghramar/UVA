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

int king,queen,go;

bool jumped(int a, int b, int c){
    int arr[] = {a, b, c};
    sort(arr,arr+3);
    return arr[1] == b;
}

void init(){
    while(scanf("%d%d%d",&king,&queen,&go)==3){
        int kx = king / 8, ky = king % 8;
        int qx = queen / 8, qy = queen % 8;
        int mx = go / 8, my = go % 8;
        if(kx == qx and ky == qy) puts("Illegal state");
        else if(qx != mx and qy != my) puts("Illegal move");
        else if(qx == mx and qy == my) puts("Illegal move");
        else if(qx == mx and qx == kx and jumped(qy, ky, my)) puts("Illegal move");
        else if(qy == my and qy == ky and jumped(qx, kx, mx)) puts("Illegal move");
        else if(mx == kx and abs(my - ky) < 2) puts("Move not allowed");
        else if(my == ky and abs(mx - kx) < 2) puts("Move not allowed");
        else if(king == 0 and go == 9) puts("Stop");
        else if(king == 56 and go == 49) puts("Stop");
        else if(king == 63 and go == 54) puts("Stop");
        else if(king == 7 and go == 14) puts("Stop");
        else puts("Continue");
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
