// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  100009
using namespace std;
using ll = long long;
vector<int> g[MAXX];
int level[MAXX];
bool taken[MAXX];
int cnt = 0;
int bfs(int s){
    cnt = 0;
    bool visited[MAXX]={false};
    level[s] = 0;
    visited[s] = true;
    
    queue<int> q;
    q.push(s);
    int u,v;
    while(!q.empty()){
        cnt++;
        u = q.front();
        q.pop();
        taken[u] = true;
        for(int i=0; i<g[u].size(); i++) {
            v = g[u][i] ;
            if(!visited[v]){
                visited[v] = true;
                level[v] = level[u]+1;
                q.push(v);
            }
        }

    }
    return u;
}


int main()
{
   // ios::sync_with_stdio(0);
    int cases,caseno=0;
    scanf("%d",&cases);
    while(cases--){
        int n,m, x,y;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n+3; i++) {
            g[i].clear();
            taken[i] = false;
        }
        bool present[n+3]={false};
        for(int i=0; i<m; i++) {
            
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
            present[x]=true;
            present[y]=true;
        }
        int superarray[n+3]={0};
        int mxcnt = 0;
        for(int i=1; i<=n; i++) {
            if(!taken[i]&&present[i]){
               
                int nextInd = bfs(i);
                
                nextInd = bfs(nextInd);
                superarray[cnt] = max(superarray[cnt],level[nextInd]);
                mxcnt = max(mxcnt,cnt);
            
            
            }
        }
       // cout<<mxcnt<<endl;
        int carryK = 0;
        for(int i=mxcnt; i>=1; i--) {
            if(carryK<superarray[i]){
                carryK=superarray[i];
            }
            else{
                superarray[i]=carryK;
               // db2(i,carryK);
            }
        }
    
        int qq;
        scanf("%d",&qq);
       // cout<<"Case "<<++caseno<<":"<<endl;
        printf("Case %d:\n",++caseno );
        while(qq--){
            int k;
            scanf("%d",&k);
            if(k==1){printf("0\n" );continue;}
            if(k>mxcnt){printf("impossible\n");continue;}
            int ans = MAXX;
            if(superarray[k]>=k-1)  
                ans = k-1; 
            else
            ans = superarray[k]+(k-1-superarray[k])*2;
            printf("%d\n",ans );
        }
    }  
    return 0;
}