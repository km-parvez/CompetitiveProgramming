// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 200005
#define INF 1000000007
using namespace std;
using ll = long long;
template<class...Args>
void debug(Args... args) {
    auto tmp = {(cout << args << ' ', 0)...};
    cout << endl;
}
int adjX[]={-1,1,0,0};
int adjY[]={0,0,-1,1};
vector< int > g[MAXX];
bool visited[MAXX];
int nodeCount = 0;
void dfs(int s){
    visited[s]=true;
    nodeCount++;
    debug(g[s]);
    for(int i=0; i<g[s].size(); i++) {
        if(!visited[g[s][i]]){
            dfs(g[s][i]);
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
        int n,m;
        cin>>n>>m;
        bool stateOfEdge[m+2];
        pair<int,pair<int,int> >edges[m+2]; 
       for(int i=0; i<m; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        edges[i]=make_pair(w,make_pair(x,y));
        stateOfEdge[i]=true;
       }
       int ans = 0;
       for(int k=30; k>=0; k--) {
            int mask = 1<<k;
            vector<int> selectedEdge;
            bool needdfs = false;
            for(int i=0; i<m; i++) {
               int tmpw = edges[i].first;
               if(tmpw & mask)
                    needdfs = true;
            }
            if(needdfs){
                for(int i=0; i<m; i++) {
                  if(stateOfEdge[i]){
                    int tmpw = edges[i].first;
                
                    if(tmpw & mask){
                        needdfs = true;
                        selectedEdge.push_back(i);
                    }
                    else
                    {
             
                        pair<int,int> tmpNode = edges[i].second;
                        g[tmpNode.first].push_back(tmpNode.second);
                        g[tmpNode.second].push_back(tmpNode.first);
                    }
                  }    
              }
       
         
          
             
              nodeCount = 0;
              dfs(1);
              if(nodeCount==n){
                 for(int i=0; i<selectedEdge.size(); i++) {
                    stateOfEdge[selectedEdge[i]]=false;
                 }
              }
              else
              {
                ans|=mask;
              }
              for(int i=0; i<=n; i++) {
                  g[i].clear();
                  visited[i]=false;
              }
             
          }
     

       }
       cout<<ans<<endl;

  
      

    }
    return 0;
}