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
constexpr int MX = 200005;

void solve(int caseno){
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    ll xr = 0;
    for(int i=0; i<n; i++) {
        xr^=(a[i]-v[i]-1);
    }
    if(xr==0){
        caseprint(caseno,"black wins");
    }
    else {
        caseprint(caseno,"white wins");
    }
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