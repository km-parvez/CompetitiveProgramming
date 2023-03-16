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
int level[MAXX];
int par[MAXX];
int mx = inf;
queue<int> q;
void bfs(int s){
    level[s] = 0;
    visited[s] = true;
    par[s] = -1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i] ;
            if(!visited[v]){
                par[v] = u;
                visited[v] = true;
                level[v] = level[u]+1;
                q.push(v);
            }
            else
            {
             //   db1("found case"); 
                if(v!=par[u]){
                int nodes = level[u]+level[v]+1;
                   mx = min(mx,nodes);
                }
            }
        }

    }
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
            level[i]=0;
            par[i]=-1;
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
            
            for(int j=0; j<n+1; j++) {
                visited[j]= false;
                par[j]=-1;
                level[j]=0;
            }
            bfs(i);   
        }
        if(mx==inf)
            cout<<"Case "<<++caseno<<": "<<"impossible"<<endl;
        else
         cout<<"Case "<<++caseno<<": "<<mx<<endl;

    }
    return 0;
}