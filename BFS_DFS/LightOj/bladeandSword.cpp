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
vector< pair<int,int> >  telePos;
int r,c,n;

int bfs(int si,int sj,int di,int dj){

	for(int i=0;i<=r+1;i++){
   		for(int j=0; j<=c+1; j++){
   			level[i][j] = INF;
   		}
   	}
	queue<pair<int,int> > q;
	q.push(make_pair(si,sj));
    level[si][sj]=0;

	bool foundFlag = false;
	while(!q.empty()){
		pair<int,int> u = q.front();
    int lvl = level[u.first][u.second];
    int uu = u.first;
    int vv = u.second;
    db3(uu,vv,lvl);
		q.pop();
		//bd2(u.first,u.second);

    if(g[u.first][u.second]=='*'){
       // db2(uu,vv);
       // db1(lvl);
        for(int i=0; i<telePos.size(); i++) {
          int x = telePos[i].first;
          int y = telePos[i].second;
         
            level[x][y]=level[u.first][u.second]+1;
            q.push(make_pair(x,y));
           
        }
        telePos.clear();
        g[u.first][u.second]='#';
        level[u.first][u.second]=level[u.first][u.second]+2;
        q.push(make_pair(u.first,u.second));
    
    }
    else{
  		for(int i=0; i<4; i++) {
  			int x = u.first+adjX[i];
  			int y = u.second+adjY[i];
  			//bd3("bLoop",x,y);
  			if(x==di && y==dj){
  				//bd2(x,y);
  				level[x][y]=level[u.first][u.second]+1;
  				foundFlag = true;
  				break;
  			}
        else if( level[x][y]==INF && g[x][y]=='*'){
          //bd2(x,y);
          level[x][y]=level[u.first][u.second]+1;
          q.push(make_pair(x,y));
        } 
  			else if( level[x][y]==INF && g[x][y]!='#'){
  				//bd2(x,y);
  				level[x][y]=level[u.first][u.second]+1;
  				q.push(make_pair(x,y));
  			}
  		}
    }
		if(foundFlag){
			while(!q.empty())q.pop();
		}
	}
	
	return level[di][dj];   
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

        int ans = bfs(si,sj,di,dj);

       	//bdArray2D(level,r+2,c+2);
       	//bdArray2D(levelFire,r+2,c+2);

	  	if(ans==INF)caseprint(caseno,"impossible");
	  	else caseprint(caseno,ans);
    }
    return 0;
}