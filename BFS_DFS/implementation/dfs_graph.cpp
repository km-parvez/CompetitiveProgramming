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
constexpr ll mod = 1000000007;
constexpr int MX = 200005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}
#define int long long
// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
vector<int> a(MX);
vector<int> g[MX];
set<pair<int,int> >st[MX];
vector<int> sz(MX);
vector<ll> score(MX); 
vector<int> p(MX);
pair<int,ll>  dfs(int par,int u){
 //  cout<<s<<endl;
   int child = 1;
   int sumscore = a[u];
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(v!=par){
            p[v]=u;
            auto [tsz,tsum] = dfs(u,v);
            child += tsz;
            sumscore += tsum;
        }
    }
    sz[u]=child;
    score[u]=sumscore;
    return {sz[u],score[u]};
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++) {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    p[1]=-1;
    dfs(-1,1);
    /*for(int i=1; i<=n; i++) {
        whatis3(p[i],sz[i],score[i]);
    }*/
    for(int i=1; i<=n; i++) {
        for(int j=0; j<g[i].size(); j++) {
            int sn = g[i][j];
            if(sn != p[i])
                st[i].emplace(-sz[sn],sn);
        }
        /*for(auto it = st[i].begin(); it != st[i].end(); it++){
            cout<<(*it).first<<" "<<(*it).second<<'\n';
            cout<<score[(*it).second]<<'\n';
        }*/
    }
    while(m--){
        int t,x;
        cin>>t>>x;
        if(t==1){
            cout<<score[x]<<'\n';   
        }
        else{
            if(st[x].size()==0)continue;
            int px = p[x];
            auto [childs,son] = *st[x].begin();
            ll scoreX = score[x];
            ll scorePX = score[px];
            ll scoreSon = score[son];
            ll szX = sz[x];
            ll szPX = sz[px];
            ll szSon = sz[son];
            assert(szSon==-childs);

            p[x]= son;
            p[son]=px;

            sz[son] = szX;
            score[son] = scoreX;
            sz[x] = szX - szSon;
            score[x] = scoreX - scoreSon;
            st[px].erase({-szX,x});
            st[px].emplace(-sz[son],son);

            st[x].erase({-szSon,son});
            st[son].emplace(-sz[x],x);

        }
    }

    
    return 0;
}   