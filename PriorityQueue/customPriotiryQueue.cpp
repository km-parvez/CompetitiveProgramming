// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 300005

using namespace std;
using ll = long long;
struct Node
{
   ll first;
   ll second;
   Node(){first=0;second=0;}
   Node(ll first, ll second)
        : first(first), second(second)
    {
    } 

};
struct Compare {
    bool operator()(Node a, Node b) {
        ll halfa = a.second/2;
        ll halfb = b.second/2;
        return (a.first*a.second-a.first*halfa) < (b.first*b.second-b.first*halfb);
    }
};
void solve(int caseno){
    ll  n,S;
    cin>>n>>S;
    vector<pair<int,int> > g[n+4];
    int ans = 0;
    for(int i=0; i<n-1; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        while(w>S){
            ans++;
            w=w/2;
        }
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    pair<int,ll> node[n+4];
    //for(int i=1; i<=n; i++) {node[i]={0,0};}

    function<int(int,int)> dfs = [&](int par, int u) {
        int mx = 0;
        for(int i=0; i<g[u].size(); i++) {
            int v = g[u][i].first ;
            if(v!=par){
                int tmp = dfs(u,v);
                node[v].second=g[u][i].second;
                mx+=tmp; 
            }
        }
        if(mx==0)mx=1;
        node[u].first = mx;
        return mx;
    };
    dfs(-1,1);
    node[1]={0,0};
    node[0]={0,0};
    priority_queue<Node, vector<Node>, Compare> pq;
    ll sum = 0;
    for(int i=2; i<=n; i++) {
       // whatis3(i,node[i].first,node[i].second);
        pq.emplace(node[i].first,node[i].second);
        sum+=(node[i].first*node[i].second);
    }
    //whatis2(sum,ans);
    while(!pq.empty()&&sum>S){
        Node top = pq.top();
        pq.pop();
      //  whatis2(top.first,top.second);
        sum-=top.first*top.second;
        top.second = top.second/2;
        sum+=(top.first*top.second);
        ans++;
        pq.emplace(top);
        
    }
    cout<<ans<<endl;
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}