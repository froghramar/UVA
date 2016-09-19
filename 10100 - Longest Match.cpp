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

#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
string t, a[N], b[N], A, B;
int cases, l,r, dp[N][N], len;

bool is(char ch){
    return !(isupper(ch) or islower(ch) or isdigit(ch));
}

void init(){
    while(getline(cin,A)){
        getline(cin,B);
        l = r = 0;
        t = "";
        int L = A.length();
        for(int i = 0; i < L; i++){
            if(is(A[i])){
                if(t != "") a[l++] = t;
                t = "";
            }
            else t += A[i];
        }
        if(t != "") a[l++] = t;
        L = B.length();
        t = "";
        for(int i = 0; i < L; i++){
            if(is(B[i])){
                if(t != "") b[r++] = t;
                t = "";
            }
            else t += B[i];
        }
        if(t != "") b[r++] = t;
        for(int i = 1; i <= l; i++){
            for(int j = 1; j <= r; j++){
                if(a[i - 1] == b[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        ++cases;
        if(A == "" or B == ""){
            if(cases < 10) printf(" %d. Blank!\n",cases);
            else printf("%d. Blank!\n",cases);
        }
        else{
            if(cases < 10) printf(" %d. Length of longest match: %d\n",cases, dp[l][r]);
            else printf("%d. Length of longest match: %d\n",cases, dp[l][r]);
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
