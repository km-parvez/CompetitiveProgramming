// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 100000007
#define MAXX 1000006

using namespace std;
using ll = long long;
int n,k;
int arr[102];
int dp[10004];

void solve(int caseno){
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
	for(int j=0; j<n; j++) {
	    for(int i=1; i<=k; i++) {
    		if(i>=arr[j]){
    			dp[i]+=dp[i-arr[j]];
	    		if(dp[i]>=mod)dp[i]-=mod;
    		}
    	}
    }
    caseprint(caseno,dp[k]);
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