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
int c[102];
int dp[100005];
int used[100005];

void solve(int caseno){
    // n is number of coin, k is what amount needs to make. 
    cin>>n>>k;
    // arr[i] is coins available
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    // c[i] is number of coin can use;
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }

    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int ans = 0;
	for(int j=0; j<n; j++) {
        memset(used,0,sizeof(used));
	    for(int i=arr[j]; i<=k; i++) {
    		if(!dp[i]&& dp[i-arr[j]]&& c[j]>used[i-arr[j]]){
                used[i]=used[i-arr[j]]+1;
    			dp[i]=1;
	    		ans++;
    		}
    	}
    }
  
    caseprint(caseno,ans);
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