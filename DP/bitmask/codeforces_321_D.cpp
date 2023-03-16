// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
constexpr ll mod = 1'000'000'007;
constexpr int MX = 20;
int n,m,k;
ll arr[MX];
ll ss[MX][MX];
ll dp[(1<<19)+5][MX];
ll func(int mask,int last){
    if(__builtin_popcount(mask)==m)return 0;
    ll &ref = dp[mask][last];
    if(ref!=-1){
        return ref;
    }
    ll best = 0;
    for(int i=1; i<=n; i++) {
        if(!(mask&(1<<(i-1)))){
            ll cur = ss[last][i]+arr[i]+func(mask|(1<<(i-1)),i);
            best = max(best,cur);
        }
    }
    ref = best;
    return ref;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    memset(ss,0,sizeof(ss));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(int i=0; i<k; i++) {
        int x,y,c;cin>>x>>y>>c;
        ss[x][y] = c;
    }
    ll ans = func(0,0);
    cout<<ans<<'\n';
    
    return 0;
}   