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
constexpr ll mod = 1'000'000'007;
constexpr int MX = 200005;
unsigned long long fac[MX];

unsigned long long power(unsigned long long x,int y, int p)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
void solve(int caseno){
    int n;
    cin>>n;
    vector<int> v(n);
    int mx = 0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        mx=max(mx,v[i]);
    }
    int sml=0;
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(mx-1>v[i]){
            sml++;
        }
        if(mx==v[i])cnt++;
    }

    ll ans = fac[n];
    if(cnt>1){
        cout<<ans<<'\n';return;
    }
    n--;
    ll sub =0;
    for(int i=0; i<=sml; i++) {
        ll tmp = nCrModPFermat(sml,sml-i,mod);
        sub = (sub+(fac[i]*fac[n-i])%mod *tmp )%mod;
        

    }
    ans -=sub;
    ans+=mod;
    cout<<(ans)%mod<<'\n';
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    fac[0] = 1;
    for (ll i = 1; i <MX; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}