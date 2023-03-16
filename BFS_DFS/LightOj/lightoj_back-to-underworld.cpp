// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX 20004

using namespace std;
using ll = long long;
vector<int> g[MAXX];
int level[MAXX];
bool visited[MAXX];
int mxlevel = 0;
int lvl[MAXX];
void dfs(int u,int l){
	mxlevel = max(mxlevel,l);
	level[l]++;
	lvl[u] = l;
	visited[u] = true;

	for(int i=0; i<g[u].size(); i++) {
		int v= g[u][i];
		if(!visited[v])
			dfs(v,l+1);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,caseno = 0;
    cin>>t;
    while(t--){
    	mxlevel = 0;
    	for(int j=0; j<MAXX; j++) {
    		g[j].clear();
    		level[j]= 0;
    		visited[j]=false;
    	}
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
        	int x,y;
        	cin>>x>>y;
        	g[x].push_back(y);
        	g[y].push_back(x);
        }
        int totMax = 0;
        for(int i =1;i<=20000;i++)
        {

        	if(g[i].size()!=0&& !visited[i]){
        	//	db2(i,lvl[i]);
	        	for(int j=0; j<mxlevel+2; j++) {
	        		level[j]= 0;
	        	}
	        	mxlevel = 0;
	        	dfs(i,1);
	        	// db1(mxlevel);
	        	int oddlevel=0,evenlevel=0;
	        	for(int j=1; j<=mxlevel; j++) {
	        	//	db1(level[j]);
	        		if(j&1)oddlevel+=level[j];
	        		else evenlevel+=level[j];
	        	}
	        	totMax +=max(evenlevel,oddlevel);
	        		
        	}
        }
    
        cout<<"Case "<<++caseno<<": "<<totMax<<'\n';

    }
    return 0;
}