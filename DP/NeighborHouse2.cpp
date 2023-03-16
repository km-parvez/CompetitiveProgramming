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
int n;
int arr[1003];
int dp[2][1003];
bool first;
int func(bool prv,int pos){
	if(pos==n-1){
		if(prv){
			return 0;
		}
		else{
			if(first)return 0;
			else return arr[n-1];
		}
		
	}
	if(dp[prv][pos]!=-1) return dp[prv][pos];
	if(prv){
		dp[prv][pos]=func(false,pos+1);
	}
	else
	{
		dp[prv][pos] = max(func(false,pos+1),func(true,pos+1)+arr[pos]);
	}
	return dp[prv][pos];
}
void solve(int caseno){

    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    first = true;
    int a = func(true,1)+arr[0];
    memset(dp,-1,sizeof(dp));
    first = false;
    int b = func(false,1);
    int ans = max(a,b);
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