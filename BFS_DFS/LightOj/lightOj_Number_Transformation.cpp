// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 5003

using namespace std;
using ll = long long;
int ss,tt;
vector<int> g[MAXX];
int dp[MAXX];
vector<int> prime;
void findPrime(int n){

	for(int i=2;i<=n;i++)
	{	bool flag = false;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0){
				flag = true;
			}
		}
		if(!flag)prime.push_back(i);
	}

	//	dbArray(prime,prime.size());
}
void primeFactor(int n)
{
	int storN = n;
	for(int i=0;i<prime.size()&&prime[i]<storN;i++){
		bool flag = false;
		while(n>1&&n%prime[i]==0){
			flag = true;
			n/=prime[i];
		}
		if(flag){g[storN].push_back(prime[i]);}
		
	}
	//dbArray(g[storN],g[storN].size());
}
int mxINT = 100000007;
int minSteps = mxINT;
int dfs(int n){
	if(dp[n]!=-1){
		return dp[n];
	}
	if(n==tt){dp[n] = 0;return dp[n];}

	if(n>tt){dp[n] = mxINT;return dp[n];}

	int minFromChild = mxINT;
	for(int i=0;i<g[n].size();i++){
		int pd = g[n][i];
		if(dp[n+pd]!=-1){
				int steps = dp[n+pd];
				minFromChild =min(minFromChild,steps); 
		}
		else
		{
			int steps = dfs(n+pd);
			minFromChild =min(minFromChild,steps); 
		}
	}
	dp[n]= 1+minFromChild;
	return dp[n];
	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    findPrime(MAXX);
    for(int i=0; i<MAXX; i++) primeFactor(i);
    int t,caseno=0;
    cin>>t;
    while(t--){
        cin>>ss>>tt;
        for(int i=0; i<MAXX; i++) {dp[i]=-1;}

       int ans = dfs(ss);
   		if(ans>=mxINT)ans=-1;
       caseprint(caseno,ans);
    }
    return 0;
}