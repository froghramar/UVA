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

map <string,set <int> > mp;
char ch;
string line, temp;
int cnt = 1;

void init(){
    ios_base :: sync_with_stdio(false); cin.tie(0);
    cin >> ch;
    cin.ignore();
    while(getline(cin, line)){
        int len = line.length();
        temp = "";
        for(int i = 0; i < len; i++){
            if(line[i] == '.' or line[i] == ' ' or line[i] == ','){
                if(temp[0] == ch) mp[temp].insert(cnt);
                temp = "";
            }
            else temp += line[i];
        }
        if(temp != "" and temp[0] == ch) mp[temp].insert(cnt);
        cnt++;
    }
    for(map <string,set <int> > :: iterator it = mp.begin(); it != mp.end(); it++){
        printf("%s",it->first.c_str());
        for(set <int> :: iterator it1 = it->second.begin(); it1 != it->second.end(); it1++){
            printf(" %d",*it1);
        }
        printf("\n");
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
