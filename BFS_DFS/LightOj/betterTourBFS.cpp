// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 50004

using namespace std;
using ll = long long;
vector<int> g[MAXX];
int par[MAXX];
void bfs(int s,int d){
	bool visited[MAXX]={false};
	visited[s]=true;
	par[s]=-1;
	queue<int> q;
	q.push(s);
	bool flag = false;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<g[u].size(); i++) {
			int v = g[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v]=true;
				par[v]=u;

				if(v==d){
					flag = true;
					break;
				}
			}
		}
		if(flag){break;}
	}

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
    	memset(par,0,sizeof par);
        int n;
        cin>>n;
        int s,d,u,v;
        cin>>u;
        s=u;
        for(int i=1;i<n;i++){
        	 cin>>v;
        	 g[u].push_back(v);
        	 g[v].push_back(u);
        	 u=v;
        }
        d=v;
        for(int i=0; i<MAXX; i++) {
        	sort(g[i].begin(), g[i].end());
        }
        bfs(s,d);
        vector<int> ans;
        while(d!=-1){
        	ans.push_back(d);
        	d= par[d];
        }
        cout<<"Case "<<++caseno<<":"<<endl;
        for(int i=ans.size()-1;i>=0;i--){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
    
        for(int i=0; i<MAXX; i++) {
        	g[i].clear();
        }
    }
    return 0;
}