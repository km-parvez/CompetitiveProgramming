// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MX  1000006
using namespace std;
using ll = long long;

int par[MX];
int element[MX];
int find(int x){
	if(par[x]==x){
		return x;
	}
	else{
		return par[x] = find(par[x]);
	}
}
void join(int a,int b){
	int ra= find(a);
	int rb= find(b);
	if(ra!=rb){
		par[rb]=ra;
	}
}
void makeset(int n){
/*	for(int i=0; i<n; i++) {
		par[element[i]]=element[i];
	}*/
	for(int i=0; i<=n; i++) {
		par[i]=i;
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        
    
        cout<<'\n';
    
    return 0;
}