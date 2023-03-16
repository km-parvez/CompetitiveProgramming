// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 30004
int INF = -1;
using namespace std;
using ll = long long;

vector< pair<int,int> > v[MAXX];
int levelCost[MAXX][3];
vector<int> indNode;
queue<int> q;
void bfs(int s,int ind){
	q.push(indNode[ind]);
	levelCost[indNode[ind]][s] = 0;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i=0; i<v[tmp].size(); i++) {
			int node = v[tmp][i].first;
			int weight = v[tmp][i].second;
			if(levelCost[node][s]==INF){
				levelCost[node][s]= levelCost[tmp][s]+weight;
				q.push(node);
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
        int n;
        cin>>n;
       for(int i=0; i<n; i++) {
       	for(int j=0; j<3; j++)
       	levelCost[i][j]=INF;
        v[i].clear();
       }
       indNode.clear();

       for(int i=0; i<n-1; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
       }
      

     
       for(int i=0; i<n; i++) {
	        if(v[i].size()==1){
	        	indNode.push_back(i);
	        }
       }
       
       int mxLevelInd=0;
       int mxLevel = 0;
       bfs(0,0);
       for(int i=0; i<indNode.size(); i++) {
       		if(levelCost[indNode[i]][0]>mxLevel){
       			mxLevelInd = i;
       			mxLevel = levelCost[indNode[i]][0];
       		}
       }
       bfs(1,mxLevelInd);
       int mxLevelInd2=0;
       int mxLevel2 = 0;
      
       for(int i=0; i<indNode.size(); i++) {
       		if(levelCost[indNode[i]][1]>mxLevel2){
       			mxLevelInd2 = i;
       			mxLevel2 = levelCost[indNode[i]][1];
       		}
       }
       
       bfs(2,mxLevelInd2);

       cout<<"Case "<<++caseno<<":"<<endl;
       for(int i=0; i<n; i++) { 
	 		int mx = max(levelCost[i][1],levelCost[i][2]);
	 		cout<<mx<<endl;
		}
		while(!q.empty())q.pop();

    }
    return 0;
}