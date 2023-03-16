// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  103
using namespace std;
using ll = long long;


int inf = 1000000007;
vector<int> g[MAXX];
bool visited[MAXX];
int level[MAXX];
int par[MAXX];
int mx = inf;
queue<int> q;
bool found = false;
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
                   if(nodes&1)
                   {
                        found = true;
                   }
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
    int cases,caseno = 0;
    cin>>cases;
    while(cases--){
        int n,m;
        cin>>n>>m;

        for(int i=0; i<n+3; i++) {
            visited[i]= false;
            level[i]=inf;
            par[i]=-1;
            g[i].clear();
        }
     	for(int i=0; i<m; i++) {
     		int x,y;
     		cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
     	}
      

        found = false;
        int ans = 0;
        int totVisited = 0;
        if(m==0) {caseprint(caseno,ans); continue;}
        bfs(1);  
         for(int i=1; i<=n; i++) 
                if(visited[i])totVisited++;
        if(totVisited==1) {caseprint(caseno,ans); continue;}
        if(found){
            caseprint(caseno,totVisited);
        }
        else {
            for(int i=1; i<=n; i++) 
                if(!(level[i]&1)) ans++;

            caseprint(caseno,ans);
        }

    }
    return 0;
}