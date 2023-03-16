// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX 505

using namespace std;
using ll = long long;
int inf = 1000000007;
vector<int> g[MAXX];
bool visited[MAXX];
bool visited2[MAXX];
int level[MAXX];
int mx = inf;
void dfs(int par, int u, int lvl){
    db1(u);
    level[u] = lvl;
    visited[u] = true;
    visited2[u] = true;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i] ;
        if(!visited[v]){
            dfs(u,v,lvl+1);
           
        }
        else
        {
            if(par!=v){
                db2(u,v);
                db2(level[u],level[v]);
                int dif=level[u]-level[v]; 
                mx = min(mx,dif+1);

            }
        }
    }
     visited[u] = false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,caseno=0;
    cin>>t;
	while(t--){

        int m,n;
        cin>>n>>m;
        for(int i=0; i<n+5; i++) {
            visited[i]= false;
            visited2[i]= false;
            level[i]=0;
            g[i].clear();
        }
        mx = inf;
        for(int i=0; i<m; i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
       for(int i=0; i<n; i++) {
            if(!visited2[i])
                dfs(-1,i,0);   
       }
        
        if(mx==inf)
            cout<<"Case "<<++caseno<<": "<<"impossible"<<endl;
        else
         cout<<"Case "<<++caseno<<": "<<mx<<endl;

    }
    return 0;
}