// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  100005
using namespace std;
using ll = long long;
int par[MAXX];
int find(int x){
	if(par[x]==x){
		return x;
	}
	else{
	 return	par[x] = find(par[x]);
	}
}
void join(int a,int b){
	int ra= find(a);
	int rb= find(b);
	if(ra!=rb){
		par[rb]=ra;
	}
}
void makeset(int n){
	for(int i=1; i<=n; i++) {
		par[i]=i;
	}
}

vector<int> g[MAXX];
int level[MAXX];

int bfs(int s){
	bool visited[MAXX]={false};
    level[s] = 0;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    int u,v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++) {
            v = g[u][i] ;
            if(!visited[v]){
                visited[v] = true;
                level[v] = level[u]+1;
                q.push(v);
            }
        }

    }
    return u;
}


int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
	cin>>cases;
	while(cases--){
        int n,m;
        cin>>n>>m;
        makeset(n);
        for(int i=0; i<n+3; i++) {
        	g[i].clear();
        }
        for(int i=0; i<m; i++) {
        	int x,y;
        	cin>>x>>y;
        	g[x].push_back(y);
        	g[y].push_back(x);
        	join(x,y);
        }
        vector<int> reps;
        int repcnt[n+3]={0};
        for(int i=1; i<=n; i++) {
        	find(i);
        }
        for(int i=1; i<=n; i++) {
        	repcnt[par[i]]++;
        }
        for(int i=1; i<=n; i++) {
        	if(repcnt[i]>1)reps.push_back(i);
        }
        int maxlen[n+3];
        for(int i=0; i<reps.size(); i++) {
        	int curRep = reps[i];
        	int nextInd = bfs(curRep);
        	nextInd = bfs(nextInd);
        	maxlen[curRep]= level[nextInd];
        }
		/*for(int i=0; i<reps.size(); i++) {
			int x = reps[i];
			db2(x,maxlen[x]);
		}*/
        int q;
        cin>>q;
        cout<<"Case "<<++caseno<<":"<<endl;
        while(q--){
        	int k;
        	cin>>k;
        	if(k==1){cout<<0<<endl;continue;}
        	bool found = false;
        	int ans = MAXX;
        	for(int i=0; i<reps.size(); i++) {
        		int curRep = reps[i];
        		if(repcnt[curRep]>=k){
        			found = true;
        			if(maxlen[curRep]>=k-1){
						ans = k-1;
						break;
        			}
        			else
        			{
        				ans = min(ans,maxlen[curRep]+(k-1-maxlen[curRep])*2);
        			}
        			
        		}
        	}
        	if(found)
        		cout<<ans<<endl;
        	else cout<<"impossible"<<endl;
        }
  	}  
    return 0;
}