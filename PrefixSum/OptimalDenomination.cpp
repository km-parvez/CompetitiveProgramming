// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MAXX 1000006

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    cin>>n;
    vector<int> v(n);
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        sum+=v[i];
    }
    if(n==1){cout<<1<<'\n';return;}
    int pregcd[n+2];
    int sufgcd[n+2];
    pregcd[0]=v[0];
    sufgcd[n-1] = v[n-1];
    for(int i=1; i<n; i++) {
    	pregcd[i] = __gcd(pregcd[i-1],v[i]);
    }

    for(int i=n-2; i>=0; i--) {
    	sufgcd[i] = __gcd(sufgcd[i+1],v[i]);
    }
    ll ans = LLONG_MAX;
    for(int i=0; i<n; i++) {
    	
    	ll x = __gcd((i-1<0?0:pregcd[i-1]),(i+1>=n?0:sufgcd[i+1])); // gcd(0,10)=10 gcd with zero remains value
    	ans = min((ll)ans,1LL+(sum-v[i])/x);
    }
    cout<<ans<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}