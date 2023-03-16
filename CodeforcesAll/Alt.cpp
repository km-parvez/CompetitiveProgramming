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

void solve(int caseno){
    int n;
    cin>>n;
    int cnt[n+5];
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        cnt[x]++;
    }
    pair<int,int> v;
    for(int i=1; i<=n; i++) {
        if(cnt[i]>0){
            v.push_back({cnt[i],i});
        }
    }   
    sort(v.begin(),v.end(),greater<pair<int,int> >()); 
    vector<int>  arr[v[0].first+4];
    int stp = v[0].first;
    for(int i=0; i<v.size(); i++) {
        
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