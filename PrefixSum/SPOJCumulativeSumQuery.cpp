// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MAXX 1000006

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1);
    ll sum[n+2];
    sum[0] = 0;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    int q;cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(y<x)swap(x,y);
        x++,y++;
        ll ans = sum[y]-sum[x-1];
        cout<<ans<<'\n';
    }
    

    return 0;
}