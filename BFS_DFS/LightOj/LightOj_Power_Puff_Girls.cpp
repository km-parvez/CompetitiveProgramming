// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 25
#define INF 1000000007
using namespace std;
using ll = long long;
int adjX[]={-1,1,0,0};
int adjY[]={0,0,-1,1};
char g[MAXX][MAXX];
int level[MAXX][MAXX];
queue< pair<int,int> > q;
pair<int,int> aa,bb,cc,h;
void bfs(){

	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int x = u.first+adjX[i];
			int y = u.second+adjY[i];
			if(level[x][y]==INF && g[x][y]!='#'){
				level[x][y]=level[u.first][u.second]+1;
				q.push(make_pair(x,y));
			}
		}
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
        int r,c;
        cin>>r>>c;
        for(int i=1; i<=r; i++){
        	for(int j=1; j<=c; j++) {
	     	level[i][j]=INF;
	        }
	    }
        for(int i=1; i<=r; i++){
        	for(int j=1; j<=c; j++) {
        		cin>>g[i][j];
        		if(g[i][j]=='m')g[i][j]='#';
        		else if(g[i][j]=='a')aa=make_pair(i,j);
        		else if(g[i][j]=='b')bb=make_pair(i,j);
        		else if(g[i][j]=='c')cc=make_pair(i,j);
        		else if(g[i][j]=='h')h=make_pair(i,j);
        	}
        }
        level[h.first][h.second]=0;
        q.push(h);
        bfs();
        int ans = -1;
        ans = max(ans,level[aa.first][aa.second]);
        ans = max(ans,level[bb.first][bb.second]);
        ans = max(ans,level[cc.first][cc.second]);
        caseprint(caseno,ans);

        while(!q.empty()){q.pop();} 
    
    }
    return 0;
}