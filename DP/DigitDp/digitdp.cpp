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
string str;
int n;
ll dp[15][3][3];
ll func(int pos,int isSmall,int hasStarted){
    if(pos>=n)return 1;
    if(dp[pos][isSmall][hasStarted]!=-1){
        return dp[pos][isSmall][hasStarted];
    }
    int low = 0,hi = 9;
    if(!isSmall) hi=str[pos]-'0';
    ll val = 0;
    for(int i=low; i<=hi; i++) {
        int newSmall = isSmall|(i<hi);
        ll suf = 0;
        if(i==0&&hasStarted)
        suf =1;
        
        val += (func(pos+1,newSmall,hasStarted|(i!=0))+suf);
    }
    return dp[pos][isSmall][hasStarted]=val;


}

void solve(int caseno){
    ll a,b;
    memset(dp,-1,sizeof(dp));
    cin>>a>>b;
    str = to_string(b);
    n = str.size();
    ll ans1 =func(0,0,0);
   // whatis1(ans1);
    ll ans2 = 0;
   // a++;
    
    memset(dp,-1,sizeof(dp));
    str = to_string(a);
    n = str.size();
    ans2 =func(0,0,0);
 //   whatis2(ans1,ans2);
    ll res = ans1-ans2;
    cout<<res<<'\n';
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