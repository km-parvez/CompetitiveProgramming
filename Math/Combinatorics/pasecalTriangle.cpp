// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 10056
#define MX 1003
using namespace std;
using ll = long long;

ll ncr[MX+1][MX+1]; 
void pascalTriangle(int n)
{
    ncr[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j<=i; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j])%mod;
        }
    }
}
ll dp[MX+1];
void func(int n){
	dp[0]=1;
	for(int i=1; i<=n; i++) {
		dp[i]=0;
		for(int j=1; j<=i; j++) {
			dp[i]=(dp[i]+(ncr[i][j]*dp[i-j])%mod)%mod;

		}
	}
}

void solve(int caseno){
    int n;
    cin>>n;
    caseprint(caseno,dp[n]);
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pascalTriangle(MX);	
    func(MX);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}