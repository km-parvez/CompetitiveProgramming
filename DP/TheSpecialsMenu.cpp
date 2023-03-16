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
#define MX 61

using namespace std;
using ll = long long;
ll dp[MX][MX];
string w;
ll func(int i,int j){
	if(i>j)return 0;
	if(i==j)return dp[i][j]=1;
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll tot = 0;
	if(w[i]==w[j]){
		tot = 1+func(i+1,j-1);
	}

	tot += func(i+1,j)+func(i,j-1)-func(i+1,j-1);	
	dp[i][j] = tot;
	//whatis3(i,j,dp[i][j]);
	return dp[i][j];
} 
void solve(int caseno){
    memset(dp,-1,sizeof(dp));
    cin>>w;
    ll ans = func(0,w.size()-1);
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