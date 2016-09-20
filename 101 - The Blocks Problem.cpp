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
const int N = 25;

int pos[N];
stack <int> s[N], tmp;

void moveOnto(int src, int dest){
    while(s[pos[src]].top() != src){
        int t = s[pos[src]].top();
        s[t].push(t);
        pos[t] = t;
        s[pos[src]].pop();
    }
    while(s[pos[dest]].top() != dest){
        int t = s[pos[dest]].top();
        s[t].push(t);
        pos[t] = t;
        s[pos[dest]].pop();
    }
    s[pos[dest]].pop();
    pos[dest] = dest;
    s[dest].push(dest);
    s[dest].push(s[pos[src]].top());
    s[pos[src]].pop();
    pos[src] = dest;
}

void moveOver(int src, int dest){
    while(s[pos[src]].top() != src){
        int t = s[pos[src]].top();
        s[t].push(t);
        pos[t] = t;
        s[pos[src]].pop();
    }
    s[pos[dest]].push(s[pos[src]].top());
    s[pos[src]].pop();
    pos[src] = pos[dest];
}

void pileOnto(int src, int dest){
    while(s[pos[dest]].top() != dest){
        int t = s[pos[dest]].top();
        s[t].push(t);
        pos[t] = t;
        s[pos[dest]].pop();
    }
    s[pos[dest]].pop();
    pos[dest] = dest;
    s[dest].push(dest);
    while(s[pos[src]].top() != src){
        tmp.push(s[pos[src]].top());
        s[pos[src]].pop();
    }
    tmp.push(s[pos[src]].top());
    s[pos[src]].pop();
    while(!tmp.empty()){
        s[pos[dest]].push(tmp.top());
        pos[tmp.top()] = pos[dest];
        tmp.pop();
    }
}

void pileOver(int src, int dest){
    while(s[pos[src]].top() != src){
        tmp.push(s[pos[src]].top());
        s[pos[src]].pop();
    }
    tmp.push(s[pos[src]].top());
    s[pos[src]].pop();
    while(!tmp.empty()){
        s[pos[dest]].push(tmp.top());
        pos[tmp.top()] = pos[dest];
        tmp.pop();
    }
}

int n, src, dest;
char cmd1[5], cmd2[5];

void init(){
    while(scanf("%d",&n)==1){
        for(int i = 0; i < n; i++){
            s[i].push(i);
            pos[i] = i;
        }
        while(scanf("%s",cmd1)==1){
            if(cmd1[0] == 'q') break;
            scanf("%d%s%d",&src,cmd2,&dest);
            if(src != dest && pos[src] != pos[dest]){
                if(cmd1[0] == 'm'){
                    if(cmd2[1] == 'n') moveOnto(src,dest);
                    else moveOver(src,dest);
                }
                else{
                    if(cmd2[1] == 'n') pileOnto(src,dest);
                    else pileOver(src,dest);
                }
            }
        }
        for(int i = 0; i < n; i++){
            printf("%d:",i);
            if(s[i].empty()) cout << endl;
            else{
                while(!s[i].empty()){
                    tmp.push(s[i].top());
                    s[i].pop();
                }
                while(!tmp.empty()){
                    printf(" %d",tmp.top());
                    tmp.pop();
                }
                printf("\n");
            }
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
