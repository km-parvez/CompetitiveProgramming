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
#define MX 103

using namespace std;
using ll = long long;
int dp[MX][MX];
int arr[MX];
int func(int s,int e){
	if(s>e)return 0;
	if(s==e)return arr[s];
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	int mx = INT_MIN;
	int sum = 0;
	for(int i=s; i<=e; i++) {
		sum+=arr[i];
		mx =max(mx,sum-func(i+1,e));
	}
	sum = 0;
	for(int i=e; i>=s; i--) {
		sum+=arr[i];
		mx =max(mx,sum-func(s,i-1));
	}
	//whatis3(s,e,mx);
	return dp[s][e] = mx;
}

void solve(int caseno){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int ans = func(0,n-1);
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