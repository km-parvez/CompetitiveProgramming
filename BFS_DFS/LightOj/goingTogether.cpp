// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define ff first
#define ss second
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 11

using namespace std;
using ll = long long;
int adjX[] = {0,0,-1,1};
int adjY[] = {-1,1,0,0};
struct three{
	pair<int,int> a;
	pair<int,int> b;
	pair<int,int> c;
};
int n;
char graph[MAXX][MAXX];
pair<int,int> rob[3];
pair<int,int> gol[3];
int dis[MAXX][MAXX][MAXX][MAXX][MAXX][MAXX];

bool check(int i,int j){
  if(i>=0&&i<n&&j>=0&&j<n) 
  	return true;
  else
   return false;
}
int bfs(int ax,int ay, int bx,int by,int cx,int cy){
	int jj = 0;
	dis[ax][ay][bx][by][cx][cy] = 0;
	queue< three > q;
	three tmp ;
	tmp.a = make_pair(ax,ay);
	tmp.b = make_pair(bx,by);
	tmp.c = make_pair(cx,cy);
	q.push(tmp);
	while(!q.empty()){

		    three u = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{

				three v=u;
				if(check(u.a.ff+adjX[i],u.a.ss+adjY[i]) && graph[u.a.ff+adjX[i]][u.a.ss+adjY[i]]!='#'){
				v.a = make_pair(u.a.ff+adjX[i],u.a.ss+adjY[i]);
			//	db3("=> ",v.a.ff,v.a.ss);
				}
				if(check(u.b.ff+adjX[i],u.b.ss+adjY[i]) && graph[u.b.ff+adjX[i]][u.b.ss+adjY[i]]!='#'){
				v.b = make_pair(u.b.ff+adjX[i],u.b.ss+adjY[i]);
			//	db3("=> ",v.b.ff,v.b.ss);
				}
				
				if(check(u.c.ff+adjX[i],u.c.ss+adjY[i]) && graph[u.c.ff+adjX[i]][u.c.ss+adjY[i]]!='#'){
				v.c = make_pair(u.c.ff+adjX[i],u.c.ss+adjY[i]);
				//db3("=> ",v.c.ff,v.c.ss);
				}
				
				if(v.a==u.a){
					if(v.b==v.a){v.b=u.b;}
					if(v.c==v.a){v.c=u.c;}
				}
				if(v.b==u.b){
					if(v.a==v.b){v.a=u.a;}
					if(v.c==v.b){v.c=u.c;}
				}
				if(v.c==u.c){
					if(v.a==v.c){v.a=u.a;}
					if(v.b==v.c){v.b=u.b;}
				}
				if(dis[v.a.ff][v.a.ss][v.b.ff][v.b.ss][v.c.ff][v.c.ss]==-1){
					dis[v.a.ff][v.a.ss][v.b.ff][v.b.ss][v.c.ff][v.c.ss]= dis[u.a.ff][u.a.ss][u.b.ff][u.b.ss][u.c.ff][u.c.ss]+1;
					if(graph[v.a.ff][v.a.ss]=='X' && graph[v.b.ff][v.b.ss]=='X' && graph[v.c.ff][v.c.ss]=='X' && (v.a!=v.b && v.b!=v.c && v.a!=v.c ) ){
						return dis[v.a.ff][v.a.ss][v.b.ff][v.b.ss][v.c.ff][v.c.ss];
					}
					q.push(v);
				}

				
			}
	}
	return -1;
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
        memset(dis,-1,sizeof dis);
        int zz=0,yy=0;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		cin>>graph[i][j];
        		if(graph[i][j]=='A'||graph[i][j]=='B'||graph[i][j]=='C'){
        			rob[zz++]=make_pair(i,j);
        		}
        		else if(graph[i][j]=='X'){
        			gol[yy++]=make_pair(i,j);
        		}
        	}
        }
        int res = bfs(rob[0].ff,rob[0].ss,rob[1].ff,rob[1].ss,rob[2].ff,rob[2].ss);
    	if(res==-1) {
    		caseprint(caseno,"trapped");
    	}
    	else
    	{
    		caseprint(caseno,res);
    	}
    }
    return 0;
}