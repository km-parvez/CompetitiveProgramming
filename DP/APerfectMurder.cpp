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
#define MAXX 1005

using namespace std;
using ll = long long;
vector<int> g[MAXX];
int visited[MAXX];
int dp[3][MAXX];
int func(bool prv,int node,int par){
	
	if(dp[prv][node]!=-1)
		return dp[prv][node];
	if(prv){
		int res = 0;
		for(int i=0; i<g[node].size(); i++) {
			int cur = g[node][i];
			if(cur!=par){
				res+=func(false,cur,node);
			}
		}
		return dp[prv][node] = res;
	}
	else
	{
		
		int res = 0;
		for(int i=0; i<g[node].size(); i++) {
			int cur = g[node][i];
			if(cur!=par){
				res+=max(func(false,cur,node),func(true,cur,node)+1);
			}
		}
		return dp[prv][node] = res;
	}
}
void solve(int caseno){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=1; i<=n; i++) {

        	if(dp[false][i]==-1){
        		ans+=max(func(false,i,-1),func(true,i,-1)+1);
        	}
        }
        caseprint(caseno,ans);
        for(int i=0; i<=n; i++)
        g[i].clear();
    
    
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