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
#define MX 1003

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    string s;
    cin>>s;
    n = s.size();
    int dp[n+1][n+1];
    int part[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n; i++) {
        part[i] = i;
        for(int j=0; j<=i; j++) {
            if(s[i]==s[j]&&(i-j<2||dp[j+1][i-1]==1)){
                part[i] = min(part[i],j<=0?0:(part[j-1]+1));
                dp[j][i] = 1;
            }
        }
    }

    caseprint(caseno,part[n-1]+1);
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