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

void solve(int caseno){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    vector<pair<int,int> > pii;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        v[i]--;
        int x = i;
        int y = v[i];
        if(x>y)swap(x,y);
        pii.emplace_back(x,y);   
    }
    string s;cin>>s;
    sort(pii.begin(),pii.end());    
    vector<int> xs,ys;
    xs.push_back(pii[0].first);
    ys.push_back(pii[0].second);
    for(int i=1; i<pii.size(); i++) {
        auto [x,y] = pii[i];
        if(ys.back()<x){
            xs.emplace_back(x);
            ys.emplace_back(y);
        }
        else{
            ys[ys.size()-1] = max(ys.back(),y);
        }
    }
    int tot = xs.size();
    int need = 0;
    int neg = 0;
    for(int k=0; k<xs.size(); k++) {
        int co = 0;
        for(int i=xs[k]; i<ys[k]; i++) {
            if(s[i]=='L'&&s[i+1]=='R')co++;
        }
        neg+=co;
    }
    while(q--){
        int ind; cin>>ind;ind--;
        auto it = upper_bound(xs.begin(), xs.end(), ind);   
        if(it==xs.begin())continue;
        it--;
        int i = it - xs.begin();
        int x = xs[i];
        int y = ys[i];

        if(y<ind)continue;
        int nw = 0;
        int has = 0;
        if(ind>x){
            if(s[ind-1]=='L'&&s[ind]=='R')has++;
        }
        if(ind<y){
            if(s[ind]=='L'&&s[ind+1]=='R')has++;
        }
        if(s[ind]=='L')
            s[ind] = 'R';
        else s[ind] = 'L';

        if(ind>x){
            if(s[ind-1]=='L'&&s[ind]=='R')nw++;
        }
        if(ind<y){
            if(s[ind]=='L'&&s[ind+1]=='R')nw++;
        }
        neg-=has;
        neg+=nw;
        if(neg==0){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }


    }
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