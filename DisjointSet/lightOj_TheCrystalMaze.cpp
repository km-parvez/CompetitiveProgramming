// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  505
using namespace std;
using ll = long long;

int adjx[] = {-1,1,0,0};
int adjy[] = {0,0,-1,1};
pair<int,int> rep[MAXX][MAXX];
char g[MAXX][MAXX];
int ans = 0;
int rootx,rooty;
int m,n,q;

bool checkBoundary(int i,int j,int mm,int nn )
{
    if(i<1||i>mm||j<1||j>nn) return false;
    else return true;
}
void dfs(int px,int py, int xx,int yy){
 //    db2(xx,yy);
    rep[xx][yy]= make_pair(rootx,rooty);
    if(g[xx][yy]=='C'){
        ans++;
     //   db1(ans);
    }
    g[xx][yy] = '#';
    for(int i=0; i<4; i++) {
        int nx = xx+adjx[i];
        int ny = yy+adjy[i];
       // db2(nx,ny);
        if(g[nx][ny]!='#' && checkBoundary(nx,ny,m,n) ){
          
            dfs(xx,yy,nx,ny); 
             
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
    
        cin>>m>>n>>q;
        int dp[m+5][n+5];

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                cin>>g[i][j];
                rep[i][j]= make_pair(i,j);
                dp[i][j]=-1;
            }
        }
  

        cout<<"Case "<<++caseno<<":"<<endl;
        int uu,vv;
        for(int i=0; i<q; i++) {
            cin>>uu>>vv;
            //db2(uu,vv);
            int tmpu = rep[uu][vv].first;
            int tmpv = rep[uu][vv].second;
            uu = tmpu;
            vv = tmpv;
           // db2(uu,vv);
            ans = 0;
            if(dp[uu][vv]!=-1){
                ans = dp[uu][vv];
            }
            else{
                rootx=uu;
                rooty=vv;
                dfs(-1,-1,uu,vv);
                dp[uu][vv]=ans;
            }
            cout<<dp[uu][vv]<<endl;
        }
     
    }
    return 0;
}