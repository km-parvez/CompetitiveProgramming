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
constexpr int MX = 300005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
int base = 31;
int base2 = 33+(rand()%55);
int pwr[MX];
int pwr2[MX];
int pre[MX];
int pre2[MX];
void solve(int caseno){
    int n;
    string s;cin>>s;
    n = s.size();
    pre[0] = 0;
    pre2[0] = 0;
    for(int i=1; i<=n; i++) {
        pre[i] = modadd(modmul(pre[i-1],base),s[i-1]-'a'+1);
        pre2[i] = modadd(modmul(pre2[i-1],base2),s[i-1]-'a'+1);
    }
    int ans = 0;
    for(int i=0; i<=n; i++) {
        int aa = i;
        if( (n-2LL*aa)%2LL != 0 )continue;

        int bb = (n-2LL*aa)/2LL;
        if(bb<0)continue;

        int cc = aa+aa+bb;

        int a = pre[aa];
        int a2 = pre2[aa];

        int ab = modsub(pre[cc],modmul(pre[aa],pwr[aa+bb]));
        int ab2 = modsub(pre2[cc],modmul(pre2[aa],pwr2[aa+bb]));

        int b = modsub(pre[n],modmul(pre[cc],pwr[bb]));
        int b2 = modsub(pre2[n],modmul(pre2[cc],pwr2[bb]));

        int coab = modadd(modmul(a,pwr[bb]),b) ;
        int coab2 = modadd(modmul(a2,pwr2[bb]),b2) ;
     //   whatis2(aa,bb);
     //   whatis3(a,ab,b);
    //    whatis2(ab,coab);
      //  whatis2(ab2,coab2);
        if(ab==coab && ab2 == coab2){
            ans++;
        }
    }
    cout<<ans<<'\n';
  
    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    pwr[0]=1;
    for(int i=1; i<MX; i++) {
        pwr[i]=modmul(pwr[i-1],base);
    }
    pwr2[0]=1;
    for(int i=1; i<MX; i++) {
        pwr2[i]=modmul(pwr2[i-1],base2);
    }
    while(cases--){
        solve(++caseno);
    }
    return 0;
}   