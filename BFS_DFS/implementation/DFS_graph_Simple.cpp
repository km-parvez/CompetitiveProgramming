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
constexpr ll mod = 1000000007;
constexpr int MX = 200009;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.

void dfs(int par,int u, vector<vector<int>> &g,vector<int> &lvl  ){
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(v!=par){
            lvl[v] = lvl[u]+1;
            dfs(u,v,g,lvl);
        }
    }
    return;
}

void solve(int caseno){
    int n,st,en;
    cin>>n>>st>>en;
    vector< vector<int> >g(n+1);
    vector<int> lvl(n+1); 
    for(int i=0; i<n+1; i++) {
        lvl[i] = -1;
    }
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lvl[en] = 0;
    dfs(-1,en,g,lvl);
    
    vector<int> lvlvec[n+5];
    for(int i=1; i<=n; i++) {
         if(lvl[i]!=-1)  
            lvlvec[lvl[i]].push_back(i);     
    }
    vector<int> ans;
    for(int i=n; i>=1; i--) {
        for(auto c:lvlvec[i]){
            ans.push_back(c);
        }
    }       
    ans.push_back(en);  
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return;

}
main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}       