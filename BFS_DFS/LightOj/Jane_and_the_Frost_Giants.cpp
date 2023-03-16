// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define dbArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 204
#define mxINT 1000000007
#define mxTime 102
using namespace std;
using ll = long long;

int adjX[] = {0,0,-1,1};
int adjY[] = {-1,1,0,0};

char g[mxTime][MAXX][MAXX];
int mxTimeNeed =0;
int r,c;
pair<int,int>  dp[MAXX][MAXX];
deque< pair<int,int> > fire;
void findMxTime(){

	int time = 0;
	for( time=1;time<mxTime;time++){
		 for(int i=0;i<=r+1;i++)
        {
        	for(int j=0; j<=c+1; j++) {
        		g[time][i][j]=g[time-1][i][j];
        	}
        }
		bool flag = false;
		fire.push_back(make_pair(-1,-5));
		while(!fire.empty()&&fire.front().second!=-5) {
			pair<int,int> tmp = fire.front();
			fire.pop_front();
		//	db2(fire[ii].first,fire[ii].second);
			for(int i=0;i<4;i++){
				int x = adjX[i]+tmp.first;
				int y = adjY[i]+tmp.second;
				
					char cur = g[time][x][y];
					if(cur=='.'){
						flag = true;
						g[time][x][y] = 'F';
						fire.push_back(make_pair(x,y));
					}

			}
		}
		fire.pop_front();
		if(!flag){mxTimeNeed= time-1; break;} 
	}
}

pair<int,int>  dfs(int si,int sj,int ft)
{
if(ft>mxTime)return dp[si][sj];
	//db3(si,sj,ft);	
	if(g[min(ft,mxTimeNeed)][si][sj]=='X'){
	//	cout<<"Top return"<<ft<<endl;
		dp[si][sj].first = min(ft,dp[si][sj].first);
		dp[si][sj].second = 0;
		return dp[si][sj];
	}

	int minSteps = mxINT;
	pair<int,int>  steps;
	int gtime = min(ft+1,mxTimeNeed);

	//dbArray2D(g[gtime],r+2,c+2);
	for(int i=0;i<4;i++){
		int x = adjX[i]+si;
		int y = adjY[i]+sj;
		char cur = g[gtime][x][y];
		if(cur=='.'||cur=='X'){
		//	db3(si,sj,cur);

			if(dp[si][sj].first>=ft+1){

				steps = dfs(x,y,ft+1);
				minSteps = min(minSteps,steps.second+1);
				//db3(x,y,minSteps);
			}
		}
	}

	dp[si][sj]= make_pair(ft,minSteps);
	return dp[si][sj];

}
void makeboundary(){
	for(int i = 0;i<=r+1;i++)g[0][i][0] = 'X';
    for(int i = 0;i<=c+1;i++)g[0][0][i] = 'X';
    for(int i = 0;i<=r+1;i++)g[0][i][c+1] = 'X';
    for(int i = 0;i<=c+1;i++)g[0][r+1][i] = 'X';
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
	

        for(int i=1;i<=r;i++)
        {
        	for(int j=1; j<=c; j++) {
        		cin>>g[0][i][j];
        		if(g[0][i][j]=='J'){si=i;sj=j;g[0][i][j]='.';}
        		if(g[0][i][j]=='F'){fire.push_back(make_pair(i,j));}
        	}
        }

        
        makeboundary();
        findMxTime();
		for(int i=0;i<=r+1;i++)
       		for(int j=0; j<=c+1; j++)
       			dp[i][j] = make_pair(mxINT,mxINT);
       			 


      //   db1(mxTimeNeed);
      //   for(int i=0; i<=mxTimeNeed; i++) {dbArray2D(g[i],r+2,c+2);}

      	int ans =  dfs(si,sj,0).second;

	  	if(ans>=mxINT)caseprint(caseno,"IMPOSSIBLE");
	  	else caseprint(caseno,ans);
    
    }
    return 0;
}