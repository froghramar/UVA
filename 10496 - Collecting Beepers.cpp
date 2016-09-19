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

struct P{
	int x,y;
};

int n,m,q;
int a,b;

int calc(vector <P> points, int size, int x, int y){
	if(size==1) return abs(a - points[0].x) + abs(b - points[0].y) + abs(x - points[0].x) + abs(y - points[0].y);
	int minimum = INT_MAX;
	for(int i=0; i<size; i++){
		vector <P> temp = points;
		temp.erase(temp.begin()+i);
		int t = calc(temp,size-1,points[i].x,points[i].y) + abs(x - points[i].x) + abs(y - points[i].y);
		if(t<minimum) minimum = t;
	}
	return minimum;
}

void init(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&n,&m,&a,&b,&q);
		vector <P> points(q);
		for(int i=0; i<q; i++)
			scanf("%d%d",&points[i].x,&points[i].y);
		printf("The shortest path has length %d\n",calc(points,q,a,b));
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
