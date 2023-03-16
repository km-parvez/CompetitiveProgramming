// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  100009
using namespace std;
using ll = long long;
vector<int> g[MAXX];
int level[3][MAXX];
bool taken[MAXX];
int cnt = 0;
int bfs(int step,int s){
    cnt = 0;
    level[step][s] = 0;  
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
            if(level[step][v]<0){
                level[step][v] = level[step][u]+1;
                q.push(v);
            }
        }

    }
    return u;
}


int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    //cin>>cases;
     scanf("%d",&cases);
    while(cases--){
        int n,m, x,y;
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n+3; i++) {
            g[i].clear();
            level[0][i]=-1;
            level[1][i]=-1;
        }
        for(int i=0; i<m; i++) {
           
           // cin>>x>>y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
            
        }
        int superarray[n+3]={0};
        int mxcnt = 0;
        for(int i=1; i<=n; i++) {
            if(level[0][i]<0){
               
                int nextInd = bfs(0,i);
                nextInd = bfs(1,nextInd);
                superarray[cnt] = max(superarray[cnt],level[1][nextInd]);
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
            int ans=0;
            scanf("%d",&k);
            if(k==1){printf("%d\n",ans );continue;}
            if(k>mxcnt){printf("impossible\n" );continue;}
            
            if(superarray[k]>=k-1)  
                ans = k-1; 
            else
            ans = superarray[k]+(k-1-superarray[k])*2;
            printf("%d\n",ans );
        }
    }  
    return 0;
}