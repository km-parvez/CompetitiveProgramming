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
constexpr int MX = 1000006;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
int pwr[MX];
int base = 31;
int val(char ch){
    int v = ch - 'a' + 1;
    return v;
}
void solve(int caseno){
    int n;
    string s;cin>>s;
    n=s.size();
    int h1 = 0;
    int h2 = 0;
    for(int i=0; i<n; i++) {
        h1 = modadd(modmul(h1,base),val(s[i]));
        h2 = modadd(h2,modmul(val(s[i]),pwr[i]));
    }
    if(h1==h2){
        caseprint(caseno,n);
        return;
    }
    int s1 = 0,s2=0;
    for(int i=0; i<n; i++) {
        s2 = modadd(modmul(s2,base),val(s[i]));
        s1 = modadd(s1,modmul(val(s[i]),pwr[i]));
     //   whatis2(s1,s2);
        int tmp1 = h1;
        int tmp2 = h2;
        tmp1 = modmul(tmp1,pwr[i+1]);
        tmp1 = modadd(tmp1,s1);
        int ts2 = s2;
        ts2 = modmul(ts2,pwr[n]);
        tmp2 = modadd(tmp2,ts2);
      //  whatis2(tmp1,tmp2);
        if(tmp2==tmp1){
            caseprint(caseno,n+i+1);
            return;
        }
    }


    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    pwr[0]=1;
    for(int i=1; i<MX; i++) {
        pwr[i] = modmul(pwr[i-1],base);
    }
    while(cases--){
        solve(++caseno);
    }
    return 0;
}   