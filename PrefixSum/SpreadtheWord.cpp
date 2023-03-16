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
#define MAXX 100005

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    cin>>n;
    vector<int> v(n+3);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    ll presum[n+3];
    presum[1] = v[1];
    for(int i=2; i<=n; i++) {
    	presum[i]=presum[i-1]+v[i];
    }
    int day = 0;
    ll res= 1;
    while(res<n){
    	day++;
    	res = res+presum[res];
    }
    cout<<day<<'\n';

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