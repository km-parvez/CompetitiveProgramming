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
int minSumWithDistanceNotGreaterThanD( vector<int>& elements, int d) {
    deque<int> window;
    vector<int> dp(elements.size());
    
    window.push_back(0);
    dp[0] = elements[0];
    
    for (int i = 1; i < elements.size(); ++i) {
        while (!window.empty() && i - window.front() > d) {
            window.pop_front();
        }
        dp[i] = elements[i] + dp[window.front()];
        
        while (!window.empty() && dp[i] <= dp[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    
    return dp.back();
}

void solve(int caseno){
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    vector<int> v[n];
    for(int i=0;i<n;i++) {
        for(int j=0; j<m; j++) {
            int x;
            cin>>x;
            x++;
            v[i].push_back(x);
        }
    }
    int cnt[n]={0};
    for(int i=0; i<n; i++) {
        cnt[i] = minSumWithDistanceNotGreaterThanD(v[i],d+1);
    }
    for(int i=1; i<n; i++) {
        cnt[i]+=cnt[i-1];
    }
    int ans = 1e18;
    for(int i=0; i<n; i++) {
        int tmp = 0;
        if((i+k-1LL)<n){
            tmp = cnt[i+k-1];
            if(i>0){
                tmp-=cnt[i-1];
            }
            ans = min(ans,tmp);
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
    while(cases--){
        solve(++caseno);
    }
    return 0;
}           