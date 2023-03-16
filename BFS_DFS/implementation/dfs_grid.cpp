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

int adjX[] = {0,1,0,-1};int adjY[] = {-1,0,1,0};
//int adjX[]={-1,-1,-1, 0, 0, 1, 1, 1};
//int adjY[]={-1, 0, 1,-1, 1,-1, 0, 1};
int g[1005][1005];
bool vis[1005][1005];
int r,c;
int room=0;
bool inBoundary(int i,int j){
    if(i<1||i>r||j<1||j>c) return false;
    else 
        return true;
}
void dfs(int si,int sj)
{
    vis[si][sj]=true;
    room++;
    for(int i=0; i<4; i++){
        int x = si+adjX[i];
        int y = sj+adjY[i];
        if((g[si][sj]&(1<<i))) continue;
        if(inBoundary(x,y)&&!vis[x][y]){
            dfs(x,y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>r>>c;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin>>g[i][j];
        }
    }
     for(int i=0;i<=r+1;i++){
        for(int j=0; j<=c+1; j++){
            vis[i][j] = false;
        }
    }
    vector<int> ans;
    // bfs(1,1);
   for(int i=1;i<=r;i++){
        for(int j=1; j<=c; j++){
            if(!vis[i][j]){
                room =0;
                dfs(i,j);
                ans.emplace_back(room);
                //cout<<'\n';
            }
 
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}