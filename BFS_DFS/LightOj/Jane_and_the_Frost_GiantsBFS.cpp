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
int levelMan[MAXX][MAXX];
int levelFire[MAXX][MAXX];
queue<pair<int,int> > qMan;
queue<pair<int,int> > qFire;
int r,c;

void bfsMan(){
	while(!qMan.empty()){
		pair<int,int> u = qMan.front();
		qMan.pop();
		//bd2(u.first,u.second);
		for(int i=0; i<4; i++) {
			int x = u.first+adjX[i];
			int y = u.second+adjY[i];
			//bd3("bLoop",x,y);
			if(levelMan[x][y]==INF && g[x][y]=='.'){
				//bd2(x,y);
				levelMan[x][y]=levelMan[u.first][u.second]+1;
				qMan.push(make_pair(x,y));
			}
		}
	}
}

void bfsFire(){
	while(!qFire.empty()){
		pair<int,int> u = qFire.front();
		qFire.pop();
		for(int i=0; i<4; i++) {
			int x = u.first+adjX[i];
			int y = u.second+adjY[i];
			if(levelFire[x][y]==INF && g[x][y]=='.'){
				levelFire[x][y]=levelFire[u.first][u.second]+1;
				qFire.push(make_pair(x,y));
			}
		}
	}
}
void makeboundary(){
	for(int i = 0;i<=r+1;i++)g[i][0] = 'X';
    for(int i = 0;i<=c+1;i++)g[0][i] = 'X';
    for(int i = 0;i<=r+1;i++)g[i][c+1] = 'X';
    for(int i = 0;i<=c+1;i++)g[r+1][i] = 'X';
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
        int si,sj;
		
		makeboundary();
		for(int i=0;i<=r+1;i++){
       		for(int j=0; j<=c+1; j++){
       			levelMan[i][j] = INF;
       			levelFire[i][j] = INF;
       		}
       	}
        for(int i=1;i<=r;i++)
        {
        	for(int j=1; j<=c; j++) {
        		cin>>g[i][j];
        		if(g[i][j]=='J'){si=i;sj=j;g[i][j]='.';}
        		if(g[i][j]=='F'){
        			qFire.push(make_pair(i,j));
        			levelFire[i][j]=0;
        		}
        	}
        }

       	qMan.push(make_pair(si,sj));
       	levelMan[si][sj]=0;
       	bfsMan();
       	bfsFire();
       	//bdArray2D(levelMan,r+2,c+2);
       	//bdArray2D(levelFire,r+2,c+2);
       	int ans= INF;
		for(int i = 1;i<=r;i++)if(levelMan[i][1]<levelFire[i][1])ans =min(ans,levelMan[i][1]+1);
	    for(int i = 1;i<=c;i++)if(levelMan[1][i]<levelFire[1][i])ans =min(ans,levelMan[1][i]+1);
	    for(int i = 1;i<=r;i++)if(levelMan[i][c]<levelFire[i][c])ans =min(ans,levelMan[i][c]+1);
	    for(int i = 1;i<=c;i++)if(levelMan[r][i]<levelFire[r][i])ans =min(ans,levelMan[r][i]+1);

	  	if(ans>=INF)caseprint(caseno,"IMPOSSIBLE");
	  	else caseprint(caseno,ans);
	  	while(!qMan.empty())qMan.pop();
	  	while(!qFire.empty())qFire.pop();
    
    }
    return 0;
}