// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 300005

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    cin>>n;
    vector<int> g[n+4];
    pair<ll,ll> rng[n+4];
    for(int i=2; i<=n; i++) {
        int u=i,v;
        cin>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll l,r;
    for(int i=1; i<=n; i++) {
        cin>>l>>r;
        rng[i]={l,r};
    }
    int ans = 0;
    function<ll(int, int)> dfs = [&](int par, int u) {
        ll mx = 0;
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i] ;
            if(v!=par){
                mx = mx+ dfs(u,v);
            }
        }
        if(rng[u].first<=mx){
            return min(rng[u].second,mx);
        }
        else{
            ans++;
            return rng[u].second;
        }
    };
    dfs(-1,1);
    cout<<ans<<endl;
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}