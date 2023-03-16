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

using namespace std;
using ll = long long;
constexpr ll mod = 1'000'000'007;
constexpr int MX = 200005;

void solve(int caseno){
    int n,kk;
    cin>>n>>kk;
    vector<int> a(n);
    vector<int> b(n);
    int atot = 0;
    int btot = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        cin>>b[i];
    }
    int dp[kk+5]={0};
    int vis[kk+5][n+5];
    for(int i=0; i<kk+5; i++) {
        for(int j=0; j<n+5; j++) {
            vis[i][j]=0;
        }
    }
    ll ans = 0;
    dp[0]=1;
    for(int k=0; k<=kk; k++) {
        if(dp[k]<=0)continue;
        for(int i=0;i<n;i++){
            if(b[i]>vis[k][i]){
                if(k+a[i]<=kk&&dp[k+a[i]]==0){
                    ans++;
                    dp[k+a[i]]=1;
                    for(int j=0; j<n+4; j++) {
                        vis[k+a[i]][j]=vis[k][j];
                    }
                    vis[k+a[i]][i]++;
                }

            }
        }
    }
    caseprint(caseno,ans);
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}