#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

map <string,string> lan = {
	{"HELLO", "ENGLISH"},
	{"HOLA", "SPANISH"},
	{"HALLO", "GERMAN"},
	{"BONJOUR", "FRENCH"},
	{"CIAO", "ITALIAN"},
	{"ZDRAVSTVUJTE", "RUSSIAN"}
};

int t;
string s, res;

void init(){
	while(cin >> s and s != "#"){
		printf("Case %d: %s\n", ++t, lan.count(s) ? lan[s].c_str() : "UNKNOWN");
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
