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
long long isqrt(long long n) {
    long long x = sqrtl(n);
    while (x * x > n) {
        --x;
    }
    while ((x + 1) * (x + 1) <= n) {
        ++x;
    }
    return x;
}
 
void solve(int caseno){
    ll l,r;
    cin>>l>>r;

    ll xl ;
    if(l==1)xl = 1;
    else 
        xl  = isqrt(l-1);
    ll xr = isqrt(r);
    ll ans = (xr-xl-1)*3LL;
    //whatis1(ans);
    ll left = (((xl+1)*(xl+1)- l)+(xl-1))/xl;
    ll right = (r - xr*xr+1LL+(xr-1))/xr;
    ans+=(left+right);
    cout<<ans<<'\n';
    return;
    
}
int main()
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