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
constexpr int MX = 3205;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
vector<int> prm;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])prm.push_back(p);
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    SieveOfEratosthenes(MX);
    int n;
    cin>>n;
    vector<int> d1(n,-1);
    vector<int> d2(n,-1);
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        int co = 0;
        for(int j=0; j<prm.size()&&prm[j]<=x; j++) {
            if( x>1 && (x%prm[j])==0){
                co++;
                
                if(co==1){
                    d1[i]=prm[j];
                }
                x/=prm[j];
                while(x>1&&(x%prm[j])==0){
                    x/=prm[j];
                }
                break;
            }

        }
        if( x>1){
            co++;
            
            if(co==1){
                d1[i]=x;
            }
            else if(co>=2){
                d2[i]=x;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(d2[i]!=-1){
            cout<<d1[i]<<' ';
        }
        else cout<<-1<<' '; 
    }
    cout<<'\n';       
    for(int i=0; i<n; i++) {
        cout<<d2[i]<<' ';
    }
    cout<<'\n';
    
    return 0;
}       