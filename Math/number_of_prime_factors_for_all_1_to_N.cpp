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
constexpr int MX = 5000006;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
int divs[MX];
void numsOfPrimeFactors(){
    for(int i=2; i<MX; i++) {
        if(divs[i]!=0)continue;
        for(int j=i; j<MX; j+=i) {
           if(divs[j]==0)divs[j] = i;
        }
    }
    for(int i=2; i<MX; i++) {
        divs[i] = 1+divs[i/divs[i]];
    }
}
void solve(int caseno){
    int a,b;
    cin>>a>>b;
    cout<<divs[a]-divs[b]<<'\n';
    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    
    numsOfPrimeFactors();
     for(int i=2; i<MX; i++) {
        divs[i] += divs[i-1];
    }

    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}       