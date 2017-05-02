#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;

int X, Y, x, y, t;

void init(){
	while(scanf("%d",&t)==1 and t){
		scanf("%d%d",&X,&Y);
		while(t--){
			scanf("%d%d",&x,&y);
			if(x == X or y == Y) puts("divisa");
			else printf("%c%c\n", y > Y ? 'N' : 'S', x > X ? 'E' : 'O');
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
