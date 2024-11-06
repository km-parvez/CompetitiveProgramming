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
constexpr int MX = 300005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}


// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.


main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Define a uniform integer distribution within the range [lower, upper]


    // Generate a random number within the specified range
    int n, q;
    cin >> n >> q;
    uniform_int_distribution<> distr(0, n-1);
    vector<int> arr(n);
    vector<int> g[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i]--;
        g[arr[i]].push_back(i);
    }

    int i =0;
    while(q--){
        int l,r;cin>>l>>r;l--;r--;
        int len = r-l+1;
        int mx = 0;
        vector<int> inds;
        int tt=40;
        while(tt--) {
            inds.emplace_back(uniform_int_distribution<int>(l,r)(rng));
        }
        for(auto c:inds) {
            int val = arr[c];
            int low = lower_bound(g[val].begin(), g[val].end(), l)-g[val].begin();
            int hi = upper_bound(g[val].begin(), g[val].end(), r)-g[val].begin();
            mx = max(mx,hi-low);
        }

        int ans = max(0,mx - (len - mx+1)) ;
        cout<<ans+1<<'\n';
        i++;
    }
    
    return 0;
}   