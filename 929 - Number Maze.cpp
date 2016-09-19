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
const int N = 1005;

struct T{
	int x,y,v;
	T(int _x, int _y, int _v){ x = _x, y = _y, v = _v;}
	bool operator <(const T &t) const{ return v > t.v;}
};

int n,m,a[N][N];
bool r[N][N];

void init(){
	int T1;
	scanf("%d",&T1);
	for(int t=1; t<=T1; t++){
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d",&a[i][j]);
			}
		}
		memset(r,0,sizeof(r));
		priority_queue <T> pq;
		pq.push(T(n-1,m-1,a[n-1][m-1]));
		while(!pq.empty()){
			T tp = pq.top();
			pq.pop();
			if(tp.x == 0 and tp.y == 0){
				printf("%d\n",tp.v);
				break;
			}
			int x = tp.x, y = tp.y;
			if(r[x][y]) continue;
			r[x][y] = 1;
			if(x > 0) pq.push(T(x-1,y,a[x-1][y]+tp.v));
			if(y > 0) pq.push(T(x,y-1,a[x][y-1]+tp.v));
			if(x < n-1) pq.push(T(x+1,y,a[x+1][y]+tp.v));
			if(y < m-1) pq.push(T(x,y+1,a[x][y+1]+tp.v));
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
