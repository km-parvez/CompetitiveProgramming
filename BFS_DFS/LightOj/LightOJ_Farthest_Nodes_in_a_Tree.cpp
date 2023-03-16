// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 30004
#define INF 1000000007
using namespace std;
using ll = long long;
int adjX[]={-1,1,0,0};
int adjY[]={0,0,-1,1};
vector< pair<int,int> > v[MAXX];

int dfs(int par,int s){
 //  cout<<s<<endl;
   int mval = 0;
    for(int i=0; i<v[s].size(); i++) {
        if(v[s][i].first!=par){
            int val = dfs(s,v[s][i].first)+v[s][i].second;
            mval =max(mval,val);
        }
    }
    return mval;
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
       for(int i=0; i<n-1; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
       }
       cout<<"Case "<<++caseno<<":"<<endl;
       for(int i=0; i<n; i++) {
        cout<<dfs(-1,i)<<endl;
       }
      // cout<<dfs(1,0)<<endl;
       for(int i=0; i<n; i++) {
        v[i].clear();
       }

    }
    return 0;
}