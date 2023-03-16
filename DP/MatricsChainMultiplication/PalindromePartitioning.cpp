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
int dp[MX][MX];
int part[MX];
int n;
string s;
int isPal(int b,int e){
	if(b>=e)return 1;
	if(dp[b][e]!=-1)return dp[b][e];
	if(s[b]==s[e]){
		dp[b][e] = isPal(b+1,e-1);
	}
	else{
		dp[b][e] = 0;	
	}
	return dp[b][e];
}



void solve(int caseno){
    cin>>s;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<s.size(); i++) {
    	for(int j=i; j<s.size(); j++) {
    		dp[i][j]=isPal(i,j); 
    	}
    }
    memset(part,0,sizeof(part));
    n= s.size();
    for(int i=0; i<n; i++) {
        part[i] = i;
        for(int j=0; j<=i; j++) {
            if(dp[j][i]==1){
                part[i] = min(part[i],j<=0?0:(part[j-1]+1));
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