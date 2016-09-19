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
const int N = 205;

int n,m,a,b,color[N];
vector <int> adj[N];
bool ok;

void dfs(int u){
    for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it){
        int v = *it;
        if(color[v] == -1){
            color[v] = 1 - color[u];
            dfs(v);
        }
        else if(color[v] == color[u]){
            ok = 0;
        }
    }
}

void init(){
    while(scanf("%d",&n)==1 and n){
        scanf("%d",&m);
        for(int i = 0; i < n; i++){
            adj[i].clear();
            color[i] = -1;
        }
        while(m--){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ok = 1;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                dfs(i);
            }
        }
        if(ok) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
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
