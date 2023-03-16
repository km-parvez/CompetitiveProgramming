	// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 100005

using namespace std;
using ll = long long;
vector<int> g[MAXX];
bool visited[MAXX];
ll cnt = 0;
ll ans = 0;
int n;
void dfs(int u){
	cnt++;
	visited[u]=true;
	for(int i=0; i<g[u].size(); i++) {
		int v= g[u][i];
		if(!visited[v]){
			dfs(v);
		}
	}
	//db2(u,cnt);
	ans+=(n-cnt);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        cin>>n;
        int x,y;
       ans = 0;	
       cnt=0;
       for(int i=0; i<n+2; i++) {
       	g[i].clear();
       	visited[i]=false;
       }
        for(int i=1;i<n;i++){
        	 cin>>x>>y;
        	 g[x].push_back(y);
        }
        dfs(1);
		cout<<"Case "<<++caseno<<": "<<n-1<<" "<<ans<<endl;
    }
    return 0;
}