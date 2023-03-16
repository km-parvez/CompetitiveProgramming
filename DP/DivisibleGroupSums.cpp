// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 203

using namespace std;
using ll = long long;
int arr[MAXX],n,q,d,m;
ll dp[MAXX][MAXX][22];
ll func(int cnt,int pos, ll rem){
    if(cnt==m && rem == 0) return 1;
    if(cnt==m && rem != 0) return 0;
    if(pos>=n) return 0;
    if(dp[cnt][pos][rem]!=-1) return dp[cnt][pos][rem];
    ll val1 = func(cnt,pos+1,rem); 
    ll val2 = func(cnt+1,pos+1,((rem+arr[pos])%d+d)%d);
    return dp[cnt][pos][rem] = val1+val2; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        cin>>n>>q;
        cout<<"Case "<<++caseno<<":"<<endl;
        for(int i=0;i<n;i++) cin>>arr[i];
            while(q--){
                memset(dp,-1,sizeof dp);
                cin>>d>>m;
                ll ans = func(0,0,0);
                cout<<ans<<endl;
            }

        
    
    }
    return 0;
}