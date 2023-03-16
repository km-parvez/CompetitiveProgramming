// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 203

using namespace std;
using ll = long long;
int INF = 1e9+7;
vector<pair<int,int> > g[MAXX];
int color[MAXX];
int ans;

void dfs(int pos,int par,int u,int tot){
	//db1(u);
	color[u]=1;
	for(int i=0; i<g[u].size(); i++) { 
		if(u==1&&i==pos)
			continue;
		pair<int,int> nxt = g[u][i];

		int v = nxt.first;
		int c = nxt.second;

		if(v!=par&&color[v]==0){
			dfs(pos,u,v,tot+c);
		}
		else if(v!=par&&v==1){
			//db2(u,c);
			color[v] = 2;
			ans = tot+c;
		}
	}
	color[u] = 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        int n,a,b,c;
        cin>>n;
        for(int i=0; i<n+3; i++) {
        	g[i].clear();
        	color[i]=0;
        }
        for(int i=0;i<n;i++){
        	cin>>a>>b>>c;
        	g[a].push_back(make_pair(b,c));
        	g[b].push_back(make_pair(a,0));
        }
		ans = 0;
  		dfs(1,-1,1,0);
		int mn1 = ans;
		memset(color,0,sizeof color);
		ans = 0;
		//cout<<"Second"<<endl;
		dfs(0,-1,1,0);
		int mn2 = ans;
	//	db2(mn1,mn2);
		caseprint(caseno,min(mn1,mn2));    
    }
    return 0;
}