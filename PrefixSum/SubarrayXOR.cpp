// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 998244353
#define MX 1000006

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    cin>>n;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int suf[n+4]={0};
    int ind= n;
    for(int i=1;i<=n;i++) {
    	if(s[i-1]=='1')suf[i]=ind;
    	ind--;
    }

    for(int i=n-1; i>=1; i--) {
    	suf[i]+=suf[i+1];
    }
   // whatisArray(suf,n+1);
    ll ans = 0;
    ll c = 1;
    for(int i=n; i>=1; i--) {
    	ans= (ans*2)%mod;
    	ans= (ans+(suf[i]&1))%mod;
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