// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 1003

using namespace std;
using ll = long long;

int adjX[] = {0,0,-1,1};
int adjY[] = {-1,1,0,0};
//int adjX[]={-1,-1,-1, 0, 0, 1, 1, 1};
//int adjY[]={-1, 0, 1,-1, 1,-1, 0, 1};
char g[MX][MX];
int level[MX][MX];
int r,c;

bool inBoundary(int i,int j){
    if(i<1||i>r||j<1||j>c) return false;
    else 
        return true;
}
void bfs(int si,int sj){

    queue<pair<int,int> > q;
    q.push(make_pair(si,sj));
    level[si][sj]=0;

    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        //bd2(u.first,u.second);
        for(int i=0; i<4; i++) {
            int x = u.first+adjX[i];
            int y = u.second+adjY[i];
            if(inBoundary(x,y)&&level[x][y]==-1){
                //bd2(x,y);
                level[x][y]=level[u.first][u.second]+1;
                q.push(make_pair(x,y));
            }
        }
    }
    
    return;   
}


void solve(int caseno){
    memset(level,-1,sizeof(level));
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1; j<=c; j++) {
            cin>>g[i][j];
        }
    }
    bfs(1,1);
    whatArray2D(level,r,c);
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}