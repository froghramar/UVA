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
#define MOD 1000000007

using namespace std;
const int N = 1000005;

struct Matrix{
    int x,y,mat[2][2];
    Matrix(int a, int b){
        x = a, y =b;
    }
    Matrix multiply(Matrix mul){
        Matrix ret(x,mul.y);
        for(int i=0; i<ret.x; i++)
            for(int j=0; j<ret.y; j++){
                ret.mat[i][j] = 0;
                for(int k=0; k<y; k++)
                    ret.mat[i][j] = (ret.mat[i][j] + ((long long)mat[i][k]*mul.mat[k][j]))%MOD;
            }
        return ret;
    }
    void showMatrix(){
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++) printf("%d ",mat[i][j]);
            printf("\n");
        }
    }
};

Matrix A(2,2),I(2,2),H(2,1);

Matrix matrix(int n){
    if(n==0) return I;
    Matrix mat = matrix(n/2);
    if(n & 1) return A.multiply(mat.multiply(mat));
    return mat.multiply(mat);
}

void init(){
	int T,d,v;
    scanf("%d",&T);
    A.mat[0][1] = 0, A.mat[1][0] = A.mat[1][1] = 1;
    I.mat[0][0] = I.mat[1][1] = 1;
    I.mat[0][1] = I.mat[1][0] = 0;
    H.mat[1][0] = 1;
    for(int t=1; t<=T; t++){
        scanf("%d%d",&d,&v);
        if(d==0) printf("Case %d: 1\n",t);
        else if(d==1) printf("Case %d: %d\n",t,(v+1)%MOD);
        else if(v==1) printf("Case %d: -1\n",t);
        else{
            H.mat[0][0] = v;
            A.mat[0][0] = v-1;
            Matrix m = matrix(d).multiply(H);
            printf("Case %d: %d\n",t,m.mat[1][0]);
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
