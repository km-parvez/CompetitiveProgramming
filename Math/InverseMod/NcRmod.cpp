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
constexpr int MX = 2000006;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
ll fact[MX];
ll modInv[MX];
bool initFact = false;

void factInit(){
    initFact = true;

    fact[0] = 1;
    for (ll i = 1; i <MX; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    modInv[MX - 1] = modinverse(fact[MX-1]);
    for (int i = MX - 2; i >= 0; i--){
        modInv[i] = modInv[i + 1] * (i + 1) % mod;
    }
}

ll nCr(ll n,ll r)
{
    if(!initFact){
        factInit();
    }
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return ((fact[n] * modInv[r])%mod * modInv[n-r])% mod;
}
void solve(int caseno){
    int z,o;
    cin>>z>>o;
    int n = z+o;
    int pp = 0,nn = 0;
    int easy = n/2;
    nn = (easy+1)/2;
    pp = easy/2;
    
    int ans = 0;
    int mn = min(pp,nn);
    for(int i=0; i<=mn; i++) {
        int got = i+i;
        int rem = o-got;
        if(rem<0)break;
       // whatis2(easy,rem);
        if(rem>easy)continue;
      

        int tmppp = nCr(pp,i);
        int tmpnn = nCr(nn,i);
        int tmprem = nCr(easy,rem);
     //   whatis3(tmppp,tmpnn,tmprem);
        int tmp = modmul(tmppp,modmul(tmpnn,tmprem));
        ans = modadd(ans,tmp);

    }
    cout<<ans<<'\n';

    return;
    
}
main()
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