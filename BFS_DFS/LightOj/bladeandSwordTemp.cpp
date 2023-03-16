// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define dbArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 204
#define INF 1000000007

using namespace std;
using ll = long long;

int adjX[] = {0,0,-1,1};
int adjY[] = {-1,1,0,0};

char g[MAXX][MAXX];
int level[MAXX][MAXX];
int level2[MAXX][MAXX];
vector< pair<int,int> >  telePos;
int r,c,n;


int bfs(int si,int sj,int di,int dj){

	queue<pair<int,int> > q;
	q.push(make_pair(si,sj));
    level[si][sj]=0;

	bool foundFlag = false;
	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();

  		for(int i=0; i<4; i++) {  
  			int x = u.first+adjX[i];
  			int y = u.second+adjY[i];
  			 if( level[x][y]==INF && g[x][y]=='.'){
  				//bd2(x,y);
  				level[x][y]=level[u.first][u.second]+1;
  				q.push(make_pair(x,y));
  			}
        else if( level[x][y]==INF && g[x][y]=='*'){
         level[x][y]=level[u.first][u.second]+1; 
        }
        else if(x==di&&y==dj){
           level[x][y]=level[u.first][u.second]+1; 
             foundFlag =true;
           break;      
        }
  		
    }

    if(foundFlag){while(!q.empty())q.pop();}
	}
	
	return level[di][dj];   
}


int bfs2(int si,int sj,int di,int dj){

  queue<pair<int,int> > q;
  q.push(make_pair(si,sj));
    level2[si][sj]=0;

  bool foundFlag = false;
  while(!q.empty()){
    pair<int,int> u = q.front();
    q.pop();

      for(int i=0; i<4; i++) {  
        int x = u.first+adjX[i];
        int y = u.second+adjY[i];
         if( level2[x][y]==INF && g[x][y]=='.'){
          //bd2(x,y);
          level2[x][y]=level2[u.first][u.second]+1;
          q.push(make_pair(x,y));
        }
        else if( level2[x][y]==INF && g[x][y]=='*'){
         level2[x][y]=level2[u.first][u.second]+1; 
        }
        else if(x==di&&y==dj){
           level2[x][y]=level2[u.first][u.second]+1;  
           foundFlag =true;
           break;       
        }
      
    }
    if(foundFlag){while(!q.empty())q.pop();}
  }
  
  return level2[di][dj];   
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases,caseno=0;
    cin>>cases;
    while(cases--){

        cin>>r>>c;
        int si,sj,di,dj;
        telePos.clear();
       	int cntFood = 0;
        for(int i=1;i<=r;i++)
        {
        	for(int j=1; j<=c; j++) {
        		cin>>g[i][j];
        		
        		if(g[i][j]=='*'){
        			telePos.push_back(make_pair(i,j));
        		}
            else if(g[i][j]=='P')
            {

              si=i;sj=j;
            }
            else if(g[i][j]=='D')
            {
              di=i;dj=j;
            }
        	}
        }
        if(telePos.size()==1){
        //  db1("FOUND");
          pair<int,int> tmp = telePos[0];
          g[tmp.first][tmp.second] = '#';
          telePos.clear();
        }

        for(int i=0;i<=r+1;i++){
            for(int j=0; j<=c+1; j++){
              level[i][j] = INF;
            }
          }
         for(int i=0;i<=r+1;i++){
          for(int j=0; j<=c+1; j++){
            level2[i][j] = INF;
          }
        }
        int ans1 = bfs2(si,sj,di,dj);
        int ans2 = bfs(di,dj,si,sj);
       // db2(ans1,ans2);
       	//bdArray2D(level,r+2,c+2);
       	//bdArray2D(levelFire,r+2,c+2);
        int ans = INF;
        int mn1 = INF;
        int mn2 = INF;
        pair<int,int> mnP1,mnP2;
        for(int i=0; i<telePos.size(); i++) {
         
            if(mn1>=level[telePos[i].first][telePos[i].second]){
              mn2=mn1;
              mnP2= mnP1;
              mnP1 = telePos[i];
              mn1 = level[telePos[i].first][telePos[i].second];
            }
            else if(mn2>=level[telePos[i].first][telePos[i].second]){
              mnP2 = telePos[i];
              mn2 = level[telePos[i].first][telePos[i].second];
            }
        }

       int mnx1 = INF;
        int mnx2 = INF;
        pair<int,int> mnxP1,mnxP2;
        for(int i=0; i<telePos.size(); i++) {
            if(mnx1>=level2[telePos[i].first][telePos[i].second]){
              mnx2=mnx1;
              mnxP2= mnxP1;
              mnxP1 = telePos[i];
              mnx1 = level2[telePos[i].first][telePos[i].second];
            }
            else if(mnx2>=level2[telePos[i].first][telePos[i].second]){
              mnxP2 = telePos[i];
              mnx2 = level2[telePos[i].first][telePos[i].second];
            }
        }
        //db2(mn1,mnx1);
       // db2(mn2,mnx2);
       int res11,res12,res21,res22;
       if(mnP1.first==mnxP1.first&&mnP1.second==mnxP1.second)
        res11= mn1+mnx1+2;
       else
        res11 = mn1+mnx1+1;

       if(mnP1.first==mnxP2.first&&mnP1.second==mnxP2.second)
        res12= mn1+mnx2+2;
       else
        res12 = mn1+mnx2+1;

      if(mnP2.first==mnxP1.first&&mnP2.second==mnxP1.second)
        res21= mn2+mnx1+2;
       else
        res21 = mn2+mnx1+1;

       if(mnP2.first==mnxP2.first&&mnP2.second==mnxP2.second)
        res22= mn2+mnx2+2;
       else
        res22 = mn2+mnx2+1;
      ans = min(ans,res11);
      ans = min(ans,res12);
      ans = min(ans,res21);
      ans = min(ans,res22);
      ans = min(ans,ans1);
      ans = min(ans,ans2);


	  	if(ans==INF)caseprint(caseno,"impossible");
	  	else caseprint(caseno,ans);
    }
    return 0;
}