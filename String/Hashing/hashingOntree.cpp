// Created by KHALED MOSHARRAF PARVEZ
#include<bits/stdc++.h>
using namespace std;
#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()

using ll = long long;
constexpr ll mod = 1000000007;
constexpr int MX = 20005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}



// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
long long base = 31;
long long base2 = 33+(rand()%55);
long long pwr[MX];
long long pwr2[MX];


long long h1[MX];
long long h2[MX];
long long sz[MX];
string s,t;
void solve(int caseno){
    long long n;
    std::getline(std::cin, s);
    std::getline(std::cin, t);

    n = s.size();
    if(n==0){
        printf("Case %d: Same\n",caseno );
        return;
    }

    h1[0] = 1;
    h2[0] = 1;
    long long lvl = 0;
    // d*base^P*(sum);
    // pre[i] = modadd(modmul(pre[i-1],base),s[i-1]-'a'+1);

    for(int i=0; i<n; i++) {
        if(s[i]=='0'){
            h1[lvl-1] = modadd(h1[lvl-1],modmul(modmul(sz[lvl],pwr[lvl]),h1[lvl]));
            h2[lvl-1] = modadd(h2[lvl-1],modmul(modmul(sz[lvl],pwr[lvl]),h2[lvl]));
            h1[lvl] = 0;
            h2[lvl] = 0;
            sz[lvl-1]+=sz[lvl];
            sz[lvl] = 0;
            lvl--;
        }
        else{
            lvl++;
            h1[lvl] = 1;
            h2[lvl] = 1;
            sz[lvl] = 1;
        }
    }
    long long hasht1 = h1[0];
    long long hasht2 = h2[0];
    h1[0] = 1;
    h2[0] = 1;
    lvl = 0;
    // d*base^P*(sum);
    // pre[i] = modadd(modmul(pre[i-1],base),s[i-1]-'a'+1);

    for(int i=0; i<n; i++) {
        if(t[i]=='0'){
            h1[lvl-1] = modadd(h1[lvl-1],modmul(modmul(sz[lvl],pwr[lvl]),h1[lvl]));
            h2[lvl-1] = modadd(h2[lvl-1],modmul(modmul(sz[lvl],pwr[lvl]),h2[lvl]));
            h1[lvl] = 0;
            h2[lvl] = 0;
            sz[lvl-1]+=sz[lvl];
            sz[lvl] = 0;
            lvl--;
        }
        else{
            lvl++;
            h1[lvl] = 1;
            h2[lvl] = 1;
            sz[lvl] = 1;
        }
    }
    if(hasht1==h1[0] && hasht2==h2[0]){
        printf("Case %d: Same\n",caseno );
    }
    else{
        printf("Case %d: Different\n",caseno );
    }

  
    return;
    
}
int main()
{   
/*
input: lightOJ problem "Same Tree";
3
1011010100
1101010010


1101010010
1011110000
*/
    int cases,caseno=0;
    scanf("%d",&cases);
    getchar();
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