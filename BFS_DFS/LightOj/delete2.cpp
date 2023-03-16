// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  100009
using namespace std;
using ll = long long;
vector<int> g[MAXX];
int level[2][MAXX];
int cnt = 0;
int bfs(int step,int s){
    cnt = 0;
    level[step][s] = 0;
    queue<int> q;
    q.push(s);
    int u,v;
    while(!q.empty()){
        cnt++;
        u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++) {
            v = g[u][i] ;
            if(level[step][v]<0){
                level[step][v] = level[step][u]+1;
                q.push(v);
            }
        }

    }
    return u;
}


int main()
{
   // ios::sync_with_stdio(0);
    int cases,caseno=0;
	  scanf("%d",&cases);
	while(cases--){
        int n,m;
       scanf("%d%d",&n,&m);
        for(int i=0; i<MAXX; i++) {
        	g[i].clear();
            level[0][i] = -1;
            level[1][i] = -1;
        }
        for(int i=0; i<m; i++) {
        	int x,y;
        	scanf("%d%d",&x,&y);
        	g[x].push_back(y);
        	g[y].push_back(x);
        }
        vector<int> reps;
        int repcnt[MAXX];
        int maxlen[MAXX];
        for(int i=1; i<=n; i++) {
            if(level[0][i]<0){
                
            	int nextInd = bfs(0,i);
                if(cnt>2){
            	nextInd = bfs(1,nextInd);
            	maxlen[i]= level[1][nextInd];
                repcnt[i]=cnt;
                reps.push_back(i);
            }
            }
        }
		/*for(int i=0; i<reps.size(); i++) {
			int x = reps[i];
			db2(x,maxlen[x]);
		}*/
        int q;
        scanf("%d",&q);
         printf("Case %d:\n",++caseno );
        while(q--){
        	int k;
        	scanf("%d",&k);
            if(k==1){printf("0\n" );continue;}
            if(k>n){printf("impossible\n");continue;}
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
                printf("%d\n",ans );
            else printf("impossible\n");
        }
  	}  
    return 0;
}