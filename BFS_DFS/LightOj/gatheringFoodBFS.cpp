// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define dbArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 12
#define INF 1000000007

using namespace std;
using ll = long long;

int adjX[] = {0,0,-1,1};
int adjY[] = {-1,1,0,0};

char g[MAXX][MAXX];
int level[MAXX][MAXX];
pair<int,int>  foodPos[33];
int r,c,n;

bool inBoundary(int i,int j){
	if(i<1||i>r||j<1||j>c) return false;
	else 
		return true;
}
int bfs(int si,int sj,int di,int dj){

	for(int i=0;i<=r+1;i++){
   		for(int j=0; j<=c+1; j++){
   			level[i][j] = INF;
   		}
   	}
	queue<pair<int,int> > qYogi;
	qYogi.push(make_pair(si,sj));
    level[si][sj]=0;

	bool foundFlag = false;
	while(!qYogi.empty()){
		pair<int,int> u = qYogi.front();
		qYogi.pop();
		//bd2(u.first,u.second);
		for(int i=0; i<4; i++) {
			int x = u.first+adjX[i];
			int y = u.second+adjY[i];
			//bd3("bLoop",x,y);
			if(x==di && y==dj){
				//bd2(x,y);
				level[x][y]=level[u.first][u.second]+1;
				g[x][y]='.';
				foundFlag = true;
				break;
			}
			else if(inBoundary(x,y)&&level[x][y]==INF && g[x][y]=='.'){
				//bd2(x,y);
				level[x][y]=level[u.first][u.second]+1;
				qYogi.push(make_pair(x,y));
			}
		}
		if(foundFlag){
			while(!qYogi.empty())qYogi.pop();
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

        cin>>n;
        r=n;c=n;

       	int cntFood = 0;
        for(int i=1;i<=r;i++)
        {
        	for(int j=1; j<=c; j++) {
        		cin>>g[i][j];
        		
        		if(g[i][j]>='A'&&g[i][j]<='Z'){
        			foodPos[g[i][j]-'A'] = make_pair(i,j);
        			g[i][j]='#';
        			cntFood++;
        		}
        	}
        }
        g[foodPos[0].first][foodPos[0].second] ='.';
        bool imp= false;
        int ans=0;
       	for(int i=1; i<cntFood; i++) {
       		int si = foodPos[i-1].first;
       		int sj = foodPos[i-1].second;
       		int di = foodPos[i].first;
       		int dj = foodPos[i].second;
       		int subans = bfs(si,sj,di,dj);
       		if(subans==INF){
       			imp = true;
       			break;
       		}
       		else
       			ans+=subans;

       	}
	   
       	//bdArray2D(level,r+2,c+2);
       	//bdArray2D(levelFire,r+2,c+2);

	  	if(imp)caseprint(caseno,"Impossible");
	  	else caseprint(caseno,ans);
    }
    return 0;
}