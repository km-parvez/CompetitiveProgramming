// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX 12

using namespace std;
using ll = long long;
//(x+1, y+2), (x+1, y-2), (x+2, y+1), (x+2, y-1), 
//(x-1, y+2), (x-1, y-2), (x-2, y+1), (x-2, y-1)
int adjX[] = {1,1,2,2,-1,-1,-2,-2};
int adjY[] = {2,-2,1,-1,2,-2,1,-1};
int g[MAXX][MAXX];
bool visited[MAXX][MAXX];
int level[MAXX*MAXX][MAXX][MAXX];
int m,n;

bool isInBoundary(int x,int y){
    if(x>=m || x<0 || y>=n || y<0)
        return false;
    else 
        return true;
}

queue<pair<int,int> > q;
void bfs(int s,int i, int j){
    level[s][i][j] = 0;
    visited[i][j] = true;
    q.push(make_pair(i,j));
    while(!q.empty()){
        pair<int,int>  u = q.front();
        q.pop();
        for(int k=0; k<8; k++) {
            int x = u.first+adjX[k];
            int y = u.second+adjY[k];
            //bd3("bLoop",x,y);
            if(isInBoundary(x,y) && !visited[x][y]){
                visited[x][y] = true;
                level[s][x][y] = level[s][u.first][u.second]+1;
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
    int t,caseno=0;
    cin>>t;
	while(t--){

        vector<int> riders;
        vector<pair<int,int> >rpos; 
        cin>>m>>n;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                char ch;
                cin>>ch;
                if(ch!='.'){
                    int digit = ch-'0';
                    riders.push_back(digit);
                    rpos.push_back(make_pair(i,j));
                }
            }
        }
        for(int k=0; k<riders.size(); k++) {
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    level[k][i][j]=-1;
                }
            }
        }
  
        for(int k=0; k<riders.size(); k++) {

            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    visited[i][j] =false;
                }
            }

            pair<int,int> cur = rpos[k];
            bfs(k,cur.first,cur.second);   
        }

     
        int inf = 1000000007;
        int ans = inf;
       for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                bool flag = true;
                int sum = 0;
                for(int k=0; k<riders.size(); k++) {
                    if(level[k][i][j]==-1){
                        flag = false;
                        break;
                    }
                    else{
                        sum+=ceil((float)level[k][i][j]/(float)riders[k]);
                    }
                }
                if(flag){
                    ans = min(ans,sum);
                }
            }
        }

        if(ans==inf)
            cout<<"Case "<<++caseno<<": "<<-1<<endl;
        else
         cout<<"Case "<<++caseno<<": "<<ans<<endl;

    }
    return 0;
}